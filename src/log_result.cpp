
#include "log_result.hpp"
#include <erf-couchdb/utils.hpp>
#include <boost/chrono/chrono_io.hpp>
#include <sstream>
#include <pstream/pstream.h>
#include <boost/property_tree/json_parser.hpp>


namespace results {

  //======================================================================

  std::string now_string()
  {
    std::ostringstream oss;
    boost::chrono::system_clock::time_point t 
      = boost::chrono::system_clock::now();
    oss << t;
    return oss.str();
  }

  //======================================================================
   
  boost::property_tree::ptree
  log_results( const couchdb::Couchdb& couch,
	       const boost::property_tree::ptree& doc )
  {
    
    // setup some defaults for the result property tree (doc)
    boost::property_tree::ptree default_doc;

    // get the default code version
    boost::property_tree::ptree code_version = get_code_version();
    default_doc.put_child( "code.version", code_version );
      
    // get the timestamp
    std::string ts = now_string();
    default_doc.put( "stored_on", ts );
      
    // ok, ensure the substructure given in results is in the default
    boost::property_tree::ptree final_doc =
      couchdb::ensure_substructure( default_doc, doc );
      
    // now save the document
    boost::property_tree::ptree res = couch.save( final_doc );
      
    return res;
  }
    
  //======================================================================

  boost::property_tree::ptree
  get_code_version( const std::string& path )
  {
    //std::cout << "CODE VERSION from: " << path << std::endl;
    std::ostringstream oss;
    oss << "git-version-script" << " " << path;
    std::string command = oss.str();
    redi::ipstream is( command );
    std::stringstream ss;
    std::string line;
    //std::cout << "VERSION RAW:" << std::endl;
    while( std::getline( is, line ) ) {
      ss << line << std::endl;
      //std::cout << line << std::endl;
    }
    boost::property_tree::ptree code_version;
    try {
      boost::property_tree::json_parser::read_json( ss, code_version );
    } catch ( boost::exception& e ) {
      throw;
    }
      
    return code_version;
  }

  //======================================================================

}

