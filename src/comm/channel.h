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

#include <itpp/comm/channel.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_channel_enum( py::module &m ) {

  //! Predefined channel profiles. Includes LOS and Doppler spectrum settings.
  py::enum_<itpp::CHANNEL_PROFILE>( m, "CHANNEL_PROFILE")
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
    .value("COST259_HTx", itpp::COST259_HTx)
  ;

  //! Fading generator type: Independent (default), Static or Correlated.
  py::enum_<itpp::FADING_TYPE>( m, "FADING_TYPE")
    .value("Independent", itpp::Independent)
    .value("Static", itpp::Static)
    .value("Correlated", itpp::Correlated)
  ;

  //! Correlated fading generation methods: Rice_MEDS (default), IFFT or FIR.
  py::enum_<itpp::CORRELATED_METHOD>( m, "CORRELATED_METHOD")
    .value("Rice_MEDS", itpp::Rice_MEDS)
    .value("IFFT", itpp::IFFT)
    .value("FIR", itpp::FIR)
  ;

  //! Rice fading generation methods: MEDS.
  py::enum_<itpp::RICE_METHOD>( m, "RICE_METHOD")
    .value("MEDS", itpp::MEDS)
  ;

  //! Predefined Doppler spectra
  py::enum_<itpp::DOPPLER_SPECTRUM>( m, "DOPPLER_SPECTRUM")
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
}

void generate_pybind_wrapper_for_itpp_fading_generator_class( py::module &m ) {

  // Fading generator class
  py::class_<itpp::Fading_Generator>( m, "Fading_Generator",
 				     "Abstract base class defining the interface of a single tap fading generator. "
				     " Besides pure interface methods it implements a common set_LOS_power() method "
				     " for setting up the Rice factor to be used in fading generators, which inherit from this class.")
    //py::no_init

    .def("set_LOS_power", &itpp::Fading_Generator::set_LOS_power
                        , "Set relative LOS power"
			, py::arg( "relative_power"))
    .def("set_LOS_doppler", &itpp::Fading_Generator::set_LOS_doppler
                          , "Set relative Doppler of the LOS component (for correlated fading generators)"
			  , py::arg( "relative_doppler"))
    .def("set_time_offset", &itpp::Fading_Generator::set_time_offset
                          , "Set time offset in samples (for correlated fading generators)"
			  , py::arg( "offset"))
    .def("set_filter_length", &itpp::Fading_Generator::set_filter_length
                            , "Set FIR filter length (for FIR fading generator)"
			    , py::arg( "filter_length"))
    .def("set_norm_doppler", &itpp::Fading_Generator::set_norm_doppler
                           , "Set normalized Doppler (for correlated fading generators). The normalized Doppler is defined as the multiplication of the maximum Doppler frequency by the sampling time "
			   , py::arg( "norm_doppler"))
    .def("set_doppler_spectrum", &itpp::Fading_Generator::set_doppler_spectrum
                               , "Set Doppler spectrum (for Rice fading generator)"
			       , py::arg( "spectrum"))
    .def("set_no_frequencies", &itpp::Fading_Generator::set_no_frequencies
                             , "Set number of sine frequencies (for Rice fading generator)"
			     , py::arg( "no_freq"))
    .def("set_rice_method", &itpp::Fading_Generator::set_rice_method
                          , "Set calculation method of Doppler frequencies and amplitudes (for Rice fading generator)"
			  , py::arg( "method"))

    .def("get_LOS_power", &itpp::Fading_Generator::get_LOS_power
                        , "Get relative power of LOS component (Rice factor)")
    .def("get_LOS_doppler", &itpp::Fading_Generator::get_LOS_doppler
                          , "Get relative Doppler of the LOS component (for correlated fading generators)")
    .def("get_time_offset", &itpp::Fading_Generator::get_time_offset
	                  , "Get time offset in samples (for correlated fading generators)")
    .def("get_filter_length", &itpp::Fading_Generator::get_filter_length
	                    , "Set FIR filter length (for FIR fading generator)")
    .def("get_norm_doppler", &itpp::Fading_Generator::get_norm_doppler
	                   , "Return normalized Doppler (for correlated fading generators)")
    .def("get_doppler_spectrum", &itpp::Fading_Generator::get_doppler_spectrum
                               , "Return Doppler spectrum (for Rice fading generator)")
    .def("get_no_frequencies", &itpp::Fading_Generator::get_no_frequencies
                             , "Get number of sine frequencies (for Rice fading generator)")
    .def("get_rice_method", &itpp::Fading_Generator::get_rice_method
                          , "Get calculation method of Doppler frequencies and amplitudes (for Rice fading generator)")

    .def("shift_time_offset", &itpp::Fading_Generator::shift_time_offset
                            , "Shift generator time offset by a number of samples (for correlated fading generators)"
			    , py::arg( "no_samples"))

    .def("init", &itpp::Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Fading_Generator::generate)
                   , "Generate \a no_samples values from the fading process"
		   , py::arg( "no_samples"), py::arg("output"))
    .def("generate", static_cast<itpp::cvec (itpp::Fading_Generator::*)(int)>(&itpp::Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , py::arg( "nrof_samples"))

  ;
}

void generate_pybind_wrapper_for_independent_fading_generator_class( py::module &m ) {

  py::class_<itpp::Independent_Fading_Generator, itpp::Fading_Generator>( m, "Independent_Fading_Generator"
						   " Independent (random) fading generator class."
						   " This class implements the intependent fading generator, which can be"
						   " used on each tap of the TDL channel model. This generator produces a"
						   " set of independent Rayleigh or Rice distributed channel coefficients.")

    .def( py::init<>(), "Default constructor" )
    .def("init", &itpp::Independent_Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::Independent_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Independent_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , py::arg( "nrof_samples"), py::arg("output"))
  ;
}

void generate_pybind_wrapper_for_static_fading_generator_class( py::module &m ) {
  py::class_<itpp::Static_Fading_Generator, itpp::Fading_Generator>( m, "Static_Fading_Generator"
					      , " Static fading generator class."
					        " This class implements the static fading generator, which can be used on "
					        " each tap of the TDL channel model. This generator produces a set of identical "
					        " (static) Rayleigh or Rice distributed channel coefficients.")

    .def( py::init<>(), "Default constructor" )
    .def("init", &itpp::Static_Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::Static_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Static_Fading_Generator::generate)
                   , "Generate \a no_samples values from the fading process"
		   , py::arg( "nrof_samples"), py::arg("output"))
  ;

}

void generate_pybind_wrapper_for_correlated_fading_generator_class( py::module &m ) {

  // Correlated (random) fading generator class
  py::class_<itpp::Correlated_Fading_Generator, itpp::Fading_Generator>( m, "Correlated_Fading_Generator"
						  ,  " Correlated fading generator class implements an abstract "
						     " interface for a set of generators. Parameter that define "
						     " the correlated fading process are the normalized Doppler "
						     " and optionally the relative Doppler of a LOS component."
						     " References:[Pat02] Matthias Patzold, Mobile fading channels, Wiley, 2002.")
    //py::no_init
    .def("set_norm_doppler", &itpp::Correlated_Fading_Generator::set_norm_doppler
                           , "Set normalized Doppler"
			   , py::arg( "norm_doppler"))
    .def("set_LOS_doppler", &itpp::Correlated_Fading_Generator::set_LOS_doppler
                          , "Set relative Doppler (compared to the maximum Doppler) for the LOS component"
                          , py::arg( "relative_doppler"))
    .def("set_time_offset", &itpp::Correlated_Fading_Generator::set_time_offset
                          , "Set time offset in samples"
			  , py::arg( "offset"))

    .def("get_norm_doppler", &itpp::Correlated_Fading_Generator::get_norm_doppler
	                   , "Return normalized Doppler")
			    
    .def("get_LOS_doppler", &itpp::Correlated_Fading_Generator::get_LOS_doppler
                          , "Get relative Doppler (compared to the maximum doppler) for the LOS component")
			   
    .def("get_time_offset", &itpp::Correlated_Fading_Generator::get_time_offset
	                  , "Get time offset in samples")

    .def("shift_time_offset", &itpp::Correlated_Fading_Generator::shift_time_offset
	                    , "Shift generator time offset by a number of samples"
			    , py::arg( "no_samples"))

    .def("init", &itpp::Correlated_Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::Correlated_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Correlated_Fading_Generator::generate)
                   , "Generate \a no_samples values from the fading process")
  ;
}

void generate_pybind_wrapper_for_rice_fading_generator_class( py::module &m ) {
  // Rice type fading generator class
  py::class_<itpp::Rice_Fading_Generator, itpp::Correlated_Fading_Generator>( m, "Rice_Fading_Generator"
					    , " A Rice generator is a generator of the form:"
					      " [ tilde mu_i(t) = sum_{n=1}^{N_i} c_{i,n} cos(2pi f_{i,n} t + theta_{i,n})]"
					      " Here $ c_{i,n} $, $ f_{i,n} $, and $ \theta_{i,n} $ are the Doppler coefficients, "
					      " discrete Doppler frequencies, and Doppler phases, respectively. Rice showed that "
					      " a generator of this form can perfectly model a Gaussian process when $ N_i -> infty $. "
					      " When generating a fading pattern we need a complex-valued generator "
					      " [tilde mu(t) = tilde mu_1(t) + j tilde mu_2(t) f]"
					      " Parameters that define the generator are the normalized Doppler and the doppler spectrum. "
					      " Possible values of the Doppler spectrum are: Jakes, J, Classic, C: The classical Jakes spectrum shape."
					      " This method can be also used for modelling LOS paths, by setting the LOS relative power (Rice factor) "
					      " and LOS Doppler parameters. GaussI, GI, Gauss1, G1"
					      ""
					      " GaussII, GII, Gauss2, G2. Furthermore also the number of sine waves, $ N_i $ and method used to calculate "
					      " the parameters $ c_{i,n} $, $ f_{i,n} $, and $theta_{i,n} $ can be specified. For now the only method defined "
					      " for calculating the parameters is the Method of Exact Doppler Spread (MEDS). See [Pat02] for more details."
					      ""
					      " References: [Pat02] Matthias Patzold, Mobile fading channels, Wiley, 2002.")

    .def( py::init<double, itpp::DOPPLER_SPECTRUM, int, itpp::RICE_METHOD>(), "Default constructor"
		                                                            , py::arg( "norm_doppler"), py::arg("spectrum"), py::arg("no_freq"), py::arg("method"))
    .def("set_doppler_spectrum", &itpp::Rice_Fading_Generator::set_doppler_spectrum
	                       , "Set Doppler spectrum"
			       , py::arg( "spectrum"))
    .def("set_no_frequencies", &itpp::Rice_Fading_Generator::set_no_frequencies
	                     , "Set number of Doppler frequencies"
			     , py::arg( "no_freq"))
    .def("set_rice_method", &itpp::Rice_Fading_Generator::set_rice_method
	                  , "Set calculation method of Doppler frequencies and amplitudes"
			  , py::arg( "method"))

    .def("get_doppler_spectrum", &itpp::Rice_Fading_Generator::get_doppler_spectrum
	                       , "Return Doppler spectrum")
			        
    .def("get_no_frequencies", &itpp::Rice_Fading_Generator::get_no_frequencies
	                     , "Get number of Doppler frequencies")
			      
    .def("get_rice_method", &itpp::Rice_Fading_Generator::get_rice_method
	                  , "Get calculation method of Doppler frequencies and amplitudes")
			   

    .def("init", &itpp::Rice_Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::Rice_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::Rice_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , py::arg( "no_samples"), py::arg("output"))
  ;
}

void generate_pybind_wrapper_for_fir_fading_generator_class( py::module &m ) {
  //! FIR type Fading generator class
  py::class_<itpp::FIR_Fading_Generator, itpp::Correlated_Fading_Generator>( m, "FIR_Fading_Generator"
					   , " A FIR generator is a linear finite impulse response (FIR) filter implementation "
				   	     " of a filter method for generation of a fading process. Parameters that define the "
					     " generator are the normalized Doppler and length of the FIR filter. "
					     " The default value of filter length is 500. If the normalized Doppler frequency "
					     " is lower than 0.1 an equivalent process of a higher normalized Doppler is generated "
					     " and linearly interpolated.")
    .def( py::init<double, int>(), "Default constructor"
		                 , py::arg( "norm_doppler"), py::arg("filter_length"))
    .def("set_filter_length", &itpp::FIR_Fading_Generator::set_filter_length
                            , "Set FIR filter length"
			    , py::arg( "filter_length"))
    .def("get_filter_length", &itpp::FIR_Fading_Generator::get_filter_length
	                    , "Get filter length")

    .def("init", &itpp::FIR_Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::FIR_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::FIR_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , py::arg( "no_samples"), py::arg("output"))
  ;
}

void generate_pybind_wrapper_for_ifft_fading_generator_class( py::module &m ) {
  //! IFFT type Fading generator class
  py::class_<itpp::IFFT_Fading_Generator, itpp::Correlated_Fading_Generator>( m, "IFFT_Fading_Generator"
					    , " A IFFT generator is a frequency domain filter implementation of filter"
					      " method for generation of a fading process. Parameters that define the"
					      " generator is the normalized Doppler."
					      ""
					      " The method is block-based and consecutive blocks are independent fading. "
					      " The method is very efficient for large blocks. The size of the FFT, "
					      " $ N_fft $, is given by the nearest higher integer power of two that is "
					      " larger than no_samples. For small blocks the FFT size is increased to keep "
					      " a good accuracy (at least 10 samples in the representation of the Doppler "
					      " spectrum). However, to keep the program reasonably efficient the largest "
					      " upsampling factor is 64. Higher factors will result in a run-time error. "
					      " If so, please use another method." )

    .def( py::init<double>(), "Default constructor"
		            , py::arg( "norm_doppler"))
    .def("init", &itpp::IFFT_Fading_Generator::init
	       , "Initialize the generator")

    .def("generate", static_cast<void (itpp::IFFT_Fading_Generator::*)(int, itpp::cvec &)>(&itpp::IFFT_Fading_Generator::generate)
	           , "Generate \a no_samples values from the fading process"
		   , py::arg( "no_samples"), py::arg("output"))
  ;
}

void generate_pybind_wrapper_for_channel_specification_class( py::module &m ) {
  //! General specification of a time-domain multipath channel
  py::class_<itpp::Channel_Specification>( m, "Channel_Specification",
					  " This class does NOT generate any channel values. It is only used to specify the channel model. "
					  " To generate channel coefficients use the Tapped-Delay Line (TDL) class TDL_Channel. A time invariant "
					  " (or at least wide-sense stationary) channel have an impulse response that can be modeled as:"
					  " [ h(t) = sum_{k=0}^{N_taps-1} a_k exp (-j theta_k) delta(t-tau_k)]"
					  " where $ N_{taps} $ is the number of channel taps, $ a_k $ is the average amplitude at delay "
					  " $ \tau_k $, and $ \theta_k $ is the channel phase of the $ k^{th} $ channel tap. The average power"
					  " profile, and the delay profiles are defined as:"
					  " [ a = [a_0, a_1, ..., a_{N_taps-1}]] and [ tau = [tau_0, tau_1, ..., tau_{N_{taps}-1}],] respectively. "
					  " We assume without loss of generality that $ tau_0 = 0$ and $ tau_0 < tau_1 < ... < tau_{N_{taps}-1} $."
					  ""
					  " To initialize the class the following parameters should be defined\n"
					  " - avg_power_dB Average power profile $ a $, given in dB \n"
					  " - delay_profile Delay profile $ tau $, given in seconds. The delay profile should be sorted (increasing delay) "
					  " and the first delay has to be 0."
					  ""
					  " Optionally one can define LOS parameters: relative_power and \a relative_doppler, and additionally the kind "
					  " of Doppler spectrum for each tap."
					  ""
					  " It is also possible to specify a predefined channel model. The implemented ones are as follows:\n"
					  " - ITU Channel models: \n"
					  "   - ITU_Vehicular_A, 6-tap channel\n"
					  "   - ITU_Vehicular_B, 6-tap channel\n"
					  "   - ITU_Pedestrian_A, 4-tap channel\n"
					  "   - ITU_Pedestrian_B, 6-tap channel\n"
					  " - COST 207 Channel models (see [Pat02] pp. 259-266):\n"
					  "   - COST207_RA, Rural area, 4-tap channel\n"
					  "   - COST207_RA6, Rural area, 6-tap channel\n"
					  "   - COST207_TU, Typical urban, 6-tap channel\n"
					  "   - COST207_TU6alt, Typical urban, alternative 6-tap channel\n"
					  "   - COST207_TU12, Typical urban, 12-tap channel\n"
					  "   - COST207_TU12alt, Typical urban, alternative 12-tap channel\n"
					  "   - COST207_BU, Bad urban, 6-tap channel\n"
					  "   - COST207_BU6alt, Bad urban, alternative 6-tap channel\n"
					  "   - COST207_BU12, Bad urban, 12-tap channel\n"
					  "   - COST207_BU12alt, Bad urban, alternative 12-tap channel\n"
					  "   - COST207_HT, Hilly terrain, 6-tap channel\n"
					  "   - COST207_HT6alt, Hilly terrain, alternative 6-tap channel\n"
					  "   - COST207_HT12, Hilly terrain, 12-tap channel\n"
					  "   - COST207_HT12alt, Hilly terrain, alternative 12-tap channel\n"
					  " - COST 259 Channel models (see [3GPP_TR_25.943]):\n"
					  "   - COST259_TUx, Typical urban, 20-tap channel\n"
					  "   - COST259_RAx, Rural ara, 10-tap channel\n"
					  "   - COST259_HTx, Hilly terrain, 20-tap channel\n" )

    .def( py::init<const itpp::vec &, const itpp::vec &>(), "Default constructor (power profile in dB, delay profile in seconds)"
		                                          , py::arg( "avg_power_dB"), py::arg("delay_prof"))

    .def(py::init<const itpp::CHANNEL_PROFILE>(), "Initialize with predetermined channel profile"
			                        , py::arg( "profile"))

    .def("set_channel_profile", static_cast<void (itpp::Channel_Specification::*)(const itpp::vec &, const itpp::vec &)>(&itpp::Channel_Specification::set_channel_profile)
	                      , "Set both average power profile in dB and power delay profile in seconds"
			      , py::arg( "avg_power_dB"), py::arg("delay_prof"))
    .def("set_channel_profile", static_cast<void (itpp::Channel_Specification::*)(itpp::CHANNEL_PROFILE)>(&itpp::Channel_Specification::set_channel_profile)
	                      , "Set channel profile to a predetermined profile"
			      , py::arg( "profile"))

    .def("set_doppler_spectrum", static_cast<void (itpp::Channel_Specification::*)(itpp::DOPPLER_SPECTRUM *)>(&itpp::Channel_Specification::set_doppler_spectrum)
	                       , "Set doppler spectrum for each tap in the channel profile"
			       , py::arg( "tap_spectrum"))
    .def("set_doppler_spectrum", static_cast<void (itpp::Channel_Specification::*)(int, itpp::DOPPLER_SPECTRUM)>(&itpp::Channel_Specification::set_doppler_spectrum)
	                       , "Set doppler spectrum for tap \a tap_number in the channel profile."
			       , py::arg( "tap_number"), py::arg("tap_spectrum"))

    .def("set_LOS", static_cast<void (itpp::Channel_Specification::*)(int, double, double)>(&itpp::Channel_Specification::set_LOS)
	          , "Set LOS (Rice) components for tap \a tap_number"
		  , py::arg( "tap_number"), py::arg("relative_power"), py::arg("relative_doppler"))
    .def("set_LOS", static_cast<void (itpp::Channel_Specification::*)(const itpp::vec &, const itpp::vec &)>(&itpp::Channel_Specification::set_LOS)
	          , "Set LOS (Rice) components for all taps"
		  , py::arg( "relative_power"), py::arg("relative_doppler"))

    .def("get_channel_profile", &itpp::Channel_Specification::get_channel_profile
                              , "Get both average power profile in dB and power delay profile in samples"
                              , py::arg( "avg_power_dB"), py::arg("delay_prof"))
    .def("get_avg_power_dB", &itpp::Channel_Specification::get_avg_power_dB
	                   , "Return power profile in dB")
			    
    .def("get_delay_prof", &itpp::Channel_Specification::get_delay_prof
	                 , "Return delay profile in seconds")

    .def("get_doppler_spectrum", static_cast<itpp::Array<itpp::DOPPLER_SPECTRUM> (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_doppler_spectrum)
	                       , "Get doppler spectrum for tap \a index")
			        
    .def("get_doppler_spectrum", static_cast<itpp::DOPPLER_SPECTRUM (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_doppler_spectrum)
	                       , "Get doppler spectrum for tap \a index"
			       , py::arg( "index"))

    .def("get_LOS_power", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_power)
	                , "Get relative power (Rice factor) for each tap")

    .def("get_LOS_doppler", static_cast<itpp::vec (itpp::Channel_Specification::*)() const>(&itpp::Channel_Specification::get_LOS_doppler)
	                  , "Get relative Doppler for each tap")

    .def("get_LOS_power", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_power)
	                , "Get relative power (Rice factor) for tap \a tap_number"
			, py::arg( "tap_number"))
    .def("get_LOS_doppler", static_cast<double (itpp::Channel_Specification::*)(int) const>(&itpp::Channel_Specification::get_LOS_doppler)
	                  , "Get relative Doppler for tap \a tap_number"
			  , py::arg( "tap_number"))

    .def("taps", &itpp::Channel_Specification::taps
	       , "Return the number of channel taps")

    .def("calc_mean_excess_delay", &itpp::Channel_Specification::calc_mean_excess_delay
	                         , "Calculate mean excess delay in samples")
    .def("calc_rms_delay_spread", &itpp::Channel_Specification::calc_rms_delay_spread
	                        , "Calculate RMS delay spread in samples")

  ;
}

void generate_pybind_wrapper_for_itpp_tdl_class( py::module &m ) {
  //! Tapped Delay Line (TDL) channel model
  py::class_<itpp::TDL_Channel>( m, "TDL_Channel"
		                  , " A time invariant (or at least wide-sense stationary) channel have an impulse response that can be modeled as:"
				   " [ h(t) = sum_{k=0}^{N_{taps}-1} a_k exp (-j theta_k ) delta(t-tau_k), ] where $ N_{taps} $ is the number of channel taps, "
				   " $ a_k $ is the average amplitude at delay $ tau_k $, and $ theta_k $ is the channel phase of the $ k^{th} $ channel tap. "
				   " The average power profile, and delay profile are defined as: [{a} = [a_0, a_1, ..., a_{N_{taps}-1}] ] and"
				   " [ {tau} = [tau_0, tau_1, ..., tau_{N_{taps}-1}],] respectively. We assume without loss of generality that "
				   " $ tau_0 = 0 $ and $ tau_0 < tau_1 < ... < tau_{N_{taps}-1}$."
				   ""
				   " To initialize the channel profile the following parameters should be defined:"
				   " - avg_power_dB Average power profile $ {a} $, given in dB\n"
				   " - delay_profile Delay profile $ {\tau} $, given in samples.\n"
				   " The delay profile should be sorted (increasing delay) and the first delay has to be 0."
				   ""
				   " In the case of correlated channel, the correlation in time is decided by the normalized Doppler frequency and Doppler spectrum. "
				   " The normalized Doppler frequency is calculated as $ f_{max} T_s $, where $ f_{max} $ is the maximum Doppler frequency and"
				   " $ T_s $ is the sample duration."
				   ""
				   " Two main types of generation methods exist: the filter method and Rice method. In the filter method the correlated fading process "
				   " is generated with a filtering of the complex Gaussian process to achieve a given Doppler spectrum (Jakes by default). "
				   " Currently there are two filter implementations:\n"
				   " - FIR - Finite Impulse Response (FIR) filter. Rather slow and inaccurate. Use with care.\n"
				   " - IFFT - Blockwise filtering in the frequency-domain. Consecutive blocks have independent fading. Very efficient method for large blocks."
				   ""
				   " The preferred method for generating the correlated fading process is the Rice method that approximate the fading process as a sum of"
				   " sinusoids. Currently there is only one implementation, the Rice Method of Exact Doppler Spread (Rice_MEDS), which is also the default "
				   " choice."
				   ""
				   " To summarize, the currently supported correlated fading generation methods are:\n"
				   " - FIR - filter FIR method\n"
				   " - IFFT - filter IFFT method\n"
				   " - Rice_MEDS - sum of sine waves MEDS method"
				   ""
				   " Beside the above described correlated methods, two additional fading generators exists: the Independent_Fading_Generator and"
				   "  Static_Fading_Generator ones. Their names are self-explanatory. The only optional parameter of these two generators is a "
				   " relative_power of the LOS component.")

    .def( py::init<const itpp::vec &, const itpp::ivec &>(), "Default constructor"
		                                           , py::arg( "avg_power_dB"), py::arg("delay_prof"))
    .def( py::init<const itpp::Channel_Specification &, double>(), "Constructor with defined Channel_Specification. Delay profile will be discretized with \a sampling_time in seconds."
	                                                         , py::arg( "channel_spec"), py::arg("sampling_time"))

    .def("set_channel_profile", static_cast<void (itpp::TDL_Channel::*)(const itpp::vec &, const itpp::ivec &)>(&itpp::TDL_Channel::set_channel_profile)
	                      , "Set both average power profile in dB and power delay profile in samples"
			      , py::arg( "avg_power_dB") , py::arg("delay_prof"))
    .def("set_channel_profile_uniform", &itpp::TDL_Channel::set_channel_profile_uniform
	                              , "Set channel profile to uniform with \a no_taps taps"
				      , py::arg( "no_taps"))
    .def("set_channel_profile_exponential", &itpp::TDL_Channel::set_channel_profile_exponential
	                                  , "Set channel profile to exponential with \a no_taps taps"
					  , py::arg( "no_taps"))
    .def("set_channel_profile", static_cast<void (itpp::TDL_Channel::*)(const itpp::Channel_Specification &, double)>(&itpp::TDL_Channel::set_channel_profile)
	                      , "Set channel profile using Channel_Specification. Delay profile will be discretized with \a sampling_time in seconds."
			      , py::arg( "channel_spec"), py::arg("sampling_time"))

    .def("set_correlated_method", &itpp::TDL_Channel::set_correlated_method
	                        , "Set the fading generation method to \a method"
				, py::arg( "method"))
    .def("set_fading_type", &itpp::TDL_Channel::set_fading_type
	                  , "Set fading type to one of \a Independent, \a Static or \a Correlated"
			  , py::arg( "fading_type"))

    .def("set_norm_doppler", &itpp::TDL_Channel::set_norm_doppler
	                   , "Set normalized Doppler rate. A \a Correlated fading type will be used."
			   , py::arg( "norm_doppler"))

    .def("set_LOS", &itpp::TDL_Channel::set_LOS
	          , "Set LOS parameters for each tap. LOS Doppler will be set to 0.7 by default."
		  , py::arg("relative_power"), py::arg("relative_dopper"))
    .def("set_LOS_power", &itpp::TDL_Channel::set_LOS_power
	                , "Set LOS power for each tap. LOS Doppler will be set to 0.7 by default."
			, py::arg( "relative_power"))
    .def("set_LOS_doppler", &itpp::TDL_Channel::set_LOS_doppler
	                  , "Set LOS doppler for each tap. A \a Correlated fading type will be used."
			  , py::arg( "relative_doppler"))

    .def("set_doppler_spectrum", static_cast<void (itpp::TDL_Channel::*)(const itpp::DOPPLER_SPECTRUM *)>(&itpp::TDL_Channel::set_doppler_spectrum)
	                       , "Set doppler spectrum for each tap in the channel profile. \a Rice_MEDS method will be used."
			       , py::arg( "tap_spectrum"))
    .def("set_doppler_spectrum", static_cast<void (itpp::TDL_Channel::*)(int, itpp::DOPPLER_SPECTRUM)>(&itpp::TDL_Channel::set_doppler_spectrum)
	                       , "Set doppler spectrum of tap \a tap_number. \a Rice_MEDS method will be used."
			       , py::arg( "tap_number"), py::arg("tap_spectrum"))
    .def("set_no_frequencies", &itpp::TDL_Channel::set_no_frequencies
	                     , "Set number of sine frequencies. \a Rice_MEDS method will be used."
			     , py::arg( "no_freq"))

    .def("set_time_offset", &itpp::TDL_Channel::set_time_offset
	                  , "Set fading generators' time offset in samples. A \a Correlated fading type will be used."
			  , py::arg( "offset"))
    .def("shift_time_offset", &itpp::TDL_Channel::shift_time_offset
	                    , "Shift fading generators' time offset. A \a Correlated fading type will be used."
			    , py::arg( "no_samples"))

    .def("set_filter_length", &itpp::TDL_Channel::set_filter_length
	                    , "Set fading generator filter length. \a FIR method will be used."
			    , py::arg( "filter_length"))

    .def("taps", &itpp::TDL_Channel::taps
	       , "Return the number of channel taps")

    .def("get_channel_profile", &itpp::TDL_Channel::get_channel_profile
	                      , "Get both average power profile in dB and power delay profile in samples"
			      , py::arg( "avg_power_dB"), py::arg("delay_prof"))
    .def("get_avg_power_dB", &itpp::TDL_Channel::get_avg_power_dB
	                   , "Return power profile in dB")
			    
    .def("get_delay_prof", &itpp::TDL_Channel::get_delay_prof
	                 , "Return delay profile in samples")

    .def("get_correlated_method", &itpp::TDL_Channel::get_correlated_method
	                        , "Return fading generation method")
				 
    .def("get_fading_type", &itpp::TDL_Channel::get_fading_type
	                  , "Return fading type")

    .def("get_norm_doppler", &itpp::TDL_Channel::get_norm_doppler
	                   , "Return normalized doppler rate")

    .def("get_LOS_power", static_cast<itpp::vec (itpp::TDL_Channel::*)() const>(&itpp::TDL_Channel::get_LOS_power)
	                , "Get relative power (Rice factor) for each tap")
		         
    .def("get_LOS_doppler", static_cast<itpp::vec (itpp::TDL_Channel::*)() const>(&itpp::TDL_Channel::get_LOS_doppler)
	                  , "Get relative Doppler (to the maximum Doppler) for each tap")
			   
    .def("get_LOS_power", static_cast<double (itpp::TDL_Channel::*)(int) const>(&itpp::TDL_Channel::get_LOS_power)
                        , "Get relative power (Rice factor) for tap \a tap_number"
			, py::arg( "tap_number"))

    .def("get_LOS_doppler", static_cast<double (itpp::TDL_Channel::*)(int) const>(&itpp::TDL_Channel::get_LOS_doppler)
	                  , "Get relative Doppler (to the maximum Doppler) for tap \a tap_number"
			  , py::arg( "tap_number"))

    .def("get_no_frequencies", &itpp::TDL_Channel::get_no_frequencies
	                     , "Get the minimum number of frequencies used in Rice MEDS fading generator")

    .def("get_time_offset", &itpp::TDL_Channel::get_time_offset
	                  , "Get fading generators' time ofset")
			   
    .def("calc_mean_excess_delay", &itpp::TDL_Channel::calc_mean_excess_delay
	                         , "Calculate mean excess delay in samples")
				  
    .def("calc_rms_delay_spread", &itpp::TDL_Channel::calc_rms_delay_spread
	                        , "Calculate RMS delay spread in samples")
				 
    .def("init", &itpp::TDL_Channel::init
	       , "Initialize all fading generators. Automatically invoked in generate() or filter() functions.")

    .def("generate", static_cast<void (itpp::TDL_Channel::*)(int, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::generate)
	           , "Generate \a no_samples values of the channel"
		   , py::arg( "no_samples"), py::arg("channel_coeff"))
    .def("generate", static_cast<void (itpp::TDL_Channel::*)(int, itpp::cmat &)>(&itpp::TDL_Channel::generate)
	           , "Generate \a no_samples values of the channel. Returns the matrix with one tap per column."
		   , py::arg( "no_samples"), py::arg("channel_coeff"))

    .def("filter_known_channel", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, const itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter_known_channel)
	                       , "Filter the \a input with the known channel values \a channel_coeff (e.g. from the generate function)"
			       , py::arg( "input"), py::arg("output"), py::arg("channel_coeff"))
    .def("filter_known_channel", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, const itpp::cmat &)>(&itpp::TDL_Channel::filter_known_channel)
	                       , "Filter the \a input with the known channel values \a channel_coeff (e.g. from the generate function)"
			       , py::arg( "input"), py::arg("output"), py::arg("channel_coeff"))

    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , py::arg( "input"), py::arg("output"), py::arg("channel_coeff"))
    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , py::arg( "input"), py::arg("output"), py::arg("channel_coeff"))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , py::arg( "input"), py::arg("channel_coeff"))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		 , py::arg( "input"), py::arg("channel_coeff"))
    .def("filter", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Only return the output"
		 , py::arg( "input"), py::arg("output"))
    .def("filter", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &)>(&itpp::TDL_Channel::filter)
	         , "Generate channel coefficients and filter the \a input. Only return the output"
		 , py::arg( "input"))

    .def("__call__", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , py::arg( "input"), py::arg("output"), py::arg("channel_coeff"))
    .def("__call__", static_cast<void (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , py::arg( "input"), py::arg("output"), py::arg("channel_coeff"))
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::Array<itpp::cvec> &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , py::arg( "input"), py::arg("channel_coeff"))
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &, itpp::cmat &)>(&itpp::TDL_Channel::operator())
	           ,"Generate channel coefficients and filter the \a input. Return output and channel coefficients"
		   , py::arg( "input"), py::arg("channel_coeff"))
    .def("__call__", static_cast<itpp::cvec (itpp::TDL_Channel::*)(const itpp::cvec &)>(&itpp::TDL_Channel::operator())
	           , "Generate channel coefficients and filter the \a input. Only return output"
		   , py::arg( "input"))

    .def("calc_impulse_response", &itpp::TDL_Channel::calc_impulse_response
	                        , "Calculate impulse-response on the supplied channel coefficients (produced by the generate() function)"
				, py::arg( "channel_coeff"), py::arg("impulse_response"))

    .def("calc_frequency_response", static_cast<void (itpp::TDL_Channel::*)(const itpp::Array<itpp::cvec> &, itpp::Array<itpp::cvec> &, const int)>(&itpp::TDL_Channel::calc_frequency_response)
	                          , "Calculate frequency-response on the supplied channel coefficients (produced by the generate() function)"
				  , py::arg( "channel_coeff"), py::arg("frequency_response"), py::arg("fft_size"))
    .def("calc_frequency_response", static_cast<void (itpp::TDL_Channel::*)(const itpp::cmat &, itpp::cmat &, const int)>(&itpp::TDL_Channel::calc_frequency_response)
	                          , "Calculate frequency-response on the supplied channel coefficients (produced by the generate() function)"
				  , py::arg( "channel_coeff"), py::arg("frequency_response"), py::arg("fft_size"))
    .def("get_sampling_time", &itpp::TDL_Channel::get_sampling_time
	                    , "Return channel sampling time (used for discretization)")

  ;
}

void generate_pybind_wrapper_for_itpp_bsc_class( py::module &m ) {
  py::class_<itpp::BSC>( m, "BSC",
			"A Binary Symetric Channel with crossover probability p. Input and output are of type \a bvec with 0 and 1.")
    .def(py::init<double>(), "Class constructor. Sets the error probability to p"
	                   , py::arg( "in_p"))
    .def("set_prob", &itpp::BSC::set_prob
	           , "Set crossover (bit error) probability"
		   , py::arg( "in_p"))
    .def("get_prob", &itpp::BSC::get_prob
	           , "Get crossover (bit error) probability")
		    
    .def("__call__", &itpp::BSC::operator()
	           , "Feed \a input through the BSC channel"
		   , py::arg( "input"))
  ;
}

void generate_pybind_wrapper_for_itpp_awgn_channel_class( py::module &m ) {
  py::class_<itpp::AWGN_Channel>( m, "AWGN_Channel",
				 "Ordinary AWGN Channel for cvec or vec inputs and outputs. For real signals, the input parameter (\a noisevar) denotes the noise"
				 " variance per real dimension. Therefore, it should be set to $N_0/2$, where $N_0$ is the noise power spectral density. "
				 " However, in case of complex signals, the input parameter (\a noisevar) represents the noise variance per complex dimension, "
				 " i.e. the sum of the variances in the real and imaginary parts, and thus is equal to \f$N_0\f$.")

    .def(py::init<double>(), "Class constructor. Sets the noise variance (for complex-valued channels the sum of real and imaginary parts)"
		           , py::arg( "noisevar"))
    .def("set_noise", &itpp::AWGN_Channel::set_noise
	            , "Set noise variance (for complex-valued channels the sum of real and imaginary parts)"
		    , py::arg( "noisevar"))
    .def("get_noise", &itpp::AWGN_Channel::get_noise
	            , "Get noise variance (for complex-valued channels the sum of real and imaginary parts)")
		     
    .def("__call__", static_cast<itpp::cvec (itpp::AWGN_Channel::*)(const itpp::cvec &)>(&itpp::AWGN_Channel::operator())
	           , "Feed the complex input \a input through the complex-valued AWGN channel"
		   , py::arg( "input"))
    .def("__call__", static_cast<itpp::vec (itpp::AWGN_Channel::*)(const itpp::vec &)>(&itpp::AWGN_Channel::operator())
	           , "Feed the input \a through the real-valued AWGN channel"
		   , py::arg( "input"))
  ;
}
