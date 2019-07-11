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

#include <itpp/base/math/log_exp.h>

namespace py = pybind11;

// Extra functions for primitive types
inline double exp(const double x) { return std::exp(x); }

inline double pow(const double x, const double y) { return std::pow(x, y); }

inline double log(const double &x) { return std::log(x); }

inline double log2(const double &x) { return std::log(x) / std::log(2.0); }

void generate_pybind_wrapper_for_log_exp_module( py::module &m ) {

  //! exp
  m.def("exp", static_cast<double (*)(const double)>(&exp)
	                  , "Exp of the element x"
	                  , py::arg("x"));

  m.def("exp", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::exp)
	                  , "Exp of the elements of a vector v"
	                  , py::arg("v"));

  m.def("exp", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::exp)
	                  , "Exp of the elements of a complex vector v"
	                  , py::arg("v"));

  m.def("exp", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::exp)
		          , "Exp of the elements of a matrix m"
	                  , py::arg("m"));

  m.def("exp", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::exp)
	                  , "Exp of the elements of a complex matrix m"
	                  , py::arg("m"));

  //! pow
  m.def("pow", static_cast<double (*)(const double, const double)>(&pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , py::arg("x"), py::arg("y"));

  m.def("pow", static_cast<itpp::vec (*)(const double, const itpp::vec &)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , py::arg("x"), py::arg("y"));

  m.def("pow", static_cast<itpp::mat (*)(const double, const itpp::mat &)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , py::arg("x"), py::arg("y"));

  m.def("pow", static_cast<itpp::vec (*)(const itpp::vec &, const double)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , py::arg("x"), py::arg("y"));

  m.def("pow", static_cast<itpp::mat (*)(const itpp::mat &, const double)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , py::arg("x"), py::arg("y"));

  //! pow2
  m.def("pow2", static_cast<double (*)(double)>(&itpp::pow2)
	                   , "Calculates two to the power of x (2^x)"
	                   , py::arg("x"));

  m.def("pow2", static_cast<double (*)(int)>(&itpp::pow2)
	                   , "Calculates two to the power of x (2^x) for integer"
	                   , py::arg("x"));

  m.def("pow2", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::pow2)
	                   , "Calculates two to the power of x (2^x)"
	                   , py::arg("v"));

  m.def("pow2", static_cast<itpp::vec (*)(const itpp::ivec &)>(&itpp::pow2)
	                   , "Calculates two to the power of x (2^x) for integer"
	                   , py::arg("v"));

  m.def("pow2", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::pow2)
	                   , "Calculates two to the power of x (2^x)"
	                   , py::arg("m"));

  m.def("pow2", static_cast<itpp::mat (*)(const itpp::imat &)>(&itpp::pow2)
	                   , "Calculates two to the power of x (2^x) for integer"
	                   , py::arg("m"));

  //! log
  m.def("log", static_cast<double (*)(const double &)>(&log)
	                  , "Natural logarithm of the element"
	                  , py::arg("x"));

  m.def("log", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , py::arg("v"));

  m.def("log", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , py::arg("v"));

  m.def("log", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , py::arg("m"));

  m.def("log", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , py::arg("m"));

  //! log2
  m.def("log2", static_cast<double (*)(const double &)>(&log2)
	                   , "log-2 of the element"
	                   , py::arg("x"));

  m.def("log2", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::log2)
	                   , "log-2 of the elements"
	                   , py::arg("v"));

  m.def("log2", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::log2)
	                   , "log-2 of the elements"
	                   , py::arg("m"));

  //! dB
  m.def("dB", static_cast<double (*)(double)>(&itpp::dB)
  	                 , "Calculates 10*log10(x)"
  	                 , py::arg("x"));

  m.def("dB", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::dB)
  	                 , "Calculates 10*log10(x) of elements of the vector v"
  	                 , py::arg("v"));

  m.def("dB", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::dB)
  	                 , "Calculates 10*log10(x) of elements of the matrix m"
  	                 , py::arg("m"));

  //! inv_dB
  m.def("inv_dB", static_cast<double (*)(double)>(&itpp::inv_dB)
  	                     , "Calulates the inverse of dB, 10^(x/10)"
  	                     , py::arg("x"));

  m.def("inv_dB", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::inv_dB)
  	                     , "Calulates the inverse of dB of the elements of vector, 10^(x/10)"
  	                     , py::arg("v"));

  m.def("inv_dB", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::inv_dB)
  	                     , "Calulates the inverse of dB the elements of the matrix, 10^(x/10)"
  	                     , py::arg("m"));

}
