cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME networking)

project(${PROJECT_NAME})

add_subdirectory(src)
include_directories(include)

set(SOURCES
    src/socket/socket.cpp
)

add_executable(tests
    ${SOURCES}
    tests/socket/test_socket.cpp
)

find_package(GTest REQUIRED)

target_link_libraries(tests PRIVATE ${GTEST_BOTH_LIBRARIES} pthread ws2_32)

add_custom_target(run_tests COMMAND tests)