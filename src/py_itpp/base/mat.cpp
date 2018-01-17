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

#include <boost/python/numpy.hpp>
#include "mat.h"

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

//! Create wrappers within the mat module
BOOST_PYTHON_MODULE(mat)
{
  // Default Matrix Type
  generate_itpp_mat_wrapper<double>("mat");

  // Default Complex Matrix Type
  generate_itpp_mat_wrapper<std::complex<double> >("cmat");

  // Default Float Matrix Type
  generate_itpp_mat_wrapper<float>("fmat");

  // Default Complex Float Matrix Type
  generate_itpp_mat_wrapper<std::complex<float> >("cfmat");

  // Integer matrix
  generate_itpp_mat_wrapper<int>("imat");

  // short int matrix
  generate_itpp_mat_wrapper<short int>("smat");

  // bin matrix
  generate_itpp_mat_wrapper<itpp::bin>("bmat");

  //! Extra functions for conversion to Numpy NDarrays
  Py_Initialize();
  boost::python::numpy::initialize();

  def("to_ndarray", &_itpp_mat_to_numpy_ndarray<int>);
  def("to_ndarray", &_itpp_mat_to_numpy_ndarray<float>);
  def("to_ndarray", &_itpp_mat_to_numpy_ndarray<double>);
  def("to_ndarray", &_itpp_mat_to_numpy_ndarray<std::complex<double> >);
  def("to_ndarray", &_itpp_mat_to_numpy_ndarray<itpp::bin>);
}
