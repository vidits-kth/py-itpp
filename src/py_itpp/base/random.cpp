//! COPYRIGHT_NOTICE

#include <itpp/base/random.h>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(random)
{
  // Random number generation from a Rayleigh distributed random variable.
  boost::python::class_<itpp::Rayleigh_RNG>("Rayleigh_RNG", boost::python::init<>())

    .def(boost::python::init<double>())

    .def("setup", &itpp::Rayleigh_RNG::setup)

	// Getters
	.def("get_setup", &itpp::Rayleigh_RNG::get_setup)

    .def("__getitem__", static_cast<double (itpp::Rayleigh_RNG::*)()>(&itpp::Rayleigh_RNG::operator()),
                                   boost::python::return_value_policy<boost::python::return_by_value>())

	.def("get_vec", static_cast<itpp::vec (itpp::Rayleigh_RNG::*)(int)>(&itpp::Rayleigh_RNG::operator()),
								   boost::python::return_value_policy<boost::python::return_by_value>())

	.def("get_mat", static_cast<itpp::mat (itpp::Rayleigh_RNG::*)(int, int)>(&itpp::Rayleigh_RNG::operator()),
								   boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  // Random number generation from a Rice distributed random variable.
  boost::python::class_<itpp::Rice_RNG>("Rice_RNG", boost::python::init<>())

	.def(boost::python::init<double, double>())

    .def("setup", &itpp::Rice_RNG::setup)

	// Getters
	.def("get_setup", &itpp::Rice_RNG::get_setup)

    .def("__getitem__", static_cast<double (itpp::Rice_RNG::*)()>(&itpp::Rice_RNG::operator()),
                                   boost::python::return_value_policy<boost::python::return_by_value>())

	.def("get_vec", static_cast<itpp::vec (itpp::Rice_RNG::*)(int)>(&itpp::Rice_RNG::operator()),
								   boost::python::return_value_policy<boost::python::return_by_value>())

	.def("get_mat", static_cast<itpp::mat (itpp::Rice_RNG::*)(int, int)>(&itpp::Rice_RNG::operator()),
								   boost::python::return_value_policy<boost::python::return_by_value>())
  ;

  //! Generates a random bit (equally likely 0s and 1s)
  boost::python::def("randb", static_cast<itpp::bin (*)()>(&itpp::randb), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline bin randb(void) { Bernoulli_RNG src; return src.sample(); }
  //! Generates a random bit vector (equally likely 0s and 1s)
  boost::python::def("randb", static_cast<void (*)(int, itpp::bvec&)>(&itpp::randb));
//  inline void randb(int size, bvec &out) { Bernoulli_RNG src; src.sample_vector(size, out); }
  //! Generates a random bit vector (equally likely 0s and 1s)
  boost::python::def("randb", static_cast<itpp::bvec (*)(int)>(&itpp::randb), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline bvec randb(int size) { bvec temp; randb(size, temp); return temp; }
  //! Generates a random bit matrix (equally likely 0s and 1s)
  boost::python::def("randb", static_cast<void (*)(int, int, itpp::bmat&)>(&itpp::randb));
//  inline void randb(int rows, int cols, bmat &out) { Bernoulli_RNG src; src.sample_matrix(rows, cols, out); }
  //! Generates a random bit matrix (equally likely 0s and 1s)
  boost::python::def("randb", static_cast<itpp::bmat (*)(int, int)>(&itpp::randb), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline bmat randb(int rows, int cols) { bmat temp; randb(rows, cols, temp); return temp; }

  //! Generates a random uniform (0,1) number
  boost::python::def("randu", static_cast<double (*)()>(&itpp::randu), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline double randu(void) { Uniform_RNG src; return src.sample(); }
  //! Generates a random uniform (0,1) vector
  boost::python::def("randu", static_cast<void (*)(int, itpp::vec &)>(&itpp::randu));
//  inline void randu(int size, vec &out) { Uniform_RNG src; src.sample_vector(size, out); }
  //! Generates a random uniform (0,1) vector
  boost::python::def("randu", static_cast<itpp::vec (*)(int)>(&itpp::randu), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline vec randu(int size) { vec temp; randu(size, temp); return temp; }
  //! Generates a random uniform (0,1) matrix
  boost::python::def("randu", static_cast<void (*)(int, int, itpp::mat &)>(&itpp::randu));
//  inline void randu(int rows, int cols, mat &out) { Uniform_RNG src; src.sample_matrix(rows, cols, out); }
  //! Generates a random uniform (0,1) matrix
  boost::python::def("randu", static_cast<itpp::mat (*)(int, int)>(&itpp::randu), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline mat randu(int rows, int cols) { mat temp; randu(rows, cols, temp); return temp; }

  //! Generates a random integer in the interval [low,high]
  boost::python::def("randi", static_cast<int (*)(int, int)>(&itpp::randi), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline int randi(int low, int high) { I_Uniform_RNG src; src.setup(low, high); return src(); }
  //! Generates a random ivec with elements in the interval [low,high]
  boost::python::def("randi", static_cast<itpp::ivec (*)(int, int, int)>(&itpp::randi), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline ivec randi(int size, int low, int high) { I_Uniform_RNG src; src.setup(low, high); return src(size); }
  //! Generates a random imat with elements in the interval [low,high]
  boost::python::def("randi", static_cast<itpp::imat (*)(int, int, int, int)>(&itpp::randi), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline imat randi(int rows, int cols, int low, int high) { I_Uniform_RNG src; src.setup(low, high); return src(rows, cols); }

  //! Generates a random Rayleigh vector
  boost::python::def("randray", &itpp::randray);
//  inline vec randray(int size, double sigma = 1.0) { Rayleigh_RNG src; src.setup(sigma); return src(size); }


  //! Generates a random Rice vector (See J.G. Poakis, "Digital Communications, 3rd ed." p.47)
  boost::python::def("randrice", &itpp::randrice, boost::python::return_value_policy<boost::python::return_by_value>());
//  inline vec randrice(int size, double sigma = 1.0, double s = 1.0) { Rice_RNG src; src.setup(sigma, s); return src(size); }

  //! Generates a random complex Gaussian vector
  boost::python::def("randexp", itpp::randexp, boost::python::return_value_policy<boost::python::return_by_value>());
//  inline vec randexp(int size, double lambda = 1.0) { Exponential_RNG src; src.setup(lambda); return src(size); }

  //! Generates a random Gaussian (0,1) variable
  boost::python::def("randn", static_cast<double (*)()>(&itpp::randn), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline double randn(void) { Normal_RNG src; return src.sample(); }
  //! Generates a random Gaussian (0,1) vector
  boost::python::def("randn", static_cast<void (*)(int, itpp::vec &)>(&itpp::randn));
//  inline void randn(int size, vec &out) { Normal_RNG src; src.sample_vector(size, out); }
  //! Generates a random Gaussian (0,1) vector
  boost::python::def("randn", static_cast<itpp::vec (*)(int)>(&itpp::randn), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline vec randn(int size) { vec temp; randn(size, temp); return temp; }
  //! Generates a random Gaussian (0,1) matrix
  boost::python::def("randn", static_cast<void (*)(int, int, itpp::mat &)>(&itpp::randn));
//  inline void randn(int rows, int cols, mat &out)  { Normal_RNG src; src.sample_matrix(rows, cols, out); }
  //! Generates a random Gaussian (0,1) matrix
  boost::python::def("randn", static_cast<itpp::mat (*)(int, int)>(&itpp::randn), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline mat randn(int rows, int cols) { mat temp; randn(rows, cols, temp); return temp; }

  /*! \brief Generates a random complex Gaussian (0,1) variable
  The real and imaginary parts are independent and have variances equal to 0.5
  */
  boost::python::def("randn_c", static_cast<std::complex<double> (*)()>(&itpp::randn_c), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline std::complex<double> randn_c(void) { Complex_Normal_RNG src; return src.sample(); }
  //! Generates a random complex Gaussian (0,1) vector
  boost::python::def("randn_c", static_cast<void (*)(int, itpp::cvec &)>(&itpp::randn_c));
//  inline void randn_c(int size, cvec &out)  { Complex_Normal_RNG src; src.sample_vector(size, out); }
  //! Generates a random complex Gaussian (0,1) vector
  boost::python::def("randn_c", static_cast<itpp::cvec (*)(int)>(&itpp::randn_c), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline cvec randn_c(int size) { cvec temp; randn_c(size, temp); return temp; }
  //! Generates a random complex Gaussian (0,1) matrix
  boost::python::def("randn_c", static_cast<void (*)(int, int, itpp::cmat &)>(&itpp::randn_c));
//  inline void randn_c(int rows, int cols, cmat &out) { Complex_Normal_RNG src; src.sample_matrix(rows, cols, out); }
  //! Generates a random complex Gaussian (0,1) matrix
  boost::python::def("randn_c", static_cast<itpp::cmat (*)(int, int)>(&itpp::randn_c), boost::python::return_value_policy<boost::python::return_by_value>());
//  inline cmat randn_c(int rows, int cols) { cmat temp; randn_c(rows, cols, temp); return temp; }
}
