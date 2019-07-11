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
#include <pybind11/complex.h>

#include <itpp/base/math/min_max.h>

namespace py = pybind11;

template<class T>
void generate_pybind_wrapper_for_min_max_module( py::module &m ) {

  m.def("max", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::max)
		          , "Maximum value of vector"
			  , py::arg("v"));

  m.def("max", static_cast<T (*)(const itpp::Vec<T> &, int &)>(&itpp::max)
		          , "Maximum value of vector, also returns the index position of max value"
			  , py::arg("v"), py::arg("index"));

  m.def("max", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::max)
		          , "Maximum values over each row/column in the matrix m"
			  , py::arg("m"), py::arg("dim"));

  m.def("max", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, itpp::Vec<int> &, int)>(&itpp::max)
		          , "Maximum values over each row/column in the matrix m. Also returns a vector of indices with positions of maximum value within a column/row."
			  , py::arg("m"), py::arg("index"), py::arg("dim"));

  m.def("min", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::min)
		          , "Minimum value of vector"
			  , py::arg("v"));

  m.def("min", static_cast<T (*)(const itpp::Vec<T> &, int &)>(&itpp::min)
		          , "Minimum value of vector, also returns the index position of min value"
			  , py::arg("v"), py::arg("index"));

  m.def("min", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::min)
		          , "Minimum values over each row/column in the matrix m"
			  , py::arg("m"), py::arg("dim"));

  m.def("min", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, itpp::Vec<int> &, int)>(&itpp::min)
		          , "Minimum values over each row/column in the matrix m. Also returns a vector of indices with positions of minimum value within a column/row."
			  , py::arg("m"), py::arg("index"), py::arg("dim"));

  m.def("max_index", static_cast<int (*)(const itpp::Vec<T> &)>(&itpp::max_index)
		                , "Return the postion of the maximum element in the vector"
			        , py::arg("in"));

  m.def("max_index", static_cast<void (*)(const itpp::Mat<T> &, int &, int &)>(&itpp::max_index)
		                , "Return the postion of the maximum element in the matrix"
			        , py::arg("m"), py::arg("row"), py::arg("col"));

  m.def("min_index", static_cast<int (*)(const itpp::Vec<T> &)>(&itpp::min_index)
		                , "Return the position of the minimum element in the vector"
			        , py::arg("in"));

  m.def("min_index", static_cast<void (*)(const itpp::Mat<T> &, int &, int &)>(&itpp::min_index)
		                , "Return the position of the minimum element in the matrix"
			        , py::arg("m"), py::arg("row"), py::arg("col"));

}
