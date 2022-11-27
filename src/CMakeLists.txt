set(TARGET_NAME ${PROJECT_NAME}_lib)

add_library(${TARGET_NAME}
    ./dynamic_programming/matrix_low_points.cpp

    # ./dynamic_programming/p1143_longest_common_subsequence.cpp
    # ./substring/p76_minimum_window_substring.cpp
    # ./breadth_first_search/p79_word_search.cpp
    # ./breadth_first_search/p994_rotting_oranges.cpp
    # ./binary_tree/helper.cpp
    # ./binary_tree/p108_convert_sorted_array.cpp
    # ./binary_tree/p437_path_sum.cpp
    # ./matrix/p240_search_2d_matrix.cpp
    # ./dynamic_programming/p322_coin_change.cpp
    # ./array/p152_max_product_subarray.cpp
    # ./array/p189_rotate_array.cpp
    # ./hash/p763_partition_labels.cpp
    # ./dynamic_programming/p300_longest_increasing_subsequence.cpp
)

target_include_directories(${TARGET_NAME}
    PUBLIC ../include)