//! COPYRIGHT_NOTICE

#include <boost/python.hpp>
#include <itpp/comm/turbo.h>

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(set_parameters_overloads, itpp::Turbo_Codec::set_parameters, 4, 9)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(set_metric_overloads, itpp::Turbo_Codec::set_metric, 0, 3)

BOOST_PYTHON_MODULE(turbo)
{
  boost::python::class_<itpp::Turbo_Codec>("turbo_codec", boost::python::init<>())

    //! Class constructor
//    Turbo_Codec(void) {}

    //! Class destructor
//    virtual ~Turbo_Codec(void) {}

    /*!
      \brief Set parameters for the turbo encoder/decoder

      \param gen1 A vector with \a n1 elements containing the generator polynomials for the first constituent encoder
      \param gen2 A vector with \a n2 elements containing the generator polynomials for the second constituent encoder
      \param constraint_length The constraint length of the two constituent encoders
      \param interleaver_sequence An ivec defining the internal turbo interleaver.
      \param in_iterations The number of decoding iterations. Default value is 8.
      \param in_metric Determines the decoder metric: "MAP", LOGMAP", "LOGMAX", or "TABLE". The default is "LOGMAX".
      \param in_logmax_scale_factor The extrinsic information from each constituent decoder is to optimistic when
      LOGMAX decoding is used.
      This parameter allows for a down-scaling of the extrinsic information that will be passed on to the next decoder.
      The default value
      is 1.0. This parameter is ignored for other metrics than "LOGMAX".
      \param in_adaptive_stop If this parameter is true, then the iterations will stop if the decoding results after one
      full iteration equals the previous iteration. Default value is false.

      \param lcalc This parameter can be used to provide a specific \c LLR_calc_unit which defines the resolution in
      the table-lookup if decoding with the metric "TABLE" is used.
    */
    .def("set_parameters", &itpp::Turbo_Codec::set_parameters, set_parameters_overloads())
//    void set_parameters(ivec gen1, ivec gen2, int constraint_length,
//                        const ivec &interleaver_sequence, int in_iterations = 8,
//                        std::string in_metric = "LOGMAX", double in_logmax_scale_factor = 1.0,
//                        bool in_adaptive_stop = false, LLR_calc_unit lcalc = LLR_calc_unit());

    /*!
      \brief Set a new internal interleaver sequence for the turbo encoder/decoder

      By changing the interleaver sequence it is possible to change the code word size of the turbo codec. Note that you
      still must use the \a set_parameters function first to set the other parameters of the turbo codec.
    */
    .def("set_interleaver", &itpp::Turbo_Codec::set_interleaver)
//    void set_interleaver(const ivec &interleaver_sequence);

    /*!
      \brief Set the decoder metric

      \param in_metric Determines the decoder metric: "MAP", LOGMAP", "LOGMAX", or "TABLE". The default is "LOGMAX".
      \param in_logmax_scale_factor The extrinsic information from each constituent decoder is to optimistic when
      LOGMAX decoding is used.
      This parameter allows for a down-scaling of the extrinsic information that will be passed on to the next decoder.
      The default value is 1.0. This parameter is ignored for other metrics than "LOGMAX".

      \param lcalc This parameter can be used to provide a specific \c LLR_calc_unit which defines the resolution in
      the table-lookup if decoding with the metric "TABLE" is used.
    */
    .def("set_metric", &itpp::Turbo_Codec::set_metric, set_metric_overloads())
//    void set_metric(std::string in_metric = "LOGMAX", double in_logmax_scale_factor = 1.0,
//                    LLR_calc_unit lcalc = LLR_calc_unit());

    /*!
      \brief Sets the number of decoding iterations. Default value is 8.
    */
    .def("set_iterations", &itpp::Turbo_Codec::set_iterations)
//    void set_iterations(int in_iterations = 8);

    /*!
      \brief Use and adaptive number of iterations

      When the adaptive stop criterion is used the iterations will stop before the maximum number of iterations is
      executed if the decoding results after one full iteration equals the previous iteration. Default value is \c true.
    */
    .def("set_adaptive_stop", &itpp::Turbo_Codec::set_adaptive_stop)
//    void set_adaptive_stop(bool in_adaptive_stop = true);

    /*!
      \brief Set parameters for decoding on an AWGN channel

      \param in_Ec The received energy per channel symbol (i.e. per soft input bit)
      \param in_N0 The single sided spectral density of the AWGN noise
    */
    .def("set_awgn_channel_parameters", &itpp::Turbo_Codec::set_awgn_channel_parameters)
//    void set_awgn_channel_parameters(double in_Ec, double in_N0);

    /*!
      \brief Set scaling factor for decoding on e.g. Rayleigh fading channels

      Setting the correct value of the channel reliability function is important for MAP decoder algorithms. However, if
      the Log-MAX decoding algorithm is used, then the value of \a Lc is not important. Assuming that the received soft
      values \f$r_k\f$ from the channel equal

      \f[ r_k = h_k c_k + w_k \f]

      where \f$h_k\f$ is the (complex valued) channel gain, \f$c_k\f$ is the transmitted symbol equal to
      \f$\{-\sqrt{E_c},+\sqrt{E_c}\}\f$, and \f$w_k\f$ is the AWGN (complex valued) noise with total variance
      of the real plus imaginary part equal to \f$N_0\f$. The input to the turbo decoder shall then be

      \f[ z_k = \hat{h}_k^{*} r_k \f]

      where \f$\hat{h}_k^{*}\f$ is the conjugate of the channel estimate. Assuming that the channel estimate is perfect,
      the channel reliability factor shall be set to

      \f[ L_c = 4\sqrt{E_c} / {N_0} \f]

      \param in_Lc the channel reliability factor of the channel.
    */
    .def("set_scaling_factor", &itpp::Turbo_Codec::set_scaling_factor)
//    void set_scaling_factor(double in_Lc);

    /*!
      \brief Encoder function

      This function can encode several consecutive coding blocks. The output is organized as follows:

      \f[ s(1), p_{1,1}(1), p_{1,2}(1), \ldots , p_{1,n_1}(1), p_{2,1}(1), p_{2,2}(1), \ldots , p_{2,n_2}(1), s(2), \ldots \f]

      In the above expression \f$s(n)\f$ is the n-th systematic bit and \f$p_{l,k}(n)\f$ is the n-th bit from the k-th
      encoder polynomial of the l-th constituent encoder. A tail of both systematic and parity bits is added after each
      coding block to force both encoder to the zero state. The tail of each encoder is structured as follows (using
      encoder one as an example):

      \f[ t_1(1), pt_{1,1}(1), pt_{1,2}(1), \ldots , pt_{1,n_1}(1), \ldots pt_{1,n_1}(m) \f]

      The tailbits from the first encoder are placed before the tailbits from the second encoder.

      \param input The input bits to the encoder. Must contain an integer number of code blocks
      \param output The encoded bits including two tail, one from each constituent encoder, after each coding block.
    */
    .def("encode", &itpp::Turbo_Codec::encode)
//    void encode(const bvec &input, bvec &output);


    /*!
      \brief Decoder function

      This function can decode several consecutive coding blocks that were encoded with the encode member function

      \param received_signal The vector of received bits
      \param decoded_bits A vector of decoded bits
      \param true_bits If this input vector is provided then the iterations will stop as soon as the decoded bits
      equals the \c true_bits. Note that this feature can not be used if the \c in_adaptive_stop parameter in the
      setup function is set to \c true.
    */
    .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                           itpp::bvec &,
                                                           const itpp::bvec &)>(&itpp::Turbo_Codec::decode))
//    virtual void decode(const vec &received_signal, bvec &decoded_bits, const bvec &true_bits = "0");

    /*!
      \brief Decoder function

      This function can decode several consecutive coding blocks that were encoded with the encode member function

      \param received_signal The vector of received bits
      \param decoded_bits A vector of decoded bits
      \param nrof_used_iterations Returns the number of used iterations for each code block.
      \param true_bits If this input vector is provided then the iterations will stop as soon as the decoded bits
      equals the \c true_bits. Note that this feature can not be used if the \c in_adaptive_stop parameter in the
      setup function is set to \c true.
    */
   .def("decode", static_cast<void (itpp::Turbo_Codec::*)(const itpp::vec &,
                                                          itpp::bvec &, itpp::ivec &,
                                                          const itpp::bvec &)>(&itpp::Turbo_Codec::decode))
//    virtual void decode(const vec &received_signal, bvec &decoded_bits, ivec &nrof_used_iterations,
//                        const bvec &true_bits = "0");

    /*!
      \brief Encode a single block

      This function is useful if rate matching is to be applied after the turbo encoder. The size of \a in1 and \a in2
      equals the size of \a input plus the tail bits. Tailbits are appended ate the end of \a in1 and \a in2. The number
      of rows in \a parity1 and \a parity2 equals the lengths of \a in1 and \a in2 respectively. The number of columns of
      \a parity1 and \a parity2 equals the number of parity bits from the first and the second constituent encoders
      respectively.

      \param input The input bits to the encoder. Must contain a single code block
      \param in1 The input bits to the first constituent encoder with a tail added at the end
      \param in2 The input bits to the second constituent encoder (i.e. the interleaved data bits) with a tail
      added at the end
      \param parity1 The parity bits from the first constituent encoder (including parity bits for the first tail)
      \param parity2 The parity bits from the second constituent encoder (including parity bits for the second tail)
    */
    .def("encode_block", &itpp::Turbo_Codec::encode_block)
//    void encode_block(const bvec &input, bvec &in1, bvec &in2, bmat &parity1, bmat &parity2);

    /*!
      \brief Decode a single block

      This function can decode a single coding blocks that was encoded with the encode_block member function.
      In order to speed up the decoding process it is possible to input the correct data bits. If this information
      is provided the decoder can stop iterating as soon as the decoded bits match the correct data bits. This
      simulation trick can greatly speed up the simulation time for high SNR cases when only a few iterations are
      required. If errors still exist after the maximum number of iterations have been performed, the decoding
      process stops.

      The matrix \a decoded_bits_i contains the result from decoding iteration \a i on row \a i. Even though both
      \a rec_syst1 and \a rec_syst2 are given as inputs, the systematic bits in \a rec_syst2 will in most cases be
      punctured and only the tailbits at the end of the vector \a rec_syst2 will have values different from zero.

      \note This decoding function assumes that the input is scaled as +-2*SNR + noise. This means that the channel
      reliability factor \a Lc must be equal to 1.0. No additional scaling is performed by this function.

      \param rec_syst1 The received input bits to the first constituent decoder with a tail added at the end
      \param rec_syst2 The received input bits to the second constituent decoder with a tail added at the end
      \param rec_parity1 The received parity bits for the first constituent decoder (including parity bits for the
      first tail)
      \param rec_parity2 The received parity bits for the second constituent decoder (including parity bits for
      the second tail)
      \param decoded_bits_i Contains the result from decoding iteration \a i on row \a i.
      \param nrof_used_iterations_i Returns the number of iterations used for decoding
      of this block.
      \param true_bits Optional input parameter. If given, the iterations will stop as soon as the decoded bits
      match the true bits.
    */
    .def("decode_block", &itpp::Turbo_Codec::decode_block)
//    virtual void decode_block(const vec &rec_syst1, const vec &rec_syst2, const mat &rec_parity1, const mat &rec_parity2,
//                              bmat &decoded_bits_i, int &nrof_used_iterations_i, const bvec &true_bits = "0");

    //! Get number of coded bits
    .def("get_Ncoded", &itpp::Turbo_Codec::get_Ncoded, boost::python::return_value_policy<boost::python::return_by_value>())
//    int get_Ncoded() const { return Ncoded; }

    //! Get number of uncoded bits
    .def("get_Nuncoded", &itpp::Turbo_Codec::get_Nuncoded, boost::python::return_value_policy<boost::python::return_by_value>())
//    int get_Nuncoded() const { return Nuncoded; }
  ;
}
