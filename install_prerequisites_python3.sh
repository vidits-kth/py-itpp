# NOTE!
# You might need to update py_itpp/src/makefile to point to Python3
#    INCLUDE_PATH := $(INCLUDE_PATH) -I/usr/include/python3.5

sudo apt-get update
sudo apt-get -y install g++
sudo apt-get -y install libblas-dev liblapack-dev libfftw3-dev
sudo apt-get -y install make cmake

#if command -v python3 &>/dev/null; then
#    sudo apt-get -y install python3 
#fi
sudo apt-get -y install python3-dev python3-numpy


# Install ITPP
sudo apt-get -y install libitpp-dev
