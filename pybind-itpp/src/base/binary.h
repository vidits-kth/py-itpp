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

#include <itpp/base/binary.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_bin_class( char const * name, py::module &m ) 
{
  //! Binary class definition
  py::class_<itpp::bin>(m, name) 
    .def(py::init<>())

    .def(py::init<const int>())
    .def(py::init<const itpp::bin &>())
  
    //! Assignment operator works differently in C++ and Python
    //.def(py::self = py::self) // use obj1 = bin(ord(obj1.value()) | obj2) instead
    //.def(py::self = py::self<itpp::bin>()) // use obj1 = obj1 | obj2 instead
  
    .def(py::self |= py::self)
    .def(py::self / py::self)
    .def(py::self | py::self)
  
    .def(py::self += py::self)
    .def(py::self ^= py::self)
    .def(py::self + py::self)
    .def(py::self ^ py::self)
    .def(py::self -= py::self)
    .def(py::self - py::self)
  
    .def(-py::self)
  
    .def(py::self *= py::self)
    .def(py::self &= py::self)
    .def(py::self * py::self)
    .def(py::self & py::self)
  
    .def(not py::self)
    .def(~py::self)
  
    .def(py::self == py::self)
    .def(py::self == py::self)
  
    .def(py::self != py::self)
    .def(py::self != py::self)
    .def(py::self < py::self)
    .def(py::self <= py::self)
  
    //! Convert \c bin to \c short
    //!--- No supported method
    //! Convert \c bin to \c int
    //.def(int_(py::self)) //!--- Broken, calls to operator int/float/long ambiguous
    //! Convert \c bin to \c bool
    //!--- No supported method
    //! Convert \c bin to \c float
  //   .def(py::float_(py::self))
    //! Convert \c bin to \c double
    //!--- No supported method
  
    .def("value", &itpp::bin::value)
  
//    .def(py::self_ns::str(py::self))
    ;

//    py::def("abs", static_cast<int (*)(const itpp::bin &)>(&std::abs)
//                            , py::return_value_policy<py::return_by_value>());

}
