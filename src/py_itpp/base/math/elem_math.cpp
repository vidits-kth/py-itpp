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
#include <itpp/base/math/elem_math.h>

inline double sqrt(const int x) { return std::sqrt(double(x)); }

inline double sqrt(const double x) { return std::sqrt(x); }

inline int abs(const int x) { return std::abs(x); }

inline double abs(const double x) { return std::abs(x); }

BOOST_PYTHON_MODULE(elem_math) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  //! real
  boost::python::def("real", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::real)
	                   , "Real part of complex values"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("real", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::real)
	                   , "Real part of complex values"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  //! imag
  boost::python::def("imag", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::imag)
	                   , "Imaginary part of complex values"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("imag", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::imag)
	                   , "Imaginary part of complex values"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  //! arg
  boost::python::def("arg", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::arg)
	                  , "Argument (angle)"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("arg", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::arg)
	                  , "Argument (angle)"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  //! angle
  boost::python::def("angle", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::angle)
	                    , "Angle"
	                    , boost::python::args("v")
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("angle", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::angle)
	                    , "Angle"
	                    , boost::python::args("m")
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  //! abs

  boost::python::def("abs", static_cast<int (*)(const int)>(&abs)
	                  , "Absolute value"
	                  , boost::python::args("x")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<double (*)(const double)>(&abs)
	                  , "Absolute value"
	                  , boost::python::args("x")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::abs)
	                  , "Absolute value"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::abs)
	                  , "Absolute value"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<itpp::ivec (*)(const itpp::ivec &)>(&itpp::abs)
	                  , "Absolute value"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<itpp::imat (*)(const itpp::imat &)>(&itpp::abs)
	                  , "Absolute value"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::abs)
	                  , "Absolute value"
	                  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("abs", static_cast<itpp::mat (*)(const itpp::cmat &)>(&itpp::abs)
	                  , "Absolute value"
	                  , boost::python::args("m")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  // sqrt

  boost::python::def("sqrt", static_cast<double (*)(const int)>(&sqrt)
	                   , "Square root of the elements"
	                   , boost::python::args("x")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("sqrt", static_cast<double (*)(const double)>(&sqrt)
	                   , "Square root of the elements"
	                   , boost::python::args("x")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("sqrt", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::sqrt)
	                   , "Square root of the elements"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("sqrt", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::sqrt)
	                   , "Square root of the elements"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  // conj
  boost::python::def("conj", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::conj)
	                   , "Conjugate of complex vector"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("conj", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::conj)
	                   , "Conjugate of complex matrix"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

}

