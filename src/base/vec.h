//! -------------------------------------------------------------------------
//!
//! Copyright (C) 2016 CC0 1.0 Universal (CC0 1.0)
//!
//! The person who associated a work with this deed has dedicated the work to
//! the public domain by waiving all of his or her rights to the work
//! worldwide under copyright law, including all related and neighboring
//! rights, to the extent allowed by law.
//!
//! You can copy, modify, distribute and perform the work, even for commercial
//! purposes, all without asking permission.
//!
//! See the complete legal text at
//! <https://creativecommons.org/publicdomain/zero/1.0/legalcode>
//!
//! -------------------------------------------------------------------------

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/complex.h>
#include <pybind11/numpy.h>

#include <sstream>

#include <itpp/base/vec.h>
//#include <itpp/base/math/elem_math.h>

namespace py = pybind11;

// Wrapper function to print Vec<Num_T> nicely in Python.
template<class Num_T>
std::string _print_wrap(const itpp::Vec<Num_T> &v)
{
  int i, sz = v.length();
  std::ostringstream oss;

  oss << "[" ;
  for (i = 0; i < sz; i++) {
    oss << v(i) ;
    if (i < sz - 1)
      oss << " ";
  }
  oss << "]" ;

  return oss.str();
}

//! Copy data at the indices indicated by a binary vector
template<class Num_T>
void _copy_logical(itpp::Vec<Num_T> &v, const itpp::Vec<itpp::bin> &binlist, const itpp::Vec<Num_T> &v1)
{
  int size1 = v1.size();
  it_assert_debug(v.length() == size1, "Vec<>::operator()(bvec &): "
                  "Wrong size of data vector");

  int size = binlist.size();
  it_assert_debug(v.length() == size, "Vec<>::operator()(bvec &): "
                  "Wrong size of binlist vector");

  for (int i = 0; i < size; ++i)
    if (binlist(i) == itpp::bin(1))
      v(i) = v1[i];
}

//! Copy data at the indices indicated by a binary vector
template<class Num_T>
void _copy_logical(itpp::Vec<Num_T> &v, const itpp::Vec<itpp::bin> &binlist, const Num_T &val)
{
  int size = binlist.size();
  it_assert_debug(v.length() == size, "Vec<>::operator()(bvec &): "
                  "Wrong size of binlist vector");

  for (int i = 0; i < size; ++i)
    if (binlist(i) == itpp::bin(1))
      v(i) = val;
}

//
// Conversion from Numpy POD array to itpp::Vec<POD>
//
template<class Num_T>
itpp::Vec<Num_T> _numpy_pod_array_to_vec(py::array_t<Num_T> in) {

  auto inbuf = in.request();
  if (inbuf.ndim != 1)
    throw std::runtime_error("Incompatible number of dimensions!");

  Num_T *inptr = (Num_T *) inbuf.ptr;

  int size = inbuf.shape[0];
  itpp::Vec<Num_T> out(size);
  out.clear();
  for( int i = 0; i < size; ++i ){
    out[i] = inptr[i];
  }
  return out;
}

//
// Conversion from Numpy char array to itpp::Vec<itpp::bin>
//
itpp::Vec<itpp::bin> _numpy_int8_array_to_bvec(py::array_t<char> in) {

  auto inbuf = in.request();
  if (inbuf.ndim != 1)
    throw std::runtime_error("Incompatible number of dimensions!");

  char *inptr = (char *) inbuf.ptr;

  int size = inbuf.shape[0];
  itpp::Vec<itpp::bin> out(size);
  out.clear();
  for( int i = 0; i < size; ++i ){
    out[i] = ( inptr[i] != 0 );
  }
  return out;
}

//
// Template specialization for POD types
//
template<class Num_T>
void numpy_array_to_vec( py::module &m ){
  m.def("numpy_array_to_vec", &_numpy_pod_array_to_vec<Num_T>);
}

//
// Template specialization for itpp::bin type
//
template<>
void numpy_array_to_vec<itpp::bin>( py::module &m ){ 
  m.def("numpy_array_to_vec", &_numpy_int8_array_to_bvec);
}

template<class Num_T>
pybind11::buffer_info vec_buffer_info(itpp::Vec<Num_T> &v){
  return pybind11::buffer_info(
            v._data(),
            sizeof(Num_T),
            pybind11::format_descriptor<Num_T>::format(),
            1,
            { v.size() },
            { sizeof( Num_T ) }
         );
}

template<>
pybind11::buffer_info vec_buffer_info<itpp::bin>(itpp::Vec<itpp::bin> &v){
  return pybind11::buffer_info(
            v._data(),
            sizeof(char),
            pybind11::format_descriptor<char>::format(),
            1,
            { v.size() },
            { sizeof( char ) }
         );
}

template<class Num_T>
void generate_module_functions( py::module &m ) {

  m.def("elem_mult", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_mult));
  m.def("elem_mult", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                     const itpp::Vec<Num_T> &)>(&itpp::elem_mult));
  m.def("elem_mult", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                     const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_mult));

  m.def("elem_mult_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                            itpp::Vec<Num_T> &)>(&itpp::elem_mult_out));
  m.def("elem_mult_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                            const itpp::Vec<Num_T> &, itpp::Vec<Num_T> &)>(&itpp::elem_mult_out));
  m.def("elem_mult_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                            const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                            itpp::Vec<Num_T> &)>(&itpp::elem_mult_out));

  m.def("elem_mult_inplace", static_cast<void (*)(const itpp::Vec<Num_T> &, itpp::Vec<Num_T> &)>(&itpp::elem_mult_inplace));
  m.def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_mult_sum));

  m.def("elem_div", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_div));
  m.def("elem_div", static_cast<itpp::Vec<Num_T> (*)(Num_T, const itpp::Vec<Num_T> &)>(&itpp::elem_div));
  m.def("elem_div_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                            itpp::Vec<Num_T> &)>(&itpp::elem_div_out));
  m.def("elem_div_sum", static_cast<Num_T (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_div_sum));

  numpy_array_to_vec<Num_T>( m );
}

//
// Template for POD types (aupports Numpy conversion)
//

template<class Num_T>
void generate_vec_class( py::module &m, char const * name ) {
  //! Declaration of Vec
  py::class_<itpp::Vec<Num_T> >(m, name, py::buffer_protocol())

    .def_buffer([](itpp::Vec<Num_T>& v) -> pybind11::buffer_info {
        return vec_buffer_info( v );
    })

    .def(py::init<>())
    .def(py::init<int>())
    .def(py::init<const itpp::Factory &>())
    .def(py::init<int, const itpp::Factory &>())
    .def(py::init<const itpp::Vec<Num_T> &>())
    .def(py::init<const itpp::Vec<Num_T> &, const itpp::Factory &>())
    .def(py::init<const char *>()) // NOTE: Cannot pass pointer from Python
    .def(py::init<const char *, const itpp::Factory &>()) // NOTE: Cannot pass pointer from Python
    .def(py::init<const std::string &>())
    .def(py::init<const std::string &, const itpp::Factory &>())
    .def(py::init<const Num_T *, int>()) // NOTE: Cannot pass pointer from Python
    .def(py::init<const Num_T *, int, const itpp::Factory &>()) // NOTE: Cannot pass pointer from Python

    .def("length", &itpp::Vec<Num_T>::length)
    .def("size", &itpp::Vec<Num_T>::size)

    .def("set_size", static_cast<void (itpp::Vec<Num_T>::*)(int, bool)>(&itpp::Vec<Num_T>::set_size))
    .def("set_length", static_cast<void (itpp::Vec<Num_T>::*)(int, bool)>(&itpp::Vec<Num_T>::set_length))
    .def("zeros", &itpp::Vec<Num_T>::zeros)
    .def("clear", &itpp::Vec<Num_T>::clear)
    .def("ones", &itpp::Vec<Num_T>::ones)
    .def("set_from_char", static_cast<void (itpp::Vec<Num_T> ::*)(const char *)>(&itpp::Vec<Num_T>::set)) // NOTE: Cannot pass pointer from Python
    .def("set_from_str", static_cast<void (itpp::Vec<Num_T>::*)(const std::string &)>(&itpp::Vec<Num_T>::set))

    .def("__getitem__", static_cast<const Num_T & (itpp::Vec<Num_T>::*)(int) const>(&itpp::Vec<Num_T>::operator[]))
    .def("__call__", static_cast<const Num_T & (itpp::Vec<Num_T>::*)(int) const>(&itpp::Vec<Num_T>::operator()))
    .def("__getitem__", static_cast<Num_T & (itpp::Vec<Num_T>::*)(int)>(&itpp::Vec<Num_T>::operator[]))
    .def("__call__", static_cast<Num_T & (itpp::Vec<Num_T>::*)(int)>(&itpp::Vec<Num_T>::operator()))
    .def("__call__", static_cast<itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(int, int) const>(&itpp::Vec<Num_T>::operator()))
    .def("__call__", static_cast<itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Vec<Num_T>::operator()))
    .def("__call__", static_cast<itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(const itpp::Vec<itpp::bin> &) const>(&itpp::Vec<Num_T>::operator()))

    .def("get", static_cast<const Num_T & (itpp::Vec<Num_T>::*)(int) const>(&itpp::Vec<Num_T>::get))
    .def("get", static_cast<itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(int, int) const>(&itpp::Vec<Num_T>::get))
    .def("get", static_cast<itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Vec<Num_T>::operator()))
    .def("get", static_cast<itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(const itpp::Vec<itpp::bin> &) const>(&itpp::Vec<Num_T>::operator()))

    .def("set", static_cast<void (itpp::Vec<Num_T> ::*)(int, Num_T)>(&itpp::Vec<Num_T>::set))

    .def("transpose", &itpp::Vec<Num_T>::transpose)
    .def("T", &itpp::Vec<Num_T>::T)
    .def("hermitian_transpose", &itpp::Vec<Num_T>::hermitian_transpose)
    .def("H", &itpp::Vec<Num_T>::H)

    .def(py::self += py::self)
    .def(py::self += Num_T())
    .def(py::self + py::self)
    .def(py::self + Num_T())
    .def(Num_T() + py::self)

    .def(py::self -= py::self)
    .def(py::self -= Num_T())
    .def(py::self - py::self)
    .def(py::self - Num_T())
    .def(Num_T() + py::self)
    // .def(-py::self)

    .def(py::self *= Num_T())
    .def(py::self * py::self)
    .def("dot", static_cast<Num_T (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::dot))
    .def("outer_product", static_cast<itpp::Mat<Num_T> (*)(const itpp::Vec<Num_T> &,
                                                           const itpp::Vec<Num_T> &, bool)>(&itpp::outer_product))
    .def(py::self * Num_T())
    .def(Num_T() * py::self)
    .def(py::self *= Num_T())
    .def(py::self * py::self)

    .def(py::self / Num_T())
    .def(Num_T() / py::self)
    .def(py::self /= Num_T())
    .def(py::self /= py::self)

//    .def("__idiv__", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, Num_T)>(&itpp::operator/),
//                                                     py::return_value_policy<py::return_by_value>())
//    .def("__idiv__", static_cast<itpp::Vec<Num_T> (*)(Num_T, const itpp::Vec<Num_T> &)>(&itpp::operator/),
//                                                     py::return_value_policy<py::return_by_value>())

    .def("right", &itpp::Vec<Num_T>::right)
    .def("left", &itpp::Vec<Num_T>::left)
    .def("mid", &itpp::Vec<Num_T>::mid)
    .def("split", &itpp::Vec<Num_T>::split)
    .def("shift_right", static_cast<void (itpp::Vec<Num_T> ::*)(Num_T, int)>(&itpp::Vec<Num_T>::shift_right))
    .def("shift_right", static_cast<void (itpp::Vec<Num_T> ::*)(const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::shift_right))
    .def("shift_left", static_cast<void (itpp::Vec<Num_T> ::*)(Num_T, int)>(&itpp::Vec<Num_T>::shift_left))
    .def("shift_left", static_cast<void (itpp::Vec<Num_T> ::*)(const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::shift_left))

    .def("set_subvector", static_cast<void (itpp::Vec<Num_T> ::*)(int, int, const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::set_subvector))
    .def("set_subvector", static_cast<void (itpp::Vec<Num_T> ::*)(int, const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::set_subvector))
    .def("set_subvector", static_cast<void (itpp::Vec<Num_T> ::*)(int, int, Num_T)>(&itpp::Vec<Num_T>::set_subvector))
    .def("replace_mid", &itpp::Vec<Num_T>::replace_mid)
    .def("del", static_cast<void (itpp::Vec<Num_T> ::*)(int)>(&itpp::Vec<Num_T>::del))
    .def("del", static_cast<void (itpp::Vec<Num_T> ::*)(int, int)>(&itpp::Vec<Num_T>::del))
    .def("ins", static_cast<void (itpp::Vec<Num_T> ::*)(int, Num_T)>(&itpp::Vec<Num_T>::ins))
    .def("ins", static_cast<void (itpp::Vec<Num_T> ::*)(int, const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::ins))

    .def("copy_element", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(Num_T)>(&itpp::Vec<Num_T>::operator=))
    .def("copy_matrix", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const itpp::Mat<Num_T> &)>(&itpp::Vec<Num_T>::operator=))
    .def("copy_char_array", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const char *)>(&itpp::Vec<Num_T>::operator=))

    .def("equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator==))
    .def("not_equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator!=))
    .def("less_than_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator<))
    .def("less_equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator<=))
    .def("greater_than_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator>))
    .def("greater_equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator>=))

    .def("set", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(Num_T)>(&itpp::Vec<Num_T>::operator=))
    .def("set", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const itpp::Vec<Num_T> &)>(&itpp::Vec<Num_T>::operator=))
    .def("set", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const itpp::Mat<Num_T> &)>(&itpp::Vec<Num_T>::operator=))
    .def("set", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const char *)>(&itpp::Vec<Num_T>::operator=)) // NOTE: Cannot pass pointer from Python
    .def("set", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const std::string &)>(&itpp::Vec<Num_T>::operator=))

    .def("copy_logical", static_cast<void (*)(itpp::Vec<Num_T> &, const itpp::Vec<itpp::bin> &, const itpp::Vec<Num_T> &)>(&_copy_logical<Num_T>))

    .def("copy_logical", static_cast<void (*)(itpp::Vec<Num_T> &, const itpp::Vec<itpp::bin> &, const Num_T &)>(&_copy_logical<Num_T>))

    .def(py::self == Num_T())
    .def(py::self != Num_T())
    .def(py::self < Num_T())
    .def(py::self <= Num_T())
    .def(py::self > Num_T())
    .def(py::self >= Num_T())

    .def(py::self == py::self)
    .def(py::self != py::self)

    // Python-style modifier
    .def("__setitem__", static_cast<void (itpp::Vec<Num_T> ::*)(int, Num_T)>(&itpp::Vec<Num_T>::set))
    // Python-style len function
    .def("__len__", &itpp::Vec<Num_T>::length)
    //! Stream output
    .def("__repr__", &_print_wrap<Num_T>)
    //! Stream output
    .def("__str__", &_print_wrap<Num_T>)

    //! Additional method to support conversion to Numpy ndarray
//    .def("to_numpy_array", &_itpp_vec_to_numpy_ndarray<Num_T>)

  ;


  m.def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, Num_T)>(&itpp::concat));

  m.def("concat", static_cast<itpp::Vec<Num_T> (*)(Num_T, const itpp::Vec<Num_T> &)>(&itpp::concat));

  m.def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::concat));

  m.def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                   const itpp::Vec<Num_T> &)>(&itpp::concat));

  m.def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                   const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::concat));

  m.def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                   const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                   const itpp::Vec<Num_T> &)>(&itpp::concat));

//  py::def("set", static_cast<void (*)(itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &, const itpp::Vec<itpp::bin> &)>(&_set_from_binlist<Num_T>));

//  py::def("set", static_cast<void (*)(itpp::Vec<Num_T> &, const Num_T &, const itpp::Vec<itpp::bin> &)>(&_set_from_value<Num_T>));

}

