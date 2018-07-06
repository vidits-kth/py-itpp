# NOTE!
# If you have both Python 2.* and Python 3.* installed, Boost may detect
# only Python 2.* and try to install against that. If so, you will need to
# manually go into ~/tmp/boost*/ and update the following in project-config.jam
#    using python : 3.5 : /usr ;
# Then run
#    > sudo ./b2 install --with-python
#
# NOTE!
# You will need to update py_itpp/src/makefile to point to Python3 libraries
#    -lboost_python3 -lboost_numpy3
# and Python3 include path
#    INCLUDE_PATH := $(INCLUDE_PATH) -I/usr/include/python3.5

sudo apt-get update
sudo apt-get -y install g++
sudo apt-get -y install libblas-* liblapack-* libfftw-*
sudo apt-get -y install make cmake

if command -v python3 &>/dev/null; then
    sudo apt-get -y install python3 
fi
sudo apt-get -y install python3-dev python3-pip python3-tk python3-numpy


export LC_ALL="en_US.UTF-8"
sudo pip3 install --upgrade pip
sudo pip3 install matplotlib


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


cp ~/.bashrc ~/.bashrc.bak
echo export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib >> ~/.bashrc
