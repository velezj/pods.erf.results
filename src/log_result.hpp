
#if !defined( __ERF_RESULTS_log_results_HPP__ )
#define __ERF_RESULTS_log_results_HPP__

#include <erf-couchdb/couchdb.hpp>


namespace results {


  //----------------------------------------------------------------------

  // Description:
  // Returns a string representation of the current time
  std::string now_string();

  //----------------------------------------------------------------------

  // Description:
  // Log a results property tree to the given couchdb
  // Returns the result (from couchdb) of storing the document
  boost::property_tree::ptree
  log_results( const couchdb::Couchdb& couch,
	       const boost::property_tree::ptree& doc );
    
  //----------------------------------------------------------------------

  // Description:
  // Returns a ptree (JSON) representing hte code version for a 
  // given path (default to current working directory)
  boost::property_tree::ptree
  get_code_version( const std::string& path = "." );

  //----------------------------------------------------------------------

  //----------------------------------------------------------------------
  //----------------------------------------------------------------------

}

#endif
