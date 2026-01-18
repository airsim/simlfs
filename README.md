C++ Simulated Low Fare Search (LFS) Library
===========================================

# Summary
SimLFS aims at providing a clean API and a simple implementation
(C++ library) of an airline-related Low Fare Search (LFS) system.
That library uses the Standard Airline IT C++ object model
(https://github.com/airsim/stdair).

SimLFS makes an extensive use of existing open-source libraries for
increased functionality, speed and accuracy. In particular the
Boost (C++ Standard Extensions: https://www.boost.org) library is used.

# Installation

## On Fedora/CentOS/RedHat distribution
Just use DNF (or Yum on older distributions):
```bash
$ dnf -y install simlfs-devel simlfs-doc
```

You can also get the RPM packages (which may work on Linux
distributions like Novel Suse and Mandriva) from the Fedora repository
(_e.g._, for Fedora Rawhide,
https://fr2.rpmfind.net/linux/RPM/fedora/devel/rawhide/x86_64/)


## Building the library and test binary from Git repository
The Sourceforge Git repository may be cloned as following:
```bash
$ git clone git@github.com:airsim/simlfs.git simlfsgit # through SSH
$ git clone https://github.com/airsim/simlfs.git # if the firewall filters SSH
$ cd simlfsgit
```

Then, you need the following packages (Fedora/RedHat/CentOS names here, 
but names may vary according to distributions):
  * cmake
  * gcc-c++
  * stdair-devel, airrac-devel, rmol-devel, airinv-devel, simfqt-devel
  * boost-devel
  * zeromq-devel
  * readline-devel
  * soci-mysql-devel
  * python-devel
  * gettext-devel (optional)
  * doxygen, ghostscript, graphviz and tetex-latex (optional)
  * rpm-build (optional)

## Building the library and test binary from the tarball
The latest stable source tarball (`simlfs*.tar.gz` or `.bz2`) can be found
on GitHub:
https://github.com/airsim/simlfs/releases

To customise the following to your environment, you can alter the path
to the installation directory:
```bash
export INSTALL_BASEDIR="${HOME}/dev/deliveries"
export LFS_VER="1.00.8"
if [ -d /usr/lib64 ]; then LIBSUFFIX="64"; fi
export LIBSUFFIX_4_CMAKE="-DLIB_SUFFIX=$LIBSUFFIX"
``

Then, as usual:
* To configure the project, type something like:
```bash
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_BASEDIR}/simlfs-${LFS_VER} \
   -DWITH_STDAIR_PREFIX=${INSTALL_BASEDIR}/stdair-stable \
   -DWITH_AIRRAC_PREFIX=${INSTALL_BASEDIR}/airrac-stable \
   -DWITH_RMOL_PREFIX=${INSTALL_BASEDIR}/rmol-stable \
   -DWITH_RMOL_PREFIX=${INSTALL_BASEDIR}/airinv-stable \
   -DWITH_RMOL_PREFIX=${INSTALL_BASEDIR}/simfqt-stable \
   -DCMAKE_BUILD_TYPE:STRING=Debug \
   -DINSTALL_DOC:BOOL=ON -DRUN_GCOV:BOOL=OFF ${LIBSUFFIX_4_CMAKE} ..
```
* To build the project, type:
```bash
  make
```
* To test the project, type:
```bash
  make check
```
* To install the library (`libsimlfs*.so*`) and the binary (`simlfs`),
  just type:
```bash
  make install
```
* To package the source files, type:
```bash
  make dist
```
* To package the binary and the (HTML and PDF) documentation:
```bash
  make package
```

Denis Arnaud

