//! COPYRIGHT_NOTICE

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
  generate_itpp_vec_wrapper<double>("vec");
  generate_itpp_vec_wrapper<std::complex<double> >("cvec");
  generate_itpp_vec_wrapper<int>("ivec");
  generate_itpp_vec_wrapper<itpp::bin>("bvec");
  generate_itpp_vec_wrapper<short int>("svec");

  //! Conversion to Numpy NDarray
  Py_Initialize();
  boost::python::numpy::initialize();

  def("vec_np", &_itpp_vec_to_numpy_ndarray<int>);
  def("vec_np", &_itpp_vec_to_numpy_ndarray<float>);
  def("vec_np", &_itpp_vec_to_numpy_ndarray<double>);
  def("vec_np", &_itpp_vec_to_numpy_ndarray<std::complex<double> >);
  def("vec_np", &_itpp_vec_to_numpy_ndarray<itpp::bin>);
}
