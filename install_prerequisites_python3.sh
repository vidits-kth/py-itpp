# NOTE!
# You might need to update py_itpp/src/makefile to point to Python3
#    INCLUDE_PATH := $(INCLUDE_PATH) -I/usr/include/python3.5

sudo apt-get update
sudo apt-get -y install g++
sudo apt-get -y install libblas-* liblapack-* libfftw-*
sudo apt-get -y install make cmake

if command -v python3 &>/dev/null; then
    sudo apt-get -y install python3 
fi
sudo apt-get -y install python3-dev python3-pip python3-tk python3-numpy


# Install ITPP
sudo apt-get -y install libitpp-dev

# Install Boost.Python
mkdir ~/tmp
cd ~/tmp
wget https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.gz
tar -xf boost_1_66_0.tar.gz
cd boost_1_66_0/
./bootstrap.sh --with-python=python3
sudo ./b2 cxxflags=-fPIC install --with-python

# Update LD_LIBRARY_PATH to point to dependencies
cp ~/.bashrc ~/.bashrc.bak
echo export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib >> ~/.bashrc
