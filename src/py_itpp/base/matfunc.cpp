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

BOOST_PYTHON_MODULE(matfunc)
{
  boost::python::def("repmat", static_cast<itpp::vec (*)(const itpp::vec &, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::cvec (*)(const itpp::cvec &, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::ivec (*)(const itpp::ivec &, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::svec (*)(const itpp::svec &, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::bvec (*)(const itpp::bvec &, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::mat (*)(const itpp::vec &, int, int, bool)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::cmat (*)(const itpp::cvec &, int, int, bool)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::imat (*)(const itpp::ivec &, int, int, bool)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::smat (*)(const itpp::svec &, int, int, bool)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::bmat (*)(const itpp::bvec &, int, int, bool)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::mat (*)(const itpp::mat &, int, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::cmat (*)(const itpp::cmat &, int, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::imat (*)(const itpp::imat &, int, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::smat (*)(const itpp::smat &, int, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("repmat", static_cast<itpp::bmat (*)(const itpp::bmat &, int, int)>(&itpp::repmat)
                             , boost::python::return_value_policy<boost::python::return_by_value>());
}
