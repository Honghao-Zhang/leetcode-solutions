set(TARGET_NAME ${PROJECT_NAME}_lib)

add_library(${TARGET_NAME}
    ./bit_operations/bit_and_oppsite_number.cpp

    # ./greedy/p300_longest_increasing_subsequence.cpp
    # ./dynamic_programming/p279_perfect_squares.cpp
    # ./array/p239_sliding_window_maximum.cpp
    # ./hash/p208_implement_trie.cpp
    # ./graph/p207_course_schedule.cpp
    # ./backtracking/p131_palindrome_partitioning.cpp
    # ./backtracking/p52_n_queens_ii.cpp
    # ./backtracking/p51_n_queens.cpp
    # ./substring/p139_word_break.cpp
    # ./dynamic_programming/matrix_low_points.cpp
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