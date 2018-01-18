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
#include <itpp/comm/modulator.h>

template<class T>
void generate_modulator(char const * name) {

  // Modulator
  boost::python::class_<itpp::Modulator<T> >(name, boost::python::init<>())

    .def(boost::python::init<const itpp::Vec<T>&, const itpp::ivec&>())

    .def("set", &itpp::Modulator<T>::set)
    .def("bits_per_symbol", &itpp::Modulator<T>::bits_per_symbol)
    .def("get_symbols", &itpp::Modulator<T>::get_symbols)
    .def("get_bits2symbols", &itpp::Modulator<T>::get_bits2symbols)

    .def("modulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::ivec&, itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate))
    .def("modulate", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::ivec&) const>(&itpp::Modulator<T>::modulate)
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,  itpp::ivec&) const>(&itpp::Modulator<T>::demodulate))
    .def("demodulate", static_cast<itpp::ivec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate)
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("modulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::bvec&, itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate_bits))
    .def("modulate_bits", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::bvec&) const>(&itpp::Modulator<T>::modulate_bits)
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, itpp::bvec&) const>(&itpp::Modulator<T>::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())

     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, double, itpp::vec&, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits))
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&, double, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , boost::python::return_value_policy<boost::python::return_by_value>())

     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, const itpp::Vec<T>&, double, itpp::vec&, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits))
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&, const itpp::Vec<T>&, double, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
