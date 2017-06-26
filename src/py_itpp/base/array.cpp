#include "array.h"

BOOST_PYTHON_MODULE(array)
{
  generate_itpp_array_wrapper<double>("array");
  generate_itpp_array_wrapper<int>("iarray");
  generate_itpp_array_wrapper<std::complex<double> >("carray");
}
