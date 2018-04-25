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
  boost::python::class_<itpp::Block_Interleaver<T> >(name, "Block Interleaver Class", boost::python::init<>("Block_Interleaver constructor", boost::python::args("self")))

    .def(boost::python::init<int, int>("Block_Interleaver constructor", boost::python::args("self", "in_rows", "in_cols")))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave)
                     , "Function for block interleaving. May add some zeros."
                     , boost::python::args("self", "input")
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("interleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave)
                     , "docstring"
                     , boost::python::args("self"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , "docstring"
                       , boost::python::args("self")
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("deinterleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , "docstring"
                       , boost::python::args("self"))

    .def("set_rows", &itpp::Block_Interleaver<T>::set_rows
                   , "docstring"
                   , boost::python::args("self"))
    .def("set_cols", &itpp::Block_Interleaver<T>::set_cols
                   , "docstring"
                   , boost::python::args("self"))

    .def("get_rows", &itpp::Block_Interleaver<T>::get_rows
                   , "docstring"
                   , boost::python::args("self")
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_cols", &itpp::Block_Interleaver<T>::get_cols
                   , "docstring"
                   , boost::python::args("self")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}

template<class T>
void generate_cross_interleaver(char const * name) {

  // Cross Interleaver Class
  boost::python::class_<itpp::Cross_Interleaver<T> >(name, boost::python::init<>("docstring", boost::python::args("self")))

    .def(boost::python::init<int>("docstring", boost::python::args("self")))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , "docstring"
                     , boost::python::args("self")
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("interleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , "docstring"
                     , boost::python::args("self"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
                       , boost::python::return_value_policy<boost::python::return_by_value>()
	               , "docstring"
	               , boost::python::args("self"))

    .def("deinterleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
                       , "docstring"
                       , boost::python::args("self"))

    .def("set_order", &itpp::Cross_Interleaver<T>::set_order
                    , "docstring"
                    , boost::python::args("self"))

    .def("get_order", &itpp::Cross_Interleaver<T>::get_order
                    , "docstring"
                    , boost::python::args("self")
                    , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}

template<class T>
void generate_sequence_interleaver(char const * name) {

  // Sequence Interleaver Class
  boost::python::class_<itpp::Sequence_Interleaver<T> >(name, boost::python::init<>("docstring", boost::python::args("self")))

    .def(boost::python::init<int>("docstring", boost::python::args("self")))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , "docstring"
                     , boost::python::args("self")
                     , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("interleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , "docstring"
                     , boost::python::args("self"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , "docstring"
                       , boost::python::args("self")
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("deinterleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , "docstring"
                       , boost::python::args("self"))

    .def("randomize_interleaver_sequence", &itpp::Sequence_Interleaver<T>::randomize_interleaver_sequence
                                         , "docstring"
                                         , boost::python::args("self"))

    .def("get_interleaver_sequence", &itpp::Sequence_Interleaver<T>::get_interleaver_sequence
                                   , "docstring"
                                   , boost::python::args("self")
                                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("set_interleaver_sequence", &itpp::Sequence_Interleaver<T>::set_interleaver_sequence
                                   , "docstring"
                                   , boost::python::args("self"))

    .def("set_interleaver_depth", &itpp::Sequence_Interleaver<T>::set_interleaver_depth
                                , "docstring"
                                , boost::python::args("self"))

    .def("get_interleaver_depth", &itpp::Sequence_Interleaver<T>::get_interleaver_depth
                                , "docstring"
                                , boost::python::args("self")
                                , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
