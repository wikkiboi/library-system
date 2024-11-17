cmake_minimum_required(VERSION 3.2)
project(library-management-system)

include_directories(include)
ADD_SUBDIRECTORY(tests)
ADD_SUBDIRECTORY(tests/googletest)



target_link_libraries(run_tests gtest gtest_main)
add_test(NAME runAllTests COMMAND run_tests)