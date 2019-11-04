#
cmake_minimum_required (VERSION 3.0)

##
# CMake macros for the project
include (config/project_config_embeddable.cmake)

##
# Project info
project (simlfs)
set_project_names (simlfs SimLFS)
set_project_brief ("C++ Simulated Low Fare Search (LFS) library")
set_project_versions (99 99 99)

##
# Project options
# The parameters are:
#  * whether or not the documentation must be built and installed
#  * whether or not the tests must be compiled and run
#  * whether or not the code coverage must be performed
set_project_options (on on off)


#####################################
##            Packaging            ##
#####################################
#
packaging_init (${PROJECT_NAME})
packaging_set_summary (
"${PROJECT_NAME} aims at providing a clean API and a simple implementation
(C++ library) of an Airline-related Low Fare Search (LFS) system. That
library uses the Standard Airline IT C++ object model
(http://sf.net/projects/stdair).

${PROJECT_NAME} makes an extensive use of existing open-source libraries for
increased functionality, speed and accuracy. In particular the Boost
(C++ Standard Extensions: http://www.boost.org) library is used.")
packaging_set_contact ("Denis Arnaud <denis_arnaud - at - users dot sourceforge dot net>")
packaging_set_vendor ("Denis Arnaud")

#
packaging_set_other_options (TBZ2 "TBZ2;TGZ")


########################################
##            Dependencies            ##
########################################
#
get_external_libs (git "python 3.4" "boost 1.41" readline mysql "soci 3.0"
  "stdair 1.00.0" "airrac 1.00.0" "rmol 1.00.0" "sevmgr 1.00.0" "airinv 1.00.0" 
  "simfqt 1.00.0" doxygen "gcov 4.6.3" "lcov 1.9")


##############################################
##           Build, Install, Export         ##
##############################################
##
# Initialise the building process
init_build ()

##
# Sub-modules
add_modules (${PROJECT_NAME})

##
# For other projects to use SimLFS, install a few helpers for standard
# build/packaging systems: CMake, GNU Autotools (M4), pkgconfig/pc, 
# simlfs-config
install_dev_helper_files ()

##
# Basic documentation (i.e., AUTHORS, NEWS, README, INSTALL)
install_basic_documentation ()


##########################################
##            Documentation             ##
##########################################
#
#handle_html_doc ()

##
# Subdirs
#add_subdirectory (man)


#####################################
##              Tests              ##
#####################################
##
# Initialise the unit test process
init_test ()

##
# Test suites
add_test_suite (${PROJECT_NAME})


#######################################
##             GCOV                 ##
#######################################
gcov_task()


#######################################
##          Overall Status           ##
#######################################
display_status ()


#######################################
##         CMake Cache Storage       ##
#######################################
store_in_cache ()
