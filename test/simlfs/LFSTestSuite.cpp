/*!
 * \page FQTTestSuite_cpp Command-Line Test to Demonstrate How To Test the SimFQT Project
 * \code
 */
// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <sstream>
#include <fstream>
#include <string>
// Boost Unit Test Framework (UTF)
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE LFSTestSuite
#include <boost/test/unit_test.hpp>
// StdAir
#include <stdair/basic/BasLogParams.hpp>
#include <stdair/basic/BasDBParams.hpp>
#include <stdair/basic/BasFileMgr.hpp>
#include <stdair/service/Logger.hpp>
// SimLFS
#include <simlfs/SIMLFS_Service.hpp>
#include <simlfs/config/simlfs-paths.hpp>

namespace boost_utf = boost::unit_test;

/**
 * Configuration for the Boost Unit Test Framework (UTF)
 */
struct UnitTestConfig {
  /** Constructor. */
  UnitTestConfig() {
    static std::ofstream _test_log ("LFSTestSuite_utfresults.xml");
    boost_utf::unit_test_log.set_stream (_test_log);
    boost_utf::unit_test_log.set_format (boost_utf::XML);
    boost_utf::unit_test_log.set_threshold_level (boost_utf::log_test_units);
    //boost_utf::unit_test_log.set_threshold_level (boost_utf::log_successful_tests);
  }

  /** Destructor. */
  ~UnitTestConfig() {
  }
};


// /////////////// Main: Unit Test Suite //////////////

// Set the UTF configuration (re-direct the output to a specific file)
BOOST_GLOBAL_FIXTURE (UnitTestConfig);

// Start the test suite
BOOST_AUTO_TEST_SUITE (master_test_suite)

/**
 * Test a simple price quotation
 */
BOOST_AUTO_TEST_CASE (simlfs_simple_pricing_test) {

  // Fare input file name
  const stdair::Filename_T lFareInputFilename (STDAIR_SAMPLE_DIR "/fare01.csv");
    
  // Check that the file path given as input corresponds to an actual file
  const bool doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lFareInputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lFareInputFilename
                       << "' input file can not be open and read");

  // Output log File
  const stdair::Filename_T lLogFilename ("LFSTestSuite.log");

  // Set the log parameters
  std::ofstream logOutputFile;
  // Open and clean the log outputfile
  logOutputFile.open (lLogFilename.c_str());
  logOutputFile.clear();
  
  // Initialise the list of classes/buckets
  const stdair::BasLogParams lLogParams (stdair::LOG::DEBUG, logOutputFile);
  SIMLFS::SIMLFS_Service simlfsService (lLogParams, lFareInputFilename);
  
  // Perform a price quotation
  // Airline code
  const stdair::AirlineCode_T lAirlineCode ("SV");
  // Number of passengers in the travelling group
  const stdair::PartySize_T lPartySize = 5;
  simlfsService.priceQuote (lAirlineCode, lPartySize);
  
  // DEBUG
  STDAIR_LOG_DEBUG ("Sample data directory: " << STDAIR_SAMPLE_DIR);
}

// //////////////////////////////////////////////////////////////////////
void LFSTestSuite::simpleLFS () {
  // TODO: Check that the LFS goes as expected
  CPPUNIT_ASSERT_NO_THROW ( simpleLFSHelper(););
}

// //////////////////////////////////////////////////////////////////////
// void LFSTestSuite::errorCase () {
//  CPPUNIT_ASSERT (false);
// }

// //////////////////////////////////////////////////////////////////////
LFSTestSuite::LFSTestSuite () {
  _describeKey << "Running test on LFS";
}

// /////////////// M A I N /////////////////
CPPUNIT_MAIN()
