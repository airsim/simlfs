// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
#include <vector>
// StdAir
#include <stdair/basic/BasConst_General.hpp>
#include <stdair/service/Logger.hpp>
// SIMFQT
#include <simfqt/SIMFQT_Types.hpp>
#include <simfqt/bom/FareRuleStruct.hpp>

namespace SIMFQT {

  // ////////////////////////////////////////////////////////////////////
  FareRuleStruct::FareRuleStruct ()
    :_fareId(0), 
     _origin(""), 
     _destination(""),
     _dateRangeStart(stdair::DEFAULT_DATE),
     _dateRangeEnd(stdair::DEFAULT_DATE),
     _timeRangeStart(stdair::DEFAULT_EPSILON_DURATION),
     _timeRangeEnd(stdair::DEFAULT_EPSILON_DURATION),
     _cabinCode (""), 
     _pos (""), 
     _advancePurchase(0), 
     _saturdayStay("T"),
     _changeFees("T"), 
     _nonRefundable("T"),
     _minimumStay(0), 
     _fare(0),
     _airlineCode(""), 
     _classCode("") {

  }

  // ////////////////////////////////////////////////////////////////////
  stdair::Date_T FareRuleStruct::getDate() const {
    _itYear.check(); _itMonth.check(); _itDay.check();
    return stdair::Date_T (_itYear._value, _itMonth._value, _itDay._value);
  }

  // ////////////////////////////////////////////////////////////////////
  stdair::Duration_T FareRuleStruct::getTime() const {
    _itHours.check(); _itMinutes.check(); _itSeconds.check();
    return boost::posix_time::hours (_itHours._value)
      + boost::posix_time::minutes (_itMinutes._value)
      + boost::posix_time::seconds (_itSeconds._value);
  }
  
 
  // ////////////////////////////////////////////////////////////////////
  const std::string FareRuleStruct::describe () const {
    std::ostringstream ostr; 
    ostr << "FareRule: " << _fareId << ", "
	 << _origin << "-" << _destination
         << ", POS(" << _pos << "), ["
	 << _dateRangeStart << "/" << _dateRangeEnd << "] - ["
	 << boost::posix_time::to_simple_string(_timeRangeStart) << "/"
	 << boost::posix_time::to_simple_string(_timeRangeEnd) << "]\n    "
         << "-Cabin code- " << _cabinCode << "\n    "
         << "-Channel-    " << _channel << "\n    "
         << "-Conditions- " << _saturdayStay << ", " <<  _changeFees << ", "
         << _nonRefundable << ", " << _advancePurchase << ", "
	 << _minimumStay << "\n    "
         << "-Fare-       " << _fare << "\n           ";
    assert (_airlineCodeList.size() == _classCodeList.size());
    stdair::ClassList_StringList_T::const_iterator lItCurrentClassCode =
      _classCodeList.begin();
    stdair::AirlineCode_T lAirlineCode; 
    std::string lClassCode;
    for (stdair::AirlineCodeList_T::const_iterator lItCurrentAirlineCode =
           _airlineCodeList.begin();
         lItCurrentAirlineCode != _airlineCodeList.end();
         lItCurrentAirlineCode++) {
      lAirlineCode = *lItCurrentAirlineCode;
      lClassCode = *lItCurrentClassCode;
      ostr << lAirlineCode << ", " << lClassCode;
      ostr << "        ";
      lItCurrentClassCode++;
    }
    ostr << std::endl;
    return ostr.str();
  }

}
