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
#include <itpp/comm/channel.h>

//! Communication Channel Models
BOOST_PYTHON_MODULE(channel)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  //! Predefined channel profiles. Includes LOS and Doppler spectrum settings.
  boost::python::enum_<itpp::CHANNEL_PROFILE>("CHANNEL_PROFILE")
    .value("ITU_Vehicular_A", itpp::ITU_Vehicular_A)
    .value("ITU_Vehicular_B", itpp::ITU_Vehicular_B)
    .value("ITU_Pedestrian_A", itpp::ITU_Pedestrian_A)
    .value("ITU_Pedestrian_B", itpp::ITU_Pedestrian_B)
    .value("COST207_RA", itpp::COST207_RA)
    .value("COST207_RA6", itpp::COST207_RA6)
    .value("COST207_TU", itpp::COST207_TU)
    .value("COST207_TU6alt", itpp::COST207_TU6alt)
    .value("COST207_TU12", itpp::COST207_TU12)
    .value("COST207_TU12alt", itpp::COST207_TU12alt)
    .value("COST207_HT", itpp::COST207_HT)
    .value("COST207_HT6alt", itpp::COST207_HT6alt)
    .value("COST207_HT12", itpp::COST207_HT12)
    .value("COST207_HT12alt", itpp::COST207_HT12alt)
    .value("COST259_TUx", itpp::COST259_TUx)
    .value("COST259_RAx", itpp::COST259_RAx)
    .value("COST259_RAx", itpp::COST259_RAx)
  ;

  //! Fading generator type: Independent (default), Static or Correlated.
  boost::python::enum_<itpp::FADING_TYPE>("FADING_TYPE")
    .value("Independent", itpp::Independent)
    .value("Static", itpp::Static)
    .value("Correlated", itpp::Correlated)
  ;

  //! Correlated fading generation methods: Rice_MEDS (default), IFFT or FIR.
  boost::python::enum_<itpp::CORRELATED_METHOD>("CORRELATED_METHOD")
    .value("Rice_MEDS", itpp::Rice_MEDS)
    .value("IFFT", itpp::IFFT)
    .value("FIR", itpp::FIR)
  ;

  //! Rice fading generation methods: MEDS.
  boost::python::enum_<itpp::RICE_METHOD>("RICE_METHOD")
    .value("MEDS", itpp::MEDS)
  ;

  //! Predefined Doppler spectra
  boost::python::enum_<itpp::DOPPLER_SPECTRUM>("DOPPLER_SPECTRUM")
    .value("Jakes", itpp::Jakes)
    .value("J", itpp::J)
    .value("Classic", itpp::Classic)
    .value("C", itpp::C)
    .value("GaussI", itpp::GaussI)
    .value("Gauss1", itpp::Gauss1)
    .value("GI", itpp::GI)
    .value("G1", itpp::G1)
    .value("GaussII", itpp::GaussII)
    .value("Gauss2", itpp::Gauss2)
    .value("GII", itpp::GII)
    .value("G2", itpp::G2)
  ;

  //! Cannot wrap abstract type Fading_Generator

//  // Fading generator class
//  boost::python::class_<itpp::Fading_Generator>("Fading_Generator", boost::python::init<>())
//
//    .def("set_LOS_power", &itpp::Fading_Generator::set_LOS_power)
//    .def("set_LOS_doppler", &itpp::Fading_Generator::set_LOS_doppler)
//    .def("set_time_offset", &itpp::Fading_Generator::set_time_offset)
//    .def("set_filter_length", &itpp::Fading_Generator::set_filter_length)
//    .def("set_norm_doppler", &itpp::Fading_Generator::set_norm_doppler)
//    .def("set_doppler_spectrum", &itpp::Fading_Generator::set_doppler_spectrum)
//    .def("set_no_frequencies", &itpp::Fading_Generator::set_no_frequencies)
//    .def("set_rice_method", &itpp::Fading_Generator::set_rice_method)
//
//    .def("get_LOS_power", &itpp::Fading_Generator::get_LOS_power)
//    .def("get_LOS_doppler", &itpp::Fading_Generator::get_LOS_doppler)
//    .def("get_time_offset", &itpp::Fading_Generator::get_time_offset)
//    .def("get_filter_length", &itpp::Fading_Generator::get_filter_length)
//    .def("get_norm_doppler", &itpp::Fading_Generator::get_norm_doppler)
//    .def("get_doppler_spectrum", &itpp::Fading_Generator::get_doppler_spectrum)
//    .def("get_no_frequencies", &itpp::Fading_Generator::get_no_frequencies)
//    .def("get_rice_method", &itpp::Fading_Generator::get_rice_method)
//
//    .def("shift_time_offset", &itpp::Fading_Generator::shift_time_offset)
//
//    .def("init", &itpp::Fading_Generator::init)

//    .def("generate", static_cast<void (itpp::Fading_Generator*)(int, itpp::cvec &)>(&itpp::Fading_Generator::generate))
//    .def("generate", static_cast<itpp::cvec (itpp::Fading_Generator*)(int, itpp::cvec &)>(&itpp::Fading_Generator::generate)
//                   , boost::python::return_value_policy<boost::python::return_by_value>())
//
//  ;

  //! Independent (random) fading generator class
  boost::python::class_<itpp::Independent_Fading_Generator>("Independent_Fading_Generator", boost::python::init<>())
    .def("init", &itpp::Independent_Fading_Generator::init)
    .def("generate", static_cast<void (itpp::Independent_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Independent_Fading_Generator::generate))
  ;

  //! Static fading generator class
  boost::python::class_<itpp::Static_Fading_Generator>("Static_Fading_Generator", boost::python::init<>())
    .def("init", &itpp::Static_Fading_Generator::init)
    .def("generate", static_cast<void (itpp::Static_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Static_Fading_Generator::generate))
  ;

  //! Cannot wrap abstract type Correlated_Fading_Generator

//  // Correlated (random) fading generator class
//  boost::python::class_<itpp::Correlated_Fading_Generator>("Correlated_Fading_Generator", boost::python::init<double>())
//    .def("set_norm_doppler", &itpp::Correlated_Fading_Generator::set_norm_doppler)
//    .def("set_LOS_doppler", &itpp::Correlated_Fading_Generator::set_LOS_doppler)
//    .def("set_time_offset", &itpp::Correlated_Fading_Generator::set_time_offset)
//
//    .def("get_norm_doppler", &itpp::Correlated_Fading_Generator::get_norm_doppler)
//    .def("get_LOS_doppler", &itpp::Correlated_Fading_Generator::get_LOS_doppler)
//    .def("get_time_offset", &itpp::Correlated_Fading_Generator::get_time_offset)
//
//    .def("shift_time_offset", &itpp::Correlated_Fading_Generator::shift_time_offset)
//
//    .def("init", &itpp::Correlated_Fading_Generator::init)
//    .def("generate", static_cast<void (itpp::Correlated_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Correlated_Fading_Generator::generate))
//  ;

  // Rice type fading generator class
  boost::python::class_<itpp::Rice_Fading_Generator>("Rice_Fading_Generator",
						     boost::python::init<double, itpp::DOPPLER_SPECTRUM, int, itpp::RICE_METHOD>())
    .def("set_doppler_spectrum", &itpp::Rice_Fading_Generator::set_doppler_spectrum)
    .def("set_no_frequencies", &itpp::Rice_Fading_Generator::set_no_frequencies)
    .def("set_rice_method", &itpp::Rice_Fading_Generator::set_rice_method)

    .def("get_doppler_spectrum", &itpp::Rice_Fading_Generator::get_doppler_spectrum)
    .def("get_no_frequencies", &itpp::Rice_Fading_Generator::get_no_frequencies)
    .def("get_rice_method", &itpp::Rice_Fading_Generator::get_rice_method)

    .def("init", &itpp::Rice_Fading_Generator::init)
    .def("generate", static_cast<void (itpp::Rice_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Rice_Fading_Generator::generate))
  ;

  //! FIR type Fading generator class
  boost::python::class_<itpp::FIR_Fading_Generator>("FIR_Fading_Generator", boost::python::init<double, int>())
    .def("set_filter_length", &itpp::FIR_Fading_Generator::set_filter_length)
    .def("get_filter_length", &itpp::FIR_Fading_Generator::get_filter_length)

    .def("init", &itpp::FIR_Fading_Generator::init)
    .def("generate", static_cast<void (itpp::FIR_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::FIR_Fading_Generator::generate))
  ;

  //! IFFT type Fading generator class
  boost::python::class_<itpp::IFFT_Fading_Generator>("IFFT_Fading_Generator", boost::python::init<double>())
    .def("init", &itpp::IFFT_Fading_Generator::init)
    .def("generate", static_cast<void (itpp::IFFT_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::IFFT_Fading_Generator::generate))
  ;

  //! General specification of a time-domain multipath channel
  boost::python::class_<itpp::Channel_Specification>("Channel_Specification", boost::python::init<const itpp::vec &, const itpp::vec &>())
    .def(boost::python::init<const itpp::CHANNEL_PROFILE>())

    .def("set_channel_profile", static_cast<void (itpp::Channel_Specification::*)(const itpp::vec &, const itpp::vec &)>(&itpp::Channel_Specification::set_channel_profile))
    .def("set_channel_profile", static_cast<void (itpp::Channel_Specification::*)(itpp::CHANNEL_PROFILE)>(&itpp::Channel_Specification::set_channel_profile))

    .def("set_doppler_spectrum", static_cast<void (itpp::Channel_Specification::*)(itpp::DOPPLER_SPECTRUM *)>(&itpp::Channel_Specification::set_doppler_spectrum))
    .def("set_doppler_spectrum", static_cast<void (itpp::Channel_Specification::*)(int, itpp::DOPPLER_SPECTRUM)>(&itpp::Channel_Specification::set_doppler_spectrum))

    .def("set_LOS", static_cast<void (itpp::Channel_Specification::*)(int, double, double)>(&itpp::Channel_Specification::set_LOS))
    .def("set_LOS", static_cast<void (itpp::Channel_Specification::*)(const itpp::vec &, const itpp::vec &)>(&itpp::Channel_Specification::set_LOS))

    .def("get_channel_profile", &itpp::Channel_Specification::get_channel_profile)
    .def("get_avg_power_dB", &itpp::Channel_Specification::get_avg_power_dB)
    .def("get_delay_prof", &itpp::Channel_Specification::get_delay_prof)

    .def("get_doppler_spectrum", static_cast<itpp::Array<itpp::DOPPLER_SPECTRUM> (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_doppler_spectrum)
	                       , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_doppler_spectrum", static_cast<itpp::DOPPLER_SPECTRUM (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_doppler_spectrum)
                               , boost::python::return_value_policy<boost::python::return_by_value>())



    .def("get_LOS_power", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_power))
    .def("get_LOS_doppler", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_doppler))
    .def("get_LOS_power", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_power))
    .def("get_LOS_doppler", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_doppler))

    .def("taps", &itpp::Channel_Specification::taps)

    .def("calc_mean_excess_delay", &itpp::Channel_Specification::calc_mean_excess_delay)
    .def("calc_rms_delay_spread", &itpp::Channel_Specification::calc_rms_delay_spread)

  ;

  //! Tapped Delay Line (TDL) channel model
  boost::python::class_<itpp::TDL_Channel>("TDL_Channel", boost::python::init<const itpp::vec &, const itpp::ivec &>())
    .def(boost::python::init<const itpp::Channel_Specification &, double>())

    .def("set_channel_profile", static_cast<void (itpp::TDL_Channel::*)(const itpp::vec &, const itpp::ivec &)>(&itpp::TDL_Channel::set_channel_profile))
    .def("set_channel_profile_uniform", &itpp::TDL_Channel::set_channel_profile_uniform)
    .def("set_channel_profile_exponential", &itpp::TDL_Channel::set_channel_profile_exponential)
    .def("set_channel_profile", static_cast<void (itpp::TDL_Channel::*)(const itpp::Channel_Specification &, double)>(&itpp::TDL_Channel::set_channel_profile))

    .def("set_correlated_method", &itpp::TDL_Channel::set_correlated_method)
    .def("set_fading_type", &itpp::TDL_Channel::set_fading_type)

    .def("set_norm_doppler", &itpp::TDL_Channel::set_norm_doppler)

    .def("set_LOS", &itpp::TDL_Channel::set_LOS)
    .def("set_LOS_power", &itpp::TDL_Channel::set_LOS_power)
    .def("set_LOS_doppler", &itpp::TDL_Channel::set_LOS_doppler)

    .def("set_doppler_spectrum", static_cast<void (itpp::TDL_Channel::*)(const itpp::DOPPLER_SPECTRUM *)>(&itpp::TDL_Channel::set_doppler_spectrum))
    .def("set_doppler_spectrum", static_cast<void (itpp::TDL_Channel::*)(int, itpp::DOPPLER_SPECTRUM)>(&itpp::TDL_Channel::set_doppler_spectrum))
    .def("set_no_frequencies", &itpp::TDL_Channel::set_no_frequencies)

    .def("set_time_offset", &itpp::TDL_Channel::set_time_offset)
    .def("shift_time_offset", &itpp::TDL_Channel::shift_time_offset)

    .def("set_filter_length", &itpp::TDL_Channel::set_filter_length)

    .def("taps", &itpp::TDL_Channel::taps)

    .def("get_channel_profile", &itpp::TDL_Channel::get_channel_profile)
    .def("get_avg_power_dB", &itpp::TDL_Channel::get_avg_power_dB)
    .def("get_delay_prof", &itpp::TDL_Channel::get_delay_prof)

    .def("get_correlated_method", &itpp::TDL_Channel::get_correlated_method)
    .def("get_fading_type", &itpp::TDL_Channel::get_fading_type)

    .def("get_norm_doppler", &itpp::TDL_Channel::get_norm_doppler)

    .def("get_LOS_power", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_power))
    .def("get_LOS_doppler", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_doppler))
    .def("get_LOS_power", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_power))
    .def("get_LOS_doppler", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_doppler))

    .def("get_no_frequencies", &itpp::TDL_Channel::get_no_frequencies)

    .def("get_time_offset", &itpp::TDL_Channel::get_time_offset)

    .def("calc_mean_excess_delay", &itpp::TDL_Channel::calc_mean_excess_delay)
    .def("calc_rms_delay_spread", &itpp::TDL_Channel::calc_rms_delay_spread)

    .def("init", &itpp::TDL_Channel::init)

    .def("generate", static_cast<void (itpp::TDL_Channel::*)(int, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::generate))
    .def("generate", static_cast<void (itpp::TDL_Channel::*)(int, itpp::cmat &)>(&itpp::TDL_Channel::generate))

    .def("filter_known_channel", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, const itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter_known_channel))
    .def("filter_known_channel", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, const itpp::cmat &)>(&itpp::TDL_Channel::filter_known_channel))

    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter))
    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::filter))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter)
                 , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::filter)
                 , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &)>(&itpp::TDL_Channel::filter))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &)>(&itpp::TDL_Channel::filter)
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("__call__", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::operator()))
    .def("__call__", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::operator()))
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &)>(&itpp::TDL_Channel::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("calc_impulse_response", &itpp::TDL_Channel::calc_impulse_response)

    .def("calc_frequency_response", static_cast<void (itpp::TDL_Channel::*)(const itpp::Array<itpp::cvec> &, itpp::Array<itpp::cvec> &, const int)>(&itpp::TDL_Channel::calc_frequency_response))
    .def("calc_frequency_response", static_cast<void (itpp::TDL_Channel::*)(const itpp::cmat &, itpp::cmat &, const int)>(&itpp::TDL_Channel::calc_frequency_response))
    .def("get_sampling_time", &itpp::TDL_Channel::get_sampling_time)
  ;

  //! A Binary Symetric Channel with crossover probability p.
  boost::python::class_<itpp::BSC>("BSC", boost::python::init<double>())
    .def("set_prob", &itpp::BSC::set_prob)
    .def("get_prob", &itpp::BSC::get_prob)
    .def("__call__", &itpp::BSC::operator())
  ;

  //! Ordinary AWGN Channel for cvec or vec inputs and outputs.
  boost::python::class_<itpp::AWGN_Channel>("AWGN_Channel", boost::python::init<double>())
    .def("set_noise", &itpp::AWGN_Channel::set_noise)
    .def("get_noise", &itpp::AWGN_Channel::get_noise)
    .def("__call__", static_cast<itpp::cvec (itpp::AWGN_Channel::*)(const itpp::cvec &)>(&itpp::AWGN_Channel::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::AWGN_Channel::*)(const itpp::vec &)>(&itpp::AWGN_Channel::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
