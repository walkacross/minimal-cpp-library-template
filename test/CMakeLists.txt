# unittest case for c++
project(unittest)

# source file path
set(TEST_PATH ${PROJECT_SOURCE_DIR})
set(GTEST_LIB gtest gtest_main)

# low_level_funcs test
add_executable(testLowLevelFunc ${TEST_PATH}/test_low_level_funcs.cpp)
target_link_libraries(testLowLevelFunc PRIVATE libminimal ${GTEST_LIB})
add_test(NAME TestLowLevelFuncs COMMAND testLowLevelFunc)