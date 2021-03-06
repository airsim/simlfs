/*!
 * \page LFSTestSuite_cpp Command-Line Test to Demonstrate How To Test the SimLFS Project
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
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/bom/BookingRequestStruct.hpp>
#include <stdair/service/Logger.hpp>
// SimLFS
#include <simlfs/SIMLFS_Service.hpp>
#include <simlfs/config/simlfs-paths.hpp>

namespace boost_utf = boost::unit_test;

// (Boost) Unit Test XML Report
std::ofstream utfReportStream ("LFSTestSuite_utfresults.xml");

/**
 * Configuration for the Boost Unit Test Framework (UTF)
 */
struct UnitTestConfig {
  /** Constructor. */
  UnitTestConfig() {
    boost_utf::unit_test_log.set_stream (utfReportStream);
#if BOOST_VERSION_MACRO >= 105900
    boost_utf::unit_test_log.set_format (boost_utf::OF_XML);
#else // BOOST_VERSION_MACRO
    boost_utf::unit_test_log.set_format (boost_utf::XML);
#endif // BOOST_VERSION_MACRO
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

  // Schedule input filename
  const stdair::Filename_T lScheduleInputFilename (STDAIR_SAMPLE_DIR
                                                   "/schedule01.csv");
  const stdair::ScheduleFilePath lScheduleFilePath (lScheduleInputFilename);
  
  // O&D input filename
  const stdair::Filename_T lOnDInputFilename (STDAIR_SAMPLE_DIR "/ond01.csv");
  const stdair::ODFilePath lODFilePath (lOnDInputFilename);

  // FRAT5 curve input file name
  const stdair::Filename_T lFRAT5InputFilename (STDAIR_SAMPLE_DIR
                                               "/frat5.csv");
  stdair::FRAT5FilePath lFRAT5FilePath (lFRAT5InputFilename);

  // Fare family disutility curve input file name
  const stdair::Filename_T lFFDisutilityInputFilename (STDAIR_SAMPLE_DIR
                                                       "/ffDisutility.csv");
  stdair::FFDisutilityFilePath lFFDisutilityFilePath (lFFDisutilityInputFilename);
    
  // Fare input file name
  const stdair::Filename_T lFareInputFilename (STDAIR_SAMPLE_DIR
                                               "/rds01/fare.csv");
  const SIMFQT::FareFilePath lFareFilePath (lFareInputFilename);
    
  // Yield input file name
  const stdair::Filename_T lYieldInputFilename (STDAIR_SAMPLE_DIR
                                                "/yieldstore01.csv");
  const AIRRAC::YieldFilePath lYieldFilePath (lYieldInputFilename);
    
  // Check that the file path given as input corresponds to an actual file
  bool doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lScheduleInputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lScheduleInputFilename
                       << "' input file can not be open and read");

  // Check that the file path given as input corresponds to an actual file
  doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lOnDInputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lOnDInputFilename
                       << "' input file can not be open and read");
  
  // Check that the file path given as input corresponds to an actual file
  doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lFRAT5InputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lFRAT5InputFilename
                       << "' input file can not be open and read");
  
  // Check that the file path given as input corresponds to an actual file
  doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lFFDisutilityInputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lFFDisutilityInputFilename
                       << "' input file can not be open and read");

  // Check that the file path given as input corresponds to an actual file
  doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lFareInputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lFareInputFilename
                       << "' input file can not be open and read");

  // Check that the file path given as input corresponds to an actual file
  doesExistAndIsReadable =
    stdair::BasFileMgr::doesExistAndIsReadable (lYieldInputFilename);
  BOOST_CHECK_MESSAGE (doesExistAndIsReadable == true,
                       "The '" << lYieldInputFilename
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
  SIMLFS::SIMLFS_Service simlfsService (lLogParams, lScheduleFilePath,
                                        lODFilePath, lFRAT5FilePath,
                                        lFFDisutilityFilePath, lFareFilePath,
                                        lYieldFilePath);
  
  // Create an empty booking request structure
  // TODO: fill the booking request structure from the input parameters
  const stdair::AirportCode_T lOrigin ("SIN");
  const stdair::AirportCode_T lDestination ("BKK");
  const stdair::AirportCode_T lPOS ("SIN");
  const stdair::Date_T lPreferredDepartureDate(2010, boost::gregorian::Jan, 30);
  const stdair::Date_T lRequestDate (2010, boost::gregorian::Jan, 22);
  const stdair::Duration_T lRequestTime (boost::posix_time::hours(10));
  const stdair::DateTime_T lRequestDateTime (lRequestDate, lRequestTime);
  const stdair::CabinCode_T lPreferredCabin ("Eco");
  const stdair::PartySize_T lPartySize (3);
  const stdair::ChannelLabel_T lChannel ("IN");
  const stdair::TripType_T lTripType ("RI");
  const stdair::DayDuration_T lStayDuration (7);
  const stdair::FrequentFlyer_T lFrequentFlyerType ("M");
  const stdair::Duration_T lPreferredDepartureTime (boost::posix_time::hours(10));
  const stdair::WTP_T lWTP (1000.0);
  const stdair::PriceValue_T lValueOfTime (100.0);
  const stdair::ChangeFees_T lChangeFees (true);
  const stdair::Disutility_T lChangeFeeDisutility (50);
  const stdair::NonRefundable_T lNonRefundable (true);
  const stdair::Disutility_T lNonRefundableDisutility (50);
  const stdair::BookingRequestStruct lBookingRequest (lOrigin, lDestination,
                                                      lPOS,
                                                      lPreferredDepartureDate,
                                                      lRequestDateTime,
                                                      lPreferredCabin,
                                                      lPartySize, lChannel,
                                                      lTripType, lStayDuration,
                                                      lFrequentFlyerType,
                                                      lPreferredDepartureTime,
                                                      lWTP, lValueOfTime,
                                                      lChangeFees,
                                                      lChangeFeeDisutility,
                                                      lNonRefundable,
                                                      lNonRefundableDisutility);

  // TODO: build a hand-made segment-path (as AirTSP service is not
  //       available from here
  /*
  const stdair::SegmentPathList_T lSegmentPath =
    simlfsService.calculateSegmentPathList (lBookingRequest);
  
  // Price the travel solution
  stdair::TravelSolutionList_T lTravelSolutionList =
    simlfsService.fareQuote (lBookingRequest, lSegmentPath);

  //
  const unsigned int lNbOfTravelSolutions = lTravelSolutionList.size();

  // TODO: change the expected number of travel solutions to the actual number
  const unsigned int lExpectedNbOfTravelSolutions = 2;
  
  // DEBUG
  STDAIR_LOG_DEBUG ("Number of travel solutions for the booking request '"
                    << lBookingRequest.describe() << "': "
                    << lNbOfTravelSolutions << ". It is expected to be "
                    << lExpectedNbOfTravelSolutions);

  BOOST_CHECK_EQUAL (lNbOfTravelSolutions, lExpectedNbOfTravelSolutions);

  BOOST_CHECK_MESSAGE(lNbOfTravelSolutions == lExpectedNbOfTravelSolutions,
                      "The number of travel solutions for the booking request '"
                      << lBookingRequest.describe() << "' is equal to "
                      << lNbOfTravelSolutions << ", but it should be equal to "
                      << lExpectedNbOfTravelSolutions);
  
  //
  const stdair::TravelSolutionStruct& lTravelSolution =
    lTravelSolutionList.front();

  //  
  const unsigned int lExpectedPrice = 2000;
  
  // DEBUG
  STDAIR_LOG_DEBUG ("The price given by the fare quoter for '"
                    << lTravelSolution.describe() << "' is: "
                    << lTravelSolution.getFare() << " Euros, and should be "
                    << lExpectedPrice);

  BOOST_CHECK_EQUAL (std::floor (lTravelSolution.getFare() + 0.5),
                     lExpectedPrice);

  BOOST_CHECK_MESSAGE (std::floor (lTravelSolution.getFare() + 0.5)
                       == lExpectedPrice,
                       "The price given by the fare quoter for '"
                       << lTravelSolution.describe() << "' is: "
                       << lTravelSolution.getFare() << " Euros, and should be "
                       << lExpectedPrice);
  */

  // Close the log file
  logOutputFile.close();
}

// End the test suite
BOOST_AUTO_TEST_SUITE_END()

/*!
 * \endcode
 */

