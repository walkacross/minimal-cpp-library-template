project(subbinary)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} libminimal)

add_subdirectory(basics)
add_subdirectory(intermediate)
add_subdirectory(domain_knowledge)