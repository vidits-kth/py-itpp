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
#include <itpp/base/math/log_exp.h>

// Extra functions for primitive types
inline double exp(const double x) { return std::exp(x); }

inline double pow(const double x, const double y) { return std::pow(x, y); }

inline double log(const double &x) { return std::log(x); }

inline double log2(const double &x) { return std::log(x) / std::log(2.0); }

BOOST_PYTHON_MODULE(log_exp) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  //! exp
  boost::python::def("exp", static_cast<double (*)(const double)>(&exp)
	                  , "Exp of the element x"
	                  , boost::python::args("x")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("exp", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::exp)
	                  , "Exp of the elements of a vector v"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("exp", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::exp)
	                  , "Exp of the elements of a complex vector v"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("exp", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::exp)
		          , "Exp of the elements of a matrix m"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("exp", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::exp)
	                  , "Exp of the elements of a complex matrix m"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  //! pow
  boost::python::def("pow", static_cast<double (*)(const double, const double)>(&pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , boost::python::args("x", "y")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("pow", static_cast<itpp::vec (*)(const double, const itpp::vec &)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , boost::python::args("x", "y")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("pow", static_cast<itpp::mat (*)(const double, const itpp::mat &)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , boost::python::args("x", "y")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("pow", static_cast<itpp::vec (*)(const itpp::vec &, const double)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , boost::python::args("x", "y")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("pow", static_cast<itpp::mat (*)(const itpp::mat &, const double)>(&itpp::pow)
	                  , "Calculates x to the power of y (x^y)"
	                  , boost::python::args("x", "y")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  //! log
  boost::python::def("log", static_cast<double (*)(const double &)>(&log)
	                  , "Natural logarithm of the element"
	                  , boost::python::args("x")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::log)
	                  , "Natural logarithm of the elements"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  //! log2
  boost::python::def("log2", static_cast<double (*)(const double &)>(&log2)
	                   , "log-2 of the element"
	                   , boost::python::args("x")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log2", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::log2)
	                   , "log-2 of the elements"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log2", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::log2)
	                   , "log-2 of the elements"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  //! dB
  boost::python::def("dB", static_cast<double (*)(double)>(&itpp::dB)
  	                 , "Calculates 10*log10(x)"
  	                 , boost::python::args("x")
                         , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("dB", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::dB)
  	                 , "Calculates 10*log10(x) of elements of the vector v"
  	                 , boost::python::args("v")
                         , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("dB", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::dB)
  	                 , "Calculates 10*log10(x) of elements of the matrix m"
  	                 , boost::python::args("m")
                         , boost::python::return_value_policy<boost::python::return_by_value>());

  //! inv_dB
  boost::python::def("inv_dB", static_cast<double (*)(double)>(&itpp::inv_dB)
  	                     , "Calulates the inverse of dB, 10^(x/10)"
  	                     , boost::python::args("x")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("inv_dB", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::inv_dB)
  	                     , "Calulates the inverse of dB of the elements of vector, 10^(x/10)"
  	                     , boost::python::args("v")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("inv_dB", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::inv_dB)
  	                     , "Calulates the inverse of dB the elements of the matrix, 10^(x/10)"
  	                     , boost::python::args("m")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

}
