#include <socket/socket.h>

Socket::Socket() : socket_fd(-1) {
    #ifdef _WIN32
    WSADATA wsaData;
    
    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
    }
    #endif
}

Socket::~Socket() {
    close();
    #ifdef _WIN32
    WSACleanup();
    #endif
}

bool Socket::create() {
    socket_fd = ::socket(AF_INET, SOCK_STREAM, 0);
    return socket_fd != -1;
}


void Socket::close() {
    if (socket_fd != -1) {
        #ifdef _WIN32
        closesocket(socket_fd);
        #else
        ::close(socket_fd);
        #endif
        socket_fd = -1;
    }
}