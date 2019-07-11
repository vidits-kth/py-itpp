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
#include <pybind11/pybind11.h>
#include <pybind11/complex.h>

#include <itpp/comm/modulator.h>

namespace py = pybind11;

template<class T>
void generate_pybind_wrapper_for_itpp_modulator_class( py::module &m, char const * name ) {

  // Modulator
  py::class_<itpp::Modulator<T> >( m, name )
	  
    .def(py::init<>(), "Default constructor")

    .def(py::init<const itpp::Vec<T>&, const itpp::ivec&>(), "Constructor")

    .def("set", &itpp::Modulator<T>::set
              , "Set the constellation to use in the modulator"
              , py::arg( "symbols"), py::arg("bits2symbols"))
    .def("bits_per_symbol", &itpp::Modulator<T>::bits_per_symbol
                          , "Returns number of bits per symbol")
    .def("get_k", &itpp::Modulator<T>::get_k
                , "Returns number of bits per symbol")
    .def("get_M", &itpp::Modulator<T>::get_M
                , "Returns number of modulation symbols")
    .def("get_symbols", &itpp::Modulator<T>::get_symbols
                      , "Get the symbol values used in the modulator")
    .def("get_bits2symbols", &itpp::Modulator<T>::get_bits2symbols
                           , "Get the bitmap, which maps input bits into symbols")

    .def("modulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::ivec&, itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate)
                   , "Modulation of symbols"
                   , py::arg( "symbolnumbers"), py::arg("output"))
    .def("modulate", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::ivec&) const>(&itpp::Modulator<T>::modulate)
                   , "Modulation of symbols"
                   , py::arg( "symbolnumbers"))

    .def("demodulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,  itpp::ivec&) const>(&itpp::Modulator<T>::demodulate)
                     , "Demodulation of symbols"
                     , py::arg( "signal"), py::arg("output"))
    .def("demodulate", static_cast<itpp::ivec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate)
                     , "Demodulation of symbols"
                     , py::arg( "signal"))

    .def("modulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::bvec&, itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate_bits)
                        , "Modulation of bits"
                        , py::arg( "bits"), py::arg("output"))
    .def("modulate_bits", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::bvec&) const>(&itpp::Modulator<T>::modulate_bits)
                        , "Modulation of bits"
                        , py::arg( "bits"))

    .def("demodulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, itpp::bvec&) const>(&itpp::Modulator<T>::demodulate_bits)
                          , "Hard demodulation of bits"
                          , py::arg( "signal"), py::arg("bits"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate_bits)
                          , "Hard demodulation of bits"
                          , py::arg( "signal"))

     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, double, itpp::vec&, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for AWGN channels"
                                , py::arg( "rx_symbols"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&, double, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for AWGN channels"
                                , py::arg( "rx_symbols"), py::arg("N0"), py::arg("method"))

     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&, const itpp::Vec<T>&, double, itpp::vec&, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for fading channels"
                                , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&, const itpp::Vec<T>&, double, itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits)
                                , "Soft demodulator for fading channels"
                                , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("method"))
  ;
}

void generate_pybind_wrapper_for_itpp_qam_class( py::module &m ) {
  //! M-ary QAM modulator with square lattice.
  py::class_<itpp::QAM, itpp::Modulator<std::complex<double> > >( m, "QAM" )
    .def(py::init<>(), "Default Constructor")
    .def(py::init<int>(), "Class Constructor"
		        , py::arg( "M"))
    .def("set_M", &itpp::QAM::set_M
                , "Change the size of the signal constellation"
                , py::arg( "M"))

    .def("demodulate_bits", static_cast<void (itpp::QAM::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::QAM::demodulate_bits)
                          , "Hard demodulation of bits"
                          , py::arg( "signal"), py::arg("bits"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::QAM::*)(const itpp::cvec &) const>(&itpp::QAM::demodulate_bits)
                          , "Hard demodulation of bits"
                          , py::arg( "signal"))
  ;
}

void generate_pybind_wrapper_for_itpp_psk_class( py::module &m ) {
  //! M-ary PSK modulator.
  py::class_<itpp::PSK, itpp::Modulator<std::complex<double> > >( m, "PSK" )
    .def(py::init<>(), "Default Constructor")
    .def(py::init<int>(), "Class constructor"
		        , py::arg( "M"))
    .def("set_M", &itpp::PSK::set_M
                , "Change the size of the signal constellation"
                , py::arg( "M"))

    .def("demodulate_bits", static_cast<void (itpp::PSK::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::PSK::demodulate_bits)
                          , "Hard demodulation of bits"
                          , py::arg( "signal"), py::arg("bits"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PSK::*)(const itpp::cvec &) const>(&itpp::PSK::demodulate_bits)
                          , "Hard demodulation of bits"
                          , py::arg( "signal"))
  ;
}

void generate_pybind_wrapper_for_itpp_qpsk_class( py::module &m ) {
  //! QPSK modulator.
  py::class_<itpp::QPSK, itpp::PSK >( m, "QPSK" )
    .def(py::init<>(), "Class Constructor")
    .def("demodulate_soft_bits", static_cast<void (itpp::QPSK::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::QPSK::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("method"))

    .def("demodulate_soft_bits", static_cast<void (itpp::QPSK::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::QPSK::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN", py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("method"))

  ;
}

void generate_pybind_wrapper_for_itpp_bpsk_c_class( py::module &m ) {
  //! BPSK modulator with complex symbols.
  py::class_<itpp::BPSK_c, itpp::PSK >( m, "BPSK_c")
    .def(py::init<>(), "Constructor")
    .def("modulate_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::bvec &, itpp::cvec &) const>(&itpp::BPSK_c::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , py::arg( "bits"), py::arg("output"))
    .def("modulate_bits", static_cast<itpp::cvec (itpp::BPSK_c::*)(const itpp::bvec &) const>(&itpp::BPSK_c::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , py::arg( "bits"))
    .def("demodulate_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::BPSK_c::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , py::arg( "signal"), py::arg("output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::BPSK_c::*)(const itpp::cvec &) const>(&itpp::BPSK_c::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , py::arg( "signal"))

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK_c::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("method"))

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("method"))
  ;
}

void generate_pybind_wrapper_for_itpp_bpsk_class( py::module &m ) {
  //! BPSK modulator with real symbols.
  py::class_<itpp::BPSK, itpp::Modulator<double> >( m, "BPSK" )
	  
    .def(py::init<>(), "Constructor")
    .def("modulate_bits", static_cast<void (itpp::BPSK::*)(const itpp::bvec &, itpp::vec &) const>(&itpp::BPSK::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , py::arg( "bits"), py::arg("output"))
    .def("modulate_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::bvec &) const>(&itpp::BPSK::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , py::arg( "bits"))
    .def("demodulate_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, itpp::bvec &) const>(&itpp::BPSK::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , py::arg( "signal"), py::arg("output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::BPSK::*)(const itpp::vec &) const>(&itpp::BPSK::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , py::arg( "signal"))

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::vec &, double, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("method"))

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, const itpp::vec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::vec &, const itpp::vec &, double, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("method"))

  ;
}

void generate_pybind_wrapper_for_itpp_pam_c_class( py::module &m ) {
  //! M-ary PAM modulator with complex symbols.
  py::class_<itpp::PAM_c, itpp::Modulator<std::complex<double> > >( m, "PAM_c")
	  
    .def(py::init<>(), "Default Constructor")
    .def(py::init<int>())

    .def("set_M", &itpp::PAM_c::set_M
                , "Set the size of the signal constellation"
		, py::arg( "M"))

    .def("demodulate_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::PAM_c::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits", py::arg( "signal"), py::arg("output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PAM_c::*)(const itpp::cvec &) const>(&itpp::PAM_c::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits", py::arg( "signal"))

    .def("demodulate_soft_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channels"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::PAM_c::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channels"
                               , py::arg( "rx_symbols"), py::arg("N0"), py::arg("method"))

    .def("demodulate_soft_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for known fading channels"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("soft_bits"), py::arg("method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::PAM_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for known fading channels"
                               , py::arg( "rx_symbols"), py::arg("channel"), py::arg("N0"), py::arg("method"))

  ;
}

void generate_pybind_wrapper_for_itpp_pam_class( py::module &m ) {
  //! PAM modulator with real symbols.
  py::class_<itpp::PAM, itpp::Modulator<double> >( m, "PAM")
    .def(py::init<>(), "Default Constructor")
    .def(py::init<int>(), "Constructor", py::arg( "M"))

    .def("set_M", &itpp::PAM::set_M
                , "Set the size of the signal constellation"
                , py::arg( "M"))

    .def("demodulate_bits", static_cast<void (itpp::PAM::*)(const itpp::vec &, itpp::bvec &) const>(&itpp::PAM::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits"
                          , py::arg( "signal"), py::arg("output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PAM::*)(const itpp::vec &) const>(&itpp::PAM::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits"
                          , py::arg( "signal"))
  ;
}
