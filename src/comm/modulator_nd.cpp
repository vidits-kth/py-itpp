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

#include "modulator_nd.h"

PYBIND11_MODULE( modulator_nd, m ) {

  // Soft demodulation method
  py::enum_<itpp::Modulator_ND::Soft_Demod_Method>( m, "Soft_Demod_Method")
    .value("FULL_ENUM_LOGMAP", itpp::Modulator_ND::FULL_ENUM_LOGMAP)
    .value("FULL_ENUM_MAXLOG", itpp::Modulator_ND::FULL_ENUM_MAXLOG)
    .value("ZF_LOGMAP", itpp::Modulator_ND::ZF_LOGMAP)
  ;

  generate_pybind_wrapper_for_itpp_modulator_nd_class( m );
  generate_pybind_wrapper_for_itpp_modulator_nrd_class( m );
  generate_pybind_wrapper_for_itpp_modulator_ncd_class( m );
  generate_pybind_wrapper_for_itpp_modulator_nrd_upam_class( m );
  generate_pybind_wrapper_for_itpp_nd_uqam_class( m );
  generate_pybind_wrapper_for_itpp_nd_upsk_class( m );

}
