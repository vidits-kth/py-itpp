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
#include <itpp/comm/llr.h>

BOOST_PYTHON_MODULE(llr) {

  boost::python::docstring_options local_docstring_options(true, true, false);

//  boost::python::class_<itpp::QLLR>("QLLR");

  boost::python::class_<itpp::QLLRvec>("QLLRvec");

  boost::python::class_<itpp::QLLRmat>("QLLRmat");

  boost::python::class_<itpp::LLR_calc_unit>("LLR_calc_unit", boost::python::init<>("Constructor, using the default table resolution", boost::python::args("self")))

    .def(boost::python::init<short int, short int, short int>("Constructor, using a specific table resolution.", boost::python::args("self", "Dint1", "Dint2", "Dint3")))

    .def("init_llr_tables", &itpp::LLR_calc_unit::init_llr_tables
	                  , "Set the quantization and table parameters"
			  , boost::python::args("self", "Dint1", "Dint2", "Dint3"))

    .def("to_qllr", static_cast<itpp::QLLR (itpp::LLR_calc_unit::*)(double) const>(&itpp::LLR_calc_unit::to_qllr)
		  , "Convert a \"real\" LLR value to an LLR type"
		  , boost::python::args("self", "l")
                  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("to_qllr", static_cast<itpp::QLLRvec (itpp::LLR_calc_unit::*)(const itpp::vec &) const>(&itpp::LLR_calc_unit::to_qllr)
		  , "Convert a vector of \"real\" LLR values to an LLR type"
		  , boost::python::args("self", "l")
                  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("to_qllr", static_cast<itpp::QLLRmat (itpp::LLR_calc_unit::*)(const itpp::mat &) const>(&itpp::LLR_calc_unit::to_qllr)
		  , "Convert a matrix of \"real\" LLR values to an LLR type"
		  , boost::python::args("self", "l")
		  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("to_double", static_cast<double(itpp::LLR_calc_unit::*)(itpp::QLLR) const>(&itpp::LLR_calc_unit::to_double)
		    , "Convert an LLR type to a \"real\" LLR"
		    , boost::python::args("self", "l")
		    , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("to_double", static_cast<itpp::vec (itpp::LLR_calc_unit::*)(const itpp::QLLRvec &) const>(&itpp::LLR_calc_unit::to_double)
		    , "Convert a vector of LLR types to a \"real\" LLR"
		    , boost::python::args("self", "l")
		    , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("to_double", static_cast<itpp::mat (itpp::LLR_calc_unit::*)(const itpp::QLLRmat &) const>(&itpp::LLR_calc_unit::to_double)
		    , "Convert a matrix of LLR types to a \"real\" LLR"
		    , boost::python::args("self", "l")
		    , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("jaclog", &itpp::LLR_calc_unit::jaclog
		 , "Jacobian logarithm. This function computes [log(exp(a)+exp(b))]"
		 , boost::python::args("self", "a", "b"))

    .def("Boxplus", &itpp::LLR_calc_unit::Boxplus
		  , "Hagenauer's \"Boxplus\" operator. This function computes: [ {sign}(a) * {sign}(b) * {min}(|a|,|b|) + f(|a+b|) - f(|a-b|)] where [ f(x) = log(1+exp(-x))]"
		  , boost::python::args("self", "a", "b"))

    .def("logexp", &itpp::LLR_calc_unit::logexp
		  , "Logexp operator. This function computes [ f(x) = log(1+exp(-x))]"
		  , boost::python::args("self", "x"))

    .def("get_Dint", &itpp::LLR_calc_unit::get_Dint
		   , "Retrieve the table resolution values"
		   , boost::python::args("self")
                   , boost::python::return_value_policy<boost::python::return_by_value>())

//    .def("__str__", static_cast<std::ostream (*)(std::ostream &, const itpp::LLR_calc_unit &)>(&itpp::operator<<)
//		  , "Print some properties of the LLR calculation unit in plain text")
  ;
}
