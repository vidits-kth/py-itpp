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

#include <itpp/base/matfunc.h>

namespace py = pybind11;

template<class T>
void generate_pybind_wrapper_for_matfunc_module(py::module &m) {

  //! sum
  m.def("sum", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::sum));
  m.def("sum", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::sum));

  //! cumsum
  m.def("cumsum", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &)>(&itpp::cumsum));
  m.def("cumsum", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::sum));

  //! repmat
  m.def("repmat", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &, int)>(&itpp::repmat));
  m.def("repmat", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::repmat));
  m.def("repmat", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, int, int, bool)>(&itpp::repmat));

  //! vectorize
  m.def("rvectorize", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &)>(&itpp::rvectorize));
  m.def("cvectorize", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &)>(&itpp::rvectorize));

  //! reshape
  m.def("reshape", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::reshape));
  m.def("reshape", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, int, int)>(&itpp::reshape));

}
