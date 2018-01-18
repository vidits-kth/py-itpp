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

#include <itpp/signal/transforms.h>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(transforms)
{
  boost::python::def("fft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::fft));
  boost::python::def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::fft)
                          , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::fft)
                          , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ifft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::ifft));
  boost::python::def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::ifft)
                           , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::ifft)
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("fft_real", static_cast<void (*)(const itpp::vec &, itpp::cvec &)>(&itpp::fft_real));
  boost::python::def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &)>(&itpp::fft_real)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &, const int)>(&itpp::fft_real)
                               , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ifft_real", static_cast<void (*)(const itpp::cvec &, itpp::vec &)>(&itpp::ifft_real));
  boost::python::def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::ifft_real)
                                , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &, const int)>(&itpp::ifft_real)
                                , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("dct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::dct));
  boost::python::def("dct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::dct)
                          , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("idct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::idct));
  boost::python::def("idct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::idct)
                           , boost::python::return_value_policy<boost::python::return_by_value>());
}
