cmake_minimum_required(VERSION 2.8.2)

project(googletest-download CXX)

include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )

# etc. as appropriate
# Now simply link against gtest or gtest_main as needed. Eg
add_executable(RunUnitTest
        tests/AddingTests.cpp
        tests/GeneralMatrixTests.cpp
        tests/MultiplayingTests.cpp
        tests/ScalarTests.cpp
        tests/SubtractingTests.cpp)
target_link_libraries(RunUnitTest gtest gtest_main)
add_dependencies(RunUnitTest googletest)
#add_dependencies(gtest_main googletest)
#add_dependencies(gtest googletest)