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

#include <itpp/comm/error_counters.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_berc_class( py::module &m, const char * name ) {

  py::class_<itpp::BERC>( m, "BERC" )
    .def( py::init<int, int, int>(), "Constructor for the berc class."
		                   , py::arg( "indelay"), py::arg( "inignorefirst"), py::arg( "inignorelast"))

    .def("count", static_cast<void (itpp::BERC::*)(const itpp::bvec&, const itpp::bvec&)>(&itpp::BERC::count)
                , "Cumulative error counter"
		, py::arg( "in1"), py::arg( "in2"))

    .def("count", static_cast<void (itpp::BERC::*)(const bool)>(&itpp::BERC::count)
		, "Variant of the cumulative error counter. Counts a bit error if x is true, and a correct bit otherwise"
		, py::arg( "x"))

    .def("estimate_delay", &itpp::BERC::estimate_delay
                         , "Run this member function if the delay between in1 and in2 is unknown."
			 , py::arg( "in1"), py::arg( "in2"), py::arg( "mindelay"), py::arg( "maxdelay"))

    .def("clear", &itpp::BERC::clear
                , "Clears the bit error counter.")

    .def("report", &itpp::BERC::report
                 , "Writes an error report")

    .def("get_delay", &itpp::BERC::get_delay
                    , "Return the delay, assumed or estimated, between in1 and in2.")
		    
    .def("get_errors", &itpp::BERC::get_errors
                     , "Returns the counted number of bit errors")
		     
    .def("get_corrects", &itpp::BERC::get_corrects
                       , "Returns the counted number of corectly received bits")
		       
    .def("get_total_bits", &itpp::BERC::get_total_bits
                         , "Returns the total number of bits processed")
			 
    .def("get_errorrate", &itpp::BERC::get_errorrate
                        , "Returns the estimated bit error rate.")
			
    .def_static("count_errors", &itpp::BERC::count_errors
                              , "static function to allow simple and fast count of bit-errors"
		              , py::arg("in1"), py::arg( "in2"), py::arg( "indelay"), py::arg( "inignorefirst"), py::arg( "inignorelast"))

  ;
}

void generate_pybind_wrapper_for_itpp_blerc_class( py::module &m, const char * name ) {

  py::class_<itpp::BLERC>( m, name )
    .def( py::init<>(), "Class constructor" )
    .def( py::init<int>(), "Specialised constructor", py::arg("blocksize"))

    .def("set_blocksize", &itpp::BLERC::set_blocksize
                        , "Set the block size"
			, py::arg( "blocksize" ), py::arg("clear"))

    .def("count", static_cast<void (itpp::BLERC::*)(const itpp::bvec&, const itpp::bvec&)>(&itpp::BLERC::count)
                , "Calculate the number of block errors between in1 and in2"
		, py::arg( "in1" ), py::arg( "in2"))

    .def("count", static_cast<void (itpp::BLERC::*)(const bool)>(&itpp::BLERC::count)
		, "Variant of the cumulative error counter. Counts a block error if x is true, and a correct block otherwise"
		, py::arg( "x"))

    .def("clear", &itpp::BLERC::clear
	        , "Clear the block error counter")

    .def("get_errors", &itpp::BLERC::get_errors
                     , "Returns the number of block errors")

    .def("get_corrects", &itpp::BLERC::get_corrects
                       , "Returns the number of correct blocks")
    .def("get_total_blocks", &itpp::BLERC::get_total_blocks
                           , "Returns the total number of block processed")

    .def("get_errorrate", &itpp::BLERC::get_errorrate
                        , "Returns the block error rate")
  ;
}
