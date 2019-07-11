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
#include <pybind11/operators.h>

#include <itpp/signal/transforms.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_transforms_module( py::module &m ) {

  //! fft
  m.def("have_fourier_transforms", &itpp::have_fourier_transforms
                                 , "Run-time test if library is built with Fast Fourier Transforms enabled");

  m.def("fft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::fft)
             , "Fast Fourier Transform"
             , py::arg("in"), py::arg("out"));

  m.def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::fft)
             , "Fast Fourier Transform"
             , py::arg("in"));

  m.def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::fft)
              , "Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
                "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
              , py::arg("in"), py::arg("N"));

  m.def("fft_real", static_cast<void (*)(const itpp::vec &, itpp::cvec &)>(&itpp::fft_real)
                  , "Real Fast Fourier Transform"
                  , py::arg("in"), py::arg("out"));

  m.def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &)>(&itpp::fft_real)
                  , "Real Fast Fourier Transform"
                  , py::arg("in"));

  m.def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &, const int)>(&itpp::fft_real)
                  , "Real Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
                    "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
                  , py::arg("in"), py::arg("N"));

  //! ifft
  m.def("ifft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::ifft)
             , "Inverse Fast Fourier Transform"
             , py::arg("in"), py::arg("out"));

  m.def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::ifft)
             , "Inverse Fast Fourier Transform"
             , py::arg("in"));

  m.def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::ifft)
              , "Inverse Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
                "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
              , py::arg("in"), py::arg("N"));

  m.def("ifft_real", static_cast<void (*)(const itpp::cvec &, itpp::vec &)>(&itpp::ifft_real)
                  , "Inverse Real Fast Fourier Transform"
                  , py::arg("in"), py::arg("out"));

  m.def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::ifft_real)
                   , "Inverse Real Fast Fourier Transform"
                   , py::arg("in"));

  m.def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &, const int)>(&itpp::ifft_real)
                   , "Inverse Real Fast Fourier Transform with zero-padding up to size N. First N points of input vector "
                     "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
		   , py::arg("in"), py::arg("N"));

  //! dct
  m.def("dct", &itpp::have_cosine_transforms
             , "Run-time test if library is built with cosine transforms enabled");

  m.def("dct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::dct)
             , "Discrete Cosine Transform (DCT)"
             , py::arg("in"), py::arg("out"));

  m.def("dct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::dct)
             , "Discrete Cosine Transform (DCT)"
             , py::arg("in"));

  m.def("dct", static_cast<itpp::vec (*)(const itpp::vec &, const int)>(&itpp::dct)
              , "Discrete Cosine Transform (DCT) with zero-padding up to size N. First N points of input vector "
                "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
              , py::arg("in"), py::arg("N"));

  //! idct
  m.def("idct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::idct)
             , "Inverse Discrete Cosine Transform (DCT)"
             , py::arg("in"), py::arg("out"));

  m.def("idct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::idct)
             , "Inverse Discrete Cosine Transform (DCT)"
             , py::arg("in"));

  m.def("idct", static_cast<itpp::vec (*)(const itpp::vec &, const int)>(&itpp::idct)
              , "Inverse Discrete Cosine Transform (DCT) with zero-padding up to size N. First N points of input vector "
                "are used to perform the transform if N < length(in). Padding with 0's is performed if N > length(in)."
              , py::arg("in"), py::arg("N"));

}
