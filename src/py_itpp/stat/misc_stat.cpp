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
#include <itpp/stat/misc_stat.h>

BOOST_PYTHON_MODULE(misc_stat) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  boost::python::def("norm", static_cast<double (*)(const itpp::cvec &, int)>(&itpp::norm)
	                   , "Calculate the p-norm: norm(v,p)=sum(abs(v).^2)^(1/p)"
	                   , boost::python::args("v", "p")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("norm", static_cast<double (*)(const itpp::cvec &, const std::string &)>(&itpp::norm)
	                   , "Calculate the Frobenius norm for s = \"fro\" (equal to 2-norm)"
	                   , boost::python::args("v", "s")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("norm", static_cast<double (*)(const itpp::mat &, int)>(&itpp::norm)
	                   , "Calculate the p-norm of a real matrix"
	                   , boost::python::args("m", "p")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("norm", static_cast<double (*)(const itpp::cmat &, int)>(&itpp::norm)
	                   , "Calculate the p-norm of a complex matrix"
	                   , boost::python::args("m", "p")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("norm", static_cast<double (*)(const itpp::mat &, const std::string &)>(&itpp::norm)
	                   , "Calculate the Frobenius norm of a real matrix for s = \"fro\" (equal to 2-norm)"
	                   , boost::python::args("m", "s")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

}

