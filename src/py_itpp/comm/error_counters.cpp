//! COPYRIGHT_NOTICE

#include <itpp/comm/error_counters.h>
#include <boost/python.hpp>


//! TODO: This doesn't compile when used, find a fix
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(count_errors_overloads, itpp::BERC::count_errors, 2, 5)

BOOST_PYTHON_MODULE(error_counters)
{
  boost::python::class_<itpp::BERC>("BERC", boost::python::init<int, int, int>())

    /*!
      \brief Constructor for the berc class.

      <ul>
      <li> \a delay is positive if \a in2 is a delayed replica of
      \a in1 and negative otherwise. </li>
      <li> \a ignorefirst and \a ignorelast may be used if errors in
      the begining and/or the end is to be ignored.</li>
      </ul>
    */
//     BERC(int indelay = 0, int inignorefirst = 0, int inignorelast = 0);

    //! Cumulative error counter
//    .def("count", &itpp::BERC::count)
//    void count(const bvec &in1, const bvec &in2);
    //! Run this member function if the delay between \a in1 and
    //! \a in2 is unknown.
    .def("estimate_delay", &itpp::BERC::estimate_delay)
//    void estimate_delay(const bvec &in1, const bvec &in2, int mindelay = -100,
//                        int maxdelay = 100);
    //! Clears the bit error counter
    .def("clear", &itpp::BERC::clear)
//    void clear() { errors = 0; corrects = 0; }
    //! Writes an error report
    .def("report", &itpp::BERC::report)
//    void report() const;
    //! Return the \a delay, assumed or estimated, between \a in1 and \a in2.
    .def("get_delay", &itpp::BERC::get_delay)
//    int get_delay() const { return delay; }
    //! Returns the counted number of bit errors
    .def("get_errors", &itpp::BERC::get_errors)
//    double get_errors() const { return errors; }
    //! Returns the counted number of corectly received bits
    .def("get_corrects", &itpp::BERC::get_corrects)
//    double get_corrects() const { return corrects; }
    //! Returns the total number of bits processed
    .def("get_total_bits", &itpp::BERC::get_total_bits)
//    double get_total_bits() const { return (errors + corrects); }
    //! Returns the estimated bit error rate.
    .def("get_errorrate", &itpp::BERC::get_errorrate)
//    double get_errorrate() const { return (errors / (corrects + errors)); }
    /*!
      \brief static function to allow simple and fast count of bit-errors

      Returns the number of errors between in1 and in2. Typical usage:
      \code
      bvec in1 = randb(100);
      bvec in2 = randb(100);
      double errors = BERC::count_errors(in1, in2);
      \endcode
    */
    .def("count_errors", &itpp::BERC::count_errors)
    .staticmethod("count_errors")
//    static double count_errors(const bvec &in1, const bvec &in2,
//                               int indelay = 0, int inignorefirst = 0,
//                               int inignorelast = 0);
  ;

  boost::python::class_<itpp::BLERC>("BLERC", boost::python::init<>())
    //! Specialised constructor
    .def(boost::python::init<int>())
//    BLERC(int blocksize);
    //! Set the block size
    .def("set_blocksize", &itpp::BLERC::set_blocksize)
//    void set_blocksize(int inblocksize, bool clear = true);
    //! Calculate the number of block errors between \a in1 and \a in2
//    .def("count", &itpp::BLERC::count)
//    void count(const bvec &in1, const bvec &in2);
    //! Clear the block error counter
    .def("clear", &itpp::BLERC::clear)
//    void clear() { errors = 0; corrects = 0; }
    //! Returns the number of block errors
    .def("get_errors", &itpp::BLERC::get_errors)
//    double get_errors() const { return errors; }
    //! Returns the number of correct blocks
    .def("get_corrects", &itpp::BLERC::get_corrects)
//    double get_corrects() const { return corrects; }
    //! Returns the total number of block processed
    .def("get_total_blocks", &itpp::BLERC::get_total_blocks)
//    double get_total_blocks() const { return (errors + corrects); }
    //! Returns the block error rate
    .def("get_errorrate", &itpp::BLERC::get_errorrate)
//    double get_errorrate() const { return (errors / (corrects + errors)); }
  ;
}
