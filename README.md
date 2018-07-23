## py-itpp
Python wrapper library for signal processing and communications research.

## Description
py-itpp is a set of Python wrappers over the open source IT++ library (which is written in C++). The wrappers use Boost.Python extensively and compile to a shared library that can be imported into Python. The py-itpp data structures can be easily converted to Numpy ndarrays for further processing and plotting. In addition to fast prototyping for signal processing and communications research, py-itpp is motivated by research into machine learning for communication systems.  

## Installation
Clone this repo  

# Python3:  
```python
cd py-itpp  
./install_prerequisites_python3.sh  
make install  
pip3 install -e .  
```
  
# Python2:  
```python
cd py-itpp  
./install_prerequisites.sh  
```
Open src/makefile and replace  
```python
libboost_python3 -> libboost_python  
libboost_numpy3 -> libboost_numpy  
```
Install this package:  
```python
make install  
pip3 install -e .  
```

## Usage
```python
import py_itpp as pyp  
a = pyp.vec('0:10:100')  
print(a)  
```
## More info, examples, etc.  
Wiki: https://github.com/vidits-kth/py-itpp/wiki
