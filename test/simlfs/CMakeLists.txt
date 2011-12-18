#
# SimLFS Tests
#

##
# Specify each test suite configuration

# * LFSTestSuite Test Suite
module_test_add_suite (simlfs LFSTestSuite LFSTestSuite.cpp)


##
# Register all the test suites to be built and performed
module_test_build_all ()

