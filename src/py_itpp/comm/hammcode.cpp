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
#include <itpp/comm/hammcode.h>

BOOST_PYTHON_MODULE(hammcode)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  boost::python::class_<itpp::Hamming_Code>("hamming_code", boost::python::init<short>())

    .def("encode", static_cast<void (itpp::Hamming_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Hamming_Code::encode))
    .def("encode", static_cast<itpp::bvec (itpp::Hamming_Code::*)(const itpp::bvec &)>(&itpp::Hamming_Code::encode)
                 , boost::python::return_value_policy<boost::python::return_by_value>())


    .def("decode", static_cast<void (itpp::Hamming_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Hamming_Code::decode))
    .def("decode", static_cast<itpp::bvec (itpp::Hamming_Code::*)(const itpp::bvec &)>(&itpp::Hamming_Code::decode)
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_rate", &itpp::Hamming_Code::get_rate)
    .def("get_n", &itpp::Hamming_Code::get_n)
    .def("get_k", &itpp::Hamming_Code::get_k)
    .def("get_H", &itpp::Hamming_Code::get_H)
    .def("get_G", &itpp::Hamming_Code::get_G)
  ;
}
