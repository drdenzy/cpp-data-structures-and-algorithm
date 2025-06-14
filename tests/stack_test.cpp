#include "stack.hpp"
#include <gtest/gtest.h>
#include <climits>

// Test Fixture
class StackTest : public ::testing::Test {
protected:
    Stack* stack;

    void SetUp() override {
        stack = new Stack(42);
    }

    void TearDown() override {
        delete stack;
    }
};

TEST_F(StackTest, ConstructorInitializesStackCorrectly) {
    EXPECT_EQ(stack->getTop(), 42);
    EXPECT_EQ(stack->getHeight(), 1);
}

TEST_F(StackTest, PushIncreasesHeightAndUpdatesTop) {
    stack->push(100);
    EXPECT_EQ(stack->getTop(), 100);
    EXPECT_EQ(stack->getHeight(), 2);

    stack->push(200);
    EXPECT_EQ(stack->getTop(), 200);
    EXPECT_EQ(stack->getHeight(), 3);
}

TEST_F(StackTest, PopReturnsTopAndDecreasesHeight) {
    stack->push(999);
    int popped = stack->pop();
    EXPECT_EQ(popped, 999);
    EXPECT_EQ(stack->getHeight(), 1);
    EXPECT_EQ(stack->getTop(), 42);
}

TEST_F(StackTest, PopUntilEmptyThenReturnsSentinel) {
    stack->pop(); // now empty
    EXPECT_EQ(stack->getHeight(), 0);
    EXPECT_EQ(stack->pop(), INT_MIN); // underflow check
    EXPECT_EQ(stack->peek(), INT_MIN);
}

TEST_F(StackTest, PeekDoesNotModifyStack) {
    int peeked = stack->peek();
    EXPECT_EQ(peeked, 42);
    EXPECT_EQ(stack->getHeight(), 1);
}

TEST_F(StackTest, ClearResetsStackToEmptyState) {
    stack->push(10);
    stack->push(20);
    EXPECT_EQ(stack->getHeight(), 3);

    stack->clear();
    EXPECT_EQ(stack->getHeight(), 0);
    EXPECT_EQ(stack->peek(), INT_MIN);
    EXPECT_EQ(stack->pop(), INT_MIN);
}

TEST_F(StackTest, ComplexPushPopSequenceMaintainsCorrectState) {
    stack->push(1);
    stack->push(2);
    stack->push(3); // Stack: 3,2,1,42

    EXPECT_EQ(stack->pop(), 3);
    EXPECT_EQ(stack->pop(), 2);
    EXPECT_EQ(stack->getTop(), 1);
    EXPECT_EQ(stack->getHeight(), 2);

    stack->push(99);
    EXPECT_EQ(stack->getTop(), 99);
    EXPECT_EQ(stack->getHeight(), 3);
}

TEST_F(StackTest, PushPopWithINTMINValue) {
    stack->push(INT_MIN);
    EXPECT_EQ(stack->getTop(), INT_MIN);
    EXPECT_EQ(stack->peek(), INT_MIN);
    EXPECT_EQ(stack->pop(), INT_MIN); // must distinguish between actual value and sentinel
    EXPECT_EQ(stack->getHeight(), 1);
}

TEST_F(StackTest, ClearOnAlreadyEmptyStackDoesNothing) {
    stack->pop(); // remove initial 42
    EXPECT_EQ(stack->getHeight(), 0);
    stack->clear(); // should not crash
    EXPECT_EQ(stack->getHeight(), 0);
}

TEST_F(StackTest, DisplayOutputsAllElements) {
    testing::internal::CaptureStdout();
    stack->push(10);
    stack->push(20);
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();

    // The stack prints top to bottom: 20, 10, 42
    EXPECT_EQ(output, "{20, 10, 42}\n");
}