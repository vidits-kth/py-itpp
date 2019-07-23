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
#include <pybind11/complex.h>

#include <itpp/base/specmat.h>

namespace py = pybind11;

//! Definitions of special vectors and matrices
void generate_pybind_wrapper_for_matfunc_module( py::module &m ) {

  m.def("find", &itpp::find);

  m.def("ones", static_cast<itpp::vec (*)(int)>(&itpp::ones));
  m.def("ones_b", static_cast<itpp::bvec (*)(int)>(&itpp::ones_b));
  m.def("ones_i", static_cast<itpp::ivec (*)(int)>(&itpp::ones_i));
  m.def("ones_c", static_cast<itpp::cvec (*)(int)>(&itpp::ones_c));

  m.def("ones", static_cast<itpp::mat (*)(int, int)>(&itpp::ones));
  m.def("ones_b", static_cast<itpp::bmat (*)(int, int)>(&itpp::ones_b));
  m.def("ones_i", static_cast<itpp::imat (*)(int, int)>(&itpp::ones_i));
  m.def("ones_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::ones_c));

  m.def("zeros", static_cast<itpp::vec (*)(int)>(&itpp::zeros));
  m.def("zeros_b", static_cast<itpp::bvec (*)(int)>(&itpp::zeros_b));
  m.def("zeros_i", static_cast<itpp::ivec (*)(int)>(&itpp::zeros_i));
  m.def("zeros_c", static_cast<itpp::cvec (*)(int)>(&itpp::zeros_c));

  m.def("zeros", static_cast<itpp::mat (*)(int, int)>(&itpp::zeros));
  m.def("zeros_b", static_cast<itpp::bmat (*)(int, int)>(&itpp::zeros_b));
  m.def("zeros_i", static_cast<itpp::imat (*)(int, int)>(&itpp::zeros_i));
  m.def("zeros_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::zeros_c));

  m.def("eye", static_cast<itpp::mat (*)(int)>(&itpp::eye));
  m.def("eye_b", static_cast<itpp::bmat (*)(int)>(&itpp::eye_b));
  m.def("eye_i", static_cast<itpp::imat (*)(int)>(&itpp::eye_i));
  m.def("eye_c", static_cast<itpp::cmat (*)(int)>(&itpp::eye_c));

  m.def("eye", static_cast<void (*)(int, itpp::mat &)>(&itpp::eye<double>));
  m.def("eye", static_cast<void (*)(int, itpp::bmat &)>(&itpp::eye<itpp::bin>));
  m.def("eye", static_cast<void (*)(int, itpp::imat &)>(&itpp::eye<int>));
  m.def("eye", static_cast<void (*)(int, itpp::cmat &)>(&itpp::eye<std::complex<double> >));

  //! Impulse vector
  m.def("impulse", static_cast<itpp::vec (*)(int)>(&itpp::impulse));

  m.def("linspace", static_cast<itpp::vec (*)(double, double, int)>(&itpp::linspace));

  m.def("zigzag_space", static_cast<itpp::vec (*)(double, double, int)>(&itpp::zigzag_space));

  m.def("hadamard", static_cast<itpp::imat (*)(int)>(&itpp::hadamard));

  m.def("conference", static_cast<itpp::imat (*)(int)>(&itpp::conference));

  m.def("toeplitz", static_cast<const itpp::mat (*)(const itpp::vec &, const itpp::vec &)>(&itpp::toeplitz<double>));
  m.def("toeplitz", static_cast<const itpp::bmat (*)(const itpp::bvec &, const itpp::bvec &)>(&itpp::toeplitz<itpp::bin>));
  m.def("toeplitz", static_cast<const itpp::imat (*)(const itpp::ivec &, const itpp::ivec &)>(&itpp::toeplitz<int>));
  m.def("toeplitz", static_cast<const itpp::cmat (*)(const itpp::cvec &, const itpp::cvec &)>(&itpp::toeplitz<std::complex<double> >));

  m.def("toeplitz", static_cast<const itpp::mat (*)(const itpp::vec &)>(&itpp::toeplitz<double>));
  m.def("toeplitz", static_cast<const itpp::bmat (*)(const itpp::bvec &)>(&itpp::toeplitz<itpp::bin>));
  m.def("toeplitz", static_cast<const itpp::imat (*)(const itpp::ivec &)>(&itpp::toeplitz<int>));
  m.def("toeplitz", static_cast<const itpp::cmat (*)(const itpp::cvec &)>(&itpp::toeplitz<std::complex<double> >));

  m.def("toeplitz", static_cast<const itpp::cmat (*)(const itpp::cvec &)>(&itpp::toeplitz));

  m.def("rotation_matrix", static_cast<itpp::mat (*)(int, int, int, double)>(&itpp::rotation_matrix));

  m.def("house", static_cast<void (*)(const itpp::vec &, itpp::vec &, double &)>(&itpp::house));

  m.def("givens", static_cast<void (*)(double, double, double &, double &)>(&itpp::givens));

  m.def("givens", static_cast<void (*)(double, double, itpp::mat&)>(&itpp::givens));

  m.def("givens", static_cast<itpp::mat (*)(double, double)>(&itpp::givens));

  m.def("givens_t", static_cast<void (*)(double, double, itpp::mat &)>(&itpp::givens_t));

  m.def("givens_t", static_cast<itpp::mat (*)(double, double)>(&itpp::givens_t));

  m.def("vec_1", static_cast<itpp::vec (*)(double)>(&itpp::vec_1<double>));
  m.def("vec_1", static_cast<itpp::bvec (*)(itpp::bin)>(&itpp::vec_1<itpp::bin>));
  m.def("vec_1", static_cast<itpp::ivec (*)(int)>(&itpp::vec_1<int>));
  m.def("vec_1", static_cast<itpp::cvec (*)(std::complex<double>)>(&itpp::vec_1<std::complex<double> >));

  m.def("vec_2", static_cast<itpp::vec (*)(double, double)>(&itpp::vec_2<double>));
  m.def("vec_2", static_cast<itpp::bvec (*)(itpp::bin, itpp::bin)>(&itpp::vec_2<itpp::bin>));
  m.def("vec_2", static_cast<itpp::ivec (*)(int, int)>(&itpp::vec_2<int>));
  m.def("vec_2", static_cast<itpp::cvec (*)(std::complex<double>, std::complex<double>)>(&itpp::vec_2<std::complex<double> >));

  m.def("vec_3", static_cast<itpp::vec (*)(double, double, double)>(&itpp::vec_3<double>));
  m.def("vec_3", static_cast<itpp::bvec (*)(itpp::bin, itpp::bin, itpp::bin)>(&itpp::vec_3<itpp::bin>));
  m.def("vec_3", static_cast<itpp::ivec (*)(int, int, int)>(&itpp::vec_3<int>));
  m.def("vec_3", static_cast<itpp::cvec (*)(std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::vec_3<std::complex<double> >));

  m.def("mat_1x1", static_cast<itpp::mat (*)(double)>(&itpp::mat_1x1<double>));
  m.def("mat_1x1", static_cast<itpp::bmat (*)(itpp::bin)>(&itpp::mat_1x1<itpp::bin>));
  m.def("mat_1x1", static_cast<itpp::imat (*)(int)>(&itpp::mat_1x1<int>));
  m.def("mat_1x1", static_cast<itpp::cmat (*)(std::complex<double>)>(&itpp::mat_1x1<std::complex<double> >));

  m.def("mat_2x1", static_cast<itpp::mat (*)(double, double)>(&itpp::mat_2x1<double>));
  m.def("mat_2x1", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin)>(&itpp::mat_2x1<itpp::bin>));
  m.def("mat_2x1", static_cast<itpp::imat (*)(int, int)>(&itpp::mat_2x1<int>));
  m.def("mat_2x1", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>)>(&itpp::mat_2x1<std::complex<double> >));

  m.def("mat_2x2", static_cast<itpp::mat (*)(double, double, double, double)>(&itpp::mat_2x2<double>));
  m.def("mat_2x2", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_2x2<itpp::bin>));
  m.def("mat_2x2", static_cast<itpp::imat (*)(int, int, int, int)>(&itpp::mat_2x2<int>));
  m.def("mat_2x2", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_2x2<std::complex<double> >));

  m.def("mat_1x3", static_cast<itpp::mat (*)(double, double, double)>(&itpp::mat_1x3<double>));
  m.def("mat_1x3", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_1x3<itpp::bin>));
  m.def("mat_1x3", static_cast<itpp::imat (*)(int, int, int)>(&itpp::mat_1x3<int>));
  m.def("mat_1x3", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_1x3<std::complex<double> >));

  m.def("mat_3x1", static_cast<itpp::mat (*)(double, double, double)>(&itpp::mat_3x1<double>));
  m.def("mat_3x1", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_3x1<itpp::bin>));
  m.def("mat_3x1", static_cast<itpp::imat (*)(int, int, int)>(&itpp::mat_3x1<int>));
  m.def("mat_3x1", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_3x1<std::complex<double> >));

  m.def("mat_2x3", static_cast<itpp::mat (*)(double, double, double, double, double, double)>(&itpp::mat_2x3<double>));
  m.def("mat_2x3", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_2x3<itpp::bin>));
  m.def("mat_2x3", static_cast<itpp::imat (*)(int, int, int, int, int, int)>(&itpp::mat_2x3<int>));
  m.def("mat_2x3", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_2x3<std::complex<double> >));

  m.def("mat_3x2", static_cast<itpp::mat (*)(double, double, double, double, double, double)>(&itpp::mat_3x2<double>));
  m.def("mat_3x2", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_3x2<itpp::bin>));
  m.def("mat_3x2", static_cast<itpp::imat (*)(int, int, int, int, int, int)>(&itpp::mat_3x2<int>));
  m.def("mat_3x2", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_3x2<std::complex<double> >));

  m.def("mat_3x3", static_cast<itpp::mat (*)(double, double, double, double, double, double, double, double, double)>(&itpp::mat_3x3<double>));
  m.def("mat_3x3", static_cast<itpp::bmat (*)(itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin, itpp::bin)>(&itpp::mat_3x3<itpp::bin>));
  m.def("mat_3x3", static_cast<itpp::imat (*)(int, int, int, int, int, int, int, int, int)>(&itpp::mat_3x3<int>));
  m.def("mat_3x3", static_cast<itpp::cmat (*)(std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>, std::complex<double>)>(&itpp::mat_3x3<std::complex<double> >));
}
