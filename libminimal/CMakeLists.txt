cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(libminimal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)

#
add_library(${PROJECT_NAME} SHARED
        src/utility.cpp
        src/low_level/base.cpp
        src/low_level/low_level_funcs.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)