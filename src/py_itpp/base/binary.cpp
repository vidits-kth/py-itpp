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
#include <itpp/base/binary.h>
#include <itpp/base/vec.h>
#include <itpp/base/math/elem_math.h>

BOOST_PYTHON_MODULE(binary) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  //! Binary class definition
  boost::python::class_<itpp::bin>("bin", boost::python::init<>())

    .def(boost::python::init<const int>())
    .def(boost::python::init<const itpp::bin &>())
  
    //! Assignment operator works differently in C++ and Python
    //.def(boost::python::self = int()) // use obj1 = bin(ord(obj1.value()) | obj2) instead
    //.def(boost::python::self = boost::python::other<itpp::bin>()) // use obj1 = obj1 | obj2 instead
  
    .def(boost::python::self |= boost::python::other<itpp::bin>())
    .def(boost::python::self / boost::python::other<itpp::bin>())
    .def(boost::python::self | boost::python::other<itpp::bin>())
  
    .def(boost::python::self += boost::python::other<itpp::bin>())
    .def(boost::python::self ^= boost::python::other<itpp::bin>())
    .def(boost::python::self + boost::python::other<itpp::bin>())
    .def(boost::python::self ^ boost::python::other<itpp::bin>())
    .def(boost::python::self -= boost::python::other<itpp::bin>())
    .def(boost::python::self - boost::python::other<itpp::bin>())
  
    .def(-boost::python::self)
  
    .def(boost::python::self *= boost::python::other<itpp::bin>())
    .def(boost::python::self &= boost::python::other<itpp::bin>())
    .def(boost::python::self * boost::python::other<itpp::bin>())
    .def(boost::python::self & boost::python::other<itpp::bin>())
  
    .def(not boost::python::self)
    .def(~boost::python::self)
  
    .def(boost::python::self == boost::python::other<itpp::bin>())
    .def(boost::python::self == boost::python::other<int>())
  
    .def(boost::python::self != boost::python::self)
    .def(boost::python::self != boost::python::other<int>())
    .def(boost::python::self < boost::python::self)
    .def(boost::python::self <= boost::python::self)
  
    //! Convert \c bin to \c short
    //!--- No supported method
    //! Convert \c bin to \c int
    //.def(int_(boost::python::self)) //!--- Broken, calls to operator int/float/long ambiguous
    //! Convert \c bin to \c bool
    //!--- No supported method
    //! Convert \c bin to \c float
  //   .def(boost::python::float_(boost::python::self))
    //! Convert \c bin to \c double
    //!--- No supported method
  
    .def("value", &itpp::bin::value
                , boost::python::return_value_policy<boost::python::return_by_value>())
  
    .def(boost::python::self_ns::str(boost::python::self))
    ;

    boost::python::def("abs", static_cast<int (*)(const itpp::bin &)>(&std::abs)
                            , boost::python::return_value_policy<boost::python::return_by_value>());

}
