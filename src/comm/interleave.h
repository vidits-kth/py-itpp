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

#include <itpp/comm/interleave.h>

namespace py = pybind11;

template<class T>
void generate_pybind_wrapper_for_itpp_block_interleaver_class( py::module &m, char const * name ) {

  // Block Interleaver Class
  py::class_<itpp::Block_Interleaver<T> >( m, name, "Block Interleaver Class" )
    .def( py::init<>(), "Block_Interleaver constructor")
    .def( py::init<int, int>(), "Block_Interleaver constructor"
		              , py::arg( "in_rows"), py::arg("in_cols"))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave)
                     , "Function for block interleaving. May add some zeros."
                     , py::arg( "input"))

    .def("interleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave)
                     , "Function for block interleaving. May add some zeros."
                     , py::arg( "input"), py::arg("output"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , "Function for block deinterleaving. Removes additional zeros if keepzeros = 0."
                       , py::arg( "input"), py::arg("keepzeroes"))

    .def("deinterleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , "Function for block deinterleaving. Removes additional zeros if keepzeros = 0."
                       , py::arg( "input"), py::arg("output"), py::arg("keepzeroes"))

    .def("set_rows", &itpp::Block_Interleaver<T>::set_rows
                   , "Set the number of rows for block interleaving"
                   , py::arg( "in_rows"))
    .def("set_cols", &itpp::Block_Interleaver<T>::set_cols
                   , "Set the number of columns for block interleaving"
                   , py::arg( "in_cols"))

    .def("get_rows", &itpp::Block_Interleaver<T>::get_rows
                   , "Get the number of rows for block interleaving")

    .def("get_cols", &itpp::Block_Interleaver<T>::get_cols
                   , "Get the number of cols for block interleaving")
  ;
}

template<class T>
void generate_pybind_wrapper_for_itpp_cross_interleaver_class( py::module &m, char const * name ) {

  // Cross Interleaver Class
  py::class_<itpp::Cross_Interleaver<T> >( m, name, "Cross Interleaver Class. See S. B. Wicker, \"Error control systems for digital communications and storage,\" Prentice Hall 1995, p. 427 for details.")
	  
    .def( py::init<>(), "Cross_Interleaver constructor")
    .def(py::init<int>(), "Cross_Interleaver constructor"
		        , py::arg( "in_order"))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , "Function for cross interleaving. Adds some zeros."
                     , py::arg( "input"))
    .def("interleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , "Function for cross interleaving. Adds some zeros."
                     , py::arg( "input"), py::arg("output"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
	               , "Function for cross deinterleaving. Removes aditional zeros if keepzeros = 0."
	               , py::arg( "input"), py::arg("keepzeroes"))
    .def("deinterleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
                       , "Function for cross deinterleaving. Removes aditional zeros if keepzeros = 0."
                       , py::arg( "input"), py::arg("output"), py::arg("keepzeroes"))

    .def("set_order", &itpp::Cross_Interleaver<T>::set_order
                    , "Set the order of the Cross Interleaver"
                    , py::arg( "in_order"))
    .def("get_order", &itpp::Cross_Interleaver<T>::get_order
                    , "Get the order of the Cross Interleaver")
                    
  ;
}

template<class T>
void generate_pybind_wrapper_for_itpp_sequence_interleaver_class( py::module &m, char const * name ) {

  // Sequence Interleaver Class
  py::class_<itpp::Sequence_Interleaver<T> >( m, name, "Sequence Interleaver Class")
    .def(py::init<>(), "Sequence_Interleaver constructor.")
    .def(py::init<int>(), "Sequence_Interleaver constructor. Chooses a random sequence of length \a in_interleaver_depth for interleaving."
		        , py::arg( "in_interleaver_depth"))
    .def(py::init<itpp::ivec>(), "Sequence_Interleaver constructor. Uses the in_interleaver_sequence for interleaving."
			       , py::arg( "in_interleaver_sequence"))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , "Function for sequence interleaving. May add some zeros."
                     , py::arg( "input"))
    .def("interleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , "Function for sequence interleaving. May add some zeros."
                     , py::arg( "input"), py::arg("output"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , "Function for sequence deinterleaving. Removes additional zeros if keepzeros = 0."
                       , py::arg( "input"), py::arg("keepzeroes"))
    .def("deinterleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , "Function for sequence deinterleaving. Removes additional zeros if keepzeros = 0."
                       , py::arg( "input"), py::arg("output"), py::arg("keepzeroes"))

    .def("randomize_interleaver_sequence", &itpp::Sequence_Interleaver<T>::randomize_interleaver_sequence
                                         , "Generate a new random sequence for interleaving.")

    .def("get_interleaver_sequence", &itpp::Sequence_Interleaver<T>::get_interleaver_sequence
                                   , "Returns the interleaver sequence presently used.")
                                   
    .def("set_interleaver_sequence", &itpp::Sequence_Interleaver<T>::set_interleaver_sequence
                                   , "Set the interleaver sequence to be used."
                                   , py::arg( "in_interleaver_sequence"))

    .def("set_interleaver_depth", &itpp::Sequence_Interleaver<T>::set_interleaver_depth
                                , "Set the length of the interleaver sequence to be used."
                                , py::arg( "in_interleaver_depth"))

    .def("get_interleaver_depth", &itpp::Sequence_Interleaver<T>::get_interleaver_depth
                                , "Get the length of the interleaver sequence presently used.")
  ;
}
