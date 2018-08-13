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

#include "circular_buffer.h"

BOOST_PYTHON_MODULE(circular_buffer)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  generate_itpp_circular_buffer_wrapper<double>("circular_buffer");
  generate_itpp_circular_buffer_wrapper<bool>("circular_buffer_b");
  generate_itpp_circular_buffer_wrapper<int>("circular_buffer_i");
  generate_itpp_circular_buffer_wrapper<short int>("circular_buffer_s");
  generate_itpp_circular_buffer_wrapper<std::complex<double> >("circular_buffer_c");
}
