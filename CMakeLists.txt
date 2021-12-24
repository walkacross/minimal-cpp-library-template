cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(libminimal_example)



# ================================================================
# prerequist
# ================================================================

# cxx compile standard
set(CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# option for unittest switch
option(ENABLE_UNITTEST "unittest for libminimal" OFF)

# project version setup
set(LIBMINIMAL_MAJOR_VERSION "0")
set(LIBMINIMAL_MINOR_VERSION "0")
set(LIBMINIMAL_PATCH_VERSION "2")

# debug message
message(STATUS "======================================================")
message(STATUS "libminimal release version: ${LIBMINIMAL_MAJOR_VERSION}.${LIBMINIMAL_MINOR_VERSION}.${LIBMINIMAL_PATCH_VERSION}")
message(STATUS "Creature unittest flag: ${ENABLE_UNITTEST}")
message(STATUS "======================================================")

# load custom cmake module
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/api.cmake)

# generate library
add_subdirectory(libminimal)
add_subdirectory(example)

if(ENABLE_UNITTEST)
    # download googletest, function from mod_fetch_googletest.cmake
    download_googletest()

    #enable cmake google test
    enable_testing()

    # include gtest library
    #include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    #message(STATUS "gtest source directory is: ${gtest_SOURCE_DIR}")

    # unittest directory
    add_subdirectory(test)
else()
    # clear cache
    unset(GTEST_VER)
endif()
