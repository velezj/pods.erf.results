
#if !defined( __ERF_RESULTS_log_results_HPP__ )
#define __ERF_RESULTS_log_results_HPP__

namespace erf {
  namespace results {


    //----------------------------------------------------------------------

    // Description:
    // Log a results property tree to the given couchdb
    void log_results( const Couchdb& couch,
		      const boost::property_tree::ptree& doc );
    
    //----------------------------------------------------------------------
    //----------------------------------------------------------------------
    //----------------------------------------------------------------------

  }
}

#endif
