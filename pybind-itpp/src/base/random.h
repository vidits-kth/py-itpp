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
#include <pybind11/complex.h>

#include <itpp/base/random.h>

namespace py = pybind11;

void generate_pybind11_wrapper_for_itpp_random_generator_class( const char * name, py::module& m ) {
  //! Random_Generator provides thread-safe generation of pseudo-random numbers
  py::class_<itpp::Random_Generator>(m, name)

    .def(py::init<>()) 
    .def("random_01", &itpp::Random_Generator::random_01)
    .def("random_01_lclosed", &itpp::Random_Generator::random_01_lclosed)
    .def("random_01_rclosed", &itpp::Random_Generator::random_01_rclosed)
    .def("random_int", &itpp::Random_Generator::random_int)

    .def("genrand_uint32", &itpp::Random_Generator::genrand_uint32)

    .def("genrand_close1_open2", &itpp::Random_Generator::genrand_close1_open2)
    .def("genrand_close_open", &itpp::Random_Generator::genrand_close_open)
    .def("genrand_open_close", &itpp::Random_Generator::genrand_open_close)
    .def("genrand_open_open", &itpp::Random_Generator::genrand_open_open)
    ;
}


void generate_pybind11_wrapper_for_itpp_bernoulli_rng_class( const char * name, py::module& m ) {
  //! Bernoulli distribution
  py::class_<itpp::Bernoulli_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double>())

    .def("setup", &itpp::Bernoulli_RNG::setup)

    .def("get_setup", &itpp::Bernoulli_RNG::get_setup)

    .def("__call__", static_cast<itpp::bin (itpp::Bernoulli_RNG::*)()>(&itpp::Bernoulli_RNG::operator()))
    .def("__call__", static_cast<itpp::bvec (itpp::Bernoulli_RNG::*)(int)>(&itpp::Bernoulli_RNG::operator()))
    .def("__call__", static_cast<itpp::bmat (itpp::Bernoulli_RNG::*)(int, int)>(&itpp::Bernoulli_RNG::operator()))

    .def("sample", &itpp::Bernoulli_RNG::sample)

    .def("sample_vector", &itpp::Bernoulli_RNG::sample_vector)

    .def("sample_matrix", &itpp::Bernoulli_RNG::sample_matrix)
    ;
}

void generate_pybind11_wrapper_for_itpp_i_uniform_rng_class( const char * name, py::module& m ) {
  //! Integer uniform distribution
  py::class_<itpp::I_Uniform_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::I_Uniform_RNG::setup)

    .def("get_setup", &itpp::I_Uniform_RNG::get_setup)

    .def("__call__", static_cast<int (itpp::I_Uniform_RNG::*)()>(&itpp::I_Uniform_RNG::operator()))
    .def("__call__", static_cast<itpp::ivec (itpp::I_Uniform_RNG::*)(int)>(&itpp::I_Uniform_RNG::operator()))
    .def("__call__", static_cast<itpp::imat (itpp::I_Uniform_RNG::*)(int, int)>(&itpp::I_Uniform_RNG::operator()))

    .def("sample", &itpp::I_Uniform_RNG::sample)
    ;
}

void generate_pybind11_wrapper_for_itpp_uniform_rng_class( const char * name, py::module& m ) {
  //! Uniform distribution
  py::class_<itpp::Uniform_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::Uniform_RNG::setup)

    .def("get_setup", &itpp::Uniform_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Uniform_RNG::*)()>(&itpp::Uniform_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Uniform_RNG::*)(int)>(&itpp::Uniform_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Uniform_RNG::*)(int, int)>(&itpp::Uniform_RNG::operator()))

    .def("sample", &itpp::Uniform_RNG::sample)

    .def("sample_vector", &itpp::Uniform_RNG::sample_vector)

    .def("sample_matrix", &itpp::Uniform_RNG::sample_matrix)
    ;

}

void generate_pybind11_wrapper_for_itpp_exponential_rng_class( const char * name, py::module& m ) {
  //! Exponential distribution
  py::class_<itpp::Exponential_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double>())

    .def("setup", &itpp::Exponential_RNG::setup)

//    .def("get_setup", &itpp::Exponential_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Exponential_RNG::*)()>(&itpp::Exponential_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Exponential_RNG::*)(int)>(&itpp::Exponential_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Exponential_RNG::*)(int, int)>(&itpp::Exponential_RNG::operator()))
    ;

}

void generate_pybind11_wrapper_for_itpp_normal_rng_class( const char * name, py::module& m ) {
  //! Normal distribution
  py::class_<itpp::Normal_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::Normal_RNG::setup)

    .def("get_setup", &itpp::Normal_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Normal_RNG::*)()>(&itpp::Normal_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Normal_RNG::*)(int)>(&itpp::Normal_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Normal_RNG::*)(int, int)>(&itpp::Normal_RNG::operator()))

    .def("sample", &itpp::Normal_RNG::sample)

    .def("sample_vector", &itpp::Normal_RNG::sample_vector)

    .def("sample_matrix", &itpp::Normal_RNG::sample_matrix)
    ;

}

void generate_pybind11_wrapper_for_itpp_gamma_rng_class( const char * name, py::module& m ) {
  //! Gamma distribution
  py::class_<itpp::Gamma_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::Gamma_RNG::setup)

    // .def("get_setup", &itpp::Gamma_RNG::get_setup) // Not defined

    .def("__call__", static_cast<double (itpp::Gamma_RNG::*)()>(&itpp::Gamma_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Gamma_RNG::*)(int)>(&itpp::Gamma_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Gamma_RNG::*)(int, int)>(&itpp::Gamma_RNG::operator()))
    ;

}

void generate_pybind11_wrapper_for_itpp_laplace_rng_class( const char * name, py::module& m ) {
  //! Laplacian distribution
  py::class_<itpp::Laplace_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::Laplace_RNG::setup)

    .def("get_setup", &itpp::Laplace_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Laplace_RNG::*)()>(&itpp::Laplace_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Laplace_RNG::*)(int)>(&itpp::Laplace_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Laplace_RNG::*)(int, int)>(&itpp::Laplace_RNG::operator()))

    .def("sample", &itpp::Laplace_RNG::sample)
    ;
}

void generate_pybind11_wrapper_for_itpp_complex_normal_rng_class( const char * name, py::module& m ) {
  //! A Complex Normal Source
  py::class_<itpp::Complex_Normal_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<std::complex<double>, double>())

    .def("setup", &itpp::Complex_Normal_RNG::setup)

    .def("get_setup", &itpp::Complex_Normal_RNG::get_setup)

    .def("__call__", static_cast<std::complex<double> (itpp::Complex_Normal_RNG::*)()>
                                (&itpp::Complex_Normal_RNG::operator()))
    .def("__call__", static_cast<itpp::cvec (itpp::Complex_Normal_RNG::*)(int)>
				(&itpp::Complex_Normal_RNG::operator()))
    .def("__call__", static_cast<itpp::cmat (itpp::Complex_Normal_RNG::*)(int, int)>
				(&itpp::Complex_Normal_RNG::operator()))

    .def("sample", &itpp::Complex_Normal_RNG::sample)

    .def("sample_vector", &itpp::Complex_Normal_RNG::sample_vector)

    .def("sample_matrix", &itpp::Complex_Normal_RNG::sample_matrix)
    ;

    // Complex_Normal_RNG & operator=(const Complex_Normal_RNG&) { return *this; } // Not required in Python
}

void generate_pybind11_wrapper_for_itpp_ar1_normal_rng_class( const char * name, py::module& m ) {
  //! Filtered normal distribution
  py::class_<itpp::AR1_Normal_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double, double>())

    .def("setup", &itpp::AR1_Normal_RNG::setup)

    .def("get_setup", &itpp::AR1_Normal_RNG::get_setup)

    .def("reset", &itpp::AR1_Normal_RNG::reset)

    .def("__call__", static_cast<double (itpp::AR1_Normal_RNG::*)()>(&itpp::AR1_Normal_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::AR1_Normal_RNG::*)(int)>(&itpp::AR1_Normal_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::AR1_Normal_RNG::*)(int, int)>(&itpp::AR1_Normal_RNG::operator()))
    ;
}

  // typedef Normal_RNG Gauss_RNG; // Handle in Python
  // typedef AR1_Normal_RNG AR1_Gauss_RNG; // Handle in Python

void generate_pybind11_wrapper_for_itpp_weibull_rng_class( const char * name, py::module& m ) {
  //! Weibull distribution
  py::class_<itpp::Weibull_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::Weibull_RNG::setup)

    .def("get_setup", &itpp::Weibull_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Weibull_RNG::*)()>(&itpp::Weibull_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Weibull_RNG::*)(int)>(&itpp::Weibull_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Weibull_RNG::*)(int, int)>(&itpp::Weibull_RNG::operator()))
    ;
}

void generate_pybind11_wrapper_for_itpp_rayleigh_rng_class( const char * name, py::module& m ) {
  //! Rayleigh distribution
  py::class_<itpp::Rayleigh_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double>())

    .def("setup", &itpp::Rayleigh_RNG::setup)

    .def("get_setup", &itpp::Rayleigh_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Rayleigh_RNG::*)()>(&itpp::Rayleigh_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Rayleigh_RNG::*)(int)>(&itpp::Rayleigh_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Rayleigh_RNG::*)(int, int)>(&itpp::Rayleigh_RNG::operator()))
    ;
}

void generate_pybind11_wrapper_for_itpp_rice_rng_class( const char * name, py::module& m ) {
  //! Rice distribution
  py::class_<itpp::Rice_RNG>(m, name)
    .def(py::init<>())
    .def(py::init<double, double>())

    .def("setup", &itpp::Rice_RNG::setup)

    .def("get_setup", &itpp::Rice_RNG::get_setup)

    .def("__call__", static_cast<double (itpp::Rice_RNG::*)()>(&itpp::Rice_RNG::operator()))
    .def("__call__", static_cast<itpp::vec (itpp::Rice_RNG::*)(int)>(&itpp::Rice_RNG::operator()))
    .def("__call__", static_cast<itpp::mat (itpp::Rice_RNG::*)(int, int)>(&itpp::Rice_RNG::operator()))
    ;
}
