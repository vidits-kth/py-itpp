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
#include <itpp/comm/error_counters.h>

BOOST_PYTHON_MODULE(error_counters)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  boost::python::class_<itpp::BERC>("BERC", boost::python::init<int, int, int>("Constructor for the berc class.", boost::python::args("self", "indelay", "inignorefirst", "inignorelast")))

    .def("count", static_cast<void (itpp::BERC::*)(const itpp::bvec&, const itpp::bvec&)>(&itpp::BERC::count)
                , "Cumulative error counter"
		, boost::python::args("self", "in1", "in2"))
    .def("count", static_cast<void (itpp::BERC::*)(const bool)>(&itpp::BERC::count)
		, "Variant of the cumulative error counter. Counts a bit error if x is true, and a correct bit otherwise"
		, boost::python::args("self", "x"))
    .def("estimate_delay", &itpp::BERC::estimate_delay
                         , "Run this member function if the delay between in1 and in2 is unknown."
			 , boost::python::args("self", "in1", "in2", "mindelay", "maxdelay"))
    .def("clear", &itpp::BERC::clear
                , "Clears the bit error counter."
                , boost::python::args("self"))
    .def("report", &itpp::BERC::report
                 , "Writes an error report"
                 , boost::python::args("self"))
    .def("get_delay", &itpp::BERC::get_delay
                    , "Return the delay, assumed or estimated, between in1 and in2."
		    , boost::python::args("self")
                    , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_errors", &itpp::BERC::get_errors
                     , "Returns the counted number of bit errors"
		     , boost::python::args("self")
                     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_corrects", &itpp::BERC::get_corrects
                       , "Returns the counted number of corectly received bits"
		       , boost::python::args("self")
                       , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_total_bits", &itpp::BERC::get_total_bits
                         , "Returns the total number of bits processed"
			 , boost::python::args("self")
                         , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_errorrate", &itpp::BERC::get_errorrate
                        , "Returns the estimated bit error rate."
			, boost::python::args("self")
			,boost::python::return_value_policy<boost::python::return_by_value>())
    .def("count_errors", &itpp::BERC::count_errors
                       , "static function to allow simple and fast count of bit-errors"
		       , boost::python::args("in1", "in2", "indelay", "inignorefirst", "inignorelast"))
    .staticmethod("count_errors")
  ;

  boost::python::class_<itpp::BLERC>("BLERC", boost::python::init<>("Class constructor", boost::python::args("self")))
    .def(boost::python::init<int>("Specialised constructor", boost::python::args("self", "blocksize")))

    .def("set_blocksize", &itpp::BLERC::set_blocksize
                        , "Set the block size"
			, boost::python::args("self", "blocksize", "clear"))
    .def("count", static_cast<void (itpp::BLERC::*)(const itpp::bvec&, const itpp::bvec&)>(&itpp::BLERC::count)
                , "Calculate the number of block errors between in1 and in2"
		, boost::python::args("self", "in1", "in2"))
    .def("count", static_cast<void (itpp::BLERC::*)(const bool)>(&itpp::BLERC::count)
		, "Variant of the cumulative error counter. Counts a block error if x is true, and a correct block otherwise"
		, boost::python::args("self", "x"))
    .def("clear", &itpp::BLERC::clear
	        , "Clear the block error counter"
		, boost::python::args("self"))
    .def("get_errors", &itpp::BLERC::get_errors
                     , "Returns the number of block errors"
		     , boost::python::args("self")
                     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_corrects", &itpp::BLERC::get_corrects
                       , "Returns the number of correct blocks"
		       , boost::python::args("self")
                       , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_total_blocks", &itpp::BLERC::get_total_blocks
                           , "Returns the total number of block processed"
			   , boost::python::args("self")
                           , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_errorrate", &itpp::BLERC::get_errorrate
                        , "Returns the block error rate"
			, boost::python::args("self")
                        , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
