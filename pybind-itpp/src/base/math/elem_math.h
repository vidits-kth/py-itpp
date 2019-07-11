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

#include <itpp/base/math/elem_math.h>

namespace py = pybind11;

inline double sqrt(const int x) { return std::sqrt(double(x)); }

inline double sqrt(const double x) { return std::sqrt(x); }

inline int abs_(const int x) { return std::abs(x); }

inline double abs_(const double x) { return std::abs(x); }

void generate_pybind_wrapper_for_elem_math_module( py::module &m ) {

  //! real
  m.def("real", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::real)
	                   , "Real part of complex values"
	                   , py::arg("v"));

  m.def("real", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::real)
	                   , "Real part of complex values"
	                   , py::arg("m"));

  //! imag
  m.def("imag", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::imag)
	                   , "Imaginary part of complex values"
	                   , py::arg("v"));

  m.def("imag", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::imag)
	                   , "Imaginary part of complex values"
	                   , py::arg("m"));

  //! arg
  m.def("arg", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::arg)
	                  , "Argument (angle)"
	                  , py::arg("v"));

  m.def("arg", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::arg)
	                  , "Argument (angle)"
	                  , py::arg("m"));

  //! angle
  m.def("angle", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::angle)
	                    , "Angle"
	                    , py::arg("v"));

  m.def("angle", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::angle)
	                    , "Angle"
	                    , py::arg("m"));

  //! abs

  m.def("abs", static_cast<int (*)(const int)>(&abs_)
	                  , "Absolute value"
	                  , py::arg("x"));

  m.def("abs", static_cast<double (*)(const double)>(&abs_)
	                  , "Absolute value"
	                  , py::arg("x"));

  m.def("abs", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::abs)
	                  , "Absolute value"
	                  , py::arg("v"));

  m.def("abs", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::abs)
	                  , "Absolute value"
	                  , py::arg("m"));

  m.def("abs", static_cast<itpp::ivec (*)(const itpp::ivec &)>(&itpp::abs)
	                  , "Absolute value"
	                  , py::arg("v"));

  m.def("abs", static_cast<itpp::imat (*)(const itpp::imat &)>(&itpp::abs)
	                  , "Absolute value"
	                  , py::arg("m"));

  m.def("abs", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::abs)
	                  , "Absolute value"
	                  , py::arg("v"));

  m.def("abs", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::abs)
	                  , "Absolute value"
	                  , py::arg("m"));

  // sqrt

  m.def("sqrt", static_cast<double (*)(const int)>(&sqrt)
	                   , "Square root of the elements"
	                   , py::arg("x"));

  m.def("sqrt", static_cast<double (*)(const double)>(&sqrt)
	                   , "Square root of the elements"
	                   , py::arg("x"));

  m.def("sqrt", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::sqrt)
	                   , "Square root of the elements"
	                   , py::arg("v"));

  m.def("sqrt", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::sqrt)
	                   , "Square root of the elements"
	                   , py::arg("m"));

  // conj
  m.def("conj", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::conj)
	                   , "Conjugate of complex vector"
	                   , py::arg("v"));

  m.def("conj", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::conj)
	                   , "Conjugate of complex matrix"
	                   , py::arg("m"));

}

