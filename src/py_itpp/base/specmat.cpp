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

#include <boost/python.hpp>
#include <itpp/base/specmat.h>

//! Definitions of special vectors and matrices
BOOST_PYTHON_MODULE(specmat) {

  boost::python::def("find", &itpp::find);

  boost::python::def("ones", static_cast<itpp::vec (*)(int)>(&itpp::ones)
                           , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ones_b", static_cast<itpp::bvec (*)(int)>(&itpp::ones_b)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ones_i", static_cast<itpp::ivec (*)(int)>(&itpp::ones_i)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ones_c", static_cast<itpp::cvec (*)(int)>(&itpp::ones_c)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("ones", static_cast<itpp::mat (*)(int, int)>(&itpp::ones)
                           , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ones_b", static_cast<itpp::bmat (*)(int, int)>(&itpp::ones_b)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ones_i", static_cast<itpp::imat (*)(int, int)>(&itpp::ones_i)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ones_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::ones_c)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("zeros", static_cast<itpp::vec (*)(int)>(&itpp::zeros)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("zeros_b", static_cast<itpp::bvec (*)(int)>(&itpp::zeros_b)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("zeros_i", static_cast<itpp::ivec (*)(int)>(&itpp::zeros_i)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("zeros_c", static_cast<itpp::cvec (*)(int)>(&itpp::zeros_c)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("zeros", static_cast<itpp::mat (*)(int, int)>(&itpp::zeros)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("zeros_b", static_cast<itpp::bmat (*)(int, int)>(&itpp::zeros_b)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("zeros_i", static_cast<itpp::imat (*)(int, int)>(&itpp::zeros_i)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("zeros_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::zeros_c)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("eye", static_cast<itpp::mat (*)(int)>(&itpp::eye)
                          , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("eye_b", static_cast<itpp::bmat (*)(int)>(&itpp::eye_b)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("eye_i", static_cast<itpp::imat (*)(int)>(&itpp::eye_i)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("eye_c", static_cast<itpp::cmat (*)(int)>(&itpp::eye_c)
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("eye", static_cast<void (*)(int, itpp::mat &)>(&itpp::eye<double>));
  boost::python::def("eye", static_cast<void (*)(int, itpp::bmat &)>(&itpp::eye<itpp::bin>));
  boost::python::def("eye", static_cast<void (*)(int, itpp::imat &)>(&itpp::eye<int>));
  boost::python::def("eye", static_cast<void (*)(int, itpp::cmat &)>(&itpp::eye<std::complex<double> >));

  //! Impulse vector
  boost::python::def("impulse", static_cast<itpp::vec (*)(int)>(&itpp::impulse)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("linspace", static_cast<itpp::vec (*)(double, double, int)>(&itpp::linspace)
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("zigzag_space", static_cast<itpp::vec (*)(double, double, int)>(&itpp::zigzag_space)
                                   , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("hadamard", static_cast<itpp::imat (*)(int)>(&itpp::hadamard)
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("conference", static_cast<itpp::imat (*)(int)>(&itpp::conference)
                                 , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("toeplitz", static_cast<const itpp::mat (*)(const itpp::vec &, const itpp::vec &)>(&itpp::toeplitz<double>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("toeplitz", static_cast<const itpp::bmat (*)(const itpp::bvec &, const itpp::bvec &)>(&itpp::toeplitz<itpp::bin>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("toeplitz", static_cast<const itpp::imat (*)(const itpp::ivec &, const itpp::ivec &)>(&itpp::toeplitz<int>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("toeplitz", static_cast<const itpp::cmat (*)(const itpp::cvec &, const itpp::cvec &)>(&itpp::toeplitz<std::complex<double> >)
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("toeplitz", static_cast<const itpp::mat (*)(const itpp::vec &)>(&itpp::toeplitz<double>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("toeplitz", static_cast<const itpp::bmat (*)(const itpp::bvec &)>(&itpp::toeplitz<itpp::bin>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("toeplitz", static_cast<const itpp::imat (*)(const itpp::ivec &)>(&itpp::toeplitz<int>)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("toeplitz", static_cast<const itpp::cmat (*)(const itpp::cvec &)>(&itpp::toeplitz<std::complex<double> >)
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("toeplitz", static_cast<const itpp::cmat (*)(const itpp::cvec &)>(&itpp::toeplitz)
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("rotation_matrix", static_cast<itpp::mat (*)(int, int, int, double)>(&itpp::rotation_matrix)
                                      , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("house", static_cast<void (*)(const itpp::vec &, itpp::vec &, double &)>(&itpp::house));

  boost::python::def("givens", static_cast<void (*)(double, double, double &, double &)>(&itpp::givens));

  boost::python::def("givens", static_cast<void (*)(double, double, itpp::mat&)>(&itpp::givens));

  boost::python::def("givens", static_cast<itpp::mat (*)(double, double)>(&itpp::givens)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("givens_t", static_cast<void (*)(double, double, itpp::mat &)>(&itpp::givens_t));

  boost::python::def("givens_t", static_cast<itpp::mat (*)(double, double)>(&itpp::givens_t)
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("vec_1", static_cast<itpp::vec (*)(double)>(&itpp::vec_1<double>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_1", static_cast<itpp::bvec (*)(itpp::bin)>(&itpp::vec_1<itpp::bin>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_1", static_cast<itpp::ivec (*)(int)>(&itpp::vec_1<int>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_1", static_cast<itpp::cvec (*)(std::complex<double>)>(&itpp::vec_1<std::complex<double> >)
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("vec_2", static_cast<itpp::vec (*)(double, double)>(&itpp::vec_2<double>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_2", static_cast<itpp::bvec (*)(itpp::bin, itpp::bin)>(&itpp::vec_2<itpp::bin>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_2", static_cast<itpp::ivec (*)(int, int)>(&itpp::vec_2<int>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_2", static_cast<itpp::cvec (*)(std::complex<double>, std::complex<double>)>(&itpp::vec_2<std::complex<double> >)
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("vec_3", static_cast<itpp::vec (*)(double, double, double)>(&itpp::vec_3<double>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_3", static_cast<itpp::bvec (*)(itpp::bin, itpp::bin, itpp::bin)>(&itpp::vec_3<itpp::bin>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_3", static_cast<itpp::ivec (*)(int, int, int)>(&itpp::vec_3<int>)
                            , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("vec_3", static_cast<itpp::cvec (*)(std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::vec_3<std::complex<double> >)
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_1x1", static_cast<itpp::mat (*)(double)>(&itpp::mat_1x1<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_1x1", static_cast<itpp::bmat (*)(itpp::bin)>(&itpp::mat_1x1<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_1x1", static_cast<itpp::imat (*)(int)>(&itpp::mat_1x1<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_1x1", static_cast<itpp::cmat (*)(std::complex<double>)>(&itpp::mat_1x1<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_2x1", static_cast<itpp::mat (*)(double, double)>(&itpp::mat_2x1<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x1", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin)>(&itpp::mat_2x1<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x1", static_cast<itpp::imat (*)(int, int)>(&itpp::mat_2x1<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x1", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>)>(&itpp::mat_2x1<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_2x2", static_cast<itpp::mat (*)(double, double, double, double)>(&itpp::mat_2x2<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x2", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_2x2<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x2", static_cast<itpp::imat (*)(int, int, int, int)>(&itpp::mat_2x2<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x2", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_2x2<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_1x3", static_cast<itpp::mat (*)(double, double, double)>(&itpp::mat_1x3<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_1x3", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_1x3<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_1x3", static_cast<itpp::imat (*)(int, int, int)>(&itpp::mat_1x3<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_1x3", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_1x3<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_3x1", static_cast<itpp::mat (*)(double, double, double)>(&itpp::mat_3x1<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x1", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_3x1<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x1", static_cast<itpp::imat (*)(int, int, int)>(&itpp::mat_3x1<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x1", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_3x1<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_2x3", static_cast<itpp::mat (*)(double, double, double, double, double, double)>(&itpp::mat_2x3<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x3", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_2x3<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x3", static_cast<itpp::imat (*)(int, int, int, int, int, int)>(&itpp::mat_2x3<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_2x3", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_2x3<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_3x2", static_cast<itpp::mat (*)(double, double, double, double, double, double)>(&itpp::mat_3x2<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x2", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_3x2<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x2", static_cast<itpp::imat (*)(int, int, int, int, int, int)>(&itpp::mat_3x2<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x2", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_3x2<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat_3x3", static_cast<itpp::mat (*)(double, double, double, double, double, double, double, double, double)>(&itpp::mat_3x3<double>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x3", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_3x3<itpp::bin>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x3", static_cast<itpp::imat (*)(int, int, int, int, int, int, int, int, int)>(&itpp::mat_3x3<int>)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("mat_3x3", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_3x3<std::complex<double> >)
                              , boost::python::return_value_policy<boost::python::return_by_value>());
}
