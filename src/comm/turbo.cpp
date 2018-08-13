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
  boost::python::docstring_options local_docstring_options(true, true, false);

  boost::python::class_<itpp::Turbo_Codec>("turbo_codec", boost::python::init<>(boost::python::args("self")))

    .def("set_parameters", &itpp::Turbo_Codec::set_parameters
                         , set_parameters_overloads("Set parameters for the turbo encoder",
                                                    boost::python::args("self", "gen1", "gen2", "constraint_length", "interleaver_sequence",
                                                                        "in_iterations", "in_metric", "in_logmax_scale_factor", "in_adaptive_stop", "lcalc")))

    .def("set_interleaver", &itpp::Turbo_Codec::set_interleaver
                          , "Set a new internal interleaver sequence for the turbo encoder/decoder"
                          , boost::python::args("self", "interleaver_sequence"))

    .def("set_metric", &itpp::Turbo_Codec::set_metric
                     , set_metric_overloads("Set the decoder metric",
                                            boost::python::args("self", "in_metric", "in_logmax_scale_factor", "lcalc")))

    .def("set_iterations", &itpp::Turbo_Codec::set_iterations
                         , "Sets the number of decoding iterations"
                         , boost::python::args("self", "in_iterations"))

    .def("set_adaptive_stop", &itpp::Turbo_Codec::set_adaptive_stop
                            , "Use an adaptive number of iterations"
                            , boost::python::args("self", "in_adaptive_stop"))

    .def("set_awgn_channel_parameters", &itpp::Turbo_Codec::set_awgn_channel_parameters
                                      , "Set parameters for decoding on an AWGN channel"
                                      , boost::python::args("self", "in_Ec", "in_N0"))

    .def("set_scaling_factor", &itpp::Turbo_Codec::set_scaling_factor
                             , "Set scaling factor for decoding on e.g. Rayleigh fading channels"
                             , boost::python::args("self", "in_Lc"))

    .def("encode", &itpp::Turbo_Codec::encode
                 , "Encoder function"
                 , boost::python::args("self", "input", "output"))

    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                           itpp::bvec &,
                                                           const itpp::bvec &)>(&itpp::Turbo_Codec::decode)
                 , "Decoder function"
                 , boost::python::args("self", "received_signal", "decoded_bits", "true_bits"))

    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                          itpp::bvec &, itpp::ivec &,
                                                          const itpp::bvec &)>(&itpp::Turbo_Codec::decode)
                 , "Decoder function"
                 , boost::python::args("self", "received_signal", "decoded_bits", "nrof_used_iterations","true_bits"))

    .def("encode_block", &itpp::Turbo_Codec::encode_block
                       , "Encode a single block"
                       , boost::python::args("self", "input", "in1", "in2", "parity1", "parity2"))

    .def("decode_block", &itpp::Turbo_Codec::decode_block
                       , "Decode a single block"
                       , boost::python::args("self", "rec_syst1", "rec_syst2", "rec_parity", "rec_parity2", "decoded_bits_i", "nrof_used_iterations_i", "true_bits"))

    .def("get_Ncoded", &itpp::Turbo_Codec::get_Ncoded
                     , "Get number of coded bits"
                     , boost::python::args("self")
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_Nuncoded", &itpp::Turbo_Codec::get_Nuncoded
                       , "Get number of uncoded bits"
                       , boost::python::args("self")
                       , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
