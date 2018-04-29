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

#include "matfunc.h"

BOOST_PYTHON_MODULE(matfunc)
{
  boost::python::docstring_options local_docstring_options(true, true, false);

  generate_matfunc_wrapper<double>();
  generate_matfunc_wrapper<std::complex<double> >();
  generate_matfunc_wrapper<int>();
  generate_matfunc_wrapper<itpp::bin>();
  generate_matfunc_wrapper<short>();

  //! sqrtm
  boost::python::def("sqrtm", static_cast<itpp::cmat (*)(const itpp::cmat &)>(&itpp::sqrtm)
                            , "Square root of the complex square matrix m"
                            , boost::python::args("m")
                            , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("sqrtm", static_cast<itpp::cmat (*)(const itpp::mat &)>(&itpp::sqrtm)
                            , "Square root of the real square matrix m"
                            , boost::python::args("m")
                            , boost::python::return_value_policy<boost::python::return_by_value>());

}
