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

#include "random.h"

PYBIND11_MODULE(random, m)
{
//  py::docstring_options local_docstring_options(true, true, false);

  //! Set of functions to work with global seed provider
  m.def("GlobalRNG_reset", static_cast<void (*)(unsigned int)>(&itpp::GlobalRNG_reset));
  m.def("GlobalRNG_reset", static_cast<void (*)()>(&itpp::GlobalRNG_reset));
  m.def("GlobalRNG_get_local_seed", &itpp::GlobalRNG_get_local_seed);
  m.def("GlobalRNG_randomize", &itpp::GlobalRNG_randomize);
  m.def("GlobalRNG_get_state", &itpp::GlobalRNG_get_state);
  m.def("GlobalRNG_set_state", &itpp::GlobalRNG_set_state);

  //! Local (per-thread) RNG context management
  m.def("RNG_reset", static_cast<void (*)(unsigned int)>(&itpp::RNG_reset));
  m.def("RNG_reset", static_cast<void (*)()>(&itpp::RNG_reset));
  m.def("RNG_randomize", &itpp::RNG_randomize);
  m.def("RNG_get_state", &itpp::RNG_get_state);
  m.def("RNG_set_state", &itpp::RNG_set_state);

  //! Wrap RNG Classes
  generate_pybind11_wrapper_for_itpp_random_generator_class( "Random_Generator", m );
  generate_pybind11_wrapper_for_itpp_bernoulli_rng_class( "Bernoulli_RNG", m );
  generate_pybind11_wrapper_for_itpp_i_uniform_rng_class( "I_Uniform_RNG", m );
  generate_pybind11_wrapper_for_itpp_uniform_rng_class( "Uniform_RNG", m );
  generate_pybind11_wrapper_for_itpp_exponential_rng_class( "Exponential_RNG", m );
  generate_pybind11_wrapper_for_itpp_normal_rng_class( "Normal_RNG", m );
  generate_pybind11_wrapper_for_itpp_gamma_rng_class( "Gamma_RNG", m );
  generate_pybind11_wrapper_for_itpp_laplace_rng_class( "Laplace_RNG", m );
  generate_pybind11_wrapper_for_itpp_complex_normal_rng_class( "Complex_Normal_RNG", m );
  generate_pybind11_wrapper_for_itpp_ar1_normal_rng_class( "AR1_Normal_RNG", m );
  generate_pybind11_wrapper_for_itpp_weibull_rng_class( "Weibull_RNG", m );
  generate_pybind11_wrapper_for_itpp_rayleigh_rng_class( "Rayleigh_RNG", m );
  generate_pybind11_wrapper_for_itpp_rice_rng_class( "Rice_RNG", m );

  // typedef Normal_RNG Gauss_RNG; // Handle in Python
  // typedef AR1_Normal_RNG AR1_Gauss_RNG; // Handle in Python

  m.def("randb", static_cast<itpp::bin (*)()>(&itpp::randb));
  m.def("randb", static_cast<void (*)(int, itpp::bvec&)>(&itpp::randb));
  m.def("randb", static_cast<itpp::bvec (*)(int)>(&itpp::randb));
  m.def("randb", static_cast<void (*)(int, int, itpp::bmat&)>(&itpp::randb));
  m.def("randb", static_cast<itpp::bmat (*)(int, int)>(&itpp::randb));

  m.def("randu", static_cast<double (*)()>(&itpp::randu));
  m.def("randu", static_cast<void (*)(int, itpp::vec &)>(&itpp::randu));
  m.def("randu", static_cast<itpp::vec (*)(int)>(&itpp::randu));
  m.def("randu", static_cast<void (*)(int, int, itpp::mat &)>(&itpp::randu));
  m.def("randu", static_cast<itpp::mat (*)(int, int)>(&itpp::randu));

  m.def("randi", static_cast<int (*)(int, int)>(&itpp::randi));
  m.def("randi", static_cast<itpp::ivec (*)(int, int, int)>(&itpp::randi));
  m.def("randi", static_cast<itpp::imat (*)(int, int, int, int)>(&itpp::randi));

  m.def("randray", &itpp::randray);

  m.def("randrice", &itpp::randrice);

  m.def("randexp", itpp::randexp);

  m.def("randn", static_cast<double (*)()>(&itpp::randn));
  m.def("randn", static_cast<void (*)(int, itpp::vec &)>(&itpp::randn));
  m.def("randn", static_cast<itpp::vec (*)(int)>(&itpp::randn));
  m.def("randn", static_cast<void (*)(int, int, itpp::mat &)>(&itpp::randn));
  m.def("randn", static_cast<itpp::mat (*)(int, int)>(&itpp::randn));

  m.def("randn_c", static_cast<std::complex<double> (*)()>(&itpp::randn_c));
  m.def("randn_c", static_cast<void (*)(int, itpp::cvec &)>(&itpp::randn_c));
  m.def("randn_c", static_cast<itpp::cvec (*)(int)>(&itpp::randn_c));
  m.def("randn_c", static_cast<void (*)(int, int, itpp::cmat &)>(&itpp::randn_c));
  m.def("randn_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::randn_c));
}
