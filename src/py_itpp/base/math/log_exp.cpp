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

inline double log2(const double &x) { return std::log(x) / std::log(2.0); }

BOOST_PYTHON_MODULE(log_exp) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  // -------------------- log2 function --------------------

  boost::python::def("log2", static_cast<double (*)(const double &)>(&log2)
	                   , "log-2 of the element"
	                   , boost::python::args("x")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("log2", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::log2)
	                   , "log-2 of the elements"
	                   , boost::python::args("v")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("mat", static_cast<itpp::mat (*)(const itpp::mat &)>(&itpp::log2)
	                   , "log-2 of the elements"
	                   , boost::python::args("m")
                           , boost::python::return_value_policy<boost::python::return_by_value>());
}
