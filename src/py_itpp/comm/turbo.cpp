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
#include <itpp/comm/turbo.h>

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(set_parameters_overloads, itpp::Turbo_Codec::set_parameters, 4, 9)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(set_metric_overloads, itpp::Turbo_Codec::set_metric, 0, 3)

BOOST_PYTHON_MODULE(turbo)
{
  boost::python::class_<itpp::Turbo_Codec>("turbo_codec", boost::python::init<>())

    .def("set_parameters", &itpp::Turbo_Codec::set_parameters, set_parameters_overloads())

    .def("set_interleaver", &itpp::Turbo_Codec::set_interleaver)

    .def("set_metric", &itpp::Turbo_Codec::set_metric, set_metric_overloads())

    .def("set_iterations", &itpp::Turbo_Codec::set_iterations)

    .def("set_adaptive_stop", &itpp::Turbo_Codec::set_adaptive_stop)

    .def("set_awgn_channel_parameters", &itpp::Turbo_Codec::set_awgn_channel_parameters)

    .def("set_scaling_factor", &itpp::Turbo_Codec::set_scaling_factor)

    .def("encode", &itpp::Turbo_Codec::encode)

    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                           itpp::bvec &,
                                                           const itpp::bvec &)>(&itpp::Turbo_Codec::decode))

    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                          itpp::bvec &, itpp::ivec &,
                                                          const itpp::bvec &)>(&itpp::Turbo_Codec::decode))
    .def("encode_block", &itpp::Turbo_Codec::encode_block)

    .def("decode_block", &itpp::Turbo_Codec::decode_block)

    .def("get_Ncoded", &itpp::Turbo_Codec::get_Ncoded, boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_Nuncoded", &itpp::Turbo_Codec::get_Nuncoded, boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
