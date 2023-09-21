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