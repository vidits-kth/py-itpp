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

#include "interleave.h"

PYBIND11_MODULE( interleave, m )
{
  generate_pybind_wrapper_for_itpp_block_interleaver_class<double>( m, "block_interleaver_double");
  generate_pybind_wrapper_for_itpp_block_interleaver_class<short>( m, "block_interleaver_short");
  generate_pybind_wrapper_for_itpp_block_interleaver_class<int>( m, "block_interleaver_int");
  generate_pybind_wrapper_for_itpp_block_interleaver_class<std::complex<double> >( m, "block_interleaver_complex");
  generate_pybind_wrapper_for_itpp_block_interleaver_class<itpp::bin>( m, "block_interleaver_bin");

  generate_pybind_wrapper_for_itpp_cross_interleaver_class<double>( m, "cross_interleaver_double");
  generate_pybind_wrapper_for_itpp_cross_interleaver_class<short>( m, "cross_interleaver_short");
  generate_pybind_wrapper_for_itpp_cross_interleaver_class<int>( m, "cross_interleaver_int");
  generate_pybind_wrapper_for_itpp_cross_interleaver_class<std::complex<double> >( m, "cross_interleaver_complex");
  generate_pybind_wrapper_for_itpp_cross_interleaver_class<itpp::bin>( m, "cross_interleaver_bin");

  generate_pybind_wrapper_for_itpp_sequence_interleaver_class<double>( m, "sequence_interleaver_double");
  generate_pybind_wrapper_for_itpp_sequence_interleaver_class<short>( m, "sequence_interleaver_short");
  generate_pybind_wrapper_for_itpp_sequence_interleaver_class<int>( m, "sequence_interleaver_int");
  generate_pybind_wrapper_for_itpp_sequence_interleaver_class<std::complex<double> >( m, "sequence_interleaver_complex");
  generate_pybind_wrapper_for_itpp_sequence_interleaver_class<itpp::bin>( m, "sequence_interleaver_bin");
}
