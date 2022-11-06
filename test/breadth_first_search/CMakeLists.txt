find_package(GTest REQUIRED)

set(TARGET_NAME ${PROJECT_NAME}_test)

add_executable(${TARGET_NAME}
    p994_rotting_oranges_test.cpp
)

target_link_libraries(${TARGET_NAME}
    PRIVATE GTest::gtest_main
    ${PROJECT_NAME}_lib
)

include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})