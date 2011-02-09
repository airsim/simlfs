#ifndef __SIMFQT_CMD_FAREPARSERHELPER_HPP
#define __SIMFQT_CMD_FAREPARSERHELPER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
//#define BOOST_SPIRIT_DEBUG
// StdAir
#include <stdair/basic/BasParserTypes.hpp>
#include <stdair/command/CmdAbstract.hpp>
// Simfqt
#include <simfqt/SIMFQT_Types.hpp>
#include <simfqt/bom/FareRuleStruct.hpp>

// Forward declarations
namespace stdair {
  class BomRoot;
}

namespace SIMFQT {

  namespace FareParserHelper {
    
    // ///////////////////////////////////////////////////////////////////
    //  Semantic actions
    // ////////////////////////////////////////////////////
    ///////////////
    /** Generic Semantic Action (Actor / Functor) for the Fare Parser. */
    struct ParserSemanticAction {
      /** Actor Constructor. */
      ParserSemanticAction (FareRuleStruct&);
      /** Actor Context. */
      FareRuleStruct& _fareRule;
    };

    /** Store the parsed fare Id. */
    struct storeFareId : public ParserSemanticAction {
      /** Actor Constructor. */
      storeFareId (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (unsigned int,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed origin. */
    struct storeOrigin : public ParserSemanticAction {
      /** Actor Constructor. */
      storeOrigin (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (std::vector<char>,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed destination. */
    struct storeDestination : public ParserSemanticAction {
      /** Actor Constructor. */
      storeDestination (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (std::vector<char>,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

     /** Store the parsed start of the date range. */
    struct storeDateRangeStart : public ParserSemanticAction {
      /** Actor Constructor. */
      storeDateRangeStart (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed end of the date range. */
    struct storeDateRangeEnd : public ParserSemanticAction {
      /** Actor Constructor. */
      storeDateRangeEnd (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed start range time. */
    struct storeStartRangeTime : public ParserSemanticAction {
      /** Actor Constructor. */
      storeStartRangeTime (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed end start range time. */
    struct storeEndRangeTime : public ParserSemanticAction {
      /** Actor Constructor. */
      storeEndRangeTime (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed customer position. */
    struct storePOS : public ParserSemanticAction {
      /** Actor Constructor. */
      storePOS (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (std::vector<char>,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the channel distribution. */
    struct storeChannel : public ParserSemanticAction {
      /** Actor Constructor. */
      storeChannel (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (std::vector<char>,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed advance purchase days. */
    struct storeAdvancePurchase : public ParserSemanticAction {
      /** Actor Constructor. */
      storeAdvancePurchase (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (unsigned int,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed saturday night. */
    struct storeSaturdayStay : public ParserSemanticAction {
      /** Actor Constructor. */
      storeSaturdayStay (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (char,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };
    
    /** Store the parsed change fees. */
    struct storeChangeFees : public ParserSemanticAction {
      /** Actor Constructor. */
      storeChangeFees (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (char,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed refundable option */
    struct storeNonRefundable : public ParserSemanticAction {
      /** Actor Constructor. */
      storeNonRefundable (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (char,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };
    
    /** Store the parsed minimum stay. */
    struct storeMinimumStay : public ParserSemanticAction {
      /** Actor Constructor. */
      storeMinimumStay (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (unsigned int,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

     /** Store the parsed fare value. */
    struct storeFare : public ParserSemanticAction {
      /** Actor Constructor. */
      storeFare (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (double,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const; 
    };
    
    /** Store the parsed airline code. */
    struct storeAirlineCode : public ParserSemanticAction {
      /** Actor Constructor. */
      storeAirlineCode (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (std::vector<char>,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
    };

    /** Store the parsed class. */
    struct storeClass : public ParserSemanticAction {
      /** Actor Constructor. */
      storeClass (FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (char,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const; 
    };
    
    /** Mark the end of the fare-rule parsing. */
    struct doEndFare : public ParserSemanticAction {
      /** Actor Constructor. */
      doEndFare (stdair::BomRoot&, FareRuleStruct&);
      /** Actor Function (functor). */
      void operator() (boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type,
                       boost::spirit::qi::unused_type) const;
      /** Actor Specific Context. */
      stdair::BomRoot& _bomRoot;
    };
  

    /////////////////////////////////////////////////////////////////////////
    //
    //  (Boost Spirit) Grammar Definition
    //
    /////////////////////////////////////////////////////////////////////////
    /**

     // Fare: fareID; OriginCity; DestinationCity; DateRangeStart;
     DateRangeEnd; DepartureTimeRangeStart; DepartureTimeRangeEnd;
     POS; AdvancePurchase; SaturdayNight; ChangeFees; NonRefundable;
     MinimumStay; Price; AirlineCode; Class;

     fareID
     OriginCity              (3-char airport code)
     DestinationCity         (3-char airport code)
     DateRangeStart          (yyyy-mm-dd)
     DateRangeEnd            (yyyy-mm-dd)
     DepartureTimeRangeStart (hh:mm)
     DepartureTimeRangeEnd   (hh:mm)
     POS                     (3-char position city)
     Channel                 (D=direct, I=indirect, N=oNline, F=oFfline)
     AdvancePurchase         
     SaturdayNight           (T=True, F=False)
     ChangeFees              (T=True, F=False)
     NonRefundable           (T=True, F=False)
     MinimumStay
     Price
     AirlineCode             (2-char airline code)
     Class                   (1-char class code)
     
     Grammar:
      Demand ::= PrefDepDate ';' Origin ';' Destination ';' PassengerType
         ';' DemandParams ';' PosDist ';' ChannelDist ';'  TripDist
         ';' StayDist ';' FfDist ';'  PrefDepTimeDist
         ';' minWTP ';' TimeValueDist ';'  DtdDist
         EndOfDemand
      PrefDepDate ::= date
      PassengerType ::= 'T' | 'F'
      DemandParams ::= DemandMean ';' DemandStdDev
      PosDist ::= PosPair (',' PosPair)*
      PosPair ::= PosCode ':' PosShare
      PosCode ::= AirportCode | "row"
      PosShare ::= real
      ChannelDist ::= ChannelPair (',' ChannelPair)*
      ChannelPair ::= Channel_Code ':' ChannelShare
      ChannelCode ::= "DF" | "DN" | "IF" | "IN"
      ChannelShare ::= real
      TripDist ::= TripPair (',' TripPair)*
      TripPair ::= TripCode ':' TripShare
      TripCode ::= "RO" | "RI" | "OW"
      TripShare ::= real
      StayDist ::= StayPair (',' StayPair)*
      StayPair ::= [0;3]-digit-integer ':' stay_share
      StayShare ::= real
      FFDist ::= FF_Pair (',' FF_Pair)*
      FFPair ::= FFCode ':' FFShare
      FFCode ::= 'P' | 'G' | 'S' | 'M' | 'N'
      FFShare ::= real
      PrefDepTimeDist ::= PrefDepTimePair (',' PrefDepTimePair)*
      PrefDepTimePair ::= time ':' PrefDepTimeShare
      PrefDepTimeShare ::= real
      minWTP ::= real
      TimeValueDist ::= TimeValuePair (',' TimeValuePair)*
      TimeValuePair ::= [0;2]-digit-integer ':' TimeValueShare
      TimeValueShare ::= real
      DTDDist ::= DTDPair (',' DTDPair)*
      DTDPair ::= real ':' DTDShare
      DTDShare ::= real
      EndOfDemand ::= ';'
     
    */ 

    /** Grammar for the Fare-Rule parser. */
    struct FareRuleParser : 
      public boost::spirit::qi::grammar<stdair::iterator_t, 
                                        boost::spirit::ascii::space_type> {

      FareRuleParser (stdair::BomRoot&, FareRuleStruct&);

      // Instantiation of rules
      boost::spirit::qi::rule<stdair::iterator_t,
                              boost::spirit::ascii::space_type>
      start, comments, fare_rule, fare_rule_end, fare_key, fare_id, origin,
        destination, dateRangeStart, dateRangeEnd, date, timeRangeStart,
        timeRangeEnd, time, position, channel, advancePurchase, saturdayStay,
        changeFees, nonRefundable, minimumStay, fare, segment;
      
      // Parser Context
      stdair::BomRoot& _bomRoot;
      FareRuleStruct& _fareRule;
    };

  }
  
  /////////////////////////////////////////////////////////////////////////
  //
  //  Entry class for the file parser
  //
  /////////////////////////////////////////////////////////////////////////
  /** Class wrapping the 
      initialisation and entry point of the parser.
      <br>The seemingly redundancy is used to force the instantiation of
      the actual parser, which is a templatised Boost Spirit grammar.
      Hence, the actual parser is instantiated within that class object
      code. */
  class FareRuleFileParser : public stdair::CmdAbstract {
  public:
    /** Constructor. */
    FareRuleFileParser (stdair::BomRoot& ioBomRoot,
                        const stdair::Filename_T& iFilename);

    /** Parse the input file and generate the Inventories. */
    bool generateFareRules ();
      
  private:
    /** Initialise. */
    void init();
      
  private:
    // Attributes
    /** File-name of the CSV-formatted schedule input file. */
    stdair::Filename_T _filename;

    /** stdair::BomRoot. */
    stdair::BomRoot& _bomRoot;

    /** Fare-Rule Structure. */
    FareRuleStruct _fareRule;
  };
    
}
#endif // __SIMFQT_CMD_FAREPARSERHELPER_HPP
