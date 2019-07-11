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

#include "channel.h"

//! Communication Channel Models
PYBIND11_MODULE(channel, m)
{
  //! Enums
  generate_pybind_wrapper_for_itpp_channel_enum( m );
  
  //! Fading Generator Classes
  generate_pybind_wrapper_for_itpp_fading_generator_class( m );
  generate_pybind_wrapper_for_independent_fading_generator_class( m );
  generate_pybind_wrapper_for_static_fading_generator_class( m );
  generate_pybind_wrapper_for_correlated_fading_generator_class( m );
  generate_pybind_wrapper_for_rice_fading_generator_class( m );
  generate_pybind_wrapper_for_fir_fading_generator_class( m );
  generate_pybind_wrapper_for_ifft_fading_generator_class( m );

  //! Channel Specification Class
  generate_pybind_wrapper_for_channel_specification_class( m );

  //! Tapped Delay Line Channel Class
  generate_pybind_wrapper_for_itpp_tdl_class( m );
  
  //! Binasry Symmetric Channel Class
  generate_pybind_wrapper_for_itpp_bsc_class( m );

  //! Additive White Gaussian Noise Channel Class
  generate_pybind_wrapper_for_itpp_awgn_channel_class( m );
}
