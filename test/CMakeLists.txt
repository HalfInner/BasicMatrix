#set(core_SRCS ADD ALL SOURCE FILES HERE)
find_package(Threads REQUIRED)
include(ExternalProject)

set(GTEST_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/gtest")
ExternalProject_Add(GTestExternal
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        TIMEOUT 10
        PREFIX "${GTEST_PREFIX}"
        INSTALL_COMMAND "")

set(LIBPREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}")
set(LIBSUFFIX "${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(GTEST_LOCATION "${GTEST_PREFIX}/src/GTestExternal-build")
set(GTEST_INCLUDES "${GTEST_PREFIX}/src/GTestExternal/googletest/include")
set(GTEST_LIBRARY "${GTEST_LOCATION}/lib/${LIBPREFIX}gtest${LIBSUFFIX}")
set(GTEST_MAINLIB "${GTEST_LOCATION}/lib/${LIBPREFIX}gtest_main${LIBSUFFIX}")

add_library(GTest IMPORTED STATIC GLOBAL)
set_target_properties(GTest PROPERTIES
        IMPORTED_LOCATION "${GTEST_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDES}"
        IMPORTED_LINK_INTERFACE_LIBRARIES "${CMAKE_THREAD_LIBS_INIT}")

add_library(GTestMain IMPORTED STATIC GLOBAL)
set_target_properties(GTestMain PROPERTIES
        IMPORTED_LOCATION "${GTEST_MAINLIB}"
        IMPORTED_LINK_INTERFACE_LIBRARIES
        "${GTEST_LIBRARY};${CMAKE_THREAD_LIBS_INIT}")

file(GLOB GTEST_SUITS_SRC
        "*.cpp")

add_executable(GTestRun ${GTEST_SUITS_SRC})

message(STATUS "Current include directory:  ${GTEST_INCLUDES}")
message(STATUS "Current library directory:  ${GTEST_LIBRARY}")
target_link_libraries(GTestRun
        ${GTEST_LIBRARY}
        ${GTEST_MAINLIB})
target_include_directories(GTestRun PRIVATE
        ${GTEST_INCLUDES}
        ${PROJECT_SOURCE_DIR}/src)