#include <gtest/gtest.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <socket/socket.h>

class SocketTest : public ::testing::Test {
protected:
    Socket socket;

    void SetUp() override {
        std::thread socketThread([&]() {
            EXPECT_TRUE(socket.create());
            EXPECT_TRUE(socket.bind(8080));
            EXPECT_TRUE(socket.listen());
        });
        socketThread.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    void TearDown() override {
        socket.close();
    }
};

TEST_F(SocketTest, AcceptSocket) {
    int clientSocket = socket.accept();
    EXPECT_GE(clientSocket, 0);
}


TEST_F(SocketTest, ConnectSocket) {
    EXPECT_TRUE(socket.create());
    EXPECT_TRUE(socket.connect("127.0.0.1", 8080));
}