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
#include <itpp/base/random.h>

BOOST_PYTHON_MODULE(random)
{
  //! Set of functions to work with global seed provider
  boost::python::def("GlobalRNG_reset", static_cast<void (*)(unsigned int)>(&itpp::GlobalRNG_reset));
  boost::python::def("GlobalRNG_reset", static_cast<void (*)()>(&itpp::GlobalRNG_reset));
  boost::python::def("GlobalRNG_get_local_seed", &itpp::GlobalRNG_get_local_seed);
  boost::python::def("GlobalRNG_randomize", &itpp::GlobalRNG_randomize);
  boost::python::def("GlobalRNG_get_state", &itpp::GlobalRNG_get_state);
  boost::python::def("GlobalRNG_set_state", &itpp::GlobalRNG_set_state);

  //! Local (per-thread) RNG context management
  boost::python::def("RNG_reset", static_cast<void (*)(unsigned int)>(&itpp::RNG_reset));
  boost::python::def("RNG_reset", static_cast<void (*)()>(&itpp::RNG_reset));
  boost::python::def("RNG_randomize", &itpp::RNG_randomize);
  boost::python::def("RNG_get_state", &itpp::RNG_get_state);
  boost::python::def("RNG_set_state", &itpp::RNG_set_state);

  //! Random_Generator provides thread-safe generation of pseudo-random numbers
  boost::python::class_<itpp::Random_Generator>("Random_Generator", boost::python::init<>())

    .def("random_01", &itpp::Random_Generator::random_01
                    , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("random_01_lclosed", &itpp::Random_Generator::random_01_lclosed
                            , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("random_01_rclosed", &itpp::Random_Generator::random_01_rclosed
                            , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("random_int", &itpp::Random_Generator::random_int
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("genrand_uint32", &itpp::Random_Generator::genrand_uint32
	                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("genrand_close1_open2", &itpp::Random_Generator::genrand_close1_open2
                               , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("genrand_close_open", &itpp::Random_Generator::genrand_close_open
                             , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("genrand_open_close", &itpp::Random_Generator::genrand_open_close
                             , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("genrand_open_open", &itpp::Random_Generator::genrand_open_open
                            , boost::python::return_value_policy<boost::python::return_by_value>())

    ;


  //! Bernoulli distribution
  boost::python::class_<itpp::Bernoulli_RNG>("Bernoulli_RNG", boost::python::init<>())
    .def(boost::python::init<double>())

    .def("setup", &itpp::Bernoulli_RNG::setup)

    .def("get_setup", &itpp::Bernoulli_RNG::get_setup)

    .def("__call__", static_cast<itpp::bin (itpp::Bernoulli_RNG::*)()>
                                (&itpp::Bernoulli_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::bvec (itpp::Bernoulli_RNG::*)(int)>
				(&itpp::Bernoulli_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::bmat (itpp::Bernoulli_RNG::*)(int, int)>
				(&itpp::Bernoulli_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample", &itpp::Bernoulli_RNG::sample
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_vector", &itpp::Bernoulli_RNG::sample_vector
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_matrix", &itpp::Bernoulli_RNG::sample_matrix
			, boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! Integer uniform distribution
  boost::python::class_<itpp::I_Uniform_RNG>("I_Uniform_RNG", boost::python::init<>())
    .def(boost::python::init<double>())

    .def("setup", &itpp::I_Uniform_RNG::setup)

    .def("get_setup", &itpp::I_Uniform_RNG::get_setup)

    .def("__call__", static_cast<int (itpp::I_Uniform_RNG::*)()>
                                (&itpp::I_Uniform_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::ivec (itpp::I_Uniform_RNG::*)(int)>
				(&itpp::I_Uniform_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::imat (itpp::I_Uniform_RNG::*)(int, int)>
				(&itpp::I_Uniform_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample", &itpp::I_Uniform_RNG::sample
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! Uniform distribution
  boost::python::class_<itpp::Uniform_RNG>("Uniform_RNG", boost::python::init<>())
    .def(boost::python::init<double>())

    .def("setup", &itpp::Uniform_RNG::setup)

    .def("get_setup", &itpp::Uniform_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Uniform_RNG::*)()>
                                (&itpp::Uniform_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::Uniform_RNG::*)(int)>
				(&itpp::Uniform_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::Uniform_RNG::*)(int, int)>
				(&itpp::Uniform_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample", &itpp::Uniform_RNG::sample
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_vector", &itpp::Uniform_RNG::sample_vector
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_matrix", &itpp::Uniform_RNG::sample_matrix
			, boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! Exponential distribution
  boost::python::class_<itpp::Exponential_RNG>("Exponential_RNG", boost::python::init<>())
    .def(boost::python::init<double>())

    .def("setup", &itpp::Exponential_RNG::setup)

    .def("get_setup", &itpp::Exponential_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Exponential_RNG::*)()>
                                (&itpp::Exponential_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::Exponential_RNG::*)(int)>
				(&itpp::Exponential_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::Exponential_RNG::*)(int, int)>
				(&itpp::Exponential_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! Normal distribution
  boost::python::class_<itpp::Normal_RNG>("Normal_RNG", boost::python::init<>())
    .def(boost::python::init<double, double>())

    .def("setup", &itpp::Normal_RNG::setup)

    .def("get_setup", &itpp::Normal_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Normal_RNG::*)()>
                                (&itpp::Normal_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::Normal_RNG::*)(int)>
				(&itpp::Normal_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::Normal_RNG::*)(int, int)>
				(&itpp::Normal_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample", &itpp::Normal_RNG::sample
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_vector", &itpp::Normal_RNG::sample_vector
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_matrix", &itpp::Normal_RNG::sample_matrix
			, boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! Gamma distribution
  boost::python::class_<itpp::Gamma_RNG>("Gamma_RNG", boost::python::init<>())
    .def(boost::python::init<double, double>())

    .def("setup", &itpp::Gamma_RNG::setup)

    // .def("get_setup", &itpp::Gamma_RNG::get_setup) // Not defined

    .def("__call__", static_cast<double (itpp::Gamma_RNG::*)()>
                                (&itpp::Gamma_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::Gamma_RNG::*)(int)>
				(&itpp::Gamma_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::Gamma_RNG::*)(int, int)>
				(&itpp::Gamma_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! Laplacian distribution
  boost::python::class_<itpp::Laplace_RNG>("Laplace_RNG", boost::python::init<>())
    .def(boost::python::init<double, double>())

    .def("setup", &itpp::Laplace_RNG::setup)

    .def("get_setup", &itpp::Laplace_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Laplace_RNG::*)()>
                                (&itpp::Laplace_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::Laplace_RNG::*)(int)>
				(&itpp::Laplace_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::Laplace_RNG::*)(int, int)>
				(&itpp::Laplace_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample", &itpp::Laplace_RNG::sample
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    ;

  //! A Complex Normal Source
  boost::python::class_<itpp::Complex_Normal_RNG>("Complex_Normal_RNG", boost::python::init<>())
    .def(boost::python::init<std::complex<double>, double>())

    .def("setup", &itpp::Complex_Normal_RNG::setup)

    .def("get_setup", &itpp::Complex_Normal_RNG::get_setup)

    .def("__call__", static_cast<std::complex<double> (itpp::Complex_Normal_RNG::*)()>
                                (&itpp::Complex_Normal_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cvec (itpp::Complex_Normal_RNG::*)(int)>
				(&itpp::Complex_Normal_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::cmat (itpp::Complex_Normal_RNG::*)(int, int)>
				(&itpp::Complex_Normal_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample", &itpp::Complex_Normal_RNG::sample
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_vector", &itpp::Complex_Normal_RNG::sample_vector
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("sample_matrix", &itpp::Complex_Normal_RNG::sample_matrix
			, boost::python::return_value_policy<boost::python::return_by_value>())

    // Complex_Normal_RNG & operator=(const Complex_Normal_RNG&) { return *this; } // Not required in Python
    ;

  //! Filtered normal distribution
  boost::python::class_<itpp::AR1_Normal_RNG>("AR1_Normal_RNG", boost::python::init<>())
    .def(boost::python::init<double, double, double>())

    .def("setup", &itpp::AR1_Normal_RNG::setup)

    .def("get_setup", &itpp::AR1_Normal_RNG::get_setup)

    .def("reset", &itpp::AR1_Normal_RNG::reset)

    .def("__call__", static_cast<double (itpp::AR1_Normal_RNG::*)()>
                                (&itpp::AR1_Normal_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::AR1_Normal_RNG::*)(int)>
				(&itpp::AR1_Normal_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::AR1_Normal_RNG::*)(int, int)>
				(&itpp::AR1_Normal_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    ;

  // typedef Normal_RNG Gauss_RNG; // Handle in Python
  // typedef AR1_Normal_RNG AR1_Gauss_RNG; // Handle in Python

  //! Weibull distribution
  boost::python::class_<itpp::Weibull_RNG>("Weibull_RNG", boost::python::init<>())
    .def(boost::python::init<double, double>())

    .def("setup", &itpp::Weibull_RNG::setup)

    .def("get_setup", &itpp::Weibull_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Weibull_RNG::*)()>
                                (&itpp::Weibull_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::vec (itpp::Weibull_RNG::*)(int)>
				(&itpp::Weibull_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<itpp::mat (itpp::Weibull_RNG::*)(int, int)>
				(&itpp::Weibull_RNG::operator())
		   , boost::python::return_value_policy<boost::python::return_by_value>())
    ;

  //! Rayleigh distribution
  boost::python::class_<itpp::Rayleigh_RNG>("Rayleigh_RNG", boost::python::init<>())

    .def(boost::python::init<double>())

    .def("setup", &itpp::Rayleigh_RNG::setup)

    .def("get_setup", &itpp::Rayleigh_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Rayleigh_RNG::*)()>
                                (&itpp::Rayleigh_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("__call__", static_cast<itpp::vec (itpp::Rayleigh_RNG::*)(int)>
                                (&itpp::Rayleigh_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("__call__", static_cast<itpp::mat (itpp::Rayleigh_RNG::*)(int, int)>
                                (&itpp::Rayleigh_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! Rice distribution
  boost::python::class_<itpp::Rice_RNG>("Rice_RNG", boost::python::init<>())

    .def(boost::python::init<double, double>())

    .def("setup", &itpp::Rice_RNG::setup)

    .def("get_setup", &itpp::Rice_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Rice_RNG::*)()>
                                (&itpp::Rice_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("__call__", static_cast<itpp::vec (itpp::Rice_RNG::*)(int)>
                                (&itpp::Rice_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("__call__", static_cast<itpp::mat (itpp::Rice_RNG::*)(int, int)>
                                (&itpp::Rice_RNG::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  boost::python::def("randb", static_cast<itpp::bin (*)()>(&itpp::randb), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randb", static_cast<void (*)(int, itpp::bvec&)>(&itpp::randb));
  boost::python::def("randb", static_cast<itpp::bvec (*)(int)>(&itpp::randb), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randb", static_cast<void (*)(int, int, itpp::bmat&)>(&itpp::randb));
  boost::python::def("randb", static_cast<itpp::bmat (*)(int, int)>(&itpp::randb), boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("randu", static_cast<double (*)()>(&itpp::randu), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randu", static_cast<void (*)(int, itpp::vec &)>(&itpp::randu));
  boost::python::def("randu", static_cast<itpp::vec (*)(int)>(&itpp::randu), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randu", static_cast<void (*)(int, int, itpp::mat &)>(&itpp::randu));
  boost::python::def("randu", static_cast<itpp::mat (*)(int, int)>(&itpp::randu), boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("randi", static_cast<int (*)(int, int)>(&itpp::randi), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randi", static_cast<itpp::ivec (*)(int, int, int)>(&itpp::randi), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randi", static_cast<itpp::imat (*)(int, int, int, int)>(&itpp::randi), boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("randray", &itpp::randray);

  boost::python::def("randrice", &itpp::randrice, boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("randexp", itpp::randexp, boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("randn", static_cast<double (*)()>(&itpp::randn), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randn", static_cast<void (*)(int, itpp::vec &)>(&itpp::randn));
  boost::python::def("randn", static_cast<itpp::vec (*)(int)>(&itpp::randn), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randn", static_cast<void (*)(int, int, itpp::mat &)>(&itpp::randn));
  boost::python::def("randn", static_cast<itpp::mat (*)(int, int)>(&itpp::randn), boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("randn_c", static_cast<std::complex<double> (*)()>(&itpp::randn_c), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randn_c", static_cast<void (*)(int, itpp::cvec &)>(&itpp::randn_c));
  boost::python::def("randn_c", static_cast<itpp::cvec (*)(int)>(&itpp::randn_c), boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("randn_c", static_cast<void (*)(int, int, itpp::cmat &)>(&itpp::randn_c));
  boost::python::def("randn_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::randn_c), boost::python::return_value_policy<boost::python::return_by_value>());
}
