set(TARGET_NAME ${PROJECT_NAME}_lib)

add_library(${TARGET_NAME}
    p994_rotting_oranges.cpp)

target_include_directories(${TARGET_NAME}
    PUBLIC ../include)