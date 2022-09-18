project(portfolio_analysis)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} libminimal)


file(COPY data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)