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

#include "vec.h"


template<class Num_T>
void generate_itpp_vec_wrapper(py::module &m, char const * name) {
  generate_module_functions<Num_T>( m );
  generate_vec_class<Num_T>( m, name );
}

PYBIND11_MODULE(vec, m)
{
  generate_itpp_vec_wrapper<double>(m, "vec");
  generate_itpp_vec_wrapper<std::complex<double> >(m, "cvec");
  generate_itpp_vec_wrapper<int>(m, "ivec");
  generate_itpp_vec_wrapper<itpp::bin>(m, "bvec");
  generate_itpp_vec_wrapper<short int>(m, "svec");
}
