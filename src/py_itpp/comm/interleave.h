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

#include <itpp/comm/interleave.h>
#include <boost/python.hpp>

//============================================================================
//============================================================================
// Template Class Block_Interleaver<T>
//============================================================================
//============================================================================
template<class T>
void generate_block_interleaver(char const * name) {

  /*! \addtogroup interl
   */

  /*! \ingroup interl
    \class Block_Interleaver comm/interleave.h
    \brief Block Interleaver Class.

    Data is written row-wise and read column-wise when interleaving.
    <h3>Example of use:</h3>
    \code
    BPSK bpsk;
    bvec bits = "0 1 1 0 0 0 1 1 1 1 0 0 1 0 0 1";
    vec symbols = bpsk.modulate_bits(bits);

    Block_Interleaver<double> block_interleaver(4,4);
    vec interleaved_symbols = block_interleaver.interleave(symbols);
    \endcode

  */

  boost::python::class_<itpp::Block_Interleaver<T> >(name, boost::python::init<>())
    //! Block_Interleaver constructor
//    Block_Interleaver(void) {rows = 0; cols = 0;};

    //! Block_Interleaver constructor
	.def(boost::python::init<int, int>())
//    Block_Interleaver(int in_rows, int in_cols);

    //! Function for block interleaving. May add some zeros.
	.def("interleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&)>
			                                                                   (&itpp::Block_Interleaver<T>::interleave),
                       boost::python::return_value_policy<boost::python::return_by_value>())
//    Vec<T> interleave(const Vec<T> &input);

    //! Function for block interleaving. May add some zeros.
	.def("interleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&,
																		itpp::Vec<T>&)>(&itpp::Block_Interleaver<T>::interleave))
//    void interleave(const Vec<T> &input, Vec<T> &output);

    //! Function for block deinterleaving. Removes additional zeros if \a keepzeros = 0.
	.def("deinterleave", static_cast<itpp::Vec<T> (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&, short)>
								  											     (&itpp::Block_Interleaver<T>::deinterleave),
	                     boost::python::return_value_policy<boost::python::return_by_value>())
//    Vec<T> deinterleave(const Vec<T> &input, short keepzeros = 0);

    //! Function for block deinterleaving. Removes additional zeros if \a keepzeros = 0.
	.def("deinterleave", static_cast<void (itpp::Block_Interleaver<T>::*)(const itpp::Vec<T>&,
	  																	  itpp::Vec<T>&, short)>(&itpp::Block_Interleaver<T>::deinterleave))
//    void deinterleave(const Vec<T> &input, Vec<T> &output, short keepzeros = 0);

    //! Set the number of \a rows for block interleaving
    .def("set_rows", &itpp::Block_Interleaver<T>::set_rows)
//    void set_rows(int in_rows) {rows = in_rows;};

    //! Set the number of \a columns for block interleaving
    .def("set_cols", &itpp::Block_Interleaver<T>::set_cols)
//    void set_cols(int in_cols) {cols = in_cols;};

    //! Get the number of \a rows for block interleaving
    .def("get_rows", &itpp::Block_Interleaver<T>::get_rows,
                     boost::python::return_value_policy<boost::python::return_by_value>())
//    int get_rows(void) {return rows;};

    //! Get the number of \a columns for block interleaving
    .def("get_cols", &itpp::Block_Interleaver<T>::get_cols,
                     boost::python::return_value_policy<boost::python::return_by_value>())
//    int get_cols(void) {return cols;};

  ;
}

//============================================================================
//============================================================================
// Template Class Cross_Interleaver<T>
//============================================================================
//============================================================================
template<class T>
void generate_cross_interleaver(char const * name) {

  /*! \ingroup interl
    \class Cross_Interleaver comm/interleave.h
    \brief Cross Interleaver Class.

    <h3> Example of use: </h3>
    \code
    BPSK bpsk;
    bvec bits = "0 1 1 0 0 0 1 1 1 1 0 0 1 0 0 1";
    vec symbols = bpsk.modulate_bits(bits);

    Cross_Interleaver<double> cross_interleaver(4);
    vec interleaved_symbols = cross_interleaver.interleave(symbols);
    \endcode

    <ul>
    <li> See S. B. Wicker, "Error control systems for digital communications and storage,"
    Prentice Hall 1995, p. 427 for details. </li>
    </ul>
  */
  boost::python::class_<itpp::Cross_Interleaver<T> >(name, boost::python::init<>())
    //! Cross_Interleaver constructor
//    Cross_Interleaver(void) {order = 0;};

    //! Cross_Interleaver constructor
    .def(boost::python::init<int>())
//    Cross_Interleaver(int in_order);

	//! Function for cross interleaving. Adds some zeros.
	.def("interleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &)>
                                                                               (&itpp::Cross_Interleaver<T>::interleave),
                       boost::python::return_value_policy<boost::python::return_by_value>())
//    Vec<T> interleave(const Vec<T> &input);

    //! Function for cross interleaving. Adds some zeros.
	.def("interleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &,
			                                                            itpp::Vec<T> &)>(&itpp::Cross_Interleaver<T>::interleave))
//    void interleave(const Vec<T> &input, Vec<T> &output);

    //! Function for cross deinterleaving. Removes aditional zeros if \a keepzeros = 0.
	.def("deinterleave", static_cast<itpp::Vec<T> (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &,
																			      short)>(&itpp::Cross_Interleaver<T>::deinterleave),
 	                     boost::python::return_value_policy<boost::python::return_by_value>())
//    Vec<T> deinterleave(const Vec<T> &input, short keepzeros = 0);

    //! Function for cross deinterleaving. Removes aditional zeros if \a keepzeros = 0.
	.def("deinterleave", static_cast<void (itpp::Cross_Interleaver<T>::*)(const itpp::Vec<T> &,
			   														      itpp::Vec<T> &, short)>(&itpp::Cross_Interleaver<T>::deinterleave))
//    void deinterleave(const Vec<T> &input, Vec<T> &output, short keepzeros = 0);

    //! Set the \a order of the Cross Interleaver
    .def("set_order", &itpp::Cross_Interleaver<T>::set_order)
//    void set_order(int in_order);

    //! Get the \a order of the Cross Interleaver
	.def("get_order", &itpp::Cross_Interleaver<T>::get_order,
                      boost::python::return_value_policy<boost::python::return_by_value>())
//    int get_order(void) {return order;};
  ;
}

//============================================================================
// Template Class Sequence_Interleaver<T>
//============================================================================
//============================================================================
template<class T>
void generate_sequence_interleaver(char const * name) {

  /*! \ingroup interl
    \class Sequence_Interleaver comm/interleave.h
    \brief Sequence Interleaver Class

    <h3> Example of use: </h3>
    \code
    BPSK bpsk;
    bvec bits = "0 1 1 0 0 0 1 1 1 1 0 0 1 0 0 1";
    vec symbols = bpsk.modulate_bits(bits);

    Sequence_Interleaver<double> sequence_interleaver(16);
    sequence_interleaver.randomize_interleaver_sequence();
    vec interleaved_symbols = sequence_snterleaver.interleave(symbols);
    \endcode

  */

  boost::python::class_<itpp::Sequence_Interleaver<T> >(name, boost::python::init<>())
    //! Sequence_Interleaver constructor.
//    Sequence_Interleaver(void) {interleaver_depth = 0;};
    /*!
      \brief Sequence_Interleaver constructor.

      Chooses a random sequence of length \a in_interleaver_depth for interleaving.
    */
    .def(boost::python::init<int>())
//    Sequence_Interleaver(int in_interleaver_depth);

    /*!
     *
      \brief Sequence_Interleaver constructor.

      Uses the \a in_interleaver_sequence for interleaving.
    */
    .def(boost::python::init<int>())
//    Sequence_Interleaver(ivec in_interleaver_sequence);

    //! Function for sequence interleaving. May add some zeros.
	.def("interleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &)>
                                                                                  (&itpp::Sequence_Interleaver<T>::interleave),
                       boost::python::return_value_policy<boost::python::return_by_value>())
//    Vec<T> interleave(const Vec<T> &input);

    //! Function for sequence interleaving. May add some zeros.
	.def("interleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &,
																		   itpp::Vec<T> &)>(&itpp::Sequence_Interleaver<T>::interleave))
//    void interleave(const Vec<T> &input, Vec<T> &output);

    //! Function for sequence deinterleaving. Removes additional zeros if \a keepzeros = 0.
	.def("deinterleave", static_cast<itpp::Vec<T> (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &,
																	                 short)>(&itpp::Sequence_Interleaver<T>::deinterleave),
 					     boost::python::return_value_policy<boost::python::return_by_value>())
//    Vec<T> deinterleave(const Vec<T> &input, short keepzeros = 0);

    //! Function for sequence deinterleaving. Removes additional zeros if \a keepzeros = 0.
    .def("deinterleave", static_cast<void (itpp::Sequence_Interleaver<T>::*)(const itpp::Vec<T> &,
	    															    	 itpp::Vec<T> &, short)>(&itpp::Sequence_Interleaver<T>::deinterleave))
//    void deinterleave(const Vec<T> &input, Vec<T> &output, short keepzeros = 0);

    //! Generate a new random sequence for interleaving.
    .def("randomize_interleaver_sequence", &itpp::Sequence_Interleaver<T>::randomize_interleaver_sequence)
//    void randomize_interleaver_sequence();

    //! Returns the interleaver sequence presently used.
	.def("get_interleaver_sequence", &itpp::Sequence_Interleaver<T>::get_interleaver_sequence,
                                     boost::python::return_value_policy<boost::python::return_by_value>())
//    ivec get_interleaver_sequence();

    //! Set the interleaver sequence to be used.
    .def("set_interleaver_sequence", &itpp::Sequence_Interleaver<T>::set_interleaver_sequence)
//    void set_interleaver_sequence(ivec in_interleaver_sequence);

    //! Set the length of the interleaver sequence to be used.
	.def("set_interleaver_depth", &itpp::Sequence_Interleaver<T>::set_interleaver_depth)
//    void set_interleaver_depth(int in_interleaver_depth) { interleaver_depth = in_interleaver_depth; };

    //! Get the length of the interleaver sequence presently used.
	.def("get_interleaver_depth", &itpp::Sequence_Interleaver<T>::get_interleaver_depth,
			                      boost::python::return_value_policy<boost::python::return_by_value>())
//    int get_interleaver_depth(void) { return interleaver_depth; };
  ;
}
