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

#include <itpp/comm/interleave.h>
#include <boost/python.hpp>

template<class T>
void generate_block_interleaver(char const * name) {

  // Block Interleaver Class
  boost::python::class_<itpp::Block_Interleaver<T> >(name, boost::python::init<>())

    .def(boost::python::init<int, int>())

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave)
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("interleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("deinterleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave))

    .def("set_rows", &itpp::Block_Interleaver<T>::set_rows)
    .def("set_cols", &itpp::Block_Interleaver<T>::set_cols)

    .def("get_rows", &itpp::Block_Interleaver<T>::get_rows
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_cols", &itpp::Block_Interleaver<T>::get_cols
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}

template<class T>
void generate_cross_interleaver(char const * name) {

  // Cross Interleaver Class
  boost::python::class_<itpp::Cross_Interleaver<T> >(name, boost::python::init<>())

    .def(boost::python::init<int>())

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("interleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("deinterleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave))

    .def("set_order", &itpp::Cross_Interleaver<T>::set_order)

    .def("get_order", &itpp::Cross_Interleaver<T>::get_order
                    , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}

template<class T>
void generate_sequence_interleaver(char const * name) {

  // Sequence Interleaver Class
  boost::python::class_<itpp::Sequence_Interleaver<T> >(name, boost::python::init<>())

    .def(boost::python::init<int>())

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("interleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("deinterleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave))

    .def("randomize_interleaver_sequence", &itpp::Sequence_Interleaver<T>::randomize_interleaver_sequence)

    .def("get_interleaver_sequence", &itpp::Sequence_Interleaver<T>::get_interleaver_sequence
                                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("set_interleaver_sequence", &itpp::Sequence_Interleaver<T>::set_interleaver_sequence)

    .def("set_interleaver_depth", &itpp::Sequence_Interleaver<T>::set_interleaver_depth)

    .def("get_interleaver_depth", &itpp::Sequence_Interleaver<T>::get_interleaver_depth
                                , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
