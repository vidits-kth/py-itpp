# py-itpp
Python Wrappers over IT++

# Description
py-itpp is a Python library mainly for signal processing and communications. It is developed as a set of lightweight wrappers over the IT++ library (which is written in C++). The wrappers are use Boost.Python extensively and compile to a shared library that can be imported into Python.

# Documentation
py-itpp mimics the IT++ API, and as such the original documentation should suffice for documentation of the modules, functions, and data structures: http://itpp.sourceforge.net/4.3.1/modules.html.  

There are some exceptions to this rule, which are listed below:  
IT++ Array class: Array is a template class, which is not supported in Python. However, py-itpp contains wrapper to the Array class along with a few pre-defined array types in Array.cpp (double, int, std::complex < double >), and new types may be defined in a similar manner. Note that py-itpp needs to be rebuilt every time a new Array type is added.

# Installation
Prerequisites:  
It++ (shared mode): http://itpp.sourceforge.net/4.3.1/installation.html    
Boost.Python: http://www.boost.org/doc/libs/1_66_0/libs/python/doc/html/building/installing_boost_python_on_your_.html   
Clone the repo  
make pylib

# Examples
