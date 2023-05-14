cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(libminimal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)


file(GLOB_RECURSE ALL_SRC_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${ALL_SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json)
