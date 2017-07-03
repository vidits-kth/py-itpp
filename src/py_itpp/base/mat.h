//! COPYRIGHT_NOTICE

#include <itpp/base/mat.h>
#include <boost/python.hpp>
#include <sstream>

// Wrapper function to print itpp::Mat<Num_T> nicely in Python.
template<class Num_T>
std::string itpp_mat_print_wrap(const itpp::Mat<Num_T> &m)
{
  int i, rows = m.rows();
  int j, cols = m.cols();

  std::ostringstream oss;

  oss << "[" ;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      oss << m(i, j);
      if (j < cols - 1)
        oss << "\t";
    }
    if (i < rows - 1)
      oss << "\n";
  }
  oss << "]";

  return oss.str();
}

template<class Num_T>
void generate_itpp_mat_wrapper(char const * name) {

  //============================================================================
  // Template class Mat<Num_T>
  //============================================================================
  boost::python::class_<itpp::Mat<Num_T> >(name, boost::python::init<>())

    //! Default constructor. An element factory \c f can be specified
    .def(boost::python::init<const itpp::Factory &>())
    //! Create a matrix of size (rows, cols). An element factory \c f can be specified.
    .def(boost::python::init<int, int>())
    .def(boost::python::init<int, int, const itpp::Factory &>())
    //! Copy constructor
    .def(boost::python::init<const itpp::Mat<Num_T> &>())
    //! Constructor, similar to the copy constructor, but also takes an element factory \c f as argument
    .def(boost::python::init<const itpp::Mat<Num_T> &, const itpp::Factory &>())
    //! Construct a matrix from a column vector \c v. An element factory \c f can be specified.
    .def(boost::python::init<const itpp::Vec<Num_T> &>())
    .def(boost::python::init<const itpp::Vec<Num_T> &, const itpp::Factory &>())
    //! Set matrix equal to values in string \c str. An element factory \c f can be specified.
    .def(boost::python::init<const std::string &>())
    .def(boost::python::init<const std::string &, const itpp::Factory &>())
    //! Set matrix equal to values in string \c str. An element factory \c f can be specified.
//    .def(boost::python::init<const char *)
//    .def(boost::python::init<const char *, const itpp::Factory &>())
    /*!
     * \brief Constructor taking a C-array as input. An element factory \c f
     * can be specified.
     *
     * By default the matrix is stored as a row-major matrix (i.e. listing
     * elements in sequence beginning with the first column).
     */
//    .def(boost::python::init<const Num_T *, int, int, bool>())
//    .def(boost::python::init<const Num_T *, int, int, bool, const itpp::Factory &>())

    //! Constructor taking a C-array as input. References all data and thus does not own it.
    //! Note: Do not use, interface is deprecated and will be changed in a future release!
//    .def(boost::python::init<Num_T *, int, int, bool, bool>())

    //! Destructor
//    ~Mat();

    //! The number of columns
    .def("cols", &itpp::Mat<Num_T>::cols)
    //! The number of rows
    .def("rows", &itpp::Mat<Num_T>::rows)
    //! The number of elements
    .def("size", &itpp::Mat<Num_T>::size)


    //! Set matrix to be a handle (i.e. not owning the memory)
    //! Note: Do not use, interface is deprecated and will be changed in a future release!
//    .def("set_handle", &itpp::Mat<Num_T>::set_handle)
    //! Set size of matrix. If copy = true then keep the data before resizing.
    .def("set_size", &itpp::Mat<Num_T>::set_size)
    //! Set matrix equal to the all zero matrix
    .def("zeros", &itpp::Mat<Num_T>::zeros)
    //! Set matrix equal to the all zero matrix
    .def("clear", &itpp::Mat<Num_T>::clear)
    //! Set matrix equal to the all one matrix
    .def("ones", &itpp::Mat<Num_T>::ones)
    //! Set matrix equal to values in \c values
//    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(const char *)>(&itpp::Mat<Num_T>::set))
    //! Set matrix equal to values in the string \c str
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(const std::string &)>(&itpp::Mat<Num_T>::set))

    //! Get elements. Python "__getitem__" supports only a single input, use 'get' method for (r,c) element
    //! Get element (r,c) from matrix
//    .def("__getitem__", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::operator()),
//                                   boost::python::return_value_policy<boost::python::copy_const_reference>())
    //! Get element (r,c) from matrix
//    .def("__getitem__", static_cast<Num_T & (itpp::Mat<Num_T>::*)(int, int)>(&itpp::Mat<Num_T>::operator()),
//                                   boost::python::return_value_policy<boost::python::copy_non_const_reference>())
    //! Get element \c i using linear addressing (by rows)
    .def("__getitem__", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int) const>(&itpp::Mat<Num_T>::operator()),
                                   boost::python::return_value_policy<boost::python::copy_const_reference>())
    //! Get element \c i using linear addressing (by rows)
    .def("__getitem__", static_cast<Num_T & (itpp::Mat<Num_T>::*)(int)>(&itpp::Mat<Num_T>::operator()),
                                   boost::python::return_value_policy<boost::python::copy_non_const_reference>())
    //! Get element (r,c) from matrix
    .def("get", static_cast<const Num_T & (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get),
                           boost::python::return_value_policy<boost::python::copy_const_reference>())
    //! Set element (r,c) of matrix
    .def("set", static_cast<void (itpp::Mat<Num_T>::*)(int, int, Num_T)>(&itpp::Mat<Num_T>::set))

    /*!
      \brief Sub-matrix from row \c r1 to row \c r2 and columns \c c1 to \c c2.

      Value -1 indicates the last row and column, respectively.
    */
    .def("get", static_cast<itpp::Mat<Num_T>  (itpp::Mat<Num_T>::*)(int, int, int, int) const>(&itpp::Mat<Num_T>::operator()),
                            boost::python::return_value_policy<boost::python::return_by_value>())
    /*!
      \brief Sub-matrix from row \c r1 to row \c r2 and columns \c c1 to \c c2.

      Value -1 indicates the last row and column, respectively.
    */
    .def("get", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int, int, int) const>(&itpp::Mat<Num_T>::get),
                           boost::python::return_value_policy<boost::python::return_by_value>())

    //! Get row \c r
    .def("get_row", &itpp::Mat<Num_T>::get_row)
    //! Get rows \c r1 through \c r2
    .def("get_rows", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get_rows),
                                boost::python::return_value_policy<boost::python::return_by_value>())
    //! Get the rows specified by \c indexlist
    .def("get_rows", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Mat<Num_T>::get_rows),
                                boost::python::return_value_policy<boost::python::return_by_value>())
    //! Get column \c c
    .def("get_col", &itpp::Mat<Num_T>::get_col)
    //! Get columns \c c1 through \c c2
    .def("get_cols", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(int, int) const>(&itpp::Mat<Num_T>::get_cols),
                                boost::python::return_value_policy<boost::python::return_by_value>())
    //! Get the columns specified by \c indexlist
    .def("get_cols", static_cast<itpp::Mat<Num_T> (itpp::Mat<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Mat<Num_T>::get_cols),
                              boost::python::return_value_policy<boost::python::return_by_value>())
    //! Set row \c r to vector \c v
    .def("set_row", &itpp::Mat<Num_T>::set_row)
    //! Set column \c c to vector \c v
    .def("set_col", &itpp::Mat<Num_T>::set_col)
    //! Set rows to matrix \c m, staring from row \c r
    .def("set_rows", &itpp::Mat<Num_T>::set_rows)
    //! Set columns to matrix \c m, starting from column \c c
    .def("set_cols", &itpp::Mat<Num_T>::set_cols)
    //! Copy row \c from onto row \c to
    .def("copy_row", &itpp::Mat<Num_T>::copy_row)
    //! Copy column \c from onto column \c to
    .def("copy_col", &itpp::Mat<Num_T>::copy_col)
    //! Swap the rows \c r1 and \c r2
    .def("swap_rows", &itpp::Mat<Num_T>::swap_rows)
    //! Swap the columns \c c1 and \c c2
    .def("swap_cols", &itpp::Mat<Num_T>::swap_cols)

    //! Set submatrix defined by rows r1,r2 and columns c1,c2 to matrix m
    .def("set_submatrix", static_cast<void (itpp::Mat<Num_T>::*)(int, int, int, int, const itpp::Mat<Num_T> &)>(&itpp::Mat<Num_T>::set_submatrix))
    //! Set submatrix defined by upper-left element (r,c) and the size of matrix m to m
    .def("set_submatrix", static_cast<void (itpp::Mat<Num_T>::*)(int, int, const itpp::Mat<Num_T> &)>(&itpp::Mat<Num_T>::set_submatrix))
    //! Set all elements of submatrix defined by rows r1,r2 and columns c1,c2 to value t
    .def("set_submatrix", static_cast<void (itpp::Mat<Num_T>::*)(int, int, int, int, Num_T)>(&itpp::Mat<Num_T>::set_submatrix))

    //! Delete row number \c r
    .def("del_row", &itpp::Mat<Num_T>::del_row)
    //! Delete rows from \c r1 to \c r2
    .def("del_rows", &itpp::Mat<Num_T>::del_rows)
    //! Delete column number \c c
    .def("del_col", &itpp::Mat<Num_T>::del_col)
    //! Delete columns from \c c1 to \c c2
    .def("del_cols", &itpp::Mat<Num_T>::del_cols)
    //! Insert vector \c v at row number \c r. The matrix can be empty.
    .def("ins_row", &itpp::Mat<Num_T>::ins_row)
    //! Insert vector \c v at column number \c c. The matrix can be empty.
    .def("ins_col", &itpp::Mat<Num_T>::ins_col)
    //! Append vector \c v to the bottom of the matrix. The matrix can be empty.
    .def("append_row", &itpp::Mat<Num_T>::append_row)
    //! Append vector \c v to the right side of the matrix. The matrix can be empty.
    .def("append_col", &itpp::Mat<Num_T>::append_col)

    //! Matrix transpose
    .def("transpose", &itpp::Mat<Num_T>::transpose)
    //! Matrix transpose
    .def("T", &itpp::Mat<Num_T>::T)
    //! Hermitian matrix transpose (conjugate transpose)
    .def("hermitian_transpose", &itpp::Mat<Num_T>::hermitian_transpose)
    //! Hermitian matrix transpose (conjugate transpose)
    .def("H", &itpp::Mat<Num_T>::H)

    //! Concatenate the matrices \c m1 and \c m2 horizontally
    .def("concat_horizontal", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                               const itpp::Mat<Num_T> &)>(&itpp::concat_horizontal),
                                         boost::python::return_value_policy<boost::python::return_by_value>())
    //! Concatenate the matrices \c m1 and \c m2 vertically
    .def("concat_vertical", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &,
                                                               const itpp::Mat<Num_T> &)>(&itpp::concat_vertical),
                                         boost::python::return_value_policy<boost::python::return_by_value>())


    //! Set all elements of the matrix equal to \c t
//    .def(boost::python::self = Num_T())
    //! Set matrix equal to \c m
//    .def(boost::python::self = boost::python::other<itpp::Mat<Num_T> >())
    //! Set matrix equal to the vector \c v, assuming column vector
//    .def(boost::python::self = itpp::Vec<Num_T>())
    //! Set matrix equal to values in the string
//    .def(boost::python::self = const char *)

    //! Addition of matrices
    .def(boost::python::self += boost::python::other<itpp::Mat<Num_T> >())
    //! Addition of scalar to matrix
    .def(boost::python::self += Num_T())
    //! Addition of two matrices
    .def(boost::python::self + boost::python::other<itpp::Mat<Num_T> >())
    //! Addition of matrix and scalar
    .def(boost::python::self + Num_T())
    //! Addition of scalar and matrix
    .def(Num_T() + boost::python::self)

    //! Subtraction of matrix
    .def(boost::python::self -= boost::python::other<itpp::Mat<Num_T> >())
    //! Subtraction of scalar from matrix
    .def(boost::python::self -= Num_T())
    //! Subtraction of \c m2 from \c m1
    .def(boost::python::self - boost::python::other<itpp::Mat<Num_T> >())
    //! Subtraction of scalar from matrix
    .def(boost::python::self - Num_T())
    //! Subtract matrix from scalar
    .def(Num_T() - boost::python::self)
    //! Subtraction of matrix
//    friend Mat<Num_T> operator-<>(const Mat<Num_T> &m);

    //! Matrix multiplication
    .def(boost::python::self *= boost::python::other<itpp::Mat<Num_T> >())
    //! Multiplication by a scalar
    .def(boost::python::self *= Num_T())
    //! Multiplication of two matrices
//    .def(boost::python::self * boost::python::other<itpp::Mat<Num_T> >())
    //! Multiplication of matrix \c m and vector \c v (column vector)
//    .def(boost::python::self * itpp::Vec<Num_T>())
    /*!
     * \brief Multiplication of vector \c v and matrix \c m with only one row
     *
     * This operator multiplies a column vector \c v times matrix \c m that
     * consists of only one row. Thus, the result of this operator is
     * exactly the same as the result of the outer product of two vectors,
     * i.e.: <tt>outer_product(v, m.get_col(0))</tt>.
     *
     * \note This operator is deprecated and might be removed or changed in
     * future releases of IT++.
     */
//    .def(itpp::Vec<Num_T>() * boost::python::self)
    //! Multiplication of matrix and scalar
//    .def(boost::python::self * Num_T())
    //! Multiplication of scalar and matrix
//    .def(Num_T() * boost::python::self)

    //! Element wise multiplication of two matrices
    .def("elem_mult", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &)>(&itpp::elem_mult),
                                 boost::python::return_value_policy<boost::python::return_by_value>())
    //! Element wise multiplication of two matrices, storing the result in matrix \c out
    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &,
                                               itpp::Mat<Num_T> &)>(&itpp::elem_mult_out))
    //! Element wise multiplication of three matrices, storing the result in matrix \c out
    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &, itpp::Mat<Num_T> &)>(&itpp::elem_mult_out))
    //! Element wise multiplication of four matrices, storing the result in matrix \c out
    .def("elem_mult_out", static_cast<void (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &,
                                               const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &,
                                               itpp::Mat<Num_T> &)>(&itpp::elem_mult_out))
    //! In-place element wise multiplication of two matrices. Fast version of B = elem_mult(A, B).
    .def("elem_mult_inplace", static_cast<void (*)(const itpp::Mat<Num_T> &, itpp::Mat<Num_T> &)>(&itpp::elem_mult_inplace))
    //! Element wise multiplication of two matrices, followed by summation of the resultant elements. Fast version of sumsum(elem_mult(A, B)).
    .def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &)>(&itpp::elem_mult_sum),
                                     boost::python::return_value_policy<boost::python::return_by_value>())

    //! Division by a scalar
    .def(boost::python::self /= Num_T())
    //! Division of matrix with scalar
    .def(boost::python::self / Num_T())
    //! Element-wise division with the current matrix
    .def(boost::python::self /= boost::python::other<itpp::Mat<Num_T> >())
//    Mat<Num_T>& operator/=(const Mat<Num_T> &m);

    //! Element wise division of two matrices
    .def("elem_div", static_cast<itpp::Mat<Num_T> (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &)>(&itpp::elem_div),
                                boost::python::return_value_policy<boost::python::return_by_value>())
    //! Element wise division of two matrices, storing the result in matrix \c out
    .def("elem_div_out", static_cast<void (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &,
                                               itpp::Mat<Num_T> &)>(&itpp::elem_div_out))
    //! Element wise division of two matrices, followed by summation of the resultant elements. Fast version of sumsum(elem_div(A, B)).
    .def("elem_div_sum", static_cast<Num_T (*)(const itpp::Mat<Num_T> &, const itpp::Mat<Num_T> &)>(&itpp::elem_mult_sum),
                                    boost::python::return_value_policy<boost::python::return_by_value>())

    //! Compare two matrices. False if wrong sizes or different values
    .def(boost::python::self == boost::python::other<itpp::Mat<Num_T> >())
    //! Compare two matrices. True if different
    .def(boost::python::self != boost::python::other<itpp::Mat<Num_T> >())

//    //! Get element (r,c) from matrix without boundary check (not recommended to use)
//    Num_T &_elem(int r, int c) { return data[r+c*no_rows]; }
//    //! Get element (r,c) from matrix without boundary check (not recommended to use)
//    const Num_T &_elem(int r, int c) const { return data[r+c*no_rows]; }
//    //! Get element \c i using linear addressing (by rows) without boundary check (not recommended to use)
//    Num_T &_elem(int i) { return data[i]; }
//    //! Get element \c i using linear addressing (by rows) without boundary check (not recommended to use)
//    const Num_T &_elem(int i) const { return data[i]; }

    //! Stream output
    .def("__repr__", &itpp_mat_print_wrap<Num_T>)
    //! Stream output
    .def("__str__", &itpp_mat_print_wrap<Num_T>)
;
}
