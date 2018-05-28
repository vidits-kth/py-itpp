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
#include <itpp/comm/convcode.h>

BOOST_PYTHON_MODULE(convcode) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  //! Type of Convolutional Code
  boost::python::enum_<itpp::CONVOLUTIONAL_CODE_TYPE>("CONVOLUTIONAL_CODE_TYPE")
    .value("MFD", itpp::MFD)
    .value("ODS", itpp::ODS)
  ;

  //! Encoding and decoding methods for Convolutional codes
  boost::python::enum_<itpp::CONVOLUTIONAL_CODE_METHOD>("CONVOLUTIONAL_CODE_METHOD")
    .value("Trunc", itpp::Trunc)
    .value("Tail", itpp::Tail)
    .value("Tailbite", itpp::Tailbite)
  ;

  boost::python::class_<itpp::Convolutional_Code>("Convolutional_Code",
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
						  " Codes of rates R=1/2 through R=1/8 and Optimum Distance Spectrum (ODS) Codes of rates R=1/2 through R=1/4.",
						  boost::python::init<>())

    .def("set_method", &itpp::Convolutional_Code::set_method
	             , "Set encoding and decoding method (Trunc, Tail, or Tailbite)"
		     , boost::python::args("self", "method"))
    .def("set_code", &itpp::Convolutional_Code::set_code
	           , "Set the code according to built-in tables"
	             " The type_of_code can be either MFD or ODS for maximum free distance codes (according to Proakis) "
	             " or Optimum Distance Spectrum Codes according to Frenger, Orten and Ottosson."
                   , boost::python::args("self", "type_of_code", "inverse_rate", "constraint_length"))

    .def("set_generator_polynomials", &itpp::Convolutional_Code::set_generator_polynomials
                                    , "Set generator polynomials. Given in Proakis integer form"
                                    , boost::python::args("self", "gen", "constraint_length"))
    .def("get_generator_polynomials", &itpp::Convolutional_Code::get_generator_polynomials
				    , "Get generator polynomials"
				    , boost::python::args("self")
				    , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("reset", &itpp::Convolutional_Code::reset
		, "Reset encoder and decoder states"
		, boost::python::args("self"))

    .def("encode", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode)
		 , "Encode an input binary vector using specified method (Tail by default)"
		 , boost::python::args("self", "input", "output"))
    .def("encode", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode)
		 , "Encode an input binary vector using specified method (Tail by default)"
		 , boost::python::args("self", "input")
                 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("encode_trunc", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_trunc)
		       , "Encode a binary vector starting from the previous encoder state"
			 " The initial encoder state can be changed using set_start_state() and init_encoder() functions."
		       , boost::python::args("self", "input", "output"))
    .def("encode_trunc", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode_trunc)
		       , "Encode a binary vector starting from the previous encoder state"
		         " The initial encoder state can be changed using set_start_state() and init_encoder() functions."
		       , boost::python::args("self", "input")
		       , boost::python::return_value_policy<boost::python::return_by_value>())

   .def("encode_tail", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_tail)
		     , "Encoding that starts and ends in the zero state"
		       " Encode a binary vector of inputs starting from zero state and also adds a tail of K-1 zeros to force the "
		       " encoder into the zero state. Well suited for packet transmission."
		       ""
		       " note The init_encoder() function has no effect on the starting state for this method."
		     , boost::python::args("self", "input", "output"))
   .def("encode_tail", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode_tail)
		     , "Encoding that starts and ends in the zero state"
		       " Encode a binary vector of inputs starting from zero state and also adds a tail of K-1 zeros to force the "
		       " encoder into the zero state. Well suited for packet transmission."
		       ""
		       " note The init_encoder() function has no effect on the starting state for this method."
		     , boost::python::args("self", "input")
		     , boost::python::return_value_policy<boost::python::return_by_value>())

   .def("encode_tailbite", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bvec &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_tailbite)
			 , "Encode an input binary vector using tailbiting."
			   " In the Tailbiting method the starting state of the encoder is initialised with the last K-1 bits of the input vector. This gives an"
			   " additional information to the decoder that the starting and ending states are identical, although not known a priori."
			   " Well suited for packet transmission with small packets, because there is no tail overhead as in the Tail method."
			   " note The init_encoder() function has no effect on the starting state for this method."
			 , boost::python::args("self", "input", "output"))
   .def("encode_tailbite", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bvec &)>(&itpp::Convolutional_Code::encode_tailbite)
			 , "Encode an input binary vector using tailbiting."
			   " In the Tailbiting method the starting state of the encoder is initialised with the last K-1 bits of the input vector. This gives an"
			   " additional information to the decoder that the starting and ending states are identical, although not known a priori."
			   " Well suited for packet transmission with small packets, because there is no tail overhead as in the Tail method."
			   " note The init_encoder() function has no effect on the starting state for this method."
			 , boost::python::args("self", "input")
			 , boost::python::return_value_policy<boost::python::return_by_value>())

   .def("encode_bit", static_cast<void (itpp::Convolutional_Code::*)(const itpp::bin &, itpp::bvec &)>(&itpp::Convolutional_Code::encode_bit)
		    , "Encode a binary bit starting from the internal encoder state. To initialize the encoder state use set_start_state() and init_encoder()"
		    , boost::python::args("self", "input", "output"))
   .def("encode_bit", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::bin &)>(&itpp::Convolutional_Code::encode_bit)
		    , "Encode a binary bit starting from the internal encoder state. To initialize the encoder state use set_start_state() and init_encoder()"
		    , boost::python::args("self", "input")
		    , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("decode", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode)
		 , "Decode a block of encoded data using specified method (Tail by default)"
		 , boost::python::args("self", "received_signal", "output"))
    .def("decode", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode)
		 , "Decode a block of encoded data using specified method (Tail by default)"
		 , boost::python::args("self", "received_signal")
		 , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("decode_tail", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode_tail)
		      , "Decode a block of encoded data where encode_tail has been used. Thus is assumes a decoder start state of zero and that a tail of"
			" K-1 zeros has been added. No memory truncation."
		      , boost::python::args("self", "received_signal", "output"))
    .def("decode_tail", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode_tail)
		      , "Decode a block of encoded data where encode_tail has been used. Thus is assumes a decoder start state of zero and that a tail of"
			" K-1 zeros has been added. No memory truncation."
		      , boost::python::args("self", "received_signal")
		      , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("decode_tailbite", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode_tailbite)
			  , "Decode a block of encoded data where encode_tailbite has been used."
			    " The decoding algorithm tries all start states, so the decode_tailbite() is $2^{K-1}$ times more complex than the"
			    " decode_tail method."
			  , boost::python::args("self", "received_signal", "output"))
    .def("decode_tailbite", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode_tailbite)
			  , "Decode a block of encoded data where encode_tailbite has been used. "
			    " The decoding algorithm tries all start states, so the decode_tailbite() is $2^{K-1}$ times more complex than the"
			    " decode_tail method."
			  , boost::python::args("self", "received_signal")
			  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("decode_trunc", static_cast<void (itpp::Convolutional_Code::*)(const itpp::vec &, itpp::bvec &)>(&itpp::Convolutional_Code::decode_trunc)
			  , "Viterbi decoding using truncation of memory (default = 5*K)."
			  , boost::python::args("self", "received_signal", "output"))
    .def("decode_trunc", static_cast<itpp::bvec (itpp::Convolutional_Code::*)(const itpp::vec &)>(&itpp::Convolutional_Code::decode_trunc)
			  , "Viterbi decoding using truncation of memory (default = 5*K)."
			  , boost::python::args("self", "received_signal")
			  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_rate", &itpp::Convolutional_Code::get_rate
		   , "Return rate of code (not including the rate-loss)"
		   , boost::python::args("self")
		   , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("set_start_state", &itpp::Convolutional_Code::set_start_state
			  , "Set encoder default start state."
			  , boost::python::args("self", "state"))

    .def("init_encoder", &itpp::Convolutional_Code::init_encoder
			  , "Initialise internal encoder state with start state. Has no effect on Tail and Tailbite methods."
			  , boost::python::args("self"))

    .def("get_encoder_state", &itpp::Convolutional_Code::get_encoder_state
			    , "Get the current encoder state."
			    , boost::python::args("self")
			    , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("set_truncation_length", &itpp::Convolutional_Code::set_truncation_length
				, "Set memory truncation length. Must be at least K."
				, boost::python::args("self", "length"))

    .def("get_truncation_length", &itpp::Convolutional_Code::get_truncation_length
				, "Get memory truncation length."
				, boost::python::args("self")
				, boost::python::return_value_policy<boost::python::return_by_value>())

    .def("catastrophic", &itpp::Convolutional_Code::catastrophic
		       , "Check if catastrophic. Returns true if catastrophic."
		       , boost::python::args("self")
		       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("inverse_tail", &itpp::Convolutional_Code::inverse_tail
		       , "Calculate the inverse sequence. Assumes that encode_tail is used in the encoding process. Returns false if there is an error in the coded"
			 " sequence (not a valid codeword). Do not check that the tail forces the encoder into the zeroth state."
		       , boost::python::args("self", "coded_sequence", "input")
		       , boost::python::return_value_policy<boost::python::return_by_value>())

     .def("distance_profile", &itpp::Convolutional_Code::distance_profile
		            , "Calculate distance profile. If reverse = true calculate for the reverse code instead."
		            , boost::python::args("self", "dist_prof", "dmax", "reverse"))

     .def("calculate_spectrum", &itpp::Convolutional_Code::calculate_spectrum
			      , "Calculate spectrum."
  		                " Calculates both the weight spectrum (Ad) and the information weight spectrum (Cd) and returns it as ivec:s in the 0:th and"
		                " 1:st component of spectrum, respectively. Suitable for calculating many terms in the spectra (uses an breadth first"
		                " algorithm). It is assumed that the code is non-catastrophic or else it is a possibility for an eternal loop."
		                " dmax = an upper bound on the free distance no_terms = no_terms including the dmax term that should be calculated."
		                " Observe that there is a risk that some of the integers are overflow if many terms are calculated in the spectrum."
			      , boost::python::args("self", "spectrum", "dmax", "no_terms"))

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
			    , boost::python::args("self", "spectrum", "no_terms", "Cdfree", "test_catastrophic")
                            , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  boost::python::def("reverse_int", &itpp::reverse_int
                                  , "Reverses the bitrepresentation of in (of size length) and converts to an integer"
                                  , boost::python::args("length", "in")
                                  , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("reverse_int", &itpp::reverse_int
                                  , "Reverses the bitrepresentation of in (of size length) and converts to an integer"
                                  , boost::python::args("length", "in")
                                  , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("weight_int", &itpp::weight_int
                                 , " Calculate the Hamming weight of the binary representation of in of size length"
                                 , boost::python::args("length", "in")
                                 , boost::python::return_value_policy<boost::python::return_by_value>());

  boost::python::def("compare_spectra", static_cast<int (*)(itpp::ivec, itpp::ivec)>(&itpp::compare_spectra)
                                      , "Compare two distance spectra. Return 1 if v1 is less, 0 if v2 less, and -1 if equal."
                                      , boost::python::args("v1", "v2")
                                      , boost::python::return_value_policy<boost::python::return_by_value>());
  boost::python::def("compare_spectra", static_cast<int (*)(itpp::ivec, itpp::ivec, itpp::vec)>(&itpp::compare_spectra)
                                      , "Compare two distance spectra using a weight profile."
                                      , boost::python::args("v1", "v2", "weight_profile")
                                      , boost::python::return_value_policy<boost::python::return_by_value>());
}
