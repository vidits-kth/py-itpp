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
  boost::python::class_<itpp::BERC>("BERC", boost::python::init<int, int, int>())

    .def("count", static_cast<void (itpp::BERC::*)(const itpp::bvec&, const itpp::bvec&)>(&itpp::BERC::count))
    .def("estimate_delay", &itpp::BERC::estimate_delay)
    .def("clear", &itpp::BERC::clear)
    .def("report", &itpp::BERC::report)
    .def("get_delay", &itpp::BERC::get_delay)
    .def("get_errors", &itpp::BERC::get_errors)
    .def("get_corrects", &itpp::BERC::get_corrects)
    .def("get_total_bits", &itpp::BERC::get_total_bits)
    .def("get_errorrate", &itpp::BERC::get_errorrate)
    .def("count_errors", &itpp::BERC::count_errors)
    .staticmethod("count_errors")
  ;

  boost::python::class_<itpp::BLERC>("BLERC", boost::python::init<>())
    .def(boost::python::init<int>())
    .def("set_blocksize", &itpp::BLERC::set_blocksize)
    .def("count", static_cast<void (itpp::BLERC::*)(const itpp::bvec&, const itpp::bvec&)>(&itpp::BLERC::count))
    .def("clear", &itpp::BLERC::clear)
    .def("get_errors", &itpp::BLERC::get_errors)
    .def("get_corrects", &itpp::BLERC::get_corrects)
    .def("get_total_blocks", &itpp::BLERC::get_total_blocks)
    .def("get_errorrate", &itpp::BLERC::get_errorrate)
  ;
}
