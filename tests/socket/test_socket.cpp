#include <gtest/gtest.h>
#include <iostream>
#include <socket/socket.h>

class SocketTest : public ::testing::Test {
protected:
    Socket socket;

    void SetUp() override {

    }

    void TearDown() override {
        socket.close();
    }
};

TEST_F(SocketTest, CreateSocket) {
    EXPECT_TRUE(socket.create());
}

TEST_F(SocketTest, BindSocket) {
    EXPECT_TRUE(socket.create());
    EXPECT_TRUE(socket.bind(8080));
}

TEST_F(SocketTest, ListenSocket) {
    EXPECT_TRUE(socket.create()); 
    EXPECT_TRUE(socket.bind(8080)); 
    EXPECT_TRUE(socket.listen()); 
}

TEST_F(SocketTest, AcceptSocket) {
    EXPECT_TRUE(socket.create()); 
    EXPECT_TRUE(socket.bind(8080)); 
    EXPECT_TRUE(socket.listen()); 

    int clientSocket = socket.accept();
    EXPECT_GE(clientSocket, 0);
}

TEST_F(SocketTest, ConnectSocket) {
    EXPECT_TRUE(socket.create());
    EXPECT_TRUE(socket.connect("127.0.0.1", 8080));
}