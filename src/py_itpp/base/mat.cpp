//! COPYRIGHT_NOTICE

#include <boost/python/numpy.hpp>
#include "mat.h"

// Convert Mat<Num_T> to Numpy array for Num_T=int,float,std::complex<double>
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

// Convert Mat<Num_T> to Numpy array for Num_T=itpp::bin
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

BOOST_PYTHON_MODULE(mat)
{
  /*!
    \relates Mat
    \brief Default Matrix Type
  */
  generate_itpp_mat_wrapper<double>("mat");

  /*!
    \relates Mat
    \brief Default Complex Matrix Type
  */
  generate_itpp_mat_wrapper<std::complex<double> >("cmat");

  /*!
    \relates Mat
    \brief Default Float Matrix Type
  */
  generate_itpp_mat_wrapper<float>("fmat");

  /*!
    \relates Mat
    \brief Default Complex Float Matrix Type
  */
  generate_itpp_mat_wrapper<std::complex<float> >("cfmat");

  /*!
    \relates Mat
    \brief Integer matrix
  */
  generate_itpp_mat_wrapper<int>("imat");

  /*!
    \relates Mat
    \brief short int matrix
  */
  generate_itpp_mat_wrapper<short int>("smat");

  /*!
    \relates Mat
    \relates GF2mat
    \relates GF2mat_sparse
    \brief bin matrix
  */
  generate_itpp_mat_wrapper<itpp::bin>("bmat");

  //! Conversion to Numpy NDarray
  Py_Initialize();
  boost::python::numpy::initialize();

  def("mat_np", &_itpp_mat_to_numpy_ndarray<int>);
  def("mat_np", &_itpp_mat_to_numpy_ndarray<float>);
  def("mat_np", &_itpp_mat_to_numpy_ndarray<double>);
  def("mat_np", &_itpp_mat_to_numpy_ndarray<std::complex<double> >);
  def("mat_np", &_itpp_mat_to_numpy_ndarray<itpp::bin>);
}
