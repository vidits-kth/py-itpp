//! COPYRIGHT_NOTICE

#include <sstream>
#include <boost/python.hpp>
#include <itpp/base/vec.h>


// Wrapper function to print Vec<Num_T> nicely in Python.
template<class Num_T>
std::string _print_wrap(const itpp::Vec<Num_T> &v)
{
  int i, sz = v.length();
  std::ostringstream oss;

  oss << "[" ;
  for (i = 0; i < sz; i++) {
    oss << v(i) ;
    if (i < sz - 1)
      oss << " ";
  }
  oss << "]" ;

  return oss.str();
}

template<class Num_T>
void generate_itpp_vec_wrapper(char const * name) {

  //============================================================================
  // Template Class "Vec<Num_T>"
  //============================================================================
  boost::python::class_<itpp::Vec<Num_T> >(name, boost::python::init<>())

    //! Constructor with size parameter.
    .def(boost::python::init<int>())
    //! Constructor with Factory.
    .def(boost::python::init<const itpp::Factory &>())
    //! Constructor with size parameter. An element factory \c f can be specified.
    .def(boost::python::init<int, const itpp::Factory &>())
    //! Copy constructor
    .def(boost::python::init<const itpp::Vec<Num_T> &>())
    //! Copy constructor, which takes an element factory \c f as an additional argument.
    .def(boost::python::init<const itpp::Vec<Num_T> &, const itpp::Factory &>())
    //! Constructor taking a char string as input.
//    .def(boost::python::init<const char *>()) //!--- Cannot pass pointer. Use strings instead
    //! Constructor taking a char string as input. An element factory \c f can be specified.
//    .def(boost::python::init<const char *, const itpp::Factory &>()) //!--- Cannot pass pointer. Use strings instead
    //! Constructor taking a string as input.
    .def(boost::python::init<const std::string &>())
    //! Constructor taking a string as input. An element factory \c f can be specified.
    .def(boost::python::init<const std::string &, const itpp::Factory &>())
    //! Constructor taking a C-array as input. Copies all data.
//    .def(boost::python::init<const Num_T *, int>()) //!--- Cannot pass pointer. Use value*vec.ones() instead
    //! Constructor taking a C-array as input. Copies all data. An element factory \c f can be specified.
//    .def(boost::python::init<const Num_T *, int, const itpp::Factory &>()) //!--- Cannot pass pointer. Use value*vec.ones() instead
    //! Constructor taking a C-array as input. References all data and thus does not own it.
    //! Note: Do not use, interface is deprecated and will be changed in a future release!
    //.def(boost::python::init<Num_T *, int, const bool>())

    //! The size of the vector
    .def("length", &itpp::Vec<Num_T>::length)
    //! The size of the vector
    .def("size", &itpp::Vec<Num_T>::size)

    //! Constructor taking a C-array as input. References all data and thus does not own it.
    //! Note: Do not use, interface is deprecated and will be changed in a future release!
    //.def("set_handle", &itpp::Vec<Num_T>::set_handle)
    //! Set length of vector. if copy = true then keeping the old values
    .def("set_size", static_cast<void (itpp::Vec<Num_T>::*)(int, bool)>(&itpp::Vec<Num_T>::set_size))
    //! Set length of vector. if copy = true then keeping the old values
    .def("set_length", static_cast<void (itpp::Vec<Num_T>::*)(int, bool)>(&itpp::Vec<Num_T>::set_length))
    //! Set the Vec<Num_T> to the all zero vector
    .def("zeros", &itpp::Vec<Num_T>::zeros)
    //! Set the vector to the all zero vector
    .def("clear", &itpp::Vec<Num_T>::clear)
    //! Set the Vec<Num_T> to the all one vector
    .def("ones", &itpp::Vec<Num_T>::ones)
    //! Set the Vec<Num_T> to equal to the values in the \c str string
    //.def("set_from_char", static_cast<void (itpp::Vec<Num_T> ::*)(const char *)>(&itpp::Vec<Num_T>::set)) //!--- Cannot pass pointer. Use set_from_string instead
    //! Set the Vec<Num_T> to equal to the values in the \c str string
    .def("set_from_str", static_cast<void (itpp::Vec<Num_T>::*)(const std::string &)>(&itpp::Vec<Num_T>::set))

    //! C-style index operator. First element is 0
    .def("__getitem__", static_cast<const Num_T & (itpp::Vec<Num_T>::*)(int) const>(&itpp::Vec<Num_T>::operator()),
                                                  boost::python::return_value_policy<boost::python::copy_const_reference>())
    //! Sub-vector with elements from \c i1 to \c i2. Index -1 indicates the last element.
    .def("__getitem__", static_cast<const itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(int, int) const>(&itpp::Vec<Num_T>::operator()),
                                                           boost::python::return_value_policy<boost::python::return_by_value>())
    //! Sub-vector where the elements are given by the list \c indexlist
    .def("__getitem__", static_cast<const itpp::Vec<Num_T> (itpp::Vec<Num_T>::*)(const itpp::Vec<int> &) const>(&itpp::Vec<Num_T>::operator()),
                                                           boost::python::return_value_policy<boost::python::return_by_value>())

    //! Accessor-style method. First element is 0
    .def("get", static_cast<const Num_T & (itpp::Vec<Num_T>::*)(int) const>(&itpp::Vec<Num_T>::get),
                                                               boost::python::return_value_policy<boost::python::copy_const_reference>())
    //! Get the elements from \c i1 to \c i2. Index -1 indicates the last element.
    .def("get", static_cast<itpp::Vec<Num_T>  (itpp::Vec<Num_T>::*)(int, int) const>(&itpp::Vec<Num_T>::get),
                                                                   boost::python::return_value_policy<boost::python::return_by_value>())
    //! Get the elements in the vector where \c binlist is \c 1
    .def("get", static_cast<itpp::Vec<Num_T>  (itpp::Vec<Num_T>::*)(const itpp::Vec<itpp::bin> &) const>(&itpp::Vec<Num_T>::get),
                                                                   boost::python::return_value_policy<boost::python::return_by_value>())

    //! Modifier-style method. First element is 0.
    .def("__setitem__", static_cast<void (itpp::Vec<Num_T> ::*)(int, Num_T)>(&itpp::Vec<Num_T>::set))

    //! Matrix transpose. Converts to a matrix with the vector in the first row
    .def("transpose", &itpp::Vec<Num_T>::transpose, boost::python::return_value_policy<boost::python::return_by_value>())
    //! Matrix transpose. Converts to a matrix with the vector in the first row
    .def("T", &itpp::Vec<Num_T>::T, boost::python::return_value_policy<boost::python::return_by_value>())
    //! Hermitian matrix transpose. Converts to a matrix with the conjugate of the vector in the first row
    .def("hermitian_transpose", &itpp::Vec<Num_T>::hermitian_transpose, boost::python::return_value_policy<boost::python::return_by_value>())
    //! Hermitian matrix transpose. Converts to a matrix with the conjugate of the vector in the first row
    .def("H", &itpp::Vec<Num_T>::H, boost::python::return_value_policy<boost::python::return_by_value>())

    //! Addition of vector
    .def(boost::python::self += boost::python::other<itpp::Vec<Num_T> >())
    //! Addition of scalar
    .def(boost::python::self += Num_T())
    //! Addition of two vectors
    .def(boost::python::self + boost::python::other<itpp::Vec<Num_T> >())
    //! Addition of a vector and a scalar
    .def(boost::python::self + Num_T())
    //! Addition of a scalar and a vector
    .def(Num_T() + boost::python::self)

    //! Subtraction of vector
    .def(boost::python::self -= boost::python::other<itpp::Vec<Num_T> >())
    //! Subtraction of scalar
    .def(boost::python::self -= Num_T())
    //! Subtraction of \c v2 from \c v1
    .def(boost::python::self -= boost::python::other<itpp::Vec<Num_T> >())
    //! Subtraction of scalar from vector
    .def(boost::python::self + Num_T())
    //! Subtraction of vector from scalar
    .def(Num_T() + boost::python::self)
    //! Negation of vector
//    friend Vec<Num_T> operator-<>(const Vec<Num_T> &v);

    //! Multiply with a scalar
    .def(boost::python::self *= Num_T())
    //! Inner (dot) product
    .def(boost::python::self * boost::python::other<itpp::Vec<Num_T> >())
    //! Inner (dot) product
    .def("dot", static_cast<Num_T (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::dot),
                                     boost::python::return_value_policy<boost::python::return_by_value>())
    //! Outer product of two vectors v1 and v2
    .def("outer_product", static_cast<itpp::Mat<Num_T> (*)(const itpp::Vec<Num_T> &,
                                                           const itpp::Vec<Num_T> &, bool)>(&itpp::outer_product),
                                                          boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise multiplication of vector and scalar
    .def(boost::python::self * Num_T())
    //! Elementwise multiplication of vector and scalar
    .def(Num_T() * boost::python::self)

    //! Elementwise multiplication
    .def("elem_mult", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_mult),
                                                      boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise multiplication of three vectors
    .def("elem_mult", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                       const itpp::Vec<Num_T> &)>(&itpp::elem_mult),
                                                       boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise multiplication of four vectors
    .def("elem_mult", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                       const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_mult),
                                                       boost::python::return_value_policy<boost::python::return_by_value>())

    //! Elementwise multiplication, storing the result in vector \c out
    .def("elem_mult_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                              itpp::Vec<Num_T> &)>(&itpp::elem_mult_out),
                                              boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise multiplication of three vectors, storing the result in vector \c out
    .def("elem_mult_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                              const itpp::Vec<Num_T> &, itpp::Vec<Num_T> &)>(&itpp::elem_mult_out),
                                              boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise multiplication of four vectors, storing the result in vector \c out
    .def("elem_mult_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                              const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                              itpp::Vec<Num_T> &)>(&itpp::elem_mult_out),
                                              boost::python::return_value_policy<boost::python::return_by_value>())

    //! In-place element-wise multiplication of two vectors. Fast version of b = elem_mult(a,b).
    .def("elem_mult_inplace", static_cast<void (*)(const itpp::Vec<Num_T> &, itpp::Vec<Num_T> &)>(&itpp::elem_mult_inplace),
                                                  boost::python::return_value_policy<boost::python::return_by_value>())
    //! Element-wise multiplication of two vectors, followed by summation of the resultant elements. Fast version of sum(elem_mult(a,b))
    .def("elem_mult_sum", static_cast<Num_T (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_mult_sum),
                                               boost::python::return_value_policy<boost::python::return_by_value>())

    //! Elementwise division
    .def(boost::python::self /= Num_T())
    //! Elementwise division
    .def(boost::python::self /= boost::python::other<itpp::Vec<Num_T> >())

    //! Elementwise division
    .def("__idiv__", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, Num_T)>(&itpp::operator/),
                                                     boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise division
    .def("__idiv__", static_cast<itpp::Vec<Num_T> (*)(Num_T, const itpp::Vec<Num_T> &)>(&itpp::operator/),
                                                     boost::python::return_value_policy<boost::python::return_by_value>())

    //! Elementwise division
    .def("elem_div", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_div),
                                                     boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise division
    .def("elem_div", static_cast<itpp::Vec<Num_T> (*)(Num_T, const itpp::Vec<Num_T> &)>(&itpp::elem_div),
                                                    boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise division
    .def("elem_div_out", static_cast<void (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                              itpp::Vec<Num_T> &)>(&itpp::elem_div_out),
                                             boost::python::return_value_policy<boost::python::return_by_value>())
    //! Elementwise division, followed by summation of the resultant elements. Fast version of sum(elem_mult(a,b))
    .def("elem_div_sum", static_cast<Num_T (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::elem_div_sum),
                                              boost::python::return_value_policy<boost::python::return_by_value>())


    //! Get the right \c nr elements from the vector
    .def("right", &itpp::Vec<Num_T>::right)
    //! Get the left \c nr elements from the vector
    .def("left", &itpp::Vec<Num_T>::left)
    //! Get the middle part of vector from \c start including \c nr elements
    .def("mid", &itpp::Vec<Num_T>::mid)
    /*!
     * \brief Split the vector into two parts at element \c pos.
     *
     * Return the first part containing elements 0 to \c pos-1, and keep the
     * second part containing the remaining elements starting from \c pos
     * (empty vector if \c pos is equal to the length of the vector).
     */
    .def("split", &itpp::Vec<Num_T>::split)
    //! Shift in element \c t at position 0 \c n times
    .def("shift_right", static_cast<void (itpp::Vec<Num_T> ::*)(Num_T, int)>(&itpp::Vec<Num_T>::shift_right))
    //! Shift in vector \c v at position 0
    .def("shift_right", static_cast<void (itpp::Vec<Num_T> ::*)(const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::shift_right))
    //! Shift out the \c n left elements and at the same time shift in the element \c t at last position \c n times
    .def("shift_left", static_cast<void (itpp::Vec<Num_T> ::*)(Num_T, int)>(&itpp::Vec<Num_T>::shift_left))
    //! Shift in vector \c v at last positions
    .def("shift_left", static_cast<void (itpp::Vec<Num_T> ::*)(const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::shift_left))

    //! Set subvector tor defined by indicies \c i1 to \c i2 to vector \c v
    .def("set_subvector", static_cast<void (itpp::Vec<Num_T> ::*)(int, int, const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::set_subvector))
    //! Set subvector to elements of vector \c v starting from element \c i
    .def("set_subvector", static_cast<void (itpp::Vec<Num_T> ::*)(int, const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::set_subvector))
    //! Set subvector defined by indices \c i1 and \c i2 to \c t
    .def("set_subvector", static_cast<void (itpp::Vec<Num_T> ::*)(int, int, Num_T)>(&itpp::Vec<Num_T>::set_subvector))
    //! An alias function of set_subvector(i, &v)
    .def("replace_mid", &itpp::Vec<Num_T>::replace_mid)
    //! Delete element number \c i
    .def("del", static_cast<void (itpp::Vec<Num_T> ::*)(int)>(&itpp::Vec<Num_T>::del))
    //! Delete elements from \c i1 to \c i2
    .def("del", static_cast<void (itpp::Vec<Num_T> ::*)(int, int)>(&itpp::Vec<Num_T>::del))
    //! Insert element \c t before element with index \c i (0 <= i <= datasize)
    .def("ins", static_cast<void (itpp::Vec<Num_T> ::*)(int, Num_T)>(&itpp::Vec<Num_T>::ins))
    //! Insert vector \c v before element with index \c i (0 <= i <= datasize)
    .def("ins", static_cast<void (itpp::Vec<Num_T> ::*)(int, const itpp::Vec<Num_T>  &)>(&itpp::Vec<Num_T>::ins))

    //! Assign all elements in Vec<Num_T> to to \c t
    .def("copy_element", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(Num_T)>(&itpp::Vec<Num_T>::operator=),
                                                        boost::python::return_value_policy<boost::python::copy_non_const_reference>())
    //! Assign vector the value and length of \c v
    //! Assign vector equal to the 1-dimensional matrix \c m
    .def("copy_matrix", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const itpp::Mat<Num_T> &)>(&itpp::Vec<Num_T>::operator=),
                                                                             boost::python::return_value_policy<boost::python::copy_non_const_reference>())
    //! Assign vector the values in the string \c values
    .def("copy_char_array", static_cast<itpp::Vec<Num_T> & (itpp::Vec<Num_T> ::*)(const char *)>(&itpp::Vec<Num_T>::operator=),
                                                           boost::python::return_value_policy<boost::python::copy_non_const_reference>())

    //! Elementwise equal to the scalar \c t
    .def("equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator==))
    //! Elementwise not-equal to the scalar \c t
    .def("not_equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator!=))
    //! Elementwise less than the scalar \c t
    .def("less_than_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator<))
    //! Elementwise less than and equal to the scalar \c t
    .def("less_equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator<=))
    //! Elementwise greater than the scalar \c t
    .def("greater_than_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator>))
    //! Elementwise greater than and equal to the scalar \c t
    .def("greater_equals_scalar", static_cast<itpp::Vec<itpp::bin> (itpp::Vec<Num_T> ::*)(Num_T) const>(&itpp::Vec<Num_T>::operator>=))

    //! Assign all elements in vector to \c t
//    Vec<Num_T>& operator=(Num_T t);
    //! Assign vector the value and length of \c v
//    Vec<Num_T>& operator=(const Vec<Num_T> &v);
    //! Assign vector equal to the 1-dimensional matrix \c m
//    Vec<Num_T>& operator=(const Mat<Num_T> &m);
    //! Assign vector the values in the string \c values
//    Vec<Num_T>& operator=(const char *values);

    //! Elementwise equal to the scalar \c t
    .def(boost::python::self == Num_T())
    //! Elementwise not-equal to the scalar \c t
    .def(boost::python::self != Num_T())
    //! Elementwise less than the scalar \c t
    .def(boost::python::self < Num_T())
    //! Elementwise less than and equal to the scalar \c t
    .def(boost::python::self <= Num_T())
    //! Elementwise greater than the scalar \c t
    .def(boost::python::self > Num_T())
    //! Elementwise greater than and equal to the scalar \c t
    .def(boost::python::self >= Num_T())

    //! Compare with vector \c v. Return false if sizes or values differ.
    .def(boost::python::self == boost::python::other<itpp::Vec<Num_T> >())
    //! Compare with vector \c v. Return true if sizes or values differ.
    .def(boost::python::self != boost::python::other<itpp::Vec<Num_T> >())

//    //! Index operator without boundary check. Not recommended to use.
//    Num_T &_elem(int i) { return data[i]; }
//    //! Index operator without boundary check. Not recommended to use.
//    const Num_T &_elem(int i) const { return data[i]; }
//
//    //! Get the pointer to the internal structure. Not recommended to use.
//    Num_T *_data() { return data; }
//    //! Get the pointer to the internal structure. Not recommended to use.
//    const Num_T *_data() const { return data; }

    //! Stream output
    .def("__repr__", &_print_wrap<Num_T>)
    //! Stream output
    .def("__str__", &_print_wrap<Num_T>)
  ;

  //! Append element \c t to the end of the vector \c v
  def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, Num_T)>(&itpp::concat),
                                                boost::python::return_value_policy<boost::python::return_by_value>());
  //! Insert element \c t at the beginning of the vector \c v
  def("concat", static_cast<itpp::Vec<Num_T> (*)(Num_T, const itpp::Vec<Num_T> &)>(&itpp::concat),
                                                boost::python::return_value_policy<boost::python::return_by_value>());
  //! Concatenate vectors \c v1 and \c v2
  def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::concat),
                                                boost::python::return_value_policy<boost::python::return_by_value>());
  //! Concatenate vectors \c v1, \c v2 and \c v3
  def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                 const itpp::Vec<Num_T> &)>(&itpp::concat),
                                                boost::python::return_value_policy<boost::python::return_by_value>());
  //! Concatenate vectors \c v1, \c v2, \c v3 and \c v4
  def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                 const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &)>(&itpp::concat),
                                                boost::python::return_value_policy<boost::python::return_by_value>());
  //! Concatenate vectors \c v1, \c v2, \c v3, \c v4 and \c v5
  def("concat", static_cast<itpp::Vec<Num_T> (*)(const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                 const itpp::Vec<Num_T> &, const itpp::Vec<Num_T> &,
                                                 const itpp::Vec<Num_T> &)>(&itpp::concat),
                                                boost::python::return_value_policy<boost::python::return_by_value>());

}
