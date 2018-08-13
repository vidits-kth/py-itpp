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

BOOST_PYTHON_MODULE(interleave)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  generate_block_interleaver<double>("block_interleaver_double");
  generate_block_interleaver<short>("block_interleaver_short");
  generate_block_interleaver<int>("block_interleaver_int");
  generate_block_interleaver<std::complex<double> >("block_interleaver_complex");
  generate_block_interleaver<itpp::bin>("block_interleaver_bin");

  generate_cross_interleaver<double>("cross_interleaver_double");
  generate_cross_interleaver<short>("cross_interleaver_short");
  generate_cross_interleaver<int>("cross_interleaver_int");
  generate_cross_interleaver<std::complex<double> >("cross_interleaver_complex");
  generate_cross_interleaver<itpp::bin>("cross_interleaver_bin");

  generate_sequence_interleaver<double>("sequence_interleaver_double");
  generate_sequence_interleaver<short>("sequence_interleaver_short");
  generate_sequence_interleaver<int>("sequence_interleaver_int");
  generate_sequence_interleaver<std::complex<double> >("sequence_interleaver_complex");
  generate_sequence_interleaver<itpp::bin>("sequence_interleaver_bin");
}
