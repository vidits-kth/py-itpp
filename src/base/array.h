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
#include <itpp/base/array.h>

template<class T>
void generate_itpp_array_wrapper(char const * name) {

  boost::python::def("concat", static_cast<const itpp::Array<T> (*)(const itpp::Array<T> &, const T &)>(&itpp::concat<T>)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("concat", static_cast<const itpp::Array<T> (*)(const T &, const itpp::Array<T> &)>(&itpp::concat<T>)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("concat", static_cast<const itpp::Array<T> (*)(const itpp::Array<T> &, const itpp::Array<T> &)>(&itpp::concat<T>)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("concat", static_cast<const itpp::Array<T> (*)(const itpp::Array<T> &, const itpp::Array<T> &, const itpp::Array<T> &)>(&itpp::concat<T>)
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  // General array class
  boost::python::class_<itpp::Array<T> >(name, boost::python::init<>())

    .def(boost::python::init<const itpp::Factory &>())
    .def(boost::python::init<int>())
    .def(boost::python::init<int, const itpp::Factory &>())
    .def(boost::python::init<const itpp::Array<T> &>())
    .def(boost::python::init<const itpp::Array<T> &, const itpp::Factory &>())
    .def(boost::python::init<std::string &>())
    .def(boost::python::init<const char*>()) // NOTE: Cannot pass pointer from Python
    .def(boost::python::init<const char*, itpp::Factory &>()) // NOTE: Cannot pass pointer from Python

    .def("__call__", static_cast<T & (itpp::Array<T>::*)(int)>(&itpp::Array<T>::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<const T & (itpp::Array<T>::*)(int) const>(&itpp::Array<T>::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<const itpp::Array<T> (itpp::Array<T>::*)(int, int) const>(&itpp::Array<T>::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("__call__", static_cast<const itpp::Array<T> (itpp::Array<T>::*)(const itpp::Array<int> &) const>(&itpp::Array<T>::operator())
                   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("left", &itpp::Array<T>::left)
    .def("right", &itpp::Array<T>::right)
    .def("mid", &itpp::Array<T>::mid)

    //! Assignment operator works differently in Python, creating named functions instead
    .def("copy_element", static_cast<itpp::Array<T> & (itpp::Array<T> ::*)(const T &)>(&itpp::Array<T>::operator=)
                       , boost::python::return_internal_reference<>())
    .def("copy_array", static_cast<itpp::Array<T> & (itpp::Array<T> ::*)(const itpp::Array<T> &)>(&itpp::Array<T>::operator=)
                     , boost::python::return_internal_reference<>())
    .def("copy_char_array", static_cast<itpp::Array<T> & (itpp::Array<T> ::*)(const char *)>(&itpp::Array<T>::operator=)
                          , boost::python::return_internal_reference<>())

    .def("length", &itpp::Array<T>::length)
    .def("size", &itpp::Array<T>::size)
    .def("set_size", static_cast<void (itpp::Array<T>::*)(int, bool)>(&itpp::Array<T>::set_size))
    .def("set_length", static_cast<void (itpp::Array<T>::*)(int, bool)>(&itpp::Array<T>::set_length))

    .def("shift_right", static_cast<T (itpp::Array<T>::*)(const T &)>(&itpp::Array<T>::shift_right)
                      , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("shift_right", static_cast<const itpp::Array<T> (itpp::Array<T>::*)(const itpp::Array<T> &)>(&itpp::Array<T>::shift_right)
                      , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("shift_left", static_cast<T (itpp::Array<T>::*)(const T &)>(&itpp::Array<T>::shift_left)
                     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("shift_left", static_cast<const itpp::Array<T> (itpp::Array<T>::*)(const itpp::Array<T> &)>(&itpp::Array<T>::shift_left)
                     , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("swap", &itpp::Array<T>::swap)

    .def("set_subarray", static_cast<void (itpp::Array<T>::*)(int, int, const itpp::Array<T> &)>(&itpp::Array<T>::set_subarray))
    .def("set_subarray", static_cast<void (itpp::Array<T>::*)(int, int, const T &)>(&itpp::Array<T>::set_subarray))

    //! Additional Python-style methods
    .def("__len__", &itpp::Array<T>::length)
  ;

}
