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

#include "convcode.h"

PYBIND11_MODULE( convcode, m ) {

  //! Type of Convolutional Code
  py::enum_<itpp::CONVOLUTIONAL_CODE_TYPE>( m, "CONVOLUTIONAL_CODE_TYPE")
    .value("MFD", itpp::MFD)
    .value("ODS", itpp::ODS)
  ;

  //! Encoding and decoding methods for Convolutional codes
  py::enum_<itpp::CONVOLUTIONAL_CODE_METHOD>( m, "CONVOLUTIONAL_CODE_METHOD")
    .value("Trunc", itpp::Trunc)
    .value("Tail", itpp::Tail)
    .value("Tailbite", itpp::Tailbite)
  ;

  //! Convolutional_Code class
  generate_pybind_wrapper_for_itpp_convolutional_code_class( m, "Convolutional_Code" );

  //! Additional functionality
  m.def("reverse_int", &itpp::reverse_int
                                  , "Reverses the bitrepresentation of in (of size length) and converts to an integer"
                                  , py::arg("length"), py::arg("in"));

  m.def("reverse_int", &itpp::reverse_int
                                  , "Reverses the bitrepresentation of in (of size length) and converts to an integer"
                                  , py::arg("length"), py::arg("in"));
  m.def("weight_int", &itpp::weight_int
                                 , " Calculate the Hamming weight of the binary representation of in of size length"
                                 , py::arg("length"), py::arg("in"));

  m.def("compare_spectra", static_cast<int (*)(itpp::ivec, itpp::ivec)>(&itpp::compare_spectra)
                                      , "Compare two distance spectra. Return 1 if v1 is less, 0 if v2 less, and -1 if equal."
                                      , py::arg("v1"), py::arg("v2"));
  m.def("compare_spectra", static_cast<int (*)(itpp::ivec, itpp::ivec, itpp::vec)>(&itpp::compare_spectra)
                                      , "Compare two distance spectra using a weight profile."
                                      , py::arg("v1"), py::arg("v2"), py::arg("weight_profile"));
}
