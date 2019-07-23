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

#ifndef PYBIND_MATFUNC_H
#define PYBIND_MATFUNC_H

#include <pybind11/pybind11.h>
#include <pybind11/complex.h>

#include <itpp/base/matfunc.h>

namespace py = pybind11;

template<class T>
void generate_pybind_wrapper_for_matfunc_module(py::module &m) {

  //! Length of vector
  m.def("length", &itpp::length<T>
		        , "Length of vector"
				, py::arg("v"));

  //! Length of vector
  m.def("size", &itpp::size<T>
	          , "Length of vector"
			  , py::arg("v"));

  //! sum
  m.def("sum", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::sum)
		     , "Sum of all elements in the vector"
			 , py::arg("v"));
  m.def("sum", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::sum)
		     , "Sum of elements in the matrix m, either along columns or rows"
			 , py::arg("m"), py::arg("dim") = 1);
  m.def("sumsum", &itpp::sumsum<T>
		        , "Sum of all elements in the given matrix. Fast version of sum(sum(X))"
				, py::arg("X"));

  //! sum_sqr
  m.def("sum_sqr", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::sum_sqr)
		         , "Sum of square of the elements in a vector"
			     , py::arg("v"));
  m.def("sum_sqr", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::sum_sqr)
		        , "Sum of the square of elements in the matrix m, either along columns or rows"
			    , py::arg("m"), py::arg("dim") = 1);

  //! cumsum
  m.def("cumsum", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &)>(&itpp::cumsum)
		        , "Cumulative sum of all elements in the vector"
				, py::arg("v"));
  m.def("cumsum", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int)>(&itpp::cumsum)
		        , "Cumulative sum of elements in the matrix m, either along columns or rows"
				, py::arg("m"), py::arg("dim") = 1);

  //! prod
  m.def("prod", static_cast<T (*)(const itpp::Vec<T> &)>(&itpp::prod)
		      , "The product of all elements in the vector"
			  , py::arg("v"));
  m.def("prod", static_cast<itpp::Vec<T> (*)(const itpp::Mat<T> &, int)>(&itpp::prod)
		      , "Product of elements in the matrix m, either along columns or rows"
		      , py::arg("m"), py::arg("dim") = 1);


  //! cross
  m.def("cross", &itpp::cross<T>
		       , "Vector cross product. Vectors need to be of size 3"
			   , py::arg("v1"), py::arg("v2"));

  //! zero_pad
  m.def("zero_pad", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &, int n)>(&itpp::zero_pad)
		          , "Zero-pad a vector to size n"
			      , py::arg("v"), py::arg("n"));
  m.def("zero_pad", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &)>(&itpp::zero_pad)
		          , "Zero-pad a vector to the nearest greater power of two"
			      , py::arg("v"));
  m.def("zero_pad", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::zero_pad)
		          , "Zero-pad a matrix to size rows x cols"
			      , py::arg("v"), py::arg("rows"), py::arg("cols"));

  //! index_zero_pad
  m.def("index_zero_pad", &itpp::index_zero_pad<T>
		                , "Return zero if indexing outside the vector v otherwise return the element index"
			            , py::arg("v1"), py::arg("index"));

  //! transpose
  m.def("transpose", static_cast<void (*)(const itpp::Mat<T> &, itpp::Mat<T> &)>(&itpp::transpose)
		           , "Transposition of the matrix m returning the transposed matrix in out"
			       , py::arg("m"), py::arg("out"));
  m.def("transpose", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &)>(&itpp::transpose)
		           , "Transposition of the matrix m"
			       , py::arg("m"));

  //! Hermitian transpose
  m.def("hermitian_transpose", static_cast<void (*)(const itpp::Mat<T> &, itpp::Mat<T> &)>(&itpp::hermitian_transpose)
		                , "Hermitian transpose (complex conjugate transpose) of the matrix m "
						  "returning the transposed matrix in out"
			            , py::arg("m"), py::arg("out"));
  m.def("hermitian_transpose", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &)>(&itpp::hermitian_transpose)
		                     , "Hermitian transpose (complex conjugate transpose) of the matrix m"
			                 , py::arg("m"));

  //! is_hermitian
  m.def("is_hermitian", &itpp::is_hermitian<T>
		              , "Returns true if matrix X is hermitian, false otherwise"
			          , py::arg("m"));

  //! is_unitary
//  m.def("is_unitary", &itpp::is_unitary<T>
//		            , "Returns true if matrix X is unitary, false otherwise"
//			        , py::arg("m"));


  //! repmat
  m.def("repmat", static_cast<itpp::Vec<T> (*)(const itpp::Vec<T> &, int)>(&itpp::repmat)
		        , "Creates a vector with n copies of the vector v"
				, py::arg("v"), py::arg("n"));
  m.def("repmat", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::repmat)
		        , "Creates a matrix with m by n copies of the matrix data"
		        , py::arg("data"), py::arg("m"), py::arg("n"));
  m.def("repmat", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, int, int, bool)>(&itpp::repmat)
		        , "Returns a matrix with m by n copies of the vector data"
				, py::arg("v"), py::arg("m"), py::arg("n"), py::arg("transpose") = false);

  //! kron
  m.def("kron", &itpp::kron<T>
	          , "Computes the Kronecker product of two matrices"
	          , py::arg("X"), py::arg("Y"));

  //! sqrtm
  m.def("sqrtm", static_cast<itpp::Mat<std::complex<double> > (*)(const itpp::Mat<std::complex<double> > &)>(&itpp::sqrtm)
		       , "Square root of the complex square matrix A"
		       , py::arg("A"));
  m.def("sqrtm", static_cast<itpp::Mat<std::complex<double> > (*)(const itpp::Mat<double> &)>(&itpp::sqrtm)
		       , "Square root of the real square matrix A"
		       , py::arg("A"));

  //! diag
  m.def("diag", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, const int)>(&itpp::diag)
		      , "Create a diagonal matrix using vector v as its diagonal"
                "All other matrix elements except the ones on its diagonal are set to "
                "zero. An optional parameter K can be used to shift the diagonal in "
                " the resulting matrix. By default K is equal to zero. "
                ""
                " The size of the diagonal matrix will be $n+|K| \times n+|K| $, where"
                " $n $ is the length of the input vector  v"
			  , py::arg("v"), py::arg("K") = 0);
  m.def("diag", static_cast<void (*)(const itpp::Vec<T> &, itpp::Mat<T> &)>(&itpp::diag)
		      , "Create a diagonal matrix using vector v as its diagonal "
                ""
                "All other matrix elements except the ones on its diagonal are set to zero."
                ""
                "The size of the diagonal matrix will be $n \times n $, where $n $"
                "is the length of the input vector  v."
			  , py::arg("v"), py::arg("m"));
  m.def("diag", static_cast<itpp::Vec<T>  (*)(const itpp::Mat<T> &)>(&itpp::diag)
		      , "Get the diagonal elements of the input matrix m"
                ""
                "The size of the output vector with diagonal elements will be "
                " $n = min(r, c) $, where $r \times c $ are the dimensions of "
                " matrix  m"
		      , py::arg("m"));

  //! bidiag
  m.def("bidiag", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, const itpp::Vec<T> &)>(&itpp::bidiag)
		        , "Returns a matrix with the elements of the input vector main on"
                  "the diagonal and the elements of the input vector  sup on the diagonal row above."
                  ""
                  "If the number of elements in the vector  main is $n $, then the"
				  "number of elements in the input vector  sup must be $n-1 $. The"
                  "size of the return matrix will be $n \times n $."
				, py::arg("main"), py::arg("sup"));

  m.def("bidiag", static_cast<void (*)(const itpp::Vec<T> &, const itpp::Vec<T> &, itpp::Mat<T> &)>(&itpp::bidiag)
		        , "Returns in the output variable m a matrix with the elements of the input vector main on"
                  "the diagonal and the elements of the input vector  sup on the diagonal row above."
                  ""
                  "If the number of elements in the vector  main is $n $, then the"
				  "number of elements in the input vector  sup must be $n-1 $. The"
                  "size of the return matrix will be $n \times n $."
				, py::arg("main"), py::arg("sup"), py::arg("m"));

  m.def("bidiag", static_cast<void (*)(const itpp::Mat<T> &, itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::bidiag)
		        , "Returns the main diagonal and the diagonal row above in the two"
                  " output vectors main and sup."
                  ""
                  "  The input matrix in must be a square $n \times n $ matrix. The"
                  "  length of the output vector  main will be $n $ and the length of"
                  "  the output vector  sup will be $n-1 $.."
				, py::arg("in"), py::arg("main"), py::arg("sup"));

  //! tridiag
  m.def("tridiag", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, const itpp::Vec<T> &, const itpp::Vec<T> &)>(&itpp::tridiag)
		         , "Returns a matrix with the elements of main on the diagonal,"
                   " the elements of sup on the diagonal row above, and the elements of "
                   "  sub on the diagonal row below."
                   ""
                   "  If the length of the input vector  main is $n $ then the lengths of"
                   "the vectors  sup and  sub must equal $n-1 $. The size of the "
                   "return matrix will be $n \times n $."
		 		, py::arg("main"), py::arg("sup"), py::arg("sub"));

  m.def("tridiag", static_cast<void (*)(const itpp::Vec<T> &, const itpp::Vec<T> &, const itpp::Vec<T> &, itpp::Mat<T> &)>(&itpp::tridiag)
		         , "Returns in the output matrix m a matrix with the elements of main on the diagonal,"
                   " the elements of sup on the diagonal row above, and the elements of "
                   "  sub on the diagonal row below."
                   ""
                   "  If the length of the input vector  main is $n $ then the lengths of"
                   "the vectors  sup and  sub must equal $n-1 $. The size of the "
                   "return matrix will be $n \times n $."
				 , py::arg("main"), py::arg("sup"), py::arg("sup"), py::arg("m"));

  m.def("tridiag", static_cast<void (*)(const itpp::Mat<T> &, itpp::Vec<T> &, itpp::Vec<T> &, itpp::Vec<T> &)>(&itpp::tridiag)
		         , "Returns the main diagonal, the diagonal row above, and the"
                   "  diagonal row below int he output vectors main, sup, and sub."
                   ""
                   "  The input matrix  m must be a square $n \times n $ matrix. The"
                   "  length of the output vector  main will be $n $ and the length of"
                   "  the output vectors  sup and  sup will be $n-1 $."
				 , py::arg("in"), py::arg("main"), py::arg("sup"), py::arg("sub"));

  //! trace
  m.def("trace", &itpp::trace<T>
	           , "The trace of the matrix m, i.e. the sum of the diagonal elements."
	           , py::arg("m"));

  //! reverse
  m.def("reverse", &itpp::reverse<T>
	             , "Reverse the input vector."
	             , py::arg("in"));

  //! vectorize
  m.def("rvectorize", &itpp::rvectorize<T>
		            , "Row vectorize the matrix [(0,0) (0,1) ... (N-1,N-2) (N-1,N-1)]"
					, py::arg("m"));
  m.def("cvectorize", &itpp::cvectorize<T>
		            , "Column vectorize the matrix [(0,0) (1,0) ... (N-2,N-1) (N-1,N-1)]"
					, py::arg("m"));

  //! reshape
  m.def("reshape", static_cast<itpp::Mat<T> (*)(const itpp::Mat<T> &, int, int)>(&itpp::reshape)
		         , "Reshape the matrix into an rows*cols matrix."
				   "The data is taken columnwise from the original matrix and written"
				   "columnwise into the new matrix."
				 , py::arg("m"), py::arg("rows"), py::arg("cols"));
  m.def("reshape", static_cast<itpp::Mat<T> (*)(const itpp::Vec<T> &, int, int)>(&itpp::reshape)
		         , "Reshape the vector into an rows*cols matrix"
                   ""
                   "  The data is element by element from the vector and written columnwise"
                   "  into the new matrix."
				 , py::arg("v"), py::arg("rows"), py::arg("cols"));

  //! all
  m.def("all", &itpp::all
	         , "Returns  true if all elements are ones and false otherwise."
	         , py::arg("testvec"));

  //! any
  m.def("any", &itpp::any
	         , "Returns  true if all elements are ones and false otherwise."
	         , py::arg("testvec"));

}

#endif

