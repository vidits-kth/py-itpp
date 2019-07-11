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

#include "modulator.h"

PYBIND11_MODULE( modulator, m )
{
  // Soft demodulation methods
  py::enum_<itpp::Soft_Method>( m, "Soft_Method" )
      .value("LOGMAP", itpp::LOGMAP)
      .value("APPROX", itpp::APPROX)
  ;

  //! Definition of 1D Modulator (with real symbols)
  generate_pybind_wrapper_for_itpp_modulator_class<double>( m, "modulator_1d");

  //! Definition of 1D Modulator (with integer symbols)
  generate_pybind_wrapper_for_itpp_modulator_class<int>( m, "modulator_1d_int");

  //! Definition of 2D Modulator (with complex symbols)
  generate_pybind_wrapper_for_itpp_modulator_class<std::complex<double> >( m, "modulator_2d");

  //! Common Modulator Classes
  generate_pybind_wrapper_for_itpp_qam_class( m );
  generate_pybind_wrapper_for_itpp_psk_class( m );
  generate_pybind_wrapper_for_itpp_qpsk_class( m );
  generate_pybind_wrapper_for_itpp_bpsk_c_class( m );
  generate_pybind_wrapper_for_itpp_bpsk_class( m );
  generate_pybind_wrapper_for_itpp_pam_c_class( m );
  generate_pybind_wrapper_for_itpp_pam_class( m );

}
