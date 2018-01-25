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
  boost::python::class_<itpp::Modulator<T> >(name, boost::python::init<>("Default constructor", boost::python::args("self")))

    .def(boost::python::init<const itpp::Vec<T>&, const itpp::ivec&>("Constructor", boost::python::args("self")))

    .def("set", &itpp::Modulator<T>::set
              , "Set the constellation to use in the modulator"
              , boost::python::args("self", "symbols", "bits2symbols"))
    .def("bits_per_symbol", &itpp::Modulator<T>::bits_per_symbol
                          , "Returns number of bits per symbol"
                          , boost::python::args("self"))
    .def("get_k", &itpp::Modulator<T>::get_k
                , "Returns number of bits per symbol"
                , boost::python::args("self"))
    .def("get_M", &itpp::Modulator<T>::get_M
                , "Returns number of modulation symbols"
                , boost::python::args("self"))
    .def("get_symbols", &itpp::Modulator<T>::get_symbols
                      , "Get the symbol values used in the modulator"
                      , boost::python::args("self"))
    .def("get_bits2symbols", &itpp::Modulator<T>::get_bits2symbols
                           , "Get the bitmap, which maps input bits into symbols"
                           , boost::python::args("self"))

    .def("modulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::ivec&, itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate)
                   , "Modulation of symbols"
                   , boost::python::args("self", "symbolnumbers", "output"))
    .def("modulate", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::ivec&) const>(&itpp::Modulator<T>::modulate)
                   , "Modulation of symbols"
                   , boost::python::args("self", "symbolnumbers")
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,  itpp::ivec&) const>(&itpp::Modulator<T>::demodulate)
                     , "Demodulation of symbols"
                     , boost::python::args("self", "signal", "output"))
    .def("demodulate", static_cast<itpp::ivec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate)
                     , "Demodulation of symbols"
                     , boost::python::args("self", "signal")
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("modulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::bvec&, itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate_bits)
                        , "Modulation of bits"
                        , boost::python::args("self", "bits", "output"))
    .def("modulate_bits", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::bvec&) const>(&itpp::Modulator<T>::modulate_bits)
                        , "Modulation of bits"
                        , boost::python::args("self", "bits")
                        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, itpp::bvec&) const>(&itpp::Modulator<T>::demodulate_bits)
                          , "Hard demodulation of bits"
                          , boost::python::args("self", "signal", "bits"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate_bits)
                          , "Hard demodulation of bits"
                          , boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, double, itpp::vec&, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for AWGN channels"
                                , boost::python::args("self", "rx_symbols", "N0", "soft_bits", "method"))
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&, double, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for AWGN channels"
                                , boost::python::args("self", "rx_symbols", "N0", "method")
                                , boost::python::return_value_policy<boost::python::return_by_value>())

     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, const itpp::Vec<T>&, double, itpp::vec&, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for fading channels"
                                , boost::python::args("self", "rx_symbols", "channel", "N0", "soft_bits","method"))
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&, const itpp::Vec<T>&, double, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for fading channels"
                                , boost::python::args("self", "rx_symbols", "channel", "N0", "method")
                                , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
