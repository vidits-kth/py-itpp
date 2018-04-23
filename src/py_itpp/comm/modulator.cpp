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

#include "modulator.h"

BOOST_PYTHON_MODULE(modulator)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  // Soft demodulation methods
  boost::python::enum_<itpp::Soft_Method>("soft_method")
      .value("LOGMAP", itpp::LOGMAP)
      .value("APPROX", itpp::APPROX)
  ;

  //! Definition of 1D Modulator (with real symbols)
  generate_modulator<double>("modulator_1d");

  //! Definition of 1D Modulator (with integer symbols)
  generate_modulator<int>("modulator_1d_int");

  //! Definition of 2D Modulator (with complex symbols)
  generate_modulator<std::complex<double> >("modulator_2d");

  //! M-ary QAM modulator with square lattice.
  boost::python::class_<itpp::QAM, boost::python::bases<itpp::Modulator<std::complex<double> > > >("QAM", boost::python::init<>("Default Constructor"))
    .def(boost::python::init<int>("Class Constructor", boost::python::args("self", "M")))
    .def("set_M", &itpp::QAM::set_M
                , "Change the size of the signal constellation"
                , boost::python::args("self", "M"))

    .def("demodulate_bits", static_cast<void (itpp::QAM::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::QAM::demodulate_bits)
                          , "Hard demodulation of bits"
                          , boost::python::args("self", "signal", "bits"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::QAM::*)(const itpp::cvec &) const>(&itpp::QAM::demodulate_bits)
                          , "Hard demodulation of bits"
                          , boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! M-ary PSK modulator.
  boost::python::class_<itpp::PSK, boost::python::bases<itpp::Modulator<std::complex<double> > > >("PSK", boost::python::init<>("Default Constructor"))
    .def(boost::python::init<int>("Class constructor", boost::python::args("self", "M")))
    .def("set_M", &itpp::PSK::set_M
                , "Change the size of the signal constellation"
                , boost::python::args("self", "M"))

    .def("demodulate_bits", static_cast<void (itpp::PSK::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::PSK::demodulate_bits)
                          , "Hard demodulation of bits"
                          , boost::python::args("self", "signal", "bits"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PSK::*)(const itpp::cvec &) const>(&itpp::PSK::demodulate_bits)
                          , "Hard demodulation of bits"
                          , boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! QPSK modulator.
  boost::python::class_<itpp::QPSK, boost::python::bases<itpp::PSK> >("QPSK", boost::python::init<>("Class Constructor"))
    .def("demodulate_soft_bits", static_cast<void (itpp::QPSK::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , boost::python::args("self", "rx_symbols", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::QPSK::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , boost::python::args("self", "rx_symbols", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::QPSK::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::QPSK::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN", boost::python::args("self", "rx_symbols", "channel", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! BPSK modulator with complex symbols.
  boost::python::class_<itpp::BPSK_c, boost::python::bases<itpp::PSK> >("BPSK_c", boost::python::init<>("Constructor"))
    .def("modulate_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::bvec &, itpp::cvec &) const>(&itpp::BPSK_c::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , boost::python::args("self", "bits", "output"))
    .def("modulate_bits", static_cast<itpp::cvec (itpp::BPSK_c::*)(const itpp::bvec &) const>(&itpp::BPSK_c::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , boost::python::args("self", "bits")
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("demodulate_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::BPSK_c::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , boost::python::args("self", "signal", "output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::BPSK_c::*)(const itpp::cvec &) const>(&itpp::BPSK_c::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , boost::python::args("self", "rx_symbols", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK_c::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , boost::python::args("self", "rx_symbols", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! BPSK modulator with real symbols.
  boost::python::class_<itpp::BPSK, boost::python::bases<itpp::Modulator<double> > >("BPSK", boost::python::init<>("Constructor"))
    .def("modulate_bits", static_cast<void (itpp::BPSK::*)(const itpp::bvec &, itpp::vec &) const>(&itpp::BPSK::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , boost::python::args("self", "bits", "output"))
    .def("modulate_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::bvec &) const>(&itpp::BPSK::modulate_bits)
                        , "Modulate bits into BPSK symbols in complex domain"
                        , boost::python::args("self", "bits")
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("demodulate_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, itpp::bvec &) const>(&itpp::BPSK::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , boost::python::args("self", "signal", "output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::BPSK::*)(const itpp::vec &) const>(&itpp::BPSK::demodulate_bits)
                          , "Demodulate noisy BPSK symbols in complex domain into bits"
                          , boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , boost::python::args("self", "rx_symbols", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::vec &, double, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channel"
                               , boost::python::args("self", "rx_symbols", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, const itpp::vec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::vec &, const itpp::vec &, double, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , "Soft demodulator for a known channel in AWGN"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! M-ary PAM modulator with complex symbols.
  boost::python::class_<itpp::PAM_c, boost::python::bases<itpp::Modulator<std::complex<double> > > >("PAM_c", boost::python::init<>("Default Constructor"))
    .def(boost::python::init<int>("dosctring", boost::python::args("self")))

    .def("set_M", &itpp::PAM_c::set_M
                , "Set the size of the signal constellation"
		, boost::python::args("self", "M"))

    .def("demodulate_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::PAM_c::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits", boost::python::args("self", "signal", "output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PAM_c::*)(const itpp::cvec &) const>(&itpp::PAM_c::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits", boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channels"
                               , boost::python::args("self", "rx_symbols", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::PAM_c::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for AWGN channels"
                               , boost::python::args("self", "rx_symbols", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for known fading channels"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "soft_bits", "method"))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::PAM_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , "Soft demodulator for known fading channels"
                               , boost::python::args("self", "rx_symbols", "channel", "N0", "method")
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! PAM modulator with real symbols.
  boost::python::class_<itpp::PAM, boost::python::bases<itpp::Modulator<double> > >("PAM", boost::python::init<>("Default Constructor"))
    .def(boost::python::init<int>("Constructor", boost::python::args("self", "M")))

    .def("set_M", &itpp::PAM::set_M
                , "Set the size of the signal constellation"
                , boost::python::args("self", "M"))

    .def("demodulate_bits", static_cast<void (itpp::PAM::*)(const itpp::vec &, itpp::bvec &) const>(&itpp::PAM::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits"
                          , boost::python::args("self", "signal", "output"))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PAM::*)(const itpp::vec &) const>(&itpp::PAM::demodulate_bits)
                          , "Hard demodulation of PAM symbols in complex domain to bits"
                          , boost::python::args("self", "signal")
                          , boost::python::return_value_policy<boost::python::return_by_value>())

  ;
}
