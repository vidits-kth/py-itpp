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
#include <pybind11/operators.h>

#include <itpp/comm/convcode.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_convolutional_code_class( py::module &m, const char * name ) {

  py::class_<itpp::Convolutional_Code>( m, name,
					"Binary Convolutional rate 1/n class. The codes are given as feedforward encoders and given in the Proakis form."
					" That is, the binary generators (K-tuples) are converted to octal integers. Observe that the constraint length (K) is defined "
					" as the number of memory cells plus one (as in Proakis). Encoding is performed with the encode function. The default method"
					" for encoding is by adding a tail of K-1 zeros and also assume that the encoder starts in the zero state (the encode_tail()"
					" function). Observe that decode() by default also assumes that a tail is added. Both encoding and decoding method can be changed by"
					" the set_method() function."
					""
					" Comment: ODS-code stand for Optimum Distance Spectrum Code. For details see T. Ottosson, \"Coding, Modulation and Multiuser"
					" Decoding for DS-CDMA Systems,\" Ph.d. thesis, Department of Information Theory, Scool of Electrical and Computer Engineering,"
					" Chalmers University of Technology, Goteborg 1997."
					""
					" It is also possible to set the generator polynomials directly using the builtin tables which consists of: Maximum Free Distance (MFD)"
					" Codes of rates R=1/2 through R=1/8 and Optimum Distance Spectrum (ODS) Codes of rates R=1/2 through R=1/4.")

    .def(py::init<>())

    .def("set_method", &itpp::Convolutional_Code::set_method
	             , "Set encoding and decoding method (Trunc, Tail, or Tailbite)"
		     ,  py::arg("method"))
    .def("set_code", &itpp::Convolutional_Code::set_code
	           , "Set the code according to built-in tables"
	             " The type_of_code can be either MFD or ODS for maximum free distance codes (according to Proakis) "
	             " or Optimum Distance Spectrum Codes according to Frenger, Orten and Ottosson."
                   ,  py::arg("type_of_code"), py::arg("inverse_rate"), py::arg("constraint_length"))

    .def("set_generator_polynomials", &itpp::Convolutional_Code::set_generator_polynomials
                                    , "Set generator polynomials. Given in Proakis integer form"
                                    ,  py::arg("gen"), py::arg("constraint_length"))
    .def("get_generator_polynomials", &itpp::Convolutional_Code::get_generator_polynomials
				    , "Get generator polynomials")

    .def("reset", &itpp::Convolutional_Code::reset
		, "Reset encoder and decoder states")

    .def("encode", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode)
		 , "Encode an input binary vector using specified method (Tail by default)"
		 ,  py::arg("input"), py::arg("output"))
    .def("encode", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode)
		 , "Encode an input binary vector using specified method (Tail by default)"
		 ,  py::arg("input"))

    .def("encode_trunc", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_trunc)
		       , "Encode a binary vector starting from the previous encoder state"
			 " The initial encoder state can be changed using set_start_state() and init_encoder() functions."
		       ,  py::arg("input"), py::arg("output"))
    .def("encode_trunc", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode_trunc)
		       , "Encode a binary vector starting from the previous encoder state"
		         " The initial encoder state can be changed using set_start_state() and init_encoder() functions."
		       ,  py::arg("input"))

   .def("encode_tail", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_tail)
		     , "Encoding that starts and ends in the zero state"
		       " Encode a binary vector of inputs starting from zero state and also adds a tail of K-1 zeros to force the "
		       " encoder into the zero state. Well suited for packet transmission."
		       ""
		       " note The init_encoder() function has no effect on the starting state for this method."
		     ,  py::arg("input"), py::arg("output"))
   .def("encode_tail", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode_tail)
		     , "Encoding that starts and ends in the zero state"
		       " Encode a binary vector of inputs starting from zero state and also adds a tail of K-1 zeros to force the "
		       " encoder into the zero state. Well suited for packet transmission."
		       ""
		       " note The init_encoder() function has no effect on the starting state for this method."
		     ,  py::arg("input"))

   .def("encode_tailbite", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_tailbite)
			 , "Encode an input binary vector using tailbiting."
			   " In the Tailbiting method the starting state of the encoder is initialised with the last K-1 bits of the input vector. This gives an"
			   " additional information to the decoder that the starting and ending states are identical, although not known a priori."
			   " Well suited for packet transmission with small packets, because there is no tail overhead as in the Tail method."
			   " note The init_encoder() function has no effect on the starting state for this method."
			 ,  py::arg("input"), py::arg("output"))
   .def("encode_tailbite", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode_tailbite)
			 , "Encode an input binary vector using tailbiting."
			   " In the Tailbiting method the starting state of the encoder is initialised with the last K-1 bits of the input vector. This gives an"
			   " additional information to the decoder that the starting and ending states are identical, although not known a priori."
			   " Well suited for packet transmission with small packets, because there is no tail overhead as in the Tail method."
			   " note The init_encoder() function has no effect on the starting state for this method."
			 ,  py::arg("input"))

   .def("encode_bit", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bin &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_bit)
		    , "Encode a binary bit starting from the internal encoder state. To initialize the encoder state use set_start_state() and init_encoder()"
		    ,  py::arg("input"), py::arg("output"))
   .def("encode_bit", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bin &)>(&itpp::Convolutional_Code::encode_bit)
		    , "Encode a binary bit starting from the internal encoder state. To initialize the encoder state use set_start_state() and init_encoder()"
		    ,  py::arg("input"))

    .def("decode", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode)
		 , "Decode a block of encoded data using specified method (Tail by default)"
		 ,  py::arg("received_signal"), py::arg("output"))
    .def("decode", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode)
		 , "Decode a block of encoded data using specified method (Tail by default)"
		 ,  py::arg("received_signal"))

    .def("decode_tail", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode_tail)
		      , "Decode a block of encoded data where encode_tail has been used. Thus is assumes a decoder start state of zero and that a tail of"
			" K-1 zeros has been added. No memory truncation."
		      ,  py::arg("received_signal"), py::arg("output"))
    .def("decode_tail", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode_tail)
		      , "Decode a block of encoded data where encode_tail has been used. Thus is assumes a decoder start state of zero and that a tail of"
			" K-1 zeros has been added. No memory truncation."
		      ,  py::arg("received_signal"))

    .def("decode_tailbite", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode_tailbite)
			  , "Decode a block of encoded data where encode_tailbite has been used."
			    " The decoding algorithm tries all start states, so the decode_tailbite() is $2^{K-1}$ times more complex than the"
			    " decode_tail method."
			  ,  py::arg("received_signal"), py::arg("output"))
    .def("decode_tailbite", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode_tailbite)
			  , "Decode a block of encoded data where encode_tailbite has been used. "
			    " The decoding algorithm tries all start states, so the decode_tailbite() is $2^{K-1}$ times more complex than the"
			    " decode_tail method."
			  ,  py::arg("received_signal"))

    .def("decode_trunc", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode_trunc)
			  , "Viterbi decoding using truncation of memory (default = 5*K)."
			  ,  py::arg("received_signal"), py::arg("output"))
    .def("decode_trunc", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode_trunc)
			  , "Viterbi decoding using truncation of memory (default = 5*K)."
			  ,  py::arg("received_signal"))

    .def("get_rate", &itpp::Convolutional_Code::get_rate
		   , "Return rate of code (not including the rate-loss)")

    .def("set_start_state", &itpp::Convolutional_Code::set_start_state
			  , "Set encoder default start state."
			  ,  py::arg("state"))

    .def("init_encoder", &itpp::Convolutional_Code::init_encoder
			  , "Initialise internal encoder state with start state. Has no effect on Tail and Tailbite methods.")

    .def("get_encoder_state", &itpp::Convolutional_Code::get_encoder_state
			    , "Get the current encoder state.")

    .def("set_truncation_length", &itpp::Convolutional_Code::set_truncation_length
				, "Set memory truncation length. Must be at least K."
				,  py::arg("length"))

    .def("get_truncation_length", &itpp::Convolutional_Code::get_truncation_length
				, "Get memory truncation length.")

    .def("catastrophic", &itpp::Convolutional_Code::catastrophic
		       , "Check if catastrophic. Returns true if catastrophic.")

    .def("inverse_tail", &itpp::Convolutional_Code::inverse_tail
		       , "Calculate the inverse sequence. Assumes that encode_tail is used in the encoding process. Returns false if there is an error in the coded"
			 " sequence (not a valid codeword). Do not check that the tail forces the encoder into the zeroth state."
		       ,  py::arg("coded_sequence"), py::arg("input"))

     .def("distance_profile", &itpp::Convolutional_Code::distance_profile
		            , "Calculate distance profile. If reverse = true calculate for the reverse code instead."
		            ,  py::arg("dist_prof"), py::arg("dmax"), py::arg("reverse"))

     .def("calculate_spectrum", &itpp::Convolutional_Code::calculate_spectrum
			      , "Calculate spectrum."
  		                " Calculates both the weight spectrum (Ad) and the information weight spectrum (Cd) and returns it as ivec:s in the 0:th and"
		                " 1:st component of spectrum, respectively. Suitable for calculating many terms in the spectra (uses an breadth first"
		                " algorithm). It is assumed that the code is non-catastrophic or else it is a possibility for an eternal loop."
		                " dmax = an upper bound on the free distance no_terms = no_terms including the dmax term that should be calculated."
		                " Observe that there is a risk that some of the integers are overflow if many terms are calculated in the spectrum."
			      ,  py::arg("spectrum"), py::arg("dmax"), py::arg("no_terms"))

     .def("fast", &itpp::Convolutional_Code::fast
			    , "Cederwall's fast algorithm."
			      " Calculates both the weight spectrum (Ad) and the information weight spectrum (Cd) and returns it as ivec:s in the 0:th and"
			      " 1:st component of spectrum, respectively. The FAST algorithm is good for calculating only a few terms in the spectrum. If many"
			      " terms are desired, use calc_spectrum instead. The algorithm returns -1 if the code tested is worse that the input dfree and"
			      " Cdfree.  It returns 0 if the code MAY be catastrophic (assuming that test_catastrophic is true), and returns 1 if everything"
			      " went right."
			      ""
			      " dfree the free distance of the code (or an upper bound). no_terms including the dfree term that should be calculated. Cdfree is the best "
			      " value of information weight spectrum found so far. Observe that there is a risk that some of the integers are overflow if many terms are "
			      " calculated in the spectrum. See IT No. 6, pp. 1146-1159, Nov. 1989 for details."
			    ,  py::arg("spectrum"), py::arg("dfree"), py::arg("no_terms"), py::arg("Cdfree"), py::arg("test_catastrophic"))
  ;
}
