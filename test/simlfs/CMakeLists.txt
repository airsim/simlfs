#
# SimLFS Tests
#
module_set_name (simlfs)


##
# Specify each test suite configuration

# * LFSTestSuite Test Suite
module_test_add_suite (LFSTestSuite LFSTestSuite.cpp)


##
# Register all the test suites to be built and performed
module_test_build_all ()
