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

#include <itpp/comm/llr.h>

namespace py = pybind11;

//  boost::python::scope().attr("QLLR") = boost::python::object(boost::python::ptr(&itpp::QLLR));

//  boost::python::scope().attr("QLLRvec") = boost::python::object(boost::python::ptr(&itpp::QLLRvec));

//  boost::python::scope().attr("QLLRmat") =  boost::python::object(boost::python::ptr(&itpp::QLLRmat));

void generate_pybind_wrapper_for_itpp_llp_calc_unit_class( py::module &m ) {

  py::class_<itpp::LLR_calc_unit>( m, "LLR_calc_unit",
					     "Log-likelihood algebra calculation unit. This class contains functions for algebra with log-likelihood ratios"
					     "(LLRs). The class is mainly useful for modules that rely on certain nonlinear operations on LLRs (e.g. boxplus for LDPC and turbo"
					     " decoding and Jacobian logarithm for soft demodulation). The routines provided are numerically efficient and use only integer"
					     " arithmetics. Additionally, they allow for arbitrary quantization of LLRs in order to study effects of limited precision "
					     " (fixed point number representations). As a consequence, computations are approximate. With the standard settings,"
					     " the numerical precision should be sufficient (and practically equivalent to floating point precision) for all practical applications."
					     " However, one can construct cases where small numerical artifacts due to quantization effects (e.g., soft demodulation with very high "
					     " or very low SNR) can be observed."
					     ""
					     " An LLR for an information bit b is defined according to [L = log frac{P(b=0)}{P(b=1)}] and it is in general a real number."
					     " LLR values are represented via the special type, \"quantized LLR\" (QLLR).  The relation between the quantized representation"
					     " and the real (floating-point) LLR value is [QLLR = {round} 2^{{Dint1}}.{LLR}]. The user parameter Dint1 determines the"
					     " granularity of the quantization, and it can be set arbitrarily. The functions to_double() and to_qllr() can be used to perform"
					     " conversions between the two representations (QLLR to floating-point, and vice versa)."
					     ""
					     " The class provides functions for the computation of the Jacobian logarithm and Hagenauer's \"boxplus\" operator."
					     " These functions are based on a table-lookup.  The resolution of the table is determined by the parameters Dint2 and Dint3. "
					     " See the class constructor for more detail.  When an object of LLR_calc_unit is created, corresponding lookup-tables are also generated. "
					     " The resolution of these tables can be adjusted by providing parameters to the constructor."
					     ""
					     " The variable table resolution allows one to study complexity versus accuracy (i.e., how different table resolutions would"
					     " degrade performance) to some extent. Yet the main purpose of the QLLR representation is to provide a tool for writing efficient"
					     " simulation code, rather than to provide for bit-level (fixed-point) simulations. For bit-level simulations, a true fixed"
					     " point representation of LLRs would be preferred/required.  With the default setting of the table parameters, using the QLLR type"
					     " is practically as accurate (but much faster) as using \"double\" to represent LLRs.  Decoder implementations may then provide"
					     " functions using QLLR, fixed-point, or double (for compatibility reasons) representations of LLR values."
					     ""
					     " Note: the QLLR type does not check that the correct quantization level is used. I.e., in theory it would be possible to add two"
					     " QLLR types with different quantization (Dint) parameters.  This is intentionally implemented this way to achieve maximum runtime"
					     " efficiency." )
					   
    .def( py::init<>(), "Constructor, using the default table resolution")

    .def(py::init<short int, short int, short int>(), "Constructor, using a specific table resolution. See init_llr_tables() for more details on the parameters.", py::arg( "Dint1"), py::arg("Dint2"), py::arg("Dint3"))

    .def("init_llr_tables", &itpp::LLR_calc_unit::init_llr_tables
	                  , "Set the quantization and table parameters"
                            "Dint1=12, Dint2=300, Dint3=7 to give a performance practically indistinguishable from that of using floating point calculations."
			  , py::arg( "Dint1"), py::arg("Dint2"), py::arg("Dint3"))

    .def("to_qllr", static_cast<itpp::QLLR (itpp::LLR_calc_unit::*)(double) const>(&itpp::LLR_calc_unit::to_qllr)
		  , "Convert a \"real\" LLR value to an LLR type"
		  , py::arg( "l"))

    .def("to_qllr", static_cast<itpp::QLLRvec (itpp::LLR_calc_unit::*)(const itpp::vec &) const>(&itpp::LLR_calc_unit::to_qllr)
		  , "Convert a vector of \"real\" LLR values to an LLR type"
		  , py::arg( "l"))

    .def("to_qllr", static_cast<itpp::QLLRmat (itpp::LLR_calc_unit::*)(const itpp::mat &) const>(&itpp::LLR_calc_unit::to_qllr)
		  , "Convert a matrix of \"real\" LLR values to an LLR type"
		  , py::arg( "l"))

    .def("to_double", static_cast<double(itpp::LLR_calc_unit::*)(itpp::QLLR) const>(&itpp::LLR_calc_unit::to_double)
		    , "Convert an LLR type to a \"real\" LLR"
		    , py::arg( "l"))

    .def("to_double", static_cast<itpp::vec (itpp::LLR_calc_unit::*)(const itpp::QLLRvec &) const>(&itpp::LLR_calc_unit::to_double)
		    , "Convert a vector of LLR types to a \"real\" LLR"
		    , py::arg( "l"))

    .def("to_double", static_cast<itpp::mat (itpp::LLR_calc_unit::*)(const itpp::QLLRmat &) const>(&itpp::LLR_calc_unit::to_double)
		    , "Convert a matrix of LLR types to a \"real\" LLR"
		    , py::arg( "l"))

    .def("jaclog", &itpp::LLR_calc_unit::jaclog
		 , "Jacobian logarithm. This function computes [log(exp(a)+exp(b))]"
		 , py::arg( "a"), py::arg("b"))

    .def("Boxplus", &itpp::LLR_calc_unit::Boxplus
		  , "Hagenauer's \"Boxplus\" operator. This function computes: [ {sign}(a) * {sign}(b) * {min}(|a|,|b|) + f(|a+b|) - f(|a-b|)] where [ f(x) = log(1+exp(-x))]"
		  , py::arg( "a"), py::arg("b"))

    .def("logexp", &itpp::LLR_calc_unit::logexp
		  , "Logexp operator. This function computes [ f(x) = log(1+exp(-x))]"
		  , py::arg( "x"))

    .def("get_Dint", &itpp::LLR_calc_unit::get_Dint
		   , "Retrieve the table resolution values")

//    .def("__str__", static_cast<std::ostream (*)(std::ostream &, const itpp::LLR_calc_unit &)>(&itpp::operator<<)
//		  , "Print some properties of the LLR calculation unit in plain text")
  ;
}
