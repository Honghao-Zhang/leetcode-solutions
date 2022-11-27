find_package(GTest REQUIRED)

set(TARGET_NAME ${PROJECT_NAME}_test)

add_executable(${TARGET_NAME}
    ./dynamic_programming/matrix_low_points_test.cpp

    # ./dynamic_programming/p1143_longest_common_subsequence_test.cpp
    # ./substring/p76_minimum_window_substring_test.cpp
    # ./breadth_first_search/p79_word_search_test.cpp
    # ./breadth_first_search/p994_rotting_oranges_test.cpp
    # ./binary_tree/p108_convert_sorted_array_test.cpp
    # ./binary_tree/p437_path_sum_test.cpp
    # ./matrix/p240_search_2d_matrix_test.cpp
    # ./heap/p295_find_median_from_data_stream_test.cpp
    # ./dynamic_programming/p322_coin_change_test.cpp
    # ./array/p152_max_product_subarray_test.cpp
    # ./array/p189_rotate_array_test.cpp
    # ./hash/p763_partition_labels_test.cpp
    # ./dynamic_programming/p300_longest_increasing_subsequence_test.cpp
)

target_link_libraries(${TARGET_NAME}
    PRIVATE GTest::gtest_main
    ${PROJECT_NAME}_lib
)

include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})