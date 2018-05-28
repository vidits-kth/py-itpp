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
                     , "Function for block interleaving. May add some zeros."
                     , boost::python::args("self", "input", "output"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , "Function for block deinterleaving. Removes additional zeros if keepzeros = 0."
                       , boost::python::args("self", "input", "keepzeroes")
                       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("deinterleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave)
                       , "Function for block deinterleaving. Removes additional zeros if keepzeros = 0."
                       , boost::python::args("self", "input", "output", "keepzeroes"))

    .def("set_rows", &itpp::Block_Interleaver<T>::set_rows
                   , "Set the number of rows for block interleaving"
                   , boost::python::args("self", "in_rows"))
    .def("set_cols", &itpp::Block_Interleaver<T>::set_cols
                   , "Set the number of columns for block interleaving"
                   , boost::python::args("self", "in_cols"))

    .def("get_rows", &itpp::Block_Interleaver<T>::get_rows
                   , "Get the number of rows for block interleaving"
                   , boost::python::args("self")
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_cols", &itpp::Block_Interleaver<T>::get_cols
                   , "Get the number of cols for block interleaving"
                   , boost::python::args("self")
                   , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}

template<class T>
void generate_cross_interleaver(char const * name) {

  // Cross Interleaver Class
  boost::python::class_<itpp::Cross_Interleaver<T> >(name,
						     "Cross Interleaver Class. See S. B. Wicker, \"Error control systems for digital communications and storage,\""
						     " Prentice Hall 1995, p. 427 for details.",
						     boost::python::init<>("Cross_Interleaver constructor", boost::python::args("self")))

    .def(boost::python::init<int>("Cross_Interleaver constructor", boost::python::args("self", "in_order")))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , "Function for cross interleaving. Adds some zeros."
                     , boost::python::args("self", "input")
                     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("interleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave)
                     , "Function for cross interleaving. Adds some zeros."
                     , boost::python::args("self", "input", "output"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
                       , boost::python::return_value_policy<boost::python::return_by_value>()
	               , "Function for cross deinterleaving. Removes aditional zeros if keepzeros = 0."
	               , boost::python::args("self", "input", "keepzeroes"))
    .def("deinterleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave)
                       , "Function for cross deinterleaving. Removes aditional zeros if keepzeros = 0."
                       , boost::python::args("self", "input", "output", "keepzeroes"))

    .def("set_order", &itpp::Cross_Interleaver<T>::set_order
                    , "Set the order of the Cross Interleaver"
                    , boost::python::args("self", "in_order"))
    .def("get_order", &itpp::Cross_Interleaver<T>::get_order
                    , "Get the order of the Cross Interleaver"
                    , boost::python::args("self")
                    , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}

template<class T>
void generate_sequence_interleaver(char const * name) {

  // Sequence Interleaver Class
  boost::python::class_<itpp::Sequence_Interleaver<T> >(name, "Sequence Interleaver Class", boost::python::init<>("Sequence_Interleaver constructor.", boost::python::args("self")))

    .def(boost::python::init<int>("Sequence_Interleaver constructor. Chooses a random sequence of length \a in_interleaver_depth for interleaving.",
				  boost::python::args("self", "in_interleaver_depth")))
    .def(boost::python::init<itpp::ivec>("Sequence_Interleaver constructor. Uses the in_interleaver_sequence for interleaving.",
					 boost::python::args("self", "in_interleaver_sequence")))

    .def("interleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , "Function for sequence interleaving. May add some zeros."
                     , boost::python::args("self", "input")
                     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("interleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave)
                     , "Function for sequence interleaving. May add some zeros."
                     , boost::python::args("self", "input", "output"))

    .def("deinterleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , "Function for sequence deinterleaving. Removes additional zeros if keepzeros = 0."
                       , boost::python::args("self", "input", "keepzeroes")
                       , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("deinterleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &, itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave)
                       , "Function for sequence deinterleaving. Removes additional zeros if keepzeros = 0."
                       , boost::python::args("self", "input", "output", "keepzeroes"))

    .def("randomize_interleaver_sequence", &itpp::Sequence_Interleaver<T>::randomize_interleaver_sequence
                                         , "Generate a new random sequence for interleaving."
                                         , boost::python::args("self"))

    .def("get_interleaver_sequence", &itpp::Sequence_Interleaver<T>::get_interleaver_sequence
                                   , "Returns the interleaver sequence presently used."
                                   , boost::python::args("self")
                                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("set_interleaver_sequence", &itpp::Sequence_Interleaver<T>::set_interleaver_sequence
                                   , "Set the interleaver sequence to be used."
                                   , boost::python::args("self", "in_interleaver_sequence"))

    .def("set_interleaver_depth", &itpp::Sequence_Interleaver<T>::set_interleaver_depth
                                , "Set the length of the interleaver sequence to be used."
                                , boost::python::args("self", "in_interleaver_depth"))

    .def("get_interleaver_depth", &itpp::Sequence_Interleaver<T>::get_interleaver_depth
                                , "Get the length of the interleaver sequence presently used."
                                , boost::python::args("self")
                                , boost::python::return_value_policy<boost::python::return_by_value>())
  ;
}
