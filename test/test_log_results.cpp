
#include <erf-results/log_result.hpp>
#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/network/uri/uri_io.hpp>


using namespace results;



int main( int argc, char** argv )
{

  try {

    // create a new couchdb instance
    couchdb::Couchdb couch( boost::network::uri::uri("http://localhost:5984/test_log_results/") );
    
    // create a fake set of results
    boost::property_tree::ptree doc;
    doc.put( "results.samples", "");
    doc.add( "results.samples", 1.1 );
    doc.add( "results.samples", 1.2 );
    doc.add( "results.samples", 1.3 );
    doc.add( "results.samples", 1.4 );
    
    doc.put( "results.mean", 5.4 );
    
    // try to log the results
    boost::property_tree::ptree res =
      log_results( couch, doc );
    
    // print out result
    std::cout << "RESPONSE: " << std::endl;
    boost::property_tree::json_parser::write_json( std::cout, res );
    std::cout << std::endl;
    
    
  } catch (boost::exception& be ) {
    std::cerr << "DIAGNOSTICS: " << std::endl;
    std::cerr << boost::diagnostic_information( be );
    std::cerr << std::endl;
    throw;
  } catch (std::exception& e ) {
    std::cerr << "DIAGNOSTICS: " << std::endl;
    std::cerr << boost::diagnostic_information( e );
    std::cerr << std::endl;
    throw;
  }


  return 0;
}
