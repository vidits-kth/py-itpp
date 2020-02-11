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

#include <itpp/base/mat.h>

namespace py = pybind11;

//! Wrapper function to print itpp::Mat<Num_T> nicely in Python.
template<class Num_T>
std::string _itpp_mat_print_wrap(const itpp::Mat<Num_T> &m)
{
  int i, rows = m.rows();
  int j, cols = m.cols();

  std::ostringstream oss;

  oss << "[" ;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      oss << m(i, j);
      if (j < cols - 1)
        oss << "\t";
    }
    if (i < rows - 1)
      oss << "\n";
  }
  oss << "]";

  return oss.str();
}

//
// Conversion from Numpy POD array to itpp::Mat<POD>
//
template<class Num_T>
itpp::Mat<Num_T> _numpy_pod_array_to_mat(py::array_t<Num_T> in) {

  auto inbuf = in.request();
  if (inbuf.ndim != 2)
    throw std::runtime_error("Incompatible number of dimensions!");

  Num_T *inptr = (Num_T *) inbuf.ptr;

  int rows = inbuf.shape[0];
  int cols = inbuf.shape[1];

  itpp::Mat<Num_T> out(rows, cols);
  out.clear();
  for( int i = 0; i < rows; ++i ){
    for( int j = 0; j < cols; ++j ){
      out.set(i, j,  inptr[i * cols + j]);
    }
  }

  return out;
}

//
// Conversion from Numpy char array to itpp::Vec<itpp::bin>
//
itpp::Mat<itpp::bin> _numpy_int8_array_to_bmat(py::array_t<char> in) {

  auto inbuf = in.request();
  if (inbuf.ndim != 2)
    throw std::runtime_error("Incompatible number of dimensions!");

  char *inptr = (char *) inbuf.ptr;

  int rows = inbuf.shape[0];
  int cols = inbuf.shape[1];

  itpp::Mat<itpp::bin> out(rows, cols);
  out.clear();
  for( int i = 0; i < rows; ++i ){
    for( int j = 0; j < cols; ++j ){
      out.set(i, j,  inptr[i * cols + j] != 0 );
    }
  }

  return out;
}

//
// Template specialization for POD types
//
template<class Num_T>
void numpy_array_to_mat( py::module &m ){
  m.def("numpy_array_to_mat", &_numpy_pod_array_to_mat<Num_T>);
}

//
// Template specialization for itpp::bin type
//
template<>
void numpy_array_to_mat<itpp::bin>( py::module &m ){
  m.def("numpy_array_to_mat", &_numpy_int8_array_to_bmat);
}

template<class Num_T>
pybind11::buffer_info mat_buffer_info(itpp::Mat<Num_T> &m){
  return pybind11::buffer_info(
           // Pointer to buffer
            m._data(),
            // Size of one scalar
            sizeof(Num_T),
            // Python struct-style format descriptor
            pybind11::format_descriptor<Num_T>::format(),
            // Number of dimensions
            2,
            // Buffer dimensions
            { m.rows(), m.cols() },
            // Strides (in bytes) for each index
            { sizeof( Num_T ),
              sizeof( Num_T ) * m.rows(),
            }
         );
}

template<>
pybind11::buffer_info mat_buffer_info<itpp::bin>(itpp::Mat<itpp::bin> &m){
  return pybind11::buffer_info(
           // Pointer to buffer
            m._data(),
            // Size of one scalar
            sizeof(char),
            // Python struct-style format descriptor
            pybind11::format_descriptor<char>::format(),
            // Number of dimensions
            2,
            // Buffer dimensions
            { m.rows(), m.cols() },
            // Strides (in bytes) for each index
            { sizeof( char ),
              sizeof( char ) * m.rows(),
            }
         );
}

template<class Num_T>
void generate_itpp_mat_wrapper(py::module &m, char const * name) {

  m.def("concat_horizontal", &itpp::concat_horizontal<Num_T>);
  m.def("concat_vertical", &itpp::concat_vertical<Num_T>);

  //! Operators are defined within the class wrapper

  m.def("elem_mult", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                                   const itpp::Mat<Num_T> &)>
                                             (&itpp::elem_mult<Num_T>));
  m.def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &,
                                                           itpp::Mat<Num_T> &)>
                                                 (&itpp::elem_mult_out<Num_T>));
  m.def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &,
							   itpp::Mat<Num_T> &)>
                                                 (&itpp::elem_mult_out<Num_T>));
  m.def("elem_mult_inplace", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                               itpp::Mat<Num_T> &)>
                                                     (&itpp::elem_mult_inplace<Num_T>));
  m.def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
                                                            const itpp::Mat<Num_T> &)>
                                                 (&itpp::elem_mult_sum<Num_T>));

  //! Operators are defined within the class wrapper

  m.def("elem_div", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                                  const itpp::Mat<Num_T> &)>
                                            (&itpp::elem_div<Num_T>));
  m.def("elem_div_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                          const itpp::Mat<Num_T> &,
							  itpp::Mat<Num_T> &)>
                                                (&itpp::elem_div_out<Num_T>));
  m.def("elem_div_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &)>
                                                (&itpp::elem_div_sum<Num_T>));

  numpy_array_to_mat<Num_T>( m );

  //! Definition of Mat
  py::class_<itpp::Mat<Num_T> >(m, name, py::buffer_protocol())

    .def_buffer([](itpp::Mat<Num_T>& m) -> pybind11::buffer_info {
        return mat_buffer_info( m );
    })

    .def(py::init<>())
    .def(py::init<const itpp::Factory &>())
    .def(py::init<int, int>())
    .def(py::init<int, int, const itpp::Factory &>())
    .def(py::init<const itpp::Mat<Num_T> &>())
    .def(py::init<const itpp::Mat<Num_T> &, const itpp::Factory &>())
    .def(py::init<const itpp::Vec<Num_T> &>())
    .def(py::init<const itpp::Vec<Num_T> &, const itpp::Factory &>())
    .def(py::init<const std::string &>())
    .def(py::init<const std::string &, const itpp::Factory &>())
    .def(py::init<const char *, const itpp::Factory &>())
    .def(py::init<const Num_T *, int, int, bool, const itpp::Factory &>())

    .def("cols", &itpp::Mat<Num_T>::cols)
    .def("rows", &itpp::Mat<Num_T>::rows)
    .def("size", &itpp::Mat<Num_T>::size)

    .def("set_size", &itpp::Mat<Num_T>::set_size)
    .def("zeros", &itpp::Mat<Num_T>::zeros)
    .def("clear", &itpp::Mat<Num_T>::clear)
    .def("ones", &itpp::Mat<Num_T>::ones)
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(const std::string &)>(&itpp::Mat<Num_T>::set))
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(const char *)>(&itpp::Mat<Num_T>::set))

    .def("__call__", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::operator()))
    .def("__call__", static_cast<Num_T & (itpp::Mat<Num_T>::*)(int, int)>(&itpp::Mat<Num_T>::operator()))
    .def("__call__", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int) const>(&itpp::Mat<Num_T>::operator()))
    .def("__call__", static_cast<Num_T & (itpp::Mat<Num_T>::*)(int)>(&itpp::Mat<Num_T>::operator()))
    .def("get", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get))
    .def("get", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int) const>(&itpp::Mat<Num_T>::get))
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(int, int, Num_T)>(&itpp::Mat<Num_T>::set))

    .def("__call__", static_cast<itpp::Mat<Num_T>  (itpp::Mat<Num_T>::*)(int, int, int, int) const>(&itpp::Mat<Num_T>::operator()))

    .def("get", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int, int, int) const>(&itpp::Mat<Num_T>::get))

    .def("get_row", &itpp::Mat<Num_T>::get_row)
    .def("get_rows", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get_rows))
    .def("get_rows", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Mat<Num_T>::get_rows))
    .def("get_col", &itpp::Mat<Num_T>::get_col)
    .def("get_cols", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get_cols))
    .def("get_cols", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Mat<Num_T>::get_cols))
    .def("set_row", &itpp::Mat<Num_T>::set_row)
    .def("set_col", &itpp::Mat<Num_T>::set_col)
    .def("set_rows", &itpp::Mat<Num_T>::set_rows)
    .def("set_cols", &itpp::Mat<Num_T>::set_cols)
    .def("copy_row", &itpp::Mat<Num_T>::copy_row)
    .def("copy_col", &itpp::Mat<Num_T>::copy_col)
    .def("swap_rows", &itpp::Mat<Num_T>::swap_rows)
    .def("swap_cols", &itpp::Mat<Num_T>::swap_cols)

    .def("set_submatrix", static_cast<void (itpp::Mat<Num_T>::*)(int, int, int, int, const itpp::Mat<Num_T> &)>
                                     (&itpp::Mat<Num_T>::set_submatrix))
    .def("set_submatrix", static_cast<void (itpp::Mat<Num_T>::*)(int, int, const itpp::Mat<Num_T> &)>
                                     (&itpp::Mat<Num_T>::set_submatrix))
    .def("set_submatrix", static_cast<void (itpp::Mat<Num_T>::*)(int, int, int, int, Num_T)>
                                     (&itpp::Mat<Num_T>::set_submatrix))

    .def("del_row", &itpp::Mat<Num_T>::del_row)
    .def("del_rows", &itpp::Mat<Num_T>::del_rows)
    .def("del_col", &itpp::Mat<Num_T>::del_col)
    .def("del_cols", &itpp::Mat<Num_T>::del_cols)
    .def("ins_row", &itpp::Mat<Num_T>::ins_row)
    .def("ins_col", &itpp::Mat<Num_T>::ins_col)
    .def("append_row", &itpp::Mat<Num_T>::append_row)
    .def("append_col", &itpp::Mat<Num_T>::append_col)

    .def("transpose", &itpp::Mat<Num_T>::transpose)
    .def("T", &itpp::Mat<Num_T>::T)
    .def("hermitian_transpose", &itpp::Mat<Num_T>::hermitian_transpose)
    .def("H", &itpp::Mat<Num_T>::H)

    .def("concat_horizontal", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                               const itpp::Mat<Num_T> &)>(&itpp::concat_horizontal))
    .def("concat_vertical", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                             const itpp::Mat<Num_T> &)>(&itpp::concat_vertical))

    //! Assignment operators work differently in C++ and Python, skipping

    .def(py::self += py::self)
    .def(py::self += Num_T())
    .def(py::self + py::self)
    .def(py::self + Num_T())
    .def(Num_T() + py::self)

    .def(py::self -= py::self)
    .def(py::self -= Num_T())
    .def(py::self - py::self)
    .def(py::self - Num_T())
    .def(Num_T() - py::self)

    .def(py::self *= py::self)
    .def(py::self *= Num_T())
    .def(py::self * py::self)
    .def(py::self * itpp::Vec<Num_T>())

    .def(py::self * Num_T())
    .def(Num_T() * py::self)

//    .def("elem_mult", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
//                                                       const itpp::Mat<Num_T> &)>
//                                 (&itpp::elem_mult)
//                    , py::return_value_policy<py::return_by_value>())
//    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &,
//                                               itpp::Mat<Num_T> &)>
//                                     (&itpp::elem_mult_out))
//    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &,
//                                               itpp::Mat<Num_T> &)>
//                                     (&itpp::elem_mult_out))
//    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &,
//                                               itpp::Mat<Num_T> &)>
//                                     (&itpp::elem_mult_out))
//    .def("elem_mult_inplace", static_cast<void (*)(const itpp::Mat<Num_T> &,
//                                                   itpp::Mat<Num_T> &)>
//                                         (&itpp::elem_mult_inplace))
//    .def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
//                                                const itpp::Mat<Num_T> &)>
//                                     (&itpp::elem_mult_sum)
//                        , py::return_value_policy<py::return_by_value>())

    .def(py::self /= Num_T())
    .def(py::self / Num_T())
    .def(py::self /= py::self)

//    .def("elem_div", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &)>
//                                (&itpp::elem_div)
//                   , py::return_value_policy<py::return_by_value>())
//    .def("elem_div_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
//                                              const itpp::Mat<Num_T> &,
//                                              itpp::Mat<Num_T> &)>
//                                    (&itpp::elem_div_out))
//    .def("elem_div_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
//                                               const itpp::Mat<Num_T> &)>
//                                    (&itpp::elem_mult_sum)
//                       , py::return_value_policy<py::return_by_value>())

    .def(py::self == py::self)
    .def(py::self != py::self)

    //! Stream output
    .def("__repr__", &_itpp_mat_print_wrap<Num_T>)
    .def("__str__", &_itpp_mat_print_wrap<Num_T>)

//    //! Additional method to support conversion to Numpy ndarray
//    .def("to_numpy_ndarray", &_itpp_mat_to_numpy_ndarray<Num_T>
//                           , "Convert py-itpp matrix to numpy ndarray of corresponding datatype"
//			   , py::args("self")
//                           , py::return_value_policy<py::return_by_value>())
;
}
