//! COPYRIGHT_NOTICE

#include <itpp/comm/modulator.h>
#include <boost/python.hpp>

template<class T>
void generate_modulator(char const * name) {

  //============================================================================
  // Template Class Modulator<T>
  //============================================================================
  boost::python::class_<itpp::Modulator<T> >(name, boost::python::init<>())

    //! Constructor
    .def(boost::python::init<const itpp::Vec<T>&, const itpp::ivec&>())
    //Modulator(const Vec<T>& symbols, const ivec& bits2symbols);

    //! Destructor
    // virtual ~Modulator() {}

    //! Set the constellation to use in the modulator
    .def("set", &itpp::Modulator<T>::set)
    //virtual void set(const Vec<T>& symbols, const ivec& bits2symbols);
    //! Returns number of bits per symbol
    .def("bits_per_symbol", &itpp::Modulator<T>::bits_per_symbol)
    //virtual int bits_per_symbol() const { return k; }
    //! Get the symbol values used in the modulator
    .def("get_symbols", &itpp::Modulator<T>::get_symbols)
    //virtual Vec<T> get_symbols() const { return symbols; }
    /*!
     * \brief Get the bitmap, which maps input bits into symbols
     *
     * The mapping is done as follows. An input bit sequence in decimal
     * notation is used for indexing the \c bits2symbols table. The indexing
     * result denotes the symbol to be used from the \c symbols table, e.g.:
     *
     * \code
     * PSK mod(8); // assume 8-PSK modulator
     * cvec sym =  mod.get_symbols();
     * ivec bits2sym = mod.get_bits2symbols();
     * bvec in_bits = "100" // input bits
     * int d = bin2dec(in_bits); // decimal representation of in_bits = 4
     * // mapping of d into PSK symbol using bits2sym and sym tables
     * std::complex<double> out_symbol = sym(bits2sym(d));
     * \endcode
     */
    .def("get_bits2symbols", &itpp::Modulator<T>::get_bits2symbols)
    //virtual ivec get_bits2symbols() const { return bits2symbols; }

    //! Modulation of symbols
    .def("modulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::ivec&,
                                                              itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate))
    //virtual void modulate(const ivec& symbolnumbers, Vec<T>& output) const;
    //! Modulation of symbols
    .def("modulate", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::ivec&) const>(&itpp::Modulator<T>::modulate),
                                 boost::python::return_value_policy<boost::python::return_by_value>())
    //virtual Vec<T> modulate(const ivec& symbolnumbers) const;

    //! Demodulation of symbols
    .def("demodulate", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,
                                                                itpp::ivec&) const>(&itpp::Modulator<T>::demodulate))
    //virtual void demodulate(const Vec<T>& signal, ivec& output) const;
    //! Demodulation of symbols
    .def("demodulate", static_cast<itpp::ivec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate),
                                   boost::python::return_value_policy<boost::python::return_by_value>())
    //virtual ivec demodulate(const Vec<T>& signal) const;

    //! Modulation of bits
    .def("modulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::bvec&,
                                                                   itpp::Vec<T>&) const>(&itpp::Modulator<T>::modulate_bits))
    //virtual void modulate_bits(const bvec& bits, Vec<T>& output) const;
    //! Modulation of bits
    .def("modulate_bits", static_cast<itpp::Vec<T> (itpp::Modulator<T>::*)(const itpp::bvec&) const>(&itpp::Modulator<T>::modulate_bits),
                                      boost::python::return_value_policy<boost::python::return_by_value>())
    //virtual Vec<T> modulate_bits(const bvec& bits) const;

    //! Hard demodulation of bits
    .def("demodulate_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,
                                                                     itpp::bvec&) const>(&itpp::Modulator<T>::demodulate_bits))
    //virtual void demodulate_bits(const Vec<T>& signal, bvec& bits) const;
    //! Hard demodulation of bits
    .def("demodulate_bits", static_cast<itpp::bvec (itpp::Modulator<T>::*)(const itpp::Vec<T>&) const>(&itpp::Modulator<T>::demodulate_bits),
                                        boost::python::return_value_policy<boost::python::return_by_value>())
    //virtual bvec demodulate_bits(const Vec<T>& signal) const;


    /*!
       \brief Soft demodulator for AWGN channels

       This function calculates the log-likelihood ratio (LLR) of the
       received signal from AWGN channels. Depending on the soft demodulation
       method chosen, either full log-MAP calculation is performed (default
       method), according to the following equation: \f[\log \left(
       \frac{P(b_i=0|r)}{P(b_i=1|r)} \right) = \log \left( \frac{\sum_{s_i
       \in S_0} \exp \left( -\frac{|r_k - s_i|^2}{N_0} \right)} {\sum_{s_i
       \in S_1} \exp \left( -\frac{|r_k - s_i|^2}{N_0} \right)} \right) \f]
       or approximate, but faster calculation is performed.

       The approximate method finds for each bit the closest constellation
       points that have zero and one in the corresponding position. Let
       \f$d_0 = |r_k - s_0|\f$ denote the distance to the closest zero point
       and \f$d_1 = |r_k - s_1|\f$ denote the distance to the closest one
       point for the corresponding bit respectively. The approximate
       algorithm then computes \f[\frac{d_1^2 - d_0^2}{N_0}\f]

       This function can be used on channels where the channel gain
       \f$c_k = 1\f$.

       When this function is to be used together with MAP-based turbo
       decoding algorithms then the channel reliability factor \f$L_c\f$ of
       the turbo decoder shall be set to 1. The output from this function can
       also be used by a Viterbi decoder using an AWGN based metric
       calculation function.

       \param rx_symbols The received noisy constellation symbols
       \param N0 The spectral density of the AWGN noise
       \param soft_bits The soft bits calculated using the expression above
       \param method The method used for demodulation (LOGMAP or APPROX)

       \note For soft demodulation it is suggested to use the
       N-dimensional modulator (\c Modulator_ND) instead, which is
       based on the QLLR (quantized) arithmetic and therefore is
       faster. Please note, however, that mixed use of \c
       Modulator_1D/\c Modulator_2D and \c Modulator_ND is not advised.
     */
     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,
                                                                           double,
                                                                           itpp::vec&,
                                                                           itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits))
//     virtual void demodulate_soft_bits(const Vec<T>& rx_symbols, double N0,
//                                       vec& soft_bits,
//                                       Soft_Method method = LOGMAP) const;
     //! Soft demodulator for AWGN channels
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&,
                                                                                double,
                                                                                itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits),
                                              boost::python::return_value_policy<boost::python::return_by_value>())
//     virtual vec demodulate_soft_bits(const Vec<T>& rx_symbols, double N0,
//                                      Soft_Method method = LOGMAP) const;
//
     /*!
       \brief Soft demodulator for fading channels

       This function calculates the log-likelihood ratio (LLR) of the
       received signal from fading channels. Depending on the soft
       demodulation method chosen, either full log-MAP calculation is
       performed (default method), according to the following equation:
       \f[\log \left( \frac{P(b_i=0|r)}{P(b_i=1|r)} \right) = \log \left(
       \frac{\sum_{s_i \in S_0} \exp \left( -\frac{|r_k - c_k s_i|^2}{N_0}
       \right)} {\sum_{s_i \in S_1} \exp \left( -\frac{|r_k - c_k
       s_i|^2}{N_0} \right)} \right) \f] or approximate, but faster
       calculation is performed.

       The approximate method finds for each bit the closest constellation
       points that have zero and one in the corresponding position. Let
       \f$d_0 = |r_k - c_k s_0|\f$ denote the distance to the closest zero
       point and \f$d_1 = |r_k - c_k s_1|\f$ denote the distance to the
       closest one point for the corresponding bit respectively. The
       approximate algorithm then computes \f[\frac{d_1^2 - d_0^2}{N_0}\f]

       When this function is to be used together with MAP-based turbo
       decoding algorithms then the channel reliability factor \f$L_c\f$ of
       the turbo decoder shall be set to 1. The output from this function can
       also be used by a Viterbi decoder using an AWGN based metric
       calculation function.

       \param rx_symbols The received noisy constellation symbols \f$r_k\f$
       \param channel The channel values \f$c_k\f$
       \param N0 The spectral density of the AWGN noise
       \param soft_bits The soft bits calculated using the expression above
       \param method The method used for demodulation (LOGMAP or APPROX)

       \note For soft demodulation it is suggested to use the
       N-dimensional modulator (Modulator_ND) instead, which is based
       on the QLLR (quantized) arithmetic and therefore is
       faster. Please note, however, that mixed use of \c
       Modulator_1D/\c Modulator_2D and \c Modulator_ND is not advised.
     */
     .def("demodulate_soft_bits", static_cast<void (itpp::Modulator<T>::*)(const itpp::Vec<T>&,
                                                                           const itpp::Vec<T>&,
                                                                           double,
                                                                           itpp::vec&,
                                                                           itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits))
//     virtual void demodulate_soft_bits(const Vec<T>& rx_symbols,
//                                       const Vec<T>& channel,
//                                       double N0, vec& soft_bits,
//                                       Soft_Method method = LOGMAP) const;
     //! Soft demodulator for fading channels
     .def("demodulate_soft_bits", static_cast<itpp::vec (itpp::Modulator<T>::*)(const itpp::Vec<T>&,
                                                                                const itpp::Vec<T>&,
                                                                                double,
                                                                                itpp::Soft_Method) const>(&itpp::Modulator<T>::demodulate_soft_bits),
                                              boost::python::return_value_policy<boost::python::return_by_value>())
//     virtual vec demodulate_soft_bits(const Vec<T>& rx_symbols,
//                                      const Vec<T>& channel,
//                                      double N0,
//                                      Soft_Method method = LOGMAP) const;
//
;
}
