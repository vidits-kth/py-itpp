#include "modulator.h"

BOOST_PYTHON_MODULE(modulator)
{
  /*!
   * \ingroup modulators
   * \brief Soft demodulation methods
   */
  boost::python::enum_<itpp::Soft_Method>("soft_method")
      .value("LOGMAP", itpp::LOGMAP)
      .value("APPROX", itpp::APPROX)
  ;

  // ----------------------------------------------------------------------
  // Type definitions of Modulator_1D and Modulator_2D
  // ----------------------------------------------------------------------

  /*!
   * \relates Modulator
   * \brief Definition of 1D Modulator (with real symbols)
   */
  generate_modulator<double>("modulator_1d");

  /*!
     * \relates Modulator
     * \brief Definition of 2D Modulator (with complex symbols)
     */
  generate_modulator<std::complex<double> >("modulator_2d");
}
