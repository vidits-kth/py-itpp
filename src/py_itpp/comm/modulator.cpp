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

  //! Definition of 2D Modulator (with complex symbols)
  generate_modulator<std::complex<double> >("modulator_2d");

  //! M-ary QAM modulator with square lattice.
  boost::python::class_<itpp::QAM, boost::python::bases<itpp::Modulator<std::complex<double> > > >("QAM", boost::python::init<>())
    .def(boost::python::init<int>())
    .def("set_M", &itpp::QAM::set_M)

    .def("demodulate_bits", static_cast<void (itpp::QAM::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::QAM::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::QAM::*)(const itpp::cvec &) const>(&itpp::QAM::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! M-ary PSK modulator.
  boost::python::class_<itpp::PSK, boost::python::bases<itpp::Modulator<std::complex<double> > > >("PSK", boost::python::init<>())
    .def(boost::python::init<int>())
    .def("set_M", &itpp::PSK::set_M)

    .def("demodulate_bits", static_cast<void (itpp::PSK::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::PSK::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PSK::*)(const itpp::cvec &) const>(&itpp::PSK::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! QPSK modulator.
  boost::python::class_<itpp::QPSK, boost::python::bases<itpp::Modulator<std::complex<double> > > >("QPSK", boost::python::init<>())
    .def("demodulate_soft_bits", static_cast<void (itpp::QPSK::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::QPSK::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::QPSK::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::QPSK::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::QPSK::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! BPSK modulator with complex symbols.
  boost::python::class_<itpp::BPSK_c, boost::python::bases<itpp::Modulator<std::complex<double> > > >("BPSK_c", boost::python::init<>())
    .def("modulate_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::bvec &, itpp::cvec &) const>(&itpp::BPSK_c::modulate_bits))
    .def("modulate_bits", static_cast<itpp::cvec (itpp::BPSK_c::*)(const itpp::bvec &) const>(&itpp::BPSK_c::modulate_bits)
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("demodulate_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::BPSK_c::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::BPSK_c::*)(const itpp::cvec &) const>(&itpp::BPSK_c::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK_c::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::BPSK_c::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! BPSK modulator with real symbols.
  boost::python::class_<itpp::BPSK, boost::python::bases<itpp::Modulator<double> > >("BPSK", boost::python::init<>())
    .def("modulate_bits", static_cast<void (itpp::BPSK::*)(const itpp::bvec &, itpp::vec &) const>(&itpp::BPSK::modulate_bits))
    .def("modulate_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::bvec &) const>(&itpp::BPSK::modulate_bits)
                        , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("demodulate_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, itpp::bvec &) const>(&itpp::BPSK::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::BPSK::*)(const itpp::vec &) const>(&itpp::BPSK::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::vec &, double, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::BPSK::*)(const itpp::vec &, const itpp::vec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::BPSK::*)(const itpp::vec &, const itpp::vec &, double, itpp::Soft_Method) const>(&itpp::BPSK::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! M-ary PAM modulator with complex symbols.
  boost::python::class_<itpp::PAM_c, boost::python::bases<itpp::Modulator<std::complex<double> > > >("PAM_c", boost::python::init<>())
    .def(boost::python::init<int>())

    .def("set_M", &itpp::PAM_c::set_M)

    .def("demodulate_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, itpp::bvec &) const>(&itpp::PAM_c::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PAM_c::*)(const itpp::cvec &) const>(&itpp::PAM_c::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::PAM_c::*)(const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::PAM_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::vec &, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits))
    .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::PAM_c::*)(const itpp::cvec &, const itpp::cvec &, double, itpp::Soft_Method) const>(&itpp::PAM_c::demodulate_soft_bits)
                               , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  //! PAM modulator with real symbols.
  boost::python::class_<itpp::PAM, boost::python::bases<itpp::Modulator<double> > >("PAM", boost::python::init<>())
    .def(boost::python::init<int>())

    .def("set_M", &itpp::PAM::set_M)

    .def("demodulate_bits", static_cast<void (itpp::PAM::*)(const itpp::vec &, itpp::bvec &) const>(&itpp::PAM::demodulate_bits))
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::PAM::*)(const itpp::vec &) const>(&itpp::PAM::demodulate_bits)
                          , boost::python::return_value_policy<boost::python::return_by_value>())

  ;
}
