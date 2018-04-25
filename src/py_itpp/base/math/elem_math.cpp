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

inline double sqrt(const double &x) { return std::sqrt(x); }

BOOST_PYTHON_MODULE(elem_math) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  // -------------------- abs function --------------------

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

  // -------------------- sqrt function --------------------

  boost::python::def("sqrt", static_cast<double (*)(const double &)>(&sqrt)
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

  // -------------------- conj function --------------------
  boost::python::def("conj", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::conj)
	                   , "Conjugate of complex vector"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("conj", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::conj)
	                   , "Conjugate of complex matrix"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

}

