#include <iostream>

#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

class Socket {
private:
    int socket_fd;
public:
    Socket();
    ~Socket();

    bool create();
    bool bind(int port);
    bool listen();
    
    int accept();
    bool connect(const std::string& ipAddress, int port);

    void close();
};