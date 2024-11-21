cmake_minimum_required(VERSION 3.2)
project(library-management-system)

include_directories(include)
ADD_SUBDIRECTORY(tests/googletest)

file(GLOB TEST_SOURCES "tests/*.cpp")
file(GLOB SRC_SOURCES "src/*.cpp")

add_executable(run_tests ${TEST_SOURCES} 
"src/User.cpp" 
"src/Administrator.cpp"
"src/Book.cpp"
"src/BorrowRecord.cpp"
"src/LibraryCatalog.cpp"
"src/RegularUser.cpp"
)

add_executable(run_main ${SRC_SOURCES})

target_link_libraries(run_tests gmock gtest gtest_main)
add_test(NAME runAllTests COMMAND run_tests)