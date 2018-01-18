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

#include <itpp/comm/hammcode.h>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hammcode)
{
  boost::python::class_<itpp::Hamming_Code>("hamming_code", boost::python::init<short>())
    //! Constructor for \c hamming(n,k). n = pow(2,m)-1 and k = pow(2,m)-m-1.
//  Hamming_Code(short m);

    //! Destructor
//    virtual ~Hamming_Code() { }

    //! Hamming encoder. Will truncate some bits if not \a length = \c integer * \a k.
    .def("encode", static_cast<void (itpp::Hamming_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Hamming_Code::encode))
//    virtual void encode(const bvec &uncoded_bits, bvec &coded_bits);
    //! Hamming encoder. Will truncate some bits if not \a length = \c integer * \a k.
    .def("encode", static_cast<itpp::bvec (itpp::Hamming_Code::*)(const itpp::bvec &)>(&itpp::Hamming_Code::encode),
                                                                boost::python::return_value_policy<boost::python::return_by_value>())
//    virtual bvec encode(const bvec &uncoded_bits);

    //! Hamming decoder. Will truncate some bits if not \a length = \c integer * \a n.
    .def("decode", static_cast<void (itpp::Hamming_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Hamming_Code::decode))
//    virtual void decode(const bvec &coded_bits, bvec &decoded_bits);
    //! Hamming decoder. Will truncate some bits if not \a length = \c integer * \a n.
    .def("decode", static_cast<itpp::bvec (itpp::Hamming_Code::*)(const itpp::bvec &)>(&itpp::Hamming_Code::decode),
                                                                boost::python::return_value_policy<boost::python::return_by_value>())
//    virtual bvec decode(const bvec &coded_bits);

    // Soft-decision decoding is not implemented
//    virtual void decode(const vec &received_signal, bvec &output);
//    virtual bvec decode(const vec &received_signal);

    //! Get the code rate
    .def("get_rate", &itpp::Hamming_Code::get_rate)
//    virtual double get_rate() const { return static_cast<double>(k) / n; };
    //! Gets the code length \a n.
    .def("get_n", &itpp::Hamming_Code::get_n)
//    short get_n() const { return n; };
    //! Gets the number of information bits per code word, \a k.
    .def("get_k", &itpp::Hamming_Code::get_k)
//    short get_k() const { return k; };
    //! Gets the parity check matrix for the code.
    .def("get_H", &itpp::Hamming_Code::get_H)
//    bmat get_H() const { return H; };
    //! Gets the generator matrix for the code.
    .def("get_G", &itpp::Hamming_Code::get_G)
//    bmat get_G() const { return G; };
  ;
}
