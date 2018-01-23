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

#include <sstream>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <itpp/base/mat.h>

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

//! Convert Mat<Num_T> to Numpy array
//! for Num_T=int,float,std::complex<double>
template<class Num_T>
boost::python::numpy::ndarray _itpp_mat_to_numpy_ndarray(const itpp::Mat<Num_T> &m)
{
  int rows = m.rows();
  int cols = m.cols();

  boost::python::tuple shape = boost::python::make_tuple(rows, cols);
  boost::python::numpy::dtype dtype = boost::python::numpy::dtype::get_builtin<Num_T>();
  boost::python::numpy::ndarray np = boost::python::numpy::zeros(shape, dtype);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      np[i][j] = m.get(i,j);
    }
  }

  return np;
}

//! Convert Mat<Num_T> to Numpy array
//! for Num_T=itpp::bin
template<>
boost::python::numpy::ndarray _itpp_mat_to_numpy_ndarray(const itpp::Mat<itpp::bin> &m)
{
  int rows = m.rows();
  int cols = m.cols();

  boost::python::tuple shape = boost::python::make_tuple(rows, cols);
  boost::python::numpy::dtype dtype = boost::python::numpy::dtype::get_builtin<bool>();
  boost::python::numpy::ndarray np = boost::python::numpy::zeros(shape, dtype);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      np[i][j] = static_cast<int>(m.get(i,j));
    }
  }

  return np;
}

//! Wrapper function of templated functions related to Mat<Num_T>
//! and the definition of the templated class Mat<Num_T>
template<class Num_T>
void generate_itpp_mat_wrapper(char const * name) {

  boost::python::def("concat_horizontal", &itpp::concat_horizontal<Num_T>
                                        , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("concat_vertical", &itpp::concat_vertical<Num_T>
                                      , boost::python::return_value_policy<boost::python::return_by_value>());

  //! Operators are defined within the class wrapper

  boost::python::def("elem_mult", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                                   const itpp::Mat<Num_T> &)>
                                             (&itpp::elem_mult<Num_T>)
                                , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &,
                                                           itpp::Mat<Num_T> &)>
                                                 (&itpp::elem_mult_out<Num_T>));
  boost::python::def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &,
							   itpp::Mat<Num_T> &)>
                                                 (&itpp::elem_mult_out<Num_T>));
  boost::python::def("elem_mult_inplace", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                               itpp::Mat<Num_T> &)>
                                                     (&itpp::elem_mult_inplace<Num_T>));
  boost::python::def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
                                                            const itpp::Mat<Num_T> &)>
                                                 (&itpp::elem_mult_sum<Num_T>)
                                    , boost::python::return_value_policy<boost::python::return_by_value>());

  //! Operators are defined within the class wrapper

  boost::python::def("elem_div", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                                  const itpp::Mat<Num_T> &)>
                                            (&itpp::elem_div<Num_T>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("elem_div_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                          const itpp::Mat<Num_T> &,
							  itpp::Mat<Num_T> &)>
                                                (&itpp::elem_div_out<Num_T>));
  boost::python::def("elem_div_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
                                                           const itpp::Mat<Num_T> &)>
                                                (&itpp::elem_div_sum<Num_T>)
                                   , boost::python::return_value_policy<boost::python::return_by_value>());

  //! Definition of Mat
  boost::python::class_<itpp::Mat<Num_T> >(name, boost::python::init<>())

    .def(boost::python::init<const itpp::Factory &>())
    .def(boost::python::init<int, int>())
    .def(boost::python::init<int, int, const itpp::Factory &>())
    .def(boost::python::init<const itpp::Mat<Num_T> &>())
    .def(boost::python::init<const itpp::Mat<Num_T> &, const itpp::Factory &>())
    .def(boost::python::init<const itpp::Vec<Num_T> &>())
    .def(boost::python::init<const itpp::Vec<Num_T> &, const itpp::Factory &>())
    .def(boost::python::init<const std::string &>())
    .def(boost::python::init<const std::string &, const itpp::Factory &>())
    .def(boost::python::init<const char *, const itpp::Factory &>())
    .def(boost::python::init<const Num_T *, int, int, bool, const itpp::Factory &>())

    .def("cols", &itpp::Mat<Num_T>::cols)
    .def("rows", &itpp::Mat<Num_T>::rows)
    .def("size", &itpp::Mat<Num_T>::size)

    .def("set_size", &itpp::Mat<Num_T>::set_size)
    .def("zeros", &itpp::Mat<Num_T>::zeros)
    .def("clear", &itpp::Mat<Num_T>::clear)
    .def("ones", &itpp::Mat<Num_T>::ones)
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(const std::string &)>(&itpp::Mat<Num_T>::set))
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(const char *)>(&itpp::Mat<Num_T>::set))

    .def("__call__", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::operator())
                   , boost::python::return_value_policy<boost::python::copy_const_reference>())
    .def("__call__", static_cast<Num_T & (itpp::Mat<Num_T>::*)(int, int)>(&itpp::Mat<Num_T>::operator())
                   , boost::python::return_value_policy<boost::python::copy_non_const_reference>())
    .def("__call__", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int) const>(&itpp::Mat<Num_T>::operator())
                   , boost::python::return_value_policy<boost::python::copy_const_reference>())
    .def("__call__", static_cast<Num_T & (itpp::Mat<Num_T>::*)(int)>(&itpp::Mat<Num_T>::operator())
                   , boost::python::return_value_policy<boost::python::copy_non_const_reference>())
    .def("get", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get)
              , boost::python::return_value_policy<boost::python::copy_const_reference>())
    .def("get", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int) const>(&itpp::Mat<Num_T>::get)
	      , boost::python::return_value_policy<boost::python::copy_const_reference>())
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(int, int, Num_T)>(&itpp::Mat<Num_T>::set))

    .def("__call__", static_cast<itpp::Mat<Num_T>  (itpp::Mat<Num_T>::*)(int, int, int, int) const>(&itpp::Mat<Num_T>::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int, int, int) const>(&itpp::Mat<Num_T>::get)
              , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_row", &itpp::Mat<Num_T>::get_row)
    .def("get_rows", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get_rows)
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_rows", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Mat<Num_T>::get_rows)
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_col", &itpp::Mat<Num_T>::get_col)
    .def("get_cols", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get_cols)
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_cols", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Mat<Num_T>::get_cols)
                   , boost::python::return_value_policy<boost::python::return_by_value>())
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
                                                               const itpp::Mat<Num_T> &)>(&itpp::concat_horizontal)
                            , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("concat_vertical", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                             const itpp::Mat<Num_T> &)>(&itpp::concat_vertical)
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    //! Assignment operators work differently in C++ and Python, skipping

    .def(boost::python::self += boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self += Num_T())
    .def(boost::python::self + boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self + Num_T())
    .def(Num_T() + boost::python::self)

    .def(boost::python::self -= boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self -= Num_T())
    .def(boost::python::self - boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self - Num_T())
    .def(Num_T() - boost::python::self)

    .def(boost::python::self *= boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self *= Num_T())
    .def(boost::python::self * boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self * itpp::Vec<Num_T>())

    .def(boost::python::self * Num_T())
    .def(Num_T() * boost::python::self)

    .def("elem_mult", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                       const itpp::Mat<Num_T> &)>
                                 (&itpp::elem_mult)
                    , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &,
                                               itpp::Mat<Num_T> &)>
                                     (&itpp::elem_mult_out))
    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &,
                                               itpp::Mat<Num_T> &)>
                                     (&itpp::elem_mult_out))
    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &,
                                               itpp::Mat<Num_T> &)>
                                     (&itpp::elem_mult_out))
    .def("elem_mult_inplace", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                                   itpp::Mat<Num_T> &)>
                                         (&itpp::elem_mult_inplace))
    .def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
                                                const itpp::Mat<Num_T> &)>
                                     (&itpp::elem_mult_sum)
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def(boost::python::self /= Num_T())
    .def(boost::python::self / Num_T())
    .def(boost::python::self /= boost::python::other<itpp::Mat<Num_T> >())

    .def("elem_div", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &)>
                                (&itpp::elem_div)
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("elem_div_out", static_cast<void (*)(const itpp::Mat<Num_T> &,
                                              const itpp::Mat<Num_T> &,
                                              itpp::Mat<Num_T> &)>
                                    (&itpp::elem_div_out))
    .def("elem_div_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &)>
                                    (&itpp::elem_mult_sum)
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def(boost::python::self == boost::python::other<itpp::Mat<Num_T> >())
    .def(boost::python::self != boost::python::other<itpp::Mat<Num_T> >())

    //! Additional method to support conversion to Numpy ndarray
    .def("to_ndarray", &_itpp_mat_to_numpy_ndarray<Num_T>)

    //! Stream output
    .def("__repr__", &_itpp_mat_print_wrap<Num_T>)
    .def("__str__", &_itpp_mat_print_wrap<Num_T>)
;
}
