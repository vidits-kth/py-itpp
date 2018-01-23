# py-itpp
Python library for signal processing and communications research.

# Description
py-itpp is a Python library for signal processing and communications. It is developed as a set of lightweight wrappers over the IT++ library (which is written in C++). The wrappers use Boost.Python extensively and compile to a shared library that can be imported into Python. The py-itpp data structures can be easily converted to Numpy ndarrays for further processing and plotting. In addition to fast prototyping for signal processing and communications research, py-itpp is motivated by research into machine learning for communication systems.  

# Documentation
py-itpp mimics the IT++ API, and as such the original documentation should suffice for documentation of the modules, functions, and data structures: http://itpp.sourceforge.net/4.3.1/modules.html. There are some exceptions to this rule as described in the wiki: https://github.com/vidits-kth/py-itpp/wiki/API-Notes  

# Installation
Prerequisites:  
It++ (shared mode): http://itpp.sourceforge.net/4.3.1/installation.html    
Boost.Python: http://www.boost.org/doc/libs/1_66_0/libs/python/doc/html/building/installing_boost_python_on_your_.html   
Clone the repo  
make pylib

# Examples
