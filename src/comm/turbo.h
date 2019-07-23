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

#include <itpp/comm/turbo.h>

#include "llr.cpp"

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_turbo_codec_class( py::module &m ) {

  py::class_<itpp::Turbo_Codec>( m, "turbo_codec" )

    .def( py::init<>())

    .def("set_parameters", &itpp::Turbo_Codec::set_parameters
                         ,  py::arg( "gen1"), py::arg("gen2"), py::arg("constraint_length"), py::arg("interleaver_sequence")
                         ,  py::arg( "in_iterations") = 8, py::arg("in_metric") = "LOGMAX", py::arg("in_logmax_scale_factor") = 1.0, py::arg("in_adaptive_stop") = false, py::arg("lcalc") = itpp::LLR_calc_unit())

    .def("set_interleaver", &itpp::Turbo_Codec::set_interleaver
                          , "Set a new internal interleaver sequence for the turbo encoder/decoder"
                          , py::arg( "interleaver_sequence"))

    .def("set_metric", &itpp::Turbo_Codec::set_metric
                     , py::arg( "in_metric") = "LOGMAX", py::arg("in_logmax_scale_factor") = 1.0, py::arg("lcalc") = itpp::LLR_calc_unit() )

    .def("set_iterations", &itpp::Turbo_Codec::set_iterations
                         , "Sets the number of decoding iterations"
                         , py::arg( "in_iterations") = 8)

    .def("set_adaptive_stop", &itpp::Turbo_Codec::set_adaptive_stop
                            , "Use an adaptive number of iterations"
                            , py::arg( "in_adaptive_stop") = true)

    .def("set_awgn_channel_parameters", &itpp::Turbo_Codec::set_awgn_channel_parameters
                                      , "Set parameters for decoding on an AWGN channel"
                                      , py::arg( "in_Ec"), py::arg("in_N0"))

    .def("set_scaling_factor", &itpp::Turbo_Codec::set_scaling_factor
                             , "Set scaling factor for decoding on e.g. Rayleigh fading channels"
                             , py::arg( "in_Lc"))

    .def("encode", &itpp::Turbo_Codec::encode
                 , "Encoder function"
                 , py::arg( "input"), py::arg("output"))

    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                           itpp::bvec &,
                                                           const itpp::bvec &)>(&itpp::Turbo_Codec::decode)
                 , "Decoder function"
                 , py::arg( "received_signal"), py::arg("decoded_bits"), py::arg("true_bits"))

    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                          itpp::bvec &, itpp::ivec &,
                                                          const itpp::bvec &)>(&itpp::Turbo_Codec::decode)
                 , "Decoder function"
                 , py::arg( "received_signal"), py::arg("decoded_bits"), py::arg("nrof_used_iterations"), py::arg("true_bits") = "0")

    .def("encode_block", &itpp::Turbo_Codec::encode_block
                       , "Encode a single block"
                       , py::arg( "input"), py::arg("in1"), py::arg("in2"), py::arg("parity1"), py::arg("parity2"))

    .def("decode_block", &itpp::Turbo_Codec::decode_block
                       , "Decode a single block"
                       , py::arg( "rec_syst1"), py::arg("rec_syst2"), py::arg("rec_parity"), py::arg("rec_parity2"), py::arg("decoded_bits_i"), py::arg("nrof_used_iterations_i"), py::arg("true_bits") = "0")

    .def("get_Ncoded", &itpp::Turbo_Codec::get_Ncoded
                     , "Get number of coded bits")

    .def("get_Nuncoded", &itpp::Turbo_Codec::get_Nuncoded
                       , "Get number of uncoded bits")
  ;
}
