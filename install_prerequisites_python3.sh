# NOTE!
# Specify the correct Python version below for --with-python option
#
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
mkdir ~/tmp
cd ~/tmp
wget https://netcologne.dl.sourceforge.net/project/itpp/itpp/4.3.1/itpp-4.3.1.tar.gz
tar -xf itpp-4.3.1.tar.gz
cd itpp-4.3.1/
mkdir build
cd build
cmake ..
make
sudo make install

# Install Boost.Python
cd ~/tmp
wget https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.gz
tar -xf boost_1_66_0.tar.gz
cd boost_1_66_0/
./bootstrap.sh --with-python=python3.5
sudo ./b2 install --with-python

# Update LD_LIBRARY_PATH to point to dependencies
cp ~/.bashrc ~/.bashrc.bak
echo export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib >> ~/.bashrc
