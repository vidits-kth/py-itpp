/*---------------------------------------------------------------------------*/
/*                                                                           */
/*     Copyright (c) ERICSSON AB, 2002                                       */
/*     The copyright to the document(s) herein is the property of            */
/*     Ericsson AB, Sweden.                                                  */
/*                                                                           */
/*     The document(s) may be used and/or copied only with the written       */
/*     permission from Ericsson AB or in accordance                          */
/*     with the terms and conditions stipulated in the agreement contract    */
/*     under which the document(s) have been supplied.                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*!
  \file
  \brief Python wrapper over the itpp::bin class.

  \author Vidit Saxena (EVIDSAX)
  \rev    py_itpp0.0.1
  \date   27 January 2017
*/

#include <boost/python.hpp>
#include <itpp/base/binary.h>

using namespace boost::python;

BOOST_PYTHON_MODULE(binary)
{

  //============================================================================
  // Class "bin"
  //============================================================================
  class_<itpp::bin>("bin", init<>())

    //! Set the binary object equal to \c value. Either "0" or "1".
    .def(init<const int>())
    //! Copy constructor
    .def(init<const itpp::bin &>())

    //! Assign a value
    //.def(self = int()) //!--- Not supported, use obj1 = bin(ord(obj1.value()) | obj2) instead
    //! Assign a value
    //.def(self = other<itpp::bin>()) //!--- Not supported, use obj1 = obj1 | obj2 instead

    //! OR
    //void operator/=(const itpp::bin &inbin) { b |= inbin.b; }
    //! OR
    //.def(self |= other<itpp::bin>()) //!--- Works, suppressed in favor of single OR
    //! OR
    //.def(self / other<itpp::bin>()) //!--- Works, suppressed in favor of single OR
    //! OR
    .def(self | other<itpp::bin>())

    //! XOR
    //.def(self += other<itpp::bin>()) //!--- Works, suppressed in favor of single XOR
    //! XOR
    //.def(self ^= other<itpp::bin>()) //!--- Works, suppressed in favor of single XOR
    //! XOR
    //.def(self + other<itpp::bin>()) //!--- Works, suppressed in favor of single XOR
    //! XOR
    .def(self ^ other<itpp::bin>())
    //! XOR
    //.def(self -= other<itpp::bin>()) //!--- Works, suppressed in favor of single XOR
    //! XOR
    // .def(self - other<itpp::bin>()) //!--- Works, suppressed in favor of single XOR

    //! Dummy definition to be able to use vec<bin>
    //.def(-self) //!--- Works, no perceived purpose

    //! AND
    //.def(self *= other<itpp::bin>()) //!--- Works, suppressed in favor of single AND
    //! AND
    //.def(self &= other<itpp::bin>()) //!--- Works, suppressed in favor of single AND
    //! AND
    //.def(self * other<itpp::bin>()) //!--- Works, suppressed in favor of single AND
    //! AND
    .def(self & other<itpp::bin>())

    //! NOT
    //.def(not self) //!--- Broken, "operator!" returns itpp::bin instead of bool
    //! NOT
    .def(~self)

    //! Check if equal
    .def(self == other<itpp::bin>())
    //! Check if equal
    .def(self == other<int>())

    //! Check if not equal
    .def(self != self)
    //! Check if not equal
    .def(self != other<int>())
    //! Less than (interpret the binary values {0,1} as integers)
    .def(self < self)
    //! Less than equal (interpret the binary values {0,1} as integers)
    .def(self <= self)

    //! Convert \c bin to \c short
    //!--- No supported method
    //! Convert \c bin to \c int
    //.def(int_(self)) //!--- Broken, calls to operator int/float/long ambiguous
    //! Convert \c bin to \c bool
    //!--- No supported method
    //! Convert \c bin to \c float
    .def(float_(self))
    //! Convert \c bin to \c double
    //!--- No supported method

    //! Output the binary value of the objectl
    .def("value", &itpp::bin::value)

    // Output stream of bin
    .def(self_ns::str(self))
;

  //============================================================================
  // Module-level utility functions
  //============================================================================
  //! absolute value of bin
  //def("abs", &itpp::abs); //!--- No additional functionality
}
