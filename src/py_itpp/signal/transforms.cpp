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
#include <itpp/signal/transforms.h>

BOOST_PYTHON_MODULE(transforms) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  //! fft
  boost::python::def("have_fourier_transforms", &itpp::have_fourier_transforms
	                                      , "Run-time test if library is built with Fast Fourier Transforms enabled"
                                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("fft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::fft)
	                  , "Fast Fourier Transform"
	                  , boost::python::args("in", "out"));

  boost::python::def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::fft)
	                  , "Fast Fourier Transform"
	                  , boost::python::args("in")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::fft)
	                   , "Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
	                     "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
	                   , boost::python::args("in", "N")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("fft_real", static_cast<void (*)(const itpp::vec &, itpp::cvec &)>(&itpp::fft_real)
	                       , "Real Fast Fourier Transform"
	                       , boost::python::args("in", "out"));

  boost::python::def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &)>(&itpp::fft_real)
	                       , "Real Fast Fourier Transform"
	                       , boost::python::args("in")
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &, const int)>(&itpp::fft_real)
	                       , "Real Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
	                         "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
	                       , boost::python::args("in", "N")
                               , boost::python::return_value_policy<boost::python::return_by_value>());

  //! ifft
  boost::python::def("ifft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::ifft)
	                  , "Inverse Fast Fourier Transform"
	                  , boost::python::args("in", "out"));

  boost::python::def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::ifft)
	                  , "Inverse Fast Fourier Transform"
	                  , boost::python::args("in")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::ifft)
	                   , "Inverse Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
	                     "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
	                   , boost::python::args("in", "N")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("ifft_real", static_cast<void (*)(const itpp::cvec &, itpp::vec &)>(&itpp::ifft_real)
	                       , "Inverse Real Fast Fourier Transform"
	                       , boost::python::args("in", "out"));

  boost::python::def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::ifft_real)
	                        , "Inverse Real Fast Fourier Transform"
	                        , boost::python::args("in")
                                , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &, const int)>(&itpp::ifft_real)
	                        , "Inverse Real Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
	                          "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
	                        , boost::python::args("in", "N")
                                , boost::python::return_value_policy<boost::python::return_by_value>());

  //! dct
  boost::python::def("dct", &itpp::have_cosine_transforms
	                  , "Run-time test if library is built with cosine transforms enabled"
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("dct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::dct)
	                  , "Discrete Cosine Transform (DCT)"
	                  , boost::python::args("in", "out"));

  boost::python::def("dct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::dct)
	                  , "Discrete Cosine Transform (DCT)"
	                  , boost::python::args("in")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("dct", static_cast<itpp::vec (*)(const itpp::vec &, const int)>(&itpp::dct)
	                   , "Discrete Cosine Transform (DCT) with zero-padding up to size N. First N points of input vector "
	                     "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
	                   , boost::python::args("in", "N")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

  //! idct
  boost::python::def("idct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::idct)
	                  , "Inverse Discrete Cosine Transform (DCT)"
	                  , boost::python::args("in", "out"));

  boost::python::def("idct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::idct)
	                  , "Inverse Discrete Cosine Transform (DCT)"
	                  , boost::python::args("in")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("idct", static_cast<itpp::vec (*)(const itpp::vec &, const int)>(&itpp::idct)
	                   , "Inverse Discrete Cosine Transform (DCT) with zero-padding up to size N. First N points of input vector "
	                     "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
	                   , boost::python::args("in", "N")
                           , boost::python::return_value_policy<boost::python::return_by_value>());

}

