set(TARGET_NAME ${PROJECT_NAME}_lib)

add_library(${TARGET_NAME}
    ./breadth_first_search/p994_rotting_oranges.cpp
    ./binary_tree/helper.cpp
    ./binary_tree/p108_convert_sorted_array.cpp
    ./binary_tree/p437_path_sum.cpp
    ./matrix/p240_search_2d_matrix.cpp
)

target_include_directories(${TARGET_NAME}
    PUBLIC ../include)