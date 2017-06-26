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
  \brief Python wrapper over itpp::Vec subtypes defined in itpp/base/Vec<Num_T> .h.
         Available methods are tested.
         Commented methods should compile ok, but functionality untested.
         Friend functions have not been implemented.

  \author Vidit Saxena (EVIDSAX)
*/

#include <itpp/base/array.h>
#include <boost/python.hpp>
// #include "../test/itpp_array_pywrap_test.h"

using namespace itpp;
using namespace boost::python;

template<class T>
void generate_itpp_array_wrapper(char const * name) {

  class_<Array<T> >(name, init<>())

    //==========================================================================
    // Overloaded Constructors
    //==========================================================================

    //! Default constructor. An element factory \c f can be specified.
    //.def(init<const Factory &>())
    //! Create an Array of size \c n. An element factory \c f can be specified.
    .def(init<int>())
    //.def(init<int, const Factory &>())
    //! Copy constructor. An element factory \c f can be specified.
    .def(init<const Array<T> &>())
    //.def(init<const Array<T> &, const Factory &>())
    //! Create an Array from string. An element factory \c f can be specified.
    //.def(init<std::string &>())
    //.def(init<std::string &, const Factory &>())
    //! Create an Array from char*. An element factory \c f can be specified.
    //.def(init<const char*>())
    //.def(init<const char*, Factory &>())
    //! Constructor taking a C-array as input. References all data and thus does not own it.
    //.def(init<T*, int, const bool>())

    //==========================================================================
    // Properties
    //==========================================================================
    .add_property("length", &Array<T>::length, &Array<T>::set_length)
    .add_property("size", &Array<T>::size, &Array<T>::set_size)

    //==========================================================================
    // Python-style methods
    //==========================================================================

    .def("__getitem__", static_cast<T & (Array<T>::*)(int)>(&Array<T>::operator()), return_value_policy<return_by_value>())

    //==========================================================================
    // Member Functions
    //==========================================================================
    //! Get \c n left elements of the array
    //.def("left", &Array<T>::left)
    //! Get \c n right elements of the array
    //.def("right", &Array<T>::right)
    //! Get \c n elements of the array starting from \c pos
    //.def("mid", &Array<T>::mid)

    //! Assignment operator
    //.def("copy_element", static_cast<Array<T> & (Array<T> ::*)(const T &)>(&Array<T>::operator=), return_internal_reference<>())
    //! Assignment operator
    //.def("copy_array", static_cast<Array<T> & (Array<T> ::*)(const Array<T> &)>(&Array<T>::operator=), return_internal_reference<>())
    //! Assignment operator
    //.def("copy_char_array", static_cast<Array<T> & (Array<T> ::*)(const char *)>(&Array<T>::operator=), return_internal_reference<>())

    //! Taking a C-array as input. References all data and thus does not own it.
    //.def("set_handle", &Array<T>::set_handle)

    //! Get the \c i element
    //.def("get()", static_cast<const T & (Array<T>::*)(int) const>(&Array<T>::operator()), return_value_policy<return_by_value>())
    //! Sub-array from element \c i1 to element \c i2
    //.def("get_subarray_by_range", static_cast<const Array<T> (Array<T>::*)(int, int) const>(&Array<T>::operator()), return_value_policy<return_by_value>())
    //! Sub-array with the elements given by the integer Array
    //.def("get_subarray_by_indices", static_cast<const Array<T> (Array<T>::*)(const Array<int> &) const>(&Array<T>::operator()), return_value_policy<return_by_value>())

    //! Resizing an Array<T>.
    //.def("set_size_copy", static_cast<void (Array<T>::*)(int, bool)>(&Array<T>::set_size))
    //! Resizing an Array<T>.
    //.def("set_length_copy", static_cast<void (Array<T>::*)(int, bool)>(&Array<T>::set_length))

    //! Shift in data at position 0. Return data from the last position.
    //.def("shift_right_element", static_cast<T (Array<T>::*)(const T &)>(&Array<T>::shift_right), return_value_policy<return_by_value>())
    //! Shift in array at position 0. Return data from the last position.
    //.def("shift_right_array", static_cast<const Array<T> (Array<T>::*)(const Array<T> &)>(&Array<T>::shift_right), return_value_policy<return_by_value>())
    //! Shift in data at the last position. Return data from position 0.
    //.def("shift_left_element", static_cast<T (Array<T>::*)(const T &)>(&Array<T>::shift_left), return_value_policy<return_by_value>())
    //! Shift in array at the last position. Return data from position 0.
    //.def("shift_left_array", static_cast<const Array<T> (Array<T>::*)(const Array<T> &)>(&Array<T>::shift_left), return_value_policy<return_by_value>())
    //! Swap elements i and j.
    //.def("swap", &Array<T>::swap)

    //! Set the subarray defined by indicies i1 to i2 to Array<T> a.
    //.def("set_subarray_by_array", static_cast<void (Array<T>::*)(int, int, const Array<T> &)>(&Array<T>::set_subarray))
    //! Set the subarray defined by indicies i1 to i2 the element value t.
    //.def("set_subarray_by_element", static_cast<void (Array<T>::*)(int, int, const T)>(&Array<T>::set_subarray))

  ;

  //==========================================================================
  // Module Functions
  //==========================================================================
//
//      //! Append element \c e to the end of the Array \c a
//      friend const Array<T> concat <>(const Array<T> &a1, const T e);
//      //! Concat element \c e to the beginning of the Array \c a
//      friend const Array<T> concat <>(const T e, const Array<T> &a);
//      //! Concat Arrays \c a1 and \c a2
//      friend const Array<T> concat <>(const Array<T> &a1, const Array<T> &a2);
//      //! Concat Arrays \c a1, \c a2 and \c a3
//      friend const Array<T> concat <>(const Array<T> &a1, const Array<T> &a2,
//                                      const Array<T> &a3);
//

}
