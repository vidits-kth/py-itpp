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
#include <itpp/base/math/min_max.h>

template<class T>
void generate_min_max_wrapper() {

  boost::python::def("max", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::max)
		          , "Maximum value of vector"
			  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("max", static_cast<T (*)(const itpp::Vec<T> &, int &)>(&itpp::max)
		          , "Maximum value of vector, also returns the index position of max value"
			  , boost::python::args("v", "index")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("max", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::max)
		          , "Maximum values over each row/column in the matrix m"
			  , boost::python::args("m", "dim")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("max", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, itpp::Vec<int> &, int)>(&itpp::max)
		          , "Maximum values over each row/column in the matrix m. Also returns a vector of indices with positions of maximum value within a column/row."
			  , boost::python::args("m", "index", "dim")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("min", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::min)
		          , "Minimum value of vector"
			  , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("min", static_cast<T (*)(const itpp::Vec<T> &, int &)>(&itpp::max)
		          , "Minimum value of vector, also returns the index position of min value"
			  , boost::python::args("v", "index")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("min", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::max)
		          , "Minimum values over each row/column in the matrix m"
			  , boost::python::args("m", "dim")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("min", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, itpp::Vec<int> &, int)>(&itpp::max)
		          , "Minimum values over each row/column in the matrix m. Also returns a vector of indices with positions of minimum value within a column/row."
			  , boost::python::args("m", "index", "dim")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("max_index", static_cast<int (*)(const itpp::Vec<T> &)>(&itpp::max_index)
		                , "Return the postion of the maximum element in the vector"
			        , boost::python::args("in")
                                , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("max_index", static_cast<void (*)(const itpp::Mat<T> &, int &, int &)>(&itpp::max_index)
		                , "Return the postion of the maximum element in the matrix"
			        , boost::python::args("m", "row", "col")
                                , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("min_index", static_cast<int (*)(const itpp::Vec<T> &)>(&itpp::min_index)
		                , "Return the position of the minimum element in the vector"
			        , boost::python::args("in")
                                , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("min_index", static_cast<void (*)(const itpp::Mat<T> &, int &, int &)>(&itpp::min_index)
		                , "Return the position of the minimum element in the matrix"
			        , boost::python::args("m", "row", "col")
                                , boost::python::return_value_policy<boost::python::return_by_value>());

}
