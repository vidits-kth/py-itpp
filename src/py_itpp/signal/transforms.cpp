//! COPYRIGHT_NOTICE

#include <itpp/signal/transforms.h>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(transforms)
{
  //! Fast Fourier Transform
  boost::python::def("fft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::fft));
//  void fft(const cvec &in, cvec &out);
  //! Fast Fourier Transform
  boost::python::def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::fft), boost::python::return_value_policy<boost::python::return_by_value>());
//  cvec fft(const cvec &in);
  //! Fast Fourier Transform, with zero-padding up to size N
  boost::python::def("fft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::fft), boost::python::return_value_policy<boost::python::return_by_value>());
//  cvec fft(const cvec &in, const int N);
  //! Inverse Fast Fourier Transform
  boost::python::def("ifft", static_cast<void (*)(const itpp::cvec &, itpp::cvec &)>(&itpp::ifft));
//  void ifft(const cvec &in, cvec &out);
  //! Inverse Fast Fourier Transform
  boost::python::def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &)>(&itpp::ifft), boost::python::return_value_policy<boost::python::return_by_value>());
//  cvec ifft(const cvec &in);
  //! Inverse Fast Fourier Transform, with zero-padding up to size N
  boost::python::def("ifft", static_cast<itpp::cvec (*)(const itpp::cvec &, const int)>(&itpp::ifft), boost::python::return_value_policy<boost::python::return_by_value>());
//  cvec ifft(const cvec &in, const int N);

  //! Real Fast Fourier Transform
  boost::python::def("fft_real", static_cast<void (*)(const itpp::vec &, itpp::cvec &)>(&itpp::fft_real));
//  void fft_real(const vec& in, cvec &out);
  //! Real Fast Fourier Transform
  boost::python::def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &)>(&itpp::fft_real), boost::python::return_value_policy<boost::python::return_by_value>());
//  cvec fft_real(const vec& in);
  //! Real Fast Fourier Transform, with zero-padding up to size N
  boost::python::def("fft_real", static_cast<itpp::cvec (*)(const itpp::vec &, const int)>(&itpp::fft_real), boost::python::return_value_policy<boost::python::return_by_value>());
//  cvec fft_real(const vec &in, const int N);
  //! Inverse Real Fast Fourier Transform. Assumes even size.
  boost::python::def("ifft_real", static_cast<void (*)(const itpp::cvec &, itpp::vec &)>(&itpp::ifft_real));
//  void ifft_real(const cvec &in, vec &out);
  //! Inverse Real Fast Fourier Transform. Assumes even size.
  boost::python::def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &)>(&itpp::ifft_real), boost::python::return_value_policy<boost::python::return_by_value>());
//  vec ifft_real(const cvec &in);
  //! Inverse Real Fast Fourier Transform, with zero-padding up to size N
  boost::python::def("ifft_real", static_cast<itpp::vec (*)(const itpp::cvec &, const int)>(&itpp::ifft_real), boost::python::return_value_policy<boost::python::return_by_value>());
//  vec ifft_real(const cvec &in, const int N);

  //! Discrete Cosine Transform (DCT)
  boost::python::def("dct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::dct));
//  void dct(const vec &in, vec &out);
  //! Discrete Cosine Transform (DCT)
  boost::python::def("dct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::dct), boost::python::return_value_policy<boost::python::return_by_value>());
//  vec dct(const vec &in);
  //! Inverse Discrete Cosine Transform (IDCT)
  boost::python::def("idct", static_cast<void (*)(const itpp::vec &, itpp::vec &)>(&itpp::idct));
//  void idct(const vec &in, vec &out);
  //! Inverse Discrete Cosine Transform (IDCT)
  boost::python::def("idct", static_cast<itpp::vec (*)(const itpp::vec &)>(&itpp::idct), boost::python::return_value_policy<boost::python::return_by_value>());
//  vec idct(const vec &in);
}
