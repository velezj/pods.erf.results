
add_library(erf-results SHARED
    log_result.cpp
)
pods_install_headers(
    log_result.hpp
    DESTINATION
    erf-results
)
pods_install_libraries( erf-results )
set(REQUIRED_PACKAGES
    erf-couchdb
    boost-1.54.0
    cppnetlib-client-connections-0.10.1
    cppnetlib-uri-0.10.1 
    openssl-1.0.1e
    unittest++)
pods_use_pkg_config_packages( erf-results ${REQUIRED_PACKAGES} )
pods_install_pkg_config_file( erf-results
    CFLAGS
    LIBS -Lerf-results
    REQUIRES ${REQUIRED_PACKAGES}
    VERSION 0.0.1
)



## # Create a shared library libhello.so with a single source file
## add_library(hello SHARED
##     hello.c)

## # make the header public
## # install it to include/hello
## pods_install_headers(hello.h DESTINATION hello)

## # make the library public
## pods_install_libraries(hello)

## # uncomment these lines to link against another library via pkg-config
## #set(REQUIRED_PACKAGES pkg_a pkg_b)
## #pods_use_pkg_config_packages(hello ${REQUIRED_PACKAGES})

## # create a pkg-config file for the library, to make it easier for other
## # software to use.
## pods_install_pkg_config_file(hello
##     CFLAGS
##     LIBS -lhello
##     REQUIRES ${REQUIRED_PACKAGES}
##     VERSION 0.0.1)


