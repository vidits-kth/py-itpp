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
#include <itpp/base/matfunc.h>

template<class T>
void generate_matfunc_wrapper()
{
  //! sum
  boost::python::def("sum", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::sum)
                          , "Sum of all elements in the vector"
                          , boost::python::args("v")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("sum", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::sum)
                          , "Sum of elements in the matrix m, either along columns or rows"
                          , boost::python::args("m", "dim")
                          , boost::python::return_value_policy<boost::python::return_by_value>());

  //! cumsum
  boost::python::def("cumsum", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &)>(&itpp::cumsum)
                             , "Cumulative sum of all elements in the vector"
                             , boost::python::args("v")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("cumsum", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::sum)
                             , "Cumulative sum of elements in the matrix m"
                             , boost::python::args("m", "dim")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  //! repmat
  boost::python::def("repmat", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &, int)>(&itpp::repmat)
                             , "Creates a vector with n copies of the vector v"
			     , boost::python::args("v", "n")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("repmat", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::repmat)
                             , "Creates a matrix with m by n copies of the matrix data"
                             , boost::python::args("data", "rows", "cols")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("repmat", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, int, int, bool)>(&itpp::repmat)
                             , "Returns a matrix with m by n copies of the vector data"
                             , boost::python::args("data", "rows", "cols", "transpose")
                             , boost::python::return_value_policy<boost::python::return_by_value>());

  //! vectorize
  boost::python::def("rvectorize", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &)>(&itpp::rvectorize)
                                 , "Row vectorize the matrix [(0,0) (0,1) ... (N-1,N-2) (N-1,N-1)]"
                                 , boost::python::args("m")
                                 , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("cvectorize", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &)>(&itpp::rvectorize)
                                 , "Column vectorize the matrix [(0,0) (1,0) ... (N-2,N-1) (N-1,N-1)]"
                                 , boost::python::args("m")
                                 , boost::python::return_value_policy<boost::python::return_by_value>());

  //! reshape
  boost::python::def("reshape", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::reshape)
                              , "Reshape the matrix into an rows*cols matrix"
                              , boost::python::args("m", "rows", "cols")
                              , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("reshape", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, int, int)>(&itpp::reshape)
                              , "Reshape the vector into an rows*cols matrix"
                              , boost::python::args("v", "rows", "cols")
                              , boost::python::return_value_policy<boost::python::return_by_value>());
}
