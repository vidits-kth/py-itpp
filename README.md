## py-itpp
Python wrapper library for signal processing and communications research.

## Description
py-itpp is a set of Python wrappers over the open source IT++ library (which is written in C++). The wrappers are built using PYBIND11 and compile to a shared library that can be imported into Python. The py-itpp data structures can be easily converted to Numpy ndarrays for further processing and plotting. In addition to fast prototyping for signal processing and communications research, py-itpp is motivated by research into machine learning for communication systems.  

## Support
As of v0.0.3, only Python3 is supported; Python2 is no longer supported by this library.

## Installation

```
pip3 install pybind11

git clone https://github.com/vidits-kth/py-itpp.git
cd py-itpp  
./install_prerequisites_python3.sh  
make install  
pip3 install -e .  
```
Re-open the terminal.  


## Usage
```python
import itpp
a = itpp.vec('0:10:100')  
print(a)  
```
## More info, examples, etc.
Examples: https://github.com/vidits-kth/py-itpp/tree/master/examples  
Wiki: https://github.com/vidits-kth/py-itpp/wiki
