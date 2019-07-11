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
#include <pybind11/operators.h>

#include <itpp/stat/misc_stat.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_misc_stat_module( py::module &m ) {

  //! mean
  m.def("mean", static_cast<double (*)(const itpp::vec &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("v"));

  m.def("mean", static_cast<std::complex<double> (*)(const itpp::cvec &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("v"));

  m.def("mean", static_cast<double (*)(const itpp::svec &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("v"));

  m.def("mean", static_cast<double (*)(const itpp::ivec &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("v"));

  m.def("mean", static_cast<double (*)(const itpp::mat &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("m"));

  m.def("mean", static_cast<std::complex<double> (*)(const itpp::cmat &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("m"));

  m.def("mean", static_cast<double (*)(const itpp::smat &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("m"));

  m.def("mean", static_cast<double (*)(const itpp::imat &)>(&itpp::mean)
	                   , "The mean value"
	                   , py::arg("m"));
  //! norm
  m.def("norm", static_cast<double (*)(const itpp::cvec &, int)>(&itpp::norm)
	                   , "Calculate the p-norm: norm(v,p)=sum(abs(v).^2)^(1/p)"
	                   , py::arg("v"), py::arg("p"));

  m.def("norm", static_cast<double (*)(const itpp::cvec &, const std::string &)>(&itpp::norm)
	                   , "Calculate the Frobenius norm for s = \"fro\" (equal to 2-norm)"
	                   , py::arg("v"), py::arg("s"));

  m.def("norm", static_cast<double (*)(const itpp::mat &, int)>(&itpp::norm)
	                   , "Calculate the p-norm of a real matrix"
	                   , py::arg("m"), py::arg("p"));

  m.def("norm", static_cast<double (*)(const itpp::cmat &, int)>(&itpp::norm)
	                   , "Calculate the p-norm of a complex matrix"
	                   , py::arg("m"), py::arg("p"));

  m.def("norm", static_cast<double (*)(const itpp::mat &, const std::string &)>(&itpp::norm)
	                   , "Calculate the Frobenius norm of a real matrix for s = \"fro\" (equal to 2-norm)"
	                   , py::arg("m"), py::arg("s"));

}
