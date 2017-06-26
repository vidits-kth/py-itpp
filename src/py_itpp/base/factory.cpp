#include <boost/python.hpp>
#include <itpp/base/factory.h>

using namespace boost::python;
using namespace itpp;

BOOST_PYTHON_MODULE(factory)
{

  class_<Factory>("factory", init<>())

    //==========================================================================
    // Overloaded Constructors
    //==========================================================================

    //==========================================================================
    // Properties
    //==========================================================================

    //==========================================================================
    // Python-style methods
    //==========================================================================

    //==========================================================================
    // Member Functions
    //==========================================================================

    //==========================================================================
    // Unary Operators
    //==========================================================================

    //==========================================================================
    // Module Functions
    //==========================================================================
;
}

//
//namespace itpp
//{
//
//// Forward declarations
//template<class T> class Array;
//template<class Num_T> class Mat;
//template<class Num_T> class Vec;
//
//class Factory
//{
//public:
//  //! Default constructor
//  Factory() {}
//  //! Destructor
//  virtual ~Factory() {}
//};
//
////! Default (dummy) factory
//const Factory DEFAULT_FACTORY;
//
//
////! Create an n-length array of T to be used as Array, Vec or Mat elements
//template<class T> inline
//void create_elements(T* &ptr, int n, const Factory &)
//{
//  void *p = operator new(sizeof(T) * n);
//  ptr = reinterpret_cast<T*>(p);
//  for (int i = 0; i < n; i++) {
//    new(ptr + i) T();
//  }
//}
//
//
////! Specialization for unsigned char data arrays (used in GF2Mat)
//template<> inline
//void create_elements<unsigned char>(unsigned char* &ptr, int n,
//                                    const Factory &)
//{
//  void *p = operator new(sizeof(unsigned char) * n);
//  ptr = reinterpret_cast<unsigned char*>(p);
//}
//
////! Specialization for binary data arrays
//template<> inline
//void create_elements<bin>(bin* &ptr, int n, const Factory &)
//{
//  void *p = operator new(sizeof(bin) * n);
//  ptr = reinterpret_cast<bin*>(p);
//}
//
////! Specialization for short integer data arrays
//template<> inline
//void create_elements<short int>(short int* &ptr, int n, const Factory &)
//{
//  void *p = operator new(sizeof(short int) * n);
//  ptr = reinterpret_cast<short int*>(p);
//}
//
////! Specialization for integer data arrays
//template<> inline
//void create_elements<int>(int* &ptr, int n, const Factory &)
//{
//  void *p = operator new(sizeof(int) * n);
//  ptr = reinterpret_cast<int*>(p);
//}
//
////! Specialization for 32-byte aligned double data arrays
//template<> inline
//void create_elements<double>(double* &ptr, int n, const Factory &)
//{
//  void *p0 = operator new(sizeof(double) * n + 32);
//  void *p1 = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p0) + 32)
//                                     & (~(std::size_t(31))));
//  *(reinterpret_cast<void**>(p1) - 1) = p0;
//  ptr = reinterpret_cast<double*>(p1);
//}
//
////! Specialization for 32-byte aligned complex double data arrays
//template<> inline
//void create_elements<std::complex<double> >(std::complex<double>* &ptr,
//    int n, const Factory &)
//{
//  void *p0 = operator new(sizeof(std::complex<double>) * n + 32);
//  void *p1 = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p0) + 32)
//                                     & (~(std::size_t(31))));
//  *(reinterpret_cast<void**>(p1) - 1) = p0;
//  ptr = reinterpret_cast<std::complex<double>*>(p1);
//}
//
////! Specialization for 32-byte aligned float data arrays
//template<> inline
//void create_elements<float>(float* &ptr, int n, const Factory &)
//{
//  void *p0 = operator new(sizeof(float) * n + 32);
//  void *p1 = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p0) + 32)
//                                     & (~(std::size_t(31))));
//  *(reinterpret_cast<void**>(p1) - 1) = p0;
//  ptr = reinterpret_cast<float*>(p1);
//}
//
////! Specialization for 32-byte aligned complex float data arrays
//template<> inline
//void create_elements<std::complex<float> >(std::complex<float>* &ptr,
//    int n, const Factory &)
//{
//  void *p0 = operator new(sizeof(std::complex<float>) * n + 32);
//  void *p1 = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p0) + 32)
//                                     & (~(std::size_t(31))));
//  *(reinterpret_cast<void**>(p1) - 1) = p0;
//  ptr = reinterpret_cast<std::complex<float>*>(p1);
//}
//
//
////! Destroy an array of Array, Vec or Mat elements
//template<class T> inline
//void destroy_elements(T* &ptr, int n)
//{
//  if (ptr) {
//    for (int i = 0; i < n; ++i) {
//      ptr[i].~T();
//    }
//    void *p = reinterpret_cast<void*>(ptr);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Specialization for unsigned char data arrays (used in GF2Mat)
//template<> inline
//void destroy_elements<unsigned char>(unsigned char* &ptr, int)
//{
//  if (ptr) {
//    void *p = reinterpret_cast<void*>(ptr);
//    operator delete(p);
//  ptr = 0;
//  }
//}
//
////! Specialization for binary data arrays
//template<> inline
//void destroy_elements<bin>(bin* &ptr, int)
//{
//  if (ptr) {
//    void *p = reinterpret_cast<void*>(ptr);
//    operator delete(p);
//    ptr = 0;
//  }
//}
////! Specialization for short integer data arrays
//template<> inline
//void destroy_elements<short int>(short int* &ptr, int)
//{
//  if (ptr) {
//    void *p = reinterpret_cast<void*>(ptr);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Specialization for integer data arrays
//template<> inline
//void destroy_elements<int>(int* &ptr, int)
//{
//  if (ptr) {
//    void *p = reinterpret_cast<void*>(ptr);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Specialisation for 32-byte aligned double data arrays
//template<> inline
//void destroy_elements<double>(double* &ptr, int)
//{
//  if (ptr) {
//    void *p = *(reinterpret_cast<void**>(ptr) - 1);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Specialisation for 32-byte aligned complex double data arrays
//template<> inline
//void destroy_elements<std::complex<double> >(std::complex<double>* &ptr, int)
//{
//  if (ptr) {
//    void *p = *(reinterpret_cast<void**>(ptr) - 1);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Specialisation for 32-byte aligned float data arrays
//template<> inline
//void destroy_elements<float>(float* &ptr, int)
//{
//  if (ptr) {
//    void *p = *(reinterpret_cast<void**>(ptr) - 1);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Specialisation for 32-byte aligned complex float data arrays
//template<> inline
//void destroy_elements<std::complex<float> >(std::complex<float>* &ptr, int)
//{
//  if (ptr) {
//    void *p = *(reinterpret_cast<void**>(ptr) - 1);
//    operator delete(p);
//    ptr = 0;
//  }
//}
//
////! Create an n-length array of Array<T> to be used as Array elements
//template<class T>
//void create_elements(Array<T>* &ptr, int n, const Factory &f)
//{
//  void *p = operator new(sizeof(Array<T>) * n);
//  ptr = reinterpret_cast<Array<T>*>(p);
//  for (int i = 0; i < n; ++i) {
//    new(ptr + i) Array<T>(f);
//  }
//}
//
////! Create an n-length array of Mat<T> to be used as Array elements
//template<class T>
//void create_elements(Mat<T>* &ptr, int n, const Factory &f)
//{
//  void *p = operator new(sizeof(Mat<T>) * n);
//  ptr = reinterpret_cast<Mat<T>*>(p);
//  for (int i = 0; i < n; ++i) {
//    new(ptr + i) Mat<T>(f);
//  }
//}
//
////! Create an n-length array of Vec<T> to be used as Array elements
//template<class T>
//void create_elements(Vec<T>* &ptr, int n, const Factory &f)
//{
//  void *p = operator new(sizeof(Vec<T>) * n);
//  ptr = reinterpret_cast<Vec<T>*>(p);
//  for (int i = 0; i < n; ++i) {
//    new(ptr + i) Vec<T>(f);
//  }
//}
//
//} // namespace itpp
//
//#endif // #ifndef FACTORY_H
