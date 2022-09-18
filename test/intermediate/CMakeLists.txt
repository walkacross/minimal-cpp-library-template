project(test_intermediate)

# source file path
set(TEST_PATH ${PROJECT_SOURCE_DIR})
set(GTEST_LIB gtest gtest_main)

# low_level_funcs test
add_executable(test_spreadsheet ${TEST_PATH}/test_spreadsheet.cpp)
target_link_libraries(test_spreadsheet PRIVATE libminimal ${GTEST_LIB})
add_test(NAME TestSpreadsheet COMMAND test_spreadsheet)