

## # Create an executable program hello-test
## add_executable(hello-test hello-test.c)

## # The test program uses the shared library, use the pkg-config file
## pods_use_pkg_config_packages(hello-test hello)

## # make executable public
## pods_install_executables(hello-test)

add_executable( erf-results-test-log-results
    test_log_results.cpp
)
pods_use_pkg_config_packages( erf-results-test-log-results erf-results )
target_link_libraries( erf-results-test-log-results erf-results )
pods_install_executables( erf-results-test-log-results )
