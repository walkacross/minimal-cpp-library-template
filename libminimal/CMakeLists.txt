cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(libminimal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)

#
add_library(${PROJECT_NAME} SHARED
        src/utility.cpp
        src/basics/basics.cpp
        src/basics/basics_funcs.cpp
        src/basics/namespace_duration_scope_linkage/global.cpp
        src/basics/namespace_duration_scope_linkage/external.cpp
        src/basics/namespace_duration_scope_linkage/support.cpp
        src/intermediate/data_reader.cpp
        src/domain_knowledge/finance/risk.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)