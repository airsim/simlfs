
Summary:
--------
SimLFS aims at providing a clean API and a simple implementation
(C++ library) of an airline-related Low Fare Search (LFS) system. That
library uses the Standard Airline IT C++ object model
(http://sf.net/projects/stdair).

SimLFS makes an extensive use of existing open-source libraries for
increased functionality, speed and accuracy. In particular the
Boost (C++ Standard Extensions: http://www.boost.org) library is used.


Getting and installing from the Fedora/CentOS/RedHat distribution:
------------------------------------------------------------------
Just use Yum:
yum -y install simlfs-devel simlfs-doc

You can also get the RPM packages (which may work on Linux
distributions like Novel Suse and Mandriva) from the Fedora repository
(e.g., for Fedora 16, 
http://fr2.rpmfind.net/linux/fedora/releases/16/Everything/)


Building the library and test binary from Git repository:
----------------------------------------------------------------
The Sourceforge Git repository may be cloned as following:
git clone ssh://simlfs.git.sourceforge.net/gitroot/simlfs/simlfs simlfsgit
cd simlfsgit
git checkout trunk

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

Building the library and test binary from the tarball:
------------------------------------------------------
The latest stable source tarball (simlfs*.tar.gz or .bz2) can be found here:
http://sourceforge.net/project/showfiles.php?group_id=365521

Then, as usual:
* To configure the project, type something like:
  mkdir build && cd build
  cmake -DCMAKE_INSTALL_PREFIX=/home/user/dev/deliveries/simlfs-1.00.0 \
   -DWITH_STDAIR_PREFIX=/home/user/dev/deliveries/stdair-stable \
   -DWITH_AIRRAC_PREFIX=/home/user/dev/deliveries/airrac-stable \
   -DWITH_RMOL_PREFIX=/home/user/dev/deliveries/rmol-stable \
   -DWITH_RMOL_PREFIX=/home/user/dev/deliveries/airinv-stable \
   -DWITH_RMOL_PREFIX=/home/user/dev/deliveries/simfqt-stable \
   -DCMAKE_BUILD_TYPE:STRING=Debug -DINSTALL_DOC:BOOL=ON ..
* To build the project, type:
  make
* To test the project, type:
  make check
* To install the library (libsimlfs*.so*) and the binary (simlfs),
  just type:
  make install
* To package the source files, type:
  make dist
* To package the binary and the (HTML and PDF) documentation:
  make package

Denis Arnaud (October 2011)

