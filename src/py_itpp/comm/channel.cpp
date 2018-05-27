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

  // Fading generator class
  boost::python::class_<itpp::Fading_Generator, boost::noncopyable>("Fading_Generator", boost::python::no_init)

    .def("set_LOS_power", &itpp::Fading_Generator::set_LOS_power
                        , "Set relative LOS power"
			, boost::python::args("self", "relative_power"))
    .def("set_LOS_doppler", &itpp::Fading_Generator::set_LOS_doppler
                          , "Set relative Doppler of the LOS component (for correlated fading generators)"
			  , boost::python::args("self", "relative_doppler"))
    .def("set_time_offset", &itpp::Fading_Generator::set_time_offset
                          , "Set time offset in samples (for correlated fading generators)"
			  , boost::python::args("self", "offset"))
    .def("set_filter_length", &itpp::Fading_Generator::set_filter_length
                            , "Set FIR filter length (for FIR fading generator)"
			    , boost::python::args("self", "filter_length"))
    .def("set_norm_doppler", &itpp::Fading_Generator::set_norm_doppler
                           , "Set normalized Doppler (for correlated fading generators)"
			   , boost::python::args("self", "norm_doppler"))
    .def("set_doppler_spectrum", &itpp::Fading_Generator::set_doppler_spectrum
                               , "Set Doppler spectrum (for Rice fading generator)"
			       , boost::python::args("self", "spectrum"))
    .def("set_no_frequencies", &itpp::Fading_Generator::set_no_frequencies
                             , "Set number of sine frequencies (for Rice fading generator)"
			     , boost::python::args("self", "no_freq"))
    .def("set_rice_method", &itpp::Fading_Generator::set_rice_method
                          , "Set calculation method of Doppler frequencies and amplitudes (for Rice fading generator)"
			  , boost::python::args("self", "method"))

    .def("get_LOS_power", &itpp::Fading_Generator::get_LOS_power
                        , "Get relative power of LOS component (Rice factor)"
			, boost::python::args("self")
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_doppler", &itpp::Fading_Generator::get_LOS_doppler
                          , "Get relative Doppler of the LOS component (for correlated fading generators)"
			  , boost::python::args("self")
	                  , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_time_offset", &itpp::Fading_Generator::get_time_offset
	                  , "Get time offset in samples (for correlated fading generators)"
			  , boost::python::args("self")
	                  , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_filter_length", &itpp::Fading_Generator::get_filter_length
	                    , "Set FIR filter length (for FIR fading generator)"
		            , boost::python::args("self")
		            , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_norm_doppler", &itpp::Fading_Generator::get_norm_doppler
	                   , "Return normalized Doppler (for correlated fading generators)"
			   , boost::python::args("self")
			   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_doppler_spectrum", &itpp::Fading_Generator::get_doppler_spectrum
                               , "Return Doppler spectrum (for Rice fading generator)"
			       , boost::python::args("self")
			       , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_no_frequencies", &itpp::Fading_Generator::get_no_frequencies
                             , "Get number of sine frequencies (for Rice fading generator)"
			     , boost::python::args("self")
			     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_rice_method", &itpp::Fading_Generator::get_rice_method
                          , "Get calculation method of Doppler frequencies and amplitudes (for Rice fading generator)"
			  , boost::python::args("self")
	                  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("shift_time_offset", &itpp::Fading_Generator::shift_time_offset
                            , "Shift generator time offset by a number of samples (for correlated fading generators)"
			    , boost::python::args("self", "no_samples"))

    .def("init", &itpp::Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Fading_Generator::generate)
                   , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "no_samples", "output"))
    .def("generate", static_cast<itpp::cvec (itpp::Fading_Generator::*)(int)>(&itpp::Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "nrof_samples")
                   , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! Independent (random) fading generator class
  boost::python::class_<itpp::Independent_Fading_Generator, boost::python::bases<itpp::Fading_Generator> >("Independent_Fading_Generator",
													   boost::python::init<>("Default constructor", boost::python::args("self")))
    .def("init", &itpp::Independent_Fading_Generator::init
	       , "Initialize the generator"
	       , boost::python::args("self"))
    .def("generate", static_cast<void (itpp::Independent_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Independent_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "nrof_samples", "output"))
  ;

  //! Static fading generator class
  boost::python::class_<itpp::Static_Fading_Generator, boost::python::bases<itpp::Fading_Generator> >("Static_Fading_Generator",
												      boost::python::init<>("Default constructor", boost::python::args("self")))
    .def("init", &itpp::Static_Fading_Generator::init
	       , "Initialize the generator"
	       , boost::python::args("self"))
    .def("generate", static_cast<void (itpp::Static_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Static_Fading_Generator::generate)
                   , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "nrof_samples", "output"))
  ;

  // Correlated (random) fading generator class
  boost::python::class_<itpp::Correlated_Fading_Generator, boost::python::bases<itpp::Fading_Generator>, boost::noncopyable>("Correlated_Fading_Generator", boost::python::no_init)
    .def("set_norm_doppler", &itpp::Correlated_Fading_Generator::set_norm_doppler
                           , "Set normalized Doppler"
			   , boost::python::args("self", "norm_doppler"))
    .def("set_LOS_doppler", &itpp::Correlated_Fading_Generator::set_LOS_doppler
                          , "Set relative Doppler (compared to the maximum Doppler) for the LOS component"
                          , boost::python::args("self", "relative_doppler"))
    .def("set_time_offset", &itpp::Correlated_Fading_Generator::set_time_offset
                          , "Set time offset in samples"
			  , boost::python::args("self", "offset"))

    .def("get_norm_doppler", &itpp::Correlated_Fading_Generator::get_norm_doppler
	                   , "Return normalized Doppler"
			   , boost::python::args("self")
                           , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_doppler", &itpp::Correlated_Fading_Generator::get_LOS_doppler
                          , "Get relative Doppler (compared to the maximum doppler) for the LOS component"
			  , boost::python::args("self")
                          , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_time_offset", &itpp::Correlated_Fading_Generator::get_time_offset
	                  , "Get time offset in samples"
	                  , boost::python::args("self")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("shift_time_offset", &itpp::Correlated_Fading_Generator::shift_time_offset
	                    , "Shift generator time offset by a number of samples"
			    , boost::python::args("self", "no_samples"))

    .def("init", &itpp::Correlated_Fading_Generator::init
	       , "Initialize the generator"
	       , boost::python::args("self"))

    .def("generate", static_cast<void (itpp::Correlated_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Correlated_Fading_Generator::generate)
                   , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self"))
  ;

  // Rice type fading generator class
  boost::python::class_<itpp::Rice_Fading_Generator, boost::python::bases<itpp::Correlated_Fading_Generator> >("Rice_Fading_Generator",
						                                                              boost::python::init<double, itpp::DOPPLER_SPECTRUM, int, itpp::RICE_METHOD>("Default constructor", boost::python::args("self", "norm_doppler", "spectrum", "no_freq", "method")))
    .def("set_doppler_spectrum", &itpp::Rice_Fading_Generator::set_doppler_spectrum
	                       , "Set Doppler spectrum"
			       , boost::python::args("self", "spectrum"))
    .def("set_no_frequencies", &itpp::Rice_Fading_Generator::set_no_frequencies
	                     , "Set number of Doppler frequencies"
			     , boost::python::args("self", "no_freq"))
    .def("set_rice_method", &itpp::Rice_Fading_Generator::set_rice_method
	                  , "Set calculation method of Doppler frequencies and amplitudes"
			  , boost::python::args("self", "method"))

    .def("get_doppler_spectrum", &itpp::Rice_Fading_Generator::get_doppler_spectrum
	                       , "Return Doppler spectrum"
			       , boost::python::args("self")
                               , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_no_frequencies", &itpp::Rice_Fading_Generator::get_no_frequencies
	                     , "Get number of Doppler frequencies"
			     , boost::python::args("self")
                             , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_rice_method", &itpp::Rice_Fading_Generator::get_rice_method
	                  , "Get calculation method of Doppler frequencies and amplitudes"
			  , boost::python::args("self")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("init", &itpp::Rice_Fading_Generator::init
	       , "Initialize the generator"
	       , boost::python::args("self"))

    .def("generate", static_cast<void (itpp::Rice_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Rice_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "no_samples", "output"))
  ;

  //! FIR type Fading generator class
  boost::python::class_<itpp::FIR_Fading_Generator, boost::python::bases<itpp::Correlated_Fading_Generator> >("FIR_Fading_Generator",
													      boost::python::init<double, int>("Default constructor", boost::python::args("self", "norm_doppler", "filter_length")))
    .def("set_filter_length", &itpp::FIR_Fading_Generator::set_filter_length
                            , "Set FIR filter length"
			    , boost::python::args("self", "filter_length"))
    .def("get_filter_length", &itpp::FIR_Fading_Generator::get_filter_length
	                    , "Get filter length"
			    , boost::python::args("self")
                            , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("init", &itpp::FIR_Fading_Generator::init
	       , "Initialize the generator"
	       , boost::python::args("self"))

    .def("generate", static_cast<void (itpp::FIR_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::FIR_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "no_samples", "output"))
  ;

  //! IFFT type Fading generator class
  boost::python::class_<itpp::IFFT_Fading_Generator, boost::python::bases<itpp::Correlated_Fading_Generator> >("IFFT_Fading_Generator",
													       boost::python::init<double>("Default constructor", boost::python::args("self", "norm_doppler")))
    .def("init", &itpp::IFFT_Fading_Generator::init
	       , "Initialize the generator"
	       , boost::python::args("self"))

    .def("generate", static_cast<void (itpp::IFFT_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::IFFT_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , boost::python::args("self", "no_samples", "output"))
  ;

  //! General specification of a time-domain multipath channel
  boost::python::class_<itpp::Channel_Specification>("Channel_Specification",
						     boost::python::init<const itpp::vec &, const itpp::vec &>("Default constructor (power profile in dB, delay profile in seconds)", boost::python::args("self", "avg_power_dB", "delay_prof")))

    .def(boost::python::init<const itpp::CHANNEL_PROFILE>("Initialize with predetermined channel profile", boost::python::args("self", "profile")))

    .def("set_channel_profile", static_cast<void (itpp::Channel_Specification::*)(const itpp::vec &, const itpp::vec &)>(&itpp::Channel_Specification::set_channel_profile)
	                      , "Set both average power profile in dB and power delay profile in seconds"
			      , boost::python::args("self", "avg_power_dB", "delay_prof"))
    .def("set_channel_profile", static_cast<void (itpp::Channel_Specification::*)(itpp::CHANNEL_PROFILE)>(&itpp::Channel_Specification::set_channel_profile)
	                      , "Set channel profile to a predetermined profile"
			      , boost::python::args("self", "profile"))

    .def("set_doppler_spectrum", static_cast<void (itpp::Channel_Specification::*)(itpp::DOPPLER_SPECTRUM *)>(&itpp::Channel_Specification::set_doppler_spectrum)
	                       , "Set doppler spectrum for each tap in the channel profile"
			       , boost::python::args("self", "tap_spectrum"))
    .def("set_doppler_spectrum", static_cast<void (itpp::Channel_Specification::*)(int, itpp::DOPPLER_SPECTRUM)>(&itpp::Channel_Specification::set_doppler_spectrum)
	                       , "Set doppler spectrum for tap \a tap_number in the channel profile."
			       , boost::python::args("self", "tap_number", "tap_spectrum"))

    .def("set_LOS", static_cast<void (itpp::Channel_Specification::*)(int, double, double)>(&itpp::Channel_Specification::set_LOS)
	          , "Set LOS (Rice) components for tap \a tap_number"
		  , boost::python::args("self", "tap_number", "relative_power", "relative_doppler"))
    .def("set_LOS", static_cast<void (itpp::Channel_Specification::*)(const itpp::vec &, const itpp::vec &)>(&itpp::Channel_Specification::set_LOS)
	          , "Set LOS (Rice) components for all taps"
		  , boost::python::args("self", "relative_power", "relative_doppler"))

    .def("get_channel_profile", &itpp::Channel_Specification::get_channel_profile
                              , "Get both average power profile in dB and power delay profile in samples"
                              , boost::python::args("self", "avg_power_dB", "delay_prof"))
    .def("get_avg_power_dB", &itpp::Channel_Specification::get_avg_power_dB
	                   , "Return power profile in dB"
			   , boost::python::args("self")
                           , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_delay_prof", &itpp::Channel_Specification::get_delay_prof
	                 , "Return delay profile in seconds"
			 , boost::python::args("self")
                         , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_doppler_spectrum", static_cast<itpp::Array<itpp::DOPPLER_SPECTRUM> (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_doppler_spectrum)
	                       , "Get doppler spectrum for tap \a index"
			       , boost::python::args("self")
	                       , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_doppler_spectrum", static_cast<itpp::DOPPLER_SPECTRUM (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_doppler_spectrum)
	                       , "Get doppler spectrum for tap \a index"
			       , boost::python::args("self", "index")
                               , boost::python::return_value_policy<boost::python::return_by_value>())



    .def("get_LOS_power", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_power)
	                , "Get relative power (Rice factor) for each tap"
			, boost::python::args("self")
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_doppler", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_doppler)
	                  , "Get relative Doppler for each tap"
			  , boost::python::args("self")
                          , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_power", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_power)
	                , "Get relative power (Rice factor) for tap \a tap_number"
			, boost::python::args("self", "tap_number")
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_doppler", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_doppler)
	                  , "Get relative Doppler for tap \a tap_number"
			  , boost::python::args("self", "tap_number")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("taps", &itpp::Channel_Specification::taps
	       , "Return the number of channel taps"
	       , boost::python::args("self")
               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("calc_mean_excess_delay", &itpp::Channel_Specification::calc_mean_excess_delay
	                         , "Calculate mean excess delay in samples"
				 , boost::python::args("self")
                                 , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("calc_rms_delay_spread", &itpp::Channel_Specification::calc_rms_delay_spread
	                        , "Calculate RMS delay spread in samples"
				, boost::python::args("self")
                                , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! Tapped Delay Line (TDL) channel model
  boost::python::class_<itpp::TDL_Channel>("TDL_Channel", boost::python::init<const itpp::vec &, const itpp::ivec &>("Default constructor", boost::python::args("self", "avg_power_dB", "delay_prof")))
    .def(boost::python::init<const itpp::Channel_Specification &, double>("Constructor with defined Channel_Specification. Delay profile will be discretized with \a sampling_time in seconds.",
	                                                                  boost::python::args("self", "channel_spec", "sampling_time")))

    .def("set_channel_profile", static_cast<void (itpp::TDL_Channel::*)(const itpp::vec &, const itpp::ivec &)>(&itpp::TDL_Channel::set_channel_profile)
	                      , "Set both average power profile in dB and power delay profile in samples"
			      , boost::python::args("self", "avg_power_dB","delay_prof"))
    .def("set_channel_profile_uniform", &itpp::TDL_Channel::set_channel_profile_uniform
	                              , "Set channel profile to uniform with \a no_taps taps"
				      , boost::python::args("self", "no_taps"))
    .def("set_channel_profile_exponential", &itpp::TDL_Channel::set_channel_profile_exponential
	                                  , "Set channel profile to exponential with \a no_taps taps"
					  , boost::python::args("self", "no_taps"))
    .def("set_channel_profile", static_cast<void (itpp::TDL_Channel::*)(const itpp::Channel_Specification &, double)>(&itpp::TDL_Channel::set_channel_profile)
	                      , "Set channel profile using Channel_Specification. Delay profile will be discretized with \a sampling_time in seconds."
			      , boost::python::args("self", "channel_spec", "sampling_time"))

    .def("set_correlated_method", &itpp::TDL_Channel::set_correlated_method
	                        , "Set the fading generation method to \a method"
				, boost::python::args("self", "method"))
    .def("set_fading_type", &itpp::TDL_Channel::set_fading_type
	                  , "Set fading type to one of \a Independent, \a Static or \a Correlated"
			  , boost::python::args("self", "fading_type"))

    .def("set_norm_doppler", &itpp::TDL_Channel::set_norm_doppler
	                   , "Set normalized Doppler rate. A \a Correlated fading type will be used."
			   , boost::python::args("self", "norm_doppler"))

    .def("set_LOS", &itpp::TDL_Channel::set_LOS
	          , "Set LOS parameters for each tap. LOS Doppler will be set to 0.7 by default."
		  , boost::python::args("relative_power", "relative_dopper"))
    .def("set_LOS_power", &itpp::TDL_Channel::set_LOS_power
	                , "Set LOS power for each tap. LOS Doppler will be set to 0.7 by default."
			, boost::python::args("self", "relative_power"))
    .def("set_LOS_doppler", &itpp::TDL_Channel::set_LOS_doppler
	                  , "Set LOS doppler for each tap. A \a Correlated fading type will be used."
			  , boost::python::args("self", "relative_doppler"))

    .def("set_doppler_spectrum", static_cast<void (itpp::TDL_Channel::*)(const itpp::DOPPLER_SPECTRUM *)>(&itpp::TDL_Channel::set_doppler_spectrum)
	                       , "Set doppler spectrum for each tap in the channel profile. \a Rice_MEDS method will be used."
			       , boost::python::args("self", "tap_spectrum"))
    .def("set_doppler_spectrum", static_cast<void (itpp::TDL_Channel::*)(int, itpp::DOPPLER_SPECTRUM)>(&itpp::TDL_Channel::set_doppler_spectrum)
	                       , "Set doppler spectrum of tap \a tap_number. \a Rice_MEDS method will be used."
			       , boost::python::args("self", "tap_number", "tap_spectrum"))
    .def("set_no_frequencies", &itpp::TDL_Channel::set_no_frequencies
	                     , "Set number of sine frequencies. \a Rice_MEDS method will be used."
			     , boost::python::args("self", "no_freq"))

    .def("set_time_offset", &itpp::TDL_Channel::set_time_offset
	                  , "Set fading generators' time offset in samples. A \a Correlated fading type will be used."
			  , boost::python::args("self", "offset"))
    .def("shift_time_offset", &itpp::TDL_Channel::shift_time_offset
	                    , "Shift fading generators' time offset. A \a Correlated fading type will be used."
			    , boost::python::args("self", "no_samples"))

    .def("set_filter_length", &itpp::TDL_Channel::set_filter_length
	                    , "Set fading generator filter length. \a FIR method will be used."
			    , boost::python::args("self", "filter_length"))

    .def("taps", &itpp::TDL_Channel::taps
	       , "Return the number of channel taps"
	       , boost::python::args("self")
               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_channel_profile", &itpp::TDL_Channel::get_channel_profile
	                      , "Get both average power profile in dB and power delay profile in samples"
			      , boost::python::args("self", "avg_power_dB", "delay_prof"))
    .def("get_avg_power_dB", &itpp::TDL_Channel::get_avg_power_dB
	                   , "Return power profile in dB"
			   , boost::python::args("self")
                           , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_delay_prof", &itpp::TDL_Channel::get_delay_prof
	                 , "Return delay profile in samples"
			 , boost::python::args("self")
                         , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_correlated_method", &itpp::TDL_Channel::get_correlated_method
	                        , "Return fading generation method"
				, boost::python::args("self")
                                , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_fading_type", &itpp::TDL_Channel::get_fading_type
	                  , "Return fading type"
			  , boost::python::args("self")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_norm_doppler", &itpp::TDL_Channel::get_norm_doppler
	                   , "Return normalized doppler rate"
			   , boost::python::args("self")
			   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_LOS_power", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_power)
	                , "Get relative power (Rice factor) for each tap"
		        , boost::python::args("self")
		        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_doppler", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_doppler)
	                  , "Get relative Doppler (to the maximum Doppler) for each tap"
			  , boost::python::args("self")
			  , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_power", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_power)
                        , "Get relative power (Rice factor) for tap \a tap_number"
			, boost::python::args("self", "tap_number")
			, boost::python::return_value_policy<boost::python::return_by_value>())
    .def("get_LOS_doppler", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_doppler)
	                  , "Get relative Doppler (to the maximum Doppler) for tap \a tap_number"
			  , boost::python::args("self", "tap_number")
	                  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_no_frequencies", &itpp::TDL_Channel::get_no_frequencies
	                     , "Get the minimum number of frequencies used in Rice MEDS fading generator"
			     , boost::python::args("self")
                             , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_time_offset", &itpp::TDL_Channel::get_time_offset
	                  , "Get fading generators' time ofset"
			  , boost::python::args("self")
			  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("calc_mean_excess_delay", &itpp::TDL_Channel::calc_mean_excess_delay
	                         , "Calculate mean excess delay in samples"
				 , boost::python::args("self")
	                         , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("calc_rms_delay_spread", &itpp::TDL_Channel::calc_rms_delay_spread
	                        , "Calculate RMS delay spread in samples"
				, boost::python::args("self")
                                , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("init", &itpp::TDL_Channel::init
	       , "Initialize all fading generators. Automatically invoked in generate() or filter() functions."
	       , boost::python::args("self"))

    .def("generate", static_cast<void (itpp::TDL_Channel::*)(int, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::generate)
	           , "Generate \a no_samples values of the channel"
		   , boost::python::args("self", "no_samples", "channel_coeff"))
    .def("generate", static_cast<void (itpp::TDL_Channel::*)(int, itpp::cmat &)>(&itpp::TDL_Channel::generate)
	           , "Generate \a no_samples values of the channel. Returns the matrix with one tap per column."
		   , boost::python::args("self", "no_samples", "channel_coeff"))

    .def("filter_known_channel", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, const itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter_known_channel)
	                       , "Filter the \a input with the known channel values \a channel_coeff (e.g. from the generate function)"
			       , boost::python::args("self", "input", "output", "channel_coeff"))
    .def("filter_known_channel", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, const itpp::cmat &)>(&itpp::TDL_Channel::filter_known_channel)
	                       , "Filter the \a input with the known channel values \a channel_coeff (e.g. from the generate function)"
			       , boost::python::args("self", "input", "output", "channel_coeff"))

    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , boost::python::args("self", "input", "output", "channel_coeff"))
    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , boost::python::args("self", "input", "output", "channel_coeff"))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , boost::python::args("self", "input", "channel_coeff")
                 , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , boost::python::args("self", "input", "channel_coeff")
                 , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Only return the output"
		 , boost::python::args("self", "input", "output"))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Only return the output"
		 , boost::python::args("self", "input")
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("__call__", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , boost::python::args("self", "input", "output", "channel_coeff"))
    .def("__call__", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , boost::python::args("self", "input", "output", "channel_coeff"))
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , boost::python::args("self", "input", "channel_coeff")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::operator())
	           ,"Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , boost::python::args("self", "input", "channel_coeff")
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Only return output"
		   , boost::python::args("self", "input")
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("calc_impulse_response", &itpp::TDL_Channel::calc_impulse_response
	                        , "Calculate impulse-response on the supplied channel coefficients (produced by the generate() function)"
				, boost::python::args("self", "channel_coeff", "impulse_response"))

    .def("calc_frequency_response", static_cast<void (itpp::TDL_Channel::*)(const itpp::Array<itpp::cvec> &, itpp::Array<itpp::cvec> &, const int)>(&itpp::TDL_Channel::calc_frequency_response)
	                          , "Calculate frequency-response on the supplied channel coefficients (produced by the generate() function)"
				  , boost::python::args("self", "channel_coeff", "frequency_response", "fft_size"))
    .def("calc_frequency_response", static_cast<void (itpp::TDL_Channel::*)(const itpp::cmat &, itpp::cmat &, const int)>(&itpp::TDL_Channel::calc_frequency_response)
	                          , "Calculate frequency-response on the supplied channel coefficients (produced by the generate() function)"
				  , boost::python::args("self", "channel_coeff", "frequency_response", "fft_size"))
    .def("get_sampling_time", &itpp::TDL_Channel::get_sampling_time
	                    , "Return channel sampling time (used for discretization)"
			    , boost::python::args("self")
                            , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! A Binary Symetric Channel with crossover probability p.
  boost::python::class_<itpp::BSC>("BSC", boost::python::init<double>("Class constructor. Sets the error probability to p", boost::python::args("self", "in_p")))
    .def("set_prob", &itpp::BSC::set_prob
	           , "Set crossover (bit error) probability"
		   , boost::python::args("self", "in_p"))
    .def("get_prob", &itpp::BSC::get_prob
	           , "Get crossover (bit error) probability"
		   , boost::python::args("self")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", &itpp::BSC::operator()
	           , "Feed \a input through the BSC channel"
		   , boost::python::args("self", "input")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! Ordinary AWGN Channel for cvec or vec inputs and outputs.
  boost::python::class_<itpp::AWGN_Channel>("AWGN_Channel", boost::python::init<double>("Class constructor. Sets the noise variance (for complex-valued channels the sum of real and imaginary parts)",
											boost::python::args("self", "noisevar")))
    .def("set_noise", &itpp::AWGN_Channel::set_noise
	            , "Set noise variance (for complex-valued channels the sum of real and imaginary parts)"
		    , boost::python::args("self", "noisevar"))
    .def("get_noise", &itpp::AWGN_Channel::get_noise
	            , "Get noise variance (for complex-valued channels the sum of real and imaginary parts)"
		    , boost::python::args("self")
                    , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cvec (itpp::AWGN_Channel::*)(const itpp::cvec &)>(&itpp::AWGN_Channel::operator())
	           , "Feed the complex input \a input through the complex-valued AWGN channel"
		   , boost::python::args("self", "input")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::AWGN_Channel::*)(const itpp::vec &)>(&itpp::AWGN_Channel::operator())
	           , "Feed the input \a through the real-valued AWGN channel"
		   , boost::python::args("self", "input")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
