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

// Dummy change to force rebuild during make install

#include <boost/python/numpy.hpp>
#include "vec.h"

// Convert Vec<Num_T> to Numpy array for Num_T=int,float,std::complex<double>
template<class Num_T>
boost::python::numpy::ndarray _itpp_vec_to_numpy_ndarray(const itpp::Vec<Num_T> &v)
{
  int i, sz = v.length();

  boost::python::tuple shape = boost::python::make_tuple(sz);
  boost::python::numpy::dtype dtype = boost::python::numpy::dtype::get_builtin<Num_T>();
  boost::python::numpy::ndarray np = boost::python::numpy::zeros(shape, dtype);

  for (i = 0; i < sz; i++) {
    np[i] = v(i);
  }

  return np;
}

// Convert Vec<Num_T> to Numpy array for Num_T=itpp::bin
template<>
boost::python::numpy::ndarray _itpp_vec_to_numpy_ndarray(const itpp::Vec<itpp::bin> &v)
{
  int i, sz = v.length();

  boost::python::tuple shape = boost::python::make_tuple(sz);
  boost::python::numpy::dtype dtype = boost::python::numpy::dtype::get_builtin<bool>();
  boost::python::numpy::ndarray np = boost::python::numpy::zeros(shape, dtype);

  for (i = 0; i < sz; i++) {
    np[i] = (int)v(i);
  }

  return np;
}

BOOST_PYTHON_MODULE(vec)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  generate_itpp_vec_wrapper<double>("vec");
  generate_itpp_vec_wrapper<std::complex<double> >("cvec");
  generate_itpp_vec_wrapper<int>("ivec");
  generate_itpp_vec_wrapper<itpp::bin>("bvec");
  generate_itpp_vec_wrapper<short int>("svec");

  //! Conversion to Numpy NDarray
  Py_Initialize();
  boost::python::numpy::initialize();

  def("to_ndarray", &_itpp_vec_to_numpy_ndarray<int>);
  def("to_ndarray", &_itpp_vec_to_numpy_ndarray<float>);
  def("to_ndarray", &_itpp_vec_to_numpy_ndarray<double>);
  def("to_ndarray", &_itpp_vec_to_numpy_ndarray<std::complex<double> >);
  def("to_ndarray", &_itpp_vec_to_numpy_ndarray<itpp::bin>);
}
