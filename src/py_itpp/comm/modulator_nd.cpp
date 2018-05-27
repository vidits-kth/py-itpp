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
#include <itpp/comm/modulator_nd.h>

BOOST_PYTHON_MODULE(modulator_nd) {

  boost::python::docstring_options local_docstring_options(true, true, false);

  // Soft demodulation method
  boost::python::enum_<itpp::Modulator_ND::Soft_Demod_Method>("Soft_Demod_Method")
    .value("FULL_ENUM_LOGMAP", itpp::Modulator_ND::FULL_ENUM_LOGMAP)
    .value("FULL_ENUM_MAXLOG", itpp::Modulator_ND::FULL_ENUM_MAXLOG)
    .value("ZF_LOGMAP", itpp::Modulator_ND::ZF_LOGMAP)
  ;

  boost::python::class_<itpp::Modulator_ND>("Modulator_ND", boost::python::init<itpp::LLR_calc_unit>("Default constructor",
												     boost::python::args("self", "llrcalc_in")))

    .def("set_llrcalc", &itpp::Modulator_ND::set_llrcalc
	              , "Set LLR calculation unit"
		      , boost::python::args("self", "llrcalc_in"))

    .def("get_llrcalc", &itpp::Modulator_ND::get_llrcalc
		      , "Get LLR calculation unit"
		      , boost::python::args("self")
                      , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_dim", &itpp::Modulator_ND::get_dim
		  , "Get number of dimensions"
		  , boost::python::args("self")
                  , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_k", &itpp::Modulator_ND::get_k
                , "Get number of bits per modulation symbol per dimension"
                , boost::python::args("self")
                , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("bits_per_symbol", &itpp::Modulator_ND::bits_per_symbol
		          , "Get number of bits per modulation symbol per dimension"
		          , boost::python::args("self")
		          , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_M", &itpp::Modulator_ND::get_M
		, "Get number of modulation symbols per dimension"
		, boost::python::args("self")
		, boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_bits2symbols", &itpp::Modulator_ND::get_bits2symbols
		           , "Get bit pattern in decimal"
		           , boost::python::args("self")
		           , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("get_bitmap", &itpp::Modulator_ND::get_bitmap
	             , "Get Bit mapping table"
		     , boost::python::args("self")
	  	     , boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  boost::python::class_<itpp::Modulator_NRD, boost::python::bases<itpp::Modulator_ND> >("Modulator_NRD",
											boost::python::init<>("Constructor", boost::python::args("self")))

    .def("get_symbols", &itpp::Modulator_NRD::get_symbols
		      , "Get modulation symbols per dimension"
		      , boost::python::args("self")
		      , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("modulate_bits", static_cast<void (itpp::Modulator_NRD::*)(const itpp::bvec &, itpp::vec &) const>(&itpp::Modulator_NRD::modulate_bits)
		        , "Modulate bits into symbols"
		        , boost::python::args("self", "bits", "symbols"))

    .def("modulate_bits", static_cast<itpp::vec (itpp::Modulator_NRD::*)(const itpp::bvec &) const>(&itpp::Modulator_NRD::modulate_bits)
		        , "Modulate bits vector. Symbols are returned."
		        , boost::python::args("self", "bits")
		        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("init_soft_demodulator", &itpp::Modulator_NRD::init_soft_demodulator
		                , "Soft MAP demodulation for multidimensional channel, by \"brute-force\" enumeration of all constellation points."
				  "It is assumed that H is real-valued. Complex-valued channels can be handled using the Modulator_NCD class."
		                , boost::python::args("self" ,"H", "sigma2"))

    .def("demodulate_soft_bits", static_cast<void (itpp::Modulator_NRD::*)(const itpp::vec &, const itpp::QLLRvec &, itpp::QLLRvec &, itpp::Modulator_ND::Soft_Demod_Method)>(&itpp::Modulator_NRD::demodulate_soft_bits)
				, "Soft MAP demodulation for multidimensional channel, by \"brute-force\" enumeration of all constellation points."
				  "It is assumed that H, y and s are real-valued. Complex-valued channels can be handled using the Modulator_NCD class. Currently the following two demodulation methods are supported:\n"
				  "- FULL_ENUM_LOGMAP - exact demodulation, which use \"brute-force\" enumeration of all constellation points\n"
				  "- FULL_ENUM_MAXLOG - max-log approximate demodulation, which use \"brute-force\" enumeration to find the constellation points that give the smallest euclidian distances\n"
				  "The function performs an exhaustive search over all possible points s in the n-dimensional constellation. "
				  "This is only feasible for relatively small constellations. The Jacobian logarithm is used to compute the sum-exp expression."
				, boost::python::args("self", "y", "LLR_apriori", "LLR_aposteriori", "method"))

    .def("demodulate_soft_bits", static_cast<void (itpp::Modulator_NRD::*)(const itpp::vec &, const itpp::mat &, double, const itpp::QLLRvec &, itpp::QLLRvec &, itpp::Modulator_ND::Soft_Demod_Method)>(&itpp::Modulator_NRD::demodulate_soft_bits)
				, "Soft demodulation wrapper function for various methods Currently the following three demodulation methods are supported: \n"
				  "- FULL_ENUM_LOGMAP - exact demodulation, which use \"brute-force\"   enumeration of all constellation points\n"
				  "- FULL_ENUM_MAXLOG - max-log approximate demodulation, which use \"brute-force\" enumeration to find the constellation points that give the smallest euclidian distances\n"
				  "- ZF_LOGMAP - approximated methods with Zero-Forcing preprocessing, which sometimes tends to perform poorly, especially for poorly conditioned H"
				, boost::python::args("self", "y", "H", "sigma2", "LLR_apriori", "LLR_aposteriori", "method"))

    .def("demodulate_soft_bits", static_cast<itpp::QLLRvec (itpp::Modulator_NRD::*)(const itpp::vec &, const itpp::mat &, double, const itpp::QLLRvec &, itpp::Modulator_ND::Soft_Demod_Method)>(&itpp::Modulator_NRD::demodulate_soft_bits)
				, "Soft demodulation wrapper function for various methods. Currently the following two demodulation methods are supported: \n"
				  "- FULL_ENUM_LOGMAP - exact demodulation, which use \"brute-force\"   enumeration of all constellation points\n"
				  "- ZF_LOGMAP - approximated methods with Zero-Forcing preprocessing, which sometimes tends to perform poorly, especially for poorly conditioned H"
				, boost::python::args("self", "y", "H", "sigma2", "LLR_apriori", "method")
                                , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::Modulator_NRD::*)(const itpp::vec &, const itpp::vec &, double, const itpp::QLLRvec &, itpp::QLLRvec &)>(&itpp::Modulator_NRD::demodulate_soft_bits)
				, "Soft MAP demodulation for parallelchannels without crosstalk. This function is a much faster equivalent to demodulate_soft_bits"
				  "with $H = {diag}(h)$. Its complexity is linear in the number of subchannels."
				, boost::python::args("self", "y", "h", "sigma2", "LLR_apriori", "LLR_aposteriori"))

//    .def("__str__", static_cast(std::ostream (*)(std::ostream &, const itpp::Modulator_NRD &))(&itpp::operator<<)
//	          , "Output some properties of the MIMO modulator (mainly to aid debugging)"
//		  , boost::python::args("self", "os", "m")
//                  , boost::python::return_value_policy<boost::python::return_by_value>())

  ;


  boost::python::class_<itpp::Modulator_NCD, boost::python::bases<itpp::Modulator_ND> >("Modulator_NCD",
											boost::python::init<>("Constructor", boost::python::args("self")))

    .def("get_symbols", &itpp::Modulator_NCD::get_symbols
		      , "Get modulation symbols per dimension"
		      , boost::python::args("self")
		      , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("modulate_bits", static_cast<void (itpp::Modulator_NCD::*)(const itpp::bvec &, itpp::cvec &) const>(&itpp::Modulator_NCD::modulate_bits)
		        , "Modulate bits into symbols"
		        , boost::python::args("self", "bits", "symbols"))

    .def("modulate_bits", static_cast<itpp::cvec (itpp::Modulator_NCD::*)(const itpp::bvec &) const>(&itpp::Modulator_NCD::modulate_bits)
		        , "Modulate bits vector. Symbols are returned."
		        , boost::python::args("self", "bits")
		        , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("init_soft_demodulator", &itpp::Modulator_NCD::init_soft_demodulator
		                , "Soft MAP demodulation for multidimensional channel, by \"brute-force\" enumeration of all constellation points."
				  "It is assumed that H is complex-valued."
		                , boost::python::args("self" ,"H", "sigma2"))

    .def("demodulate_soft_bits", static_cast<void (itpp::Modulator_NCD::*)(const itpp::cvec &, const itpp::QLLRvec &, itpp::QLLRvec &, itpp::Modulator_ND::Soft_Demod_Method)>(&itpp::Modulator_NCD::demodulate_soft_bits)
				, "Soft MAP demodulation for multidimensional channel, by \"brute-force\" enumeration of all constellation points."
				  "It is assumed that H, y and s are real-valued. Complex-valued channels can be handled using the Modulator_NCD class. Currently the following two demodulation methods are supported:\n"
				  "- FULL_ENUM_LOGMAP - exact demodulation, which use \"brute-force\" enumeration of all constellation points\n"
				  "- FULL_ENUM_MAXLOG - max-log approximate demodulation, which use \"brute-force\" enumeration to find the constellation points that give the smallest euclidian distances\n"
				  "The function performs an exhaustive search over all possible points s in the n-dimensional constellation. "
				  "This is only feasible for relatively small constellations. The Jacobian logarithm is used to compute the sum-exp expression."
				, boost::python::args("self", "y", "LLR_apriori", "LLR_aposteriori", "method"))

    .def("demodulate_soft_bits", static_cast<void (itpp::Modulator_NCD::*)(const itpp::cvec &, const itpp::cmat &, double, const itpp::QLLRvec &, itpp::QLLRvec &, itpp::Modulator_ND::Soft_Demod_Method)>(&itpp::Modulator_NCD::demodulate_soft_bits)
				, "Soft demodulation wrapper function for various methods Currently the following three demodulation methods are supported: \n"
				  "- FULL_ENUM_LOGMAP - exact demodulation, which use \"brute-force\"   enumeration of all constellation points\n"
				  "- FULL_ENUM_MAXLOG - max-log approximate demodulation, which use \"brute-force\" enumeration to find the constellation points that give the smallest euclidian distances\n"
				  "- ZF_LOGMAP - approximated methods with Zero-Forcing preprocessing, which sometimes tends to perform poorly, especially for poorly conditioned H"
				, boost::python::args("self", "y", "H", "sigma2", "LLR_apriori", "LLR_aposteriori", "method"))

    .def("demodulate_soft_bits", static_cast<itpp::QLLRvec (itpp::Modulator_NCD::*)(const itpp::cvec &, const itpp::cmat &, double, const itpp::QLLRvec &, itpp::Modulator_ND::Soft_Demod_Method)>(&itpp::Modulator_NCD::demodulate_soft_bits)
				, "Soft demodulation wrapper function for various methods. Currently the following two demodulation methods are supported: \n"
				  "- FULL_ENUM_LOGMAP - exact demodulation, which use \"brute-force\"   enumeration of all constellation points\n"
				  "- ZF_LOGMAP - approximated methods with Zero-Forcing preprocessing, which sometimes tends to perform poorly, especially for poorly conditioned H"
				, boost::python::args("self", "y", "H", "sigma2", "LLR_apriori", "method")
                                , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("demodulate_soft_bits", static_cast<void (itpp::Modulator_NCD::*)(const itpp::cvec &, const itpp::cvec &, double, const itpp::QLLRvec &, itpp::QLLRvec &)>(&itpp::Modulator_NCD::demodulate_soft_bits)
				, "Soft MAP demodulation for parallelchannels without crosstalk. This function is a much faster equivalent to demodulate_soft_bits"
				  "with $H = {diag}(h)$. Its complexity is linear in the number of subchannels."
				, boost::python::args("self", "y", "h", "sigma2", "LLR_apriori", "LLR_aposteriori"))

//    .def("__str__", static_cast(std::ostream (*)(std::ostream &, const itpp::Modulator_NCD &))(&itpp::operator<<)
//	          , "Output some properties of the MIMO modulator (mainly to aid debugging)"
//		  , boost::python::args("self", "os", "m")
//                  , boost::python::return_value_policy<boost::python::return_by_value>())

  ;

  boost::python::class_<itpp::ND_UPAM, boost::python::bases<itpp::Modulator_NRD> >("ND_UPAM",
										   boost::python::init<int, int>("Constructor", boost::python::args("self", "int", "Mary")))
    .def("set_M", static_cast<void (itpp::ND_UPAM::*)(int, int)>(&itpp::ND_UPAM::set_M)
	        , "Set component modulators to M-PAM with Gray mapping"
		, boost::python::args("self", "Nt", "Mary"))

    .def("set_M", static_cast<void (itpp::ND_UPAM::*)(int, itpp::ivec)>(&itpp::ND_UPAM::set_M)
		, "Set component modulators to M-PAM with Gray mapping, different M per component"
		, boost::python::args("self", "Nt", "Mary"))

    .def("sphere_decoding", &itpp::ND_UPAM::sphere_decoding
		          , "Sphere decoding. This function solves the integer-constrained minimization problem"
		            "[{min} |y - Hs|] with respect to $s$ using a sphere decoding algorithm and the Schnorr-Eucner search strategy "
		            "(see the source code for further implementation notes). The function starts with an initial search radius and "
		            "increases it with a factor (stepup) until the search succeeds."
		          , boost::python::args("self", "y", "M", "rmin", "rmax", "stepup", "detected_bits")
                          , boost::python::return_value_policy<boost::python::return_by_value>())
  ;


  boost::python::class_<itpp::ND_UQAM, boost::python::bases<itpp::Modulator_NCD> >("ND_UQAM",
										   boost::python::init<int, int>("Constructor", boost::python::args("self", "int", "Mary")))
    .def("set_M", static_cast<void (itpp::ND_UQAM::*)(int, int)>(&itpp::ND_UQAM::set_M)
	        , "Set component modulators to M-QAM with Gray mapping"
		, boost::python::args("self", "Nt", "Mary"))

    .def("set_M", static_cast<void (itpp::ND_UQAM::*)(int, itpp::ivec)>(&itpp::ND_UQAM::set_M)
		, "Set component modulators to M-QAM with Gray mapping, different M per component"
		, boost::python::args("self", "Nt", "Mary"))

    .def("set_constellation_points", &itpp::ND_UQAM::set_constellation_points
		          , "Set the constellation points"
		          , boost::python::args("self", "nth", "inConstellation", "in_bit2symbols"))
  ;

  boost::python::class_<itpp::ND_UPSK, boost::python::bases<itpp::Modulator_NCD> >("ND_UPSK",
										   boost::python::init<int, int>("Constructor", boost::python::args("self", "int", "Mary")))
    .def("set_M", static_cast<void (itpp::ND_UPSK::*)(int, int)>(&itpp::ND_UPSK::set_M)
	        , "Set component modulators to M-PSK with Gray mapping"
		, boost::python::args("self", "Nt", "Mary"))

    .def("set_M", static_cast<void (itpp::ND_UPSK::*)(int, itpp::ivec)>(&itpp::ND_UPSK::set_M)
		, "Set component modulators to M-PSK with Gray mapping, different M per component"
		, boost::python::args("self", "Nt", "Mary"))
  ;
}
