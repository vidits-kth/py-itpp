## py-itpp
Python wrapper library for signal processing and communications research.

## Description
py-itpp is a set of Python wrappers over the open source IT++ library (which is written in C++). The wrappers use Boost.Python extensively and compile to a shared library that can be imported into Python. The py-itpp data structures can be easily converted to Numpy ndarrays for further processing and plotting. In addition to fast prototyping for signal processing and communications research, py-itpp is motivated by research into machine learning for communication systems.  

## Native Installation
Clone this repo.  

### Python3:  
```
cd py-itpp  
./install_prerequisites_python3.sh  
make install  
pip3 install -e .  
```
Close the terminal and open a new one.  

### Python2:  
```
cd py-itpp  
./install_prerequisites_python2.sh  
```
Open src/makefile and replace  
```
libboost_python3 -> libboost_python  
libboost_numpy3 -> libboost_numpy  
INCLUDE_PATH := $(INCLUDE_PATH) -I/usr/include/python2.7  
```
Install this package:  
```
make install  
pip install -e .  
```
Close the terminal and open a new one.  

## Anaconda Installation
Clone this repo.  

### Python3:  
```
cd py-itpp  
./install_prerequisites_python3.sh  
conda install boost
make install  
pip install -e .  
```


## Usage
```python
import itpp
a = itpp.vec('0:10:100')  
print(a)  
```
## More info, examples, etc.  
Wiki: https://github.com/vidits-kth/py-itpp/wiki
