find_package(GTest REQUIRED)

set(TARGET_NAME ${PROJECT_NAME}_test)

add_executable(${TARGET_NAME}
    ./breadth_first_search/p994_rotting_oranges_test.cpp
    ./binary_tree/p108_convert_sorted_array_test.cpp
    ./binary_tree/p437_path_sum_test.cpp
    ./matrix/p240_search_2d_matrix_test.cpp
    ./heap/p295_find_median_from_data_stream_test.cpp
)

target_link_libraries(${TARGET_NAME}
    PRIVATE GTest::gtest_main
    ${PROJECT_NAME}_lib
)

include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})