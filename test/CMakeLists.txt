include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${RANGE_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS})

add_executable(range-tests
    range-tests.cpp)

target_link_libraries(range-tests
    ${GTEST_MAIN_LIBRARIES})

add_test(NAME whoshuu-range-tests COMMAND range-tests)
