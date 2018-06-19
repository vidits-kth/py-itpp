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
#include <itpp/base/circular_buffer.h>

//---------------------------------------------------------------------------------------------
//! Replace Array functions with Python lists
template <class T>
void _put_python_list(itpp::Circular_Buffer<T>& buf, boost::python::list& lst) {
  for (int i = 0; i < boost::python::len(lst); ++i)
  {
      buf.put(boost::python::extract<T>(lst[i]));
  }
}

template <class T>
void _get_python_list(itpp::Circular_Buffer<T>& buf, boost::python::list& lst, const int N) {
  itpp::Array<T> arr;
  buf.get(arr, N);

  for (int i = 0; i < arr.length(); ++i)
  {
      lst.append<T>(arr(i));
  }
}

template <class T>
void _peek_python_list(const itpp::Circular_Buffer<T>& buf, boost::python::list& lst, const int N) {
  itpp::Array<T> arr;
  buf.peek(arr, N);

  for (int i = 0; i < arr.length(); ++i)
  {
      lst.append<T>(arr(i));
  }
}

template <class T>
void _peek_python_list(const itpp::Circular_Buffer<T>& buf, const itpp::ivec& index, boost::python::list& lst) {
  itpp::Array<T> arr;
  buf.peek(index, arr);

  for (int i = 0; i < arr.length(); ++i)
  {
      lst.append<T>(arr(i));
  }
}

template <class T>
void _peek_reverse_python_list(const itpp::Circular_Buffer<T>& buf, boost::python::list& lst, const int N) {
  itpp::Array<T> arr;
  buf.peek_reverse(arr, N);

  for (int i = 0; i < arr.length(); ++i)
  {
      lst.append<T>(arr(i));
  }
}

//---------------------------------------------------------------------------------------------

template <class T>
void generate_itpp_circular_buffer_wrapper(char const * name) {

  boost::python::class_<itpp::Circular_Buffer<T> >(name,
					           boost::python::init<>("Default constructor"))

    .def(boost::python::init<int>("Create a Circular_Buffer of size n", boost::python::args("self", "n")))

    .def(boost::python::init<const itpp::Circular_Buffer<T> &>("Create a copy of s", boost::python::args("self", "s")))

    //! put
    .def("put", static_cast<void (itpp::Circular_Buffer<T>::*)(const T &)>(&itpp::Circular_Buffer<T>::put)
              , "Write the element \"in\" to the buffer"
	      , boost::python::args("self", "in"))

    .def("put", static_cast<void (itpp::Circular_Buffer<T>::*)(const itpp::Vec<T> &)>(&itpp::Circular_Buffer<T>::put)
	      , "Write the vector of elements \"in\" to the circular buffer"
	      , boost::python::args("self", "in"))

    .def("put", &_put_python_list<T>
	      , "Write the Python list of elements \"in\" to the circular buffer"
	      , boost::python::args("self", "in"))

    //! get
    .def("get", static_cast<void (itpp::Circular_Buffer<T>::*)(T &)>(&itpp::Circular_Buffer<T>::get)
	      , "Get the oldest element in the circular buffer"
	      , boost::python::args("self", "out"))

    .def("get", static_cast<T (itpp::Circular_Buffer<T>::*)()>(&itpp::Circular_Buffer<T>::get)
	      , "Get the oldest element in the circular buffer"
	      , boost::python::args("self"))

    .def("get", static_cast<void (itpp::Circular_Buffer<T>::*)(itpp::Vec<T> &, const int)>(&itpp::Circular_Buffer<T>::get)
	      , "Get the N oldest element in the circular buffer. N=-1 returns all elements in the buffer"
	      , boost::python::args("self", "out", "N"))

    .def("get", _get_python_list<T>
	      , "Get the N oldest element in the circular buffer. N=-1 returns all elements in the buffer"
	      , boost::python::args("self", "in"))

    //! peek
    .def("peek", static_cast<void (itpp::Circular_Buffer<T>::*)(T &) const>(&itpp::Circular_Buffer<T>::peek)
	       , "Peek at the oldest element in the circular buffer, without removing it."
	       , boost::python::args("self", "out"))

    .def("peek", static_cast<T (itpp::Circular_Buffer<T>::*)() const>(&itpp::Circular_Buffer<T>::peek)
	       , "Peek at the oldest element in the circular buffer, without removing it."
	       , boost::python::args("self"))

    .def("peek", static_cast<void (itpp::Circular_Buffer<T>::*)(const int, T &) const>(&itpp::Circular_Buffer<T>::peek)
	       , "Peek at the element with index \"index\" in the circular buffer, without removing it."
	       , boost::python::args("self", "index", "out"))

    .def("peek", static_cast<void (itpp::Circular_Buffer<T>::*)(itpp::Vec<T> &, const int) const>(&itpp::Circular_Buffer<T>::peek)
	       , "Peek at the N first elements of the circular buffer, without removing them. N=-1 peeks all elements in the buffer"
	       , boost::python::args("self", "out", "N"))

    .def("peek", static_cast<void (itpp::Circular_Buffer<T>::*)(const itpp::ivec &, itpp::Vec<T> &) const>(&itpp::Circular_Buffer<T>::peek)
	       , "Peek at the elements with index \"index\" in the circular buffer, without removing them."
	       , boost::python::args("self", "out", "N"))

    .def("peek", static_cast<void (*)(const itpp::Circular_Buffer<T>&, boost::python::list &, const int)>(&_peek_python_list<T>)
	       , "Peek at the N first elements of the circular buffer, without removing them. N=-1 peeks all elements in the buffer"
	       , boost::python::args("self", "out", "N"))

    .def("peek", static_cast<void (*)(const itpp::Circular_Buffer<T>&, const itpp::ivec &, boost::python::list &)>(&_peek_python_list<T>)
	       , "Peek at the elements with index \"index\" in the circular buffer, without removing them."
	       , boost::python::args("self", "index", "out"))

    //! peek_reverse
    .def("peek_reverse", static_cast<void (itpp::Circular_Buffer<T>::*)(T &) const>(&itpp::Circular_Buffer<T>::peek_reverse)
	               , "Peek at the latest element in the circular buffer, without removing it."
                       , boost::python::args("self", "out"))

    .def("peek_reverse", static_cast<T (itpp::Circular_Buffer<T>::*)() const>(&itpp::Circular_Buffer<T>::peek_reverse)
                       , "Peek at the latest element in the circular buffer, without removing it."
                       , boost::python::args("self"))

    .def("peek_reverse", static_cast<void (itpp::Circular_Buffer<T>::*)(itpp::Vec<T> &, const int) const>(&itpp::Circular_Buffer<T>::peek_reverse)
		       , "Peek at the N latest elements of the circular buffer in reverse order, without removing them. N=-1 returns all elements in the buffer."
                       , boost::python::args("self", "out", "N"))

    .def("peek_reverse", &_peek_reverse_python_list<T>
 	               , "Peek at the N latest elements of the circular buffer in reverse order, without removing them. N=-1 returns all elements in the buffer"
		       , boost::python::args("self", "out", "N"))

    .def("clear", &itpp::Circular_Buffer<T>::clear
	        , "Empty the circular buffer"
                , boost::python::args("self"))

    .def("clone", &itpp::Circular_Buffer<T>::operator=
		, "Clone the circular buffer"
                , boost::python::args("self"))

    .def("size", &itpp::Circular_Buffer<T>::size
	       , "Returns the maximum number of data elements the circular buffer can store"
	       , boost::python::args("self"))

    .def("nrof_elements", &itpp::Circular_Buffer<T>::nrof_elements
		        , "Returns the number of data elements currently stored in the circular buffer"
		        , boost::python::args("self"))

    .def("set_size", &itpp::Circular_Buffer<T>::set_size
		   , "Resizing a Circular_Buffer."
		   , boost::python::args("self", "n", "copy"))

  ;
}
