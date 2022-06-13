## py-itpp
Python wrapper library for signal processing and communications research.

## Description
py-itpp is a set of Python wrappers over the open source IT++ library (which is written in C++). The wrappers are built using PYBIND11 and compile to a shared library that can be imported into Python. The py-itpp data structures can be easily converted to Numpy ndarrays for further processing and plotting. In addition to fast prototyping for signal processing and communications research, py-itpp is motivated by research into machine learning for communication systems.  

## Support
As of v0.0.3, only Python3 is supported.

## Docker

py-itpp is available as a public Docker image hosted at [vidit13/py-itpp](https://hub.docker.com/repository/docker/vidit13/py-itpp) .

The latest image can be pulled by specifying
```
FROM vidit13/py-itpp
```


## Installation

```
pip3 install pybind11
```
Re-open the terminal.  

```
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

## Projects using py-itpp
https://github.com/lpkg/LinkAdaptationCSI  
https://github.com/vidits-kth/contextual-mab-link-adaptation  
https://github.com/vidits-kth/py-radio-autoencoder  
