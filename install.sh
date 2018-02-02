sudo apt-get update
sudo apt-get -y install g++
sudo apt-get -y install libblas-* liblapack-* libfftw-*
sudo apt-get -y install make cmake
sudo apt-get -y install python2.7* 
sudo apt-get -y install python-dev python-pip python-numpy

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


cd ~/tmp
wget https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.gz
tar -xf boost_1_66_0.tar.gz
cd boost_1_66_0/
./bootstrap.sh
sudo ./b2 install --with-python

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

cd ~
mkdir workspace
cd workspace
git clone https://github.com/vidits-kth/py-itpp.git
cd py-itpp
sudo make install

export PYTHONPATH=$PYTHONPATH:~/workspace/py-itpp/lib/gcc
