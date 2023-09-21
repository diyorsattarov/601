add_library(socket
    socket/socket.cpp
    ../include/socket/socket.h
)

target_include_directories(socket PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})