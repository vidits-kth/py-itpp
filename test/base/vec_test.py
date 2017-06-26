from py_itpp import vec, cvec, ivec, bvec, vec_np
from py_itpp import factory
import ctypes

def setup_teardown_test(vec_):
    
    print '-------Testing setup and teardown of ', vec_, '-------'
    val = 10
    size = 10
    
    print '--Default constructor--'
    obj = vec_()
    del obj
    print '--Constructor with size parameter--'
    obj = vec_(size)
    del obj
    print '--Copy constructor--'
    obj = vec_(size)
    obj1 = vec_(obj)
    del obj, obj1
    print '--Constructor taking a string as input.--'
    a = '1'
    obj = vec_(a)
    print obj
    del obj
    print '--Conversion to Numpy array.--'
    a = vec_('1 0 1 0')
    print a
    b = vec_np(a)
    print b
    del a,b
    
''' 
    //==========================================================================
    // Member Functions
    //==========================================================================
    //! The size of the vector
    .def("length", &Vec<Num_T>::length)
    //! The size of the vector
    .def("size", &Vec<Num_T>::size)l
    //! Constructor taking a C-array as input. References all data and thus does not own it.
    //! Note: Do not use, interface is deprecated and will be changed in a future release!
    //.def("set_handle", &Vec<Num_T>::set_handle)
    //! Set length of vector. if copy = true then keeping the old values
    .def("set_size", static_cast< void(Vec<Num_T>::*)(int, bool)>(&Vec<Num_T>::set_size))
    //! Set length of vector. if copy = true then keeping the old values
    .def("set_length", static_cast< void(Vec<Num_T>::*)(int, bool)>(&Vec<Num_T>::set_length))
    //! Set the Vec<Num_T> to the all zero Vec<Num_T> tor
    .def("zeros", &Vec<Num_T>::zeros)
    //! Set the Vec<Num_T> tor to the all zero Vec<Num_T> tor
    .def("clear", &Vec<Num_T>::clear)
    //! Set the Vec<Num_T> to the all one Vec<Num_T> tor
    .def("ones", &Vec<Num_T>::ones)'''

def data_manipulation_test(vec_):
    obj1 = vec_(10)
    print obj1
    
    print '--Set the vector to the all zero vector--'
    obj1.zeros
    print obj1
    print '--Set the vector to the all zero vector--'
    obj1.clear()
    print obj1
    print '--Set the vector to the all one vector--'
    obj1.ones
    print obj1
    print obj1[ivec('0 2')]
#     print 'Set the vector equal to the values in the \c str string'
#     obj1.set("a")
#     print obj1
#     print 'Set the vector equal to the values in the \c str string'
#     obj1.set('a')
#     print obj1
#     del obj1
    
def shape_manipulation_test(vec_):
    obj1 = vec_(10)
    pos = 5
    
    obj2 = obj1.split(pos)
    
    
if __name__ == '__main__':
    
    '''Create and destroy objects'''
    setup_teardown_test(vec)
    setup_teardown_test(ivec)
    setup_teardown_test(cvec)
    setup_teardown_test(bvec)

#     '''Vector data manipulation'''
#     data_manipulation_test(ivec)
#         
#     '''Shaping operations'''
#     shape_manipulation_test(ivec)
    
#     '''Logical operations'''
