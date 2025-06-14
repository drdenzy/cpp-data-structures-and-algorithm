#include "queue.hpp"
#include <gtest/gtest.h>
#include <climits>
#include <string>

class QueueTest : public ::testing::Test {
protected:
    Queue* queue = nullptr;

    void SetUp() override {
        queue = new Queue(10);
    }

    void TearDown() override {
        delete queue;
    }
};

TEST_F(QueueTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(queue->getSize(), 1);
    EXPECT_EQ(queue->peek(), 10);
}

TEST_F(QueueTest, EnQueueIncreasesSizeAndAddsToBack) {
    queue->enQueue(20);
    EXPECT_EQ(queue->getSize(), 2);
    queue->enQueue(30);
    EXPECT_EQ(queue->getSize(), 3);
}

TEST_F(QueueTest, DeQueueReturnsCorrectValueAndReducesSize) {
    queue->enQueue(20);
    queue->enQueue(30);
    EXPECT_EQ(queue->deQueue(), 10);
    EXPECT_EQ(queue->getSize(), 2);
    EXPECT_EQ(queue->peek(), 20);
}

TEST_F(QueueTest, PeekDoesNotRemoveElement) {
    EXPECT_EQ(queue->peek(), 10);
    EXPECT_EQ(queue->getSize(), 1);
}

TEST_F(QueueTest, DeQueueUntilEmptyThenReturnsSentinel) {
    EXPECT_EQ(queue->deQueue(), 10);
    EXPECT_EQ(queue->deQueue(), INT_MIN);  // Underflow
    EXPECT_EQ(queue->peek(), INT_MIN);
    EXPECT_EQ(queue->getSize(), 0);
}

TEST_F(QueueTest, EnQueueAfterEmptyWorksCorrectly) {
    queue->deQueue();  // Now empty
    EXPECT_EQ(queue->getSize(), 0);

    queue->enQueue(99);
    EXPECT_EQ(queue->peek(), 99);
    EXPECT_EQ(queue->getSize(), 1);
}

TEST_F(QueueTest, ClearRemovesAllElementsSafely) {
    queue->enQueue(1);
    queue->enQueue(2);
    queue->clear();

    EXPECT_EQ(queue->getSize(), 0);
    EXPECT_EQ(queue->peek(), INT_MIN);
    EXPECT_EQ(queue->deQueue(), INT_MIN);
}

TEST_F(QueueTest, ClearOnEmptyQueueIsSafe) {
    queue->deQueue();
    EXPECT_EQ(queue->getSize(), 0);
    queue->clear();  // Should not crash or leak
    EXPECT_EQ(queue->getSize(), 0);
}

TEST_F(QueueTest, HandlesINTMINAsValidValue) {
    queue->enQueue(INT_MIN);
    EXPECT_EQ(queue->deQueue(), 10);  // original
    EXPECT_EQ(queue->peek(), INT_MIN);  // actual INT_MIN in queue
    EXPECT_EQ(queue->deQueue(), INT_MIN);
    EXPECT_EQ(queue->deQueue(), INT_MIN);  // now empty sentinel
}

TEST_F(QueueTest, DisplayOutputsExpectedFormat) {
    testing::internal::CaptureStdout();
    queue->enQueue(20);
    queue->enQueue(30);
    queue->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "{10, 20, 30}\n");
}

// Test with negative and positive numbers
TEST_F(QueueTest, MixedValues) {
    queue->clear();  // Empty the queue
    queue->enQueue(-5);
    queue->enQueue(0);
    queue->enQueue(10);
    EXPECT_EQ(queue->getSize(), 3);
    EXPECT_EQ(queue->peek(), -5);
    EXPECT_EQ(queue->deQueue(), -5);
    EXPECT_EQ(queue->deQueue(), 0);
    EXPECT_EQ(queue->deQueue(), 10);
    EXPECT_EQ(queue->getSize(), 0);
}

// Test alternating enqueue and dequeue
TEST_F(QueueTest, AlternatingEnQueueDeQueue) {
    queue->deQueue();
    queue->enQueue(1);
    EXPECT_EQ(queue->getSize(), 1);
    EXPECT_EQ(queue->deQueue(), 1);
    EXPECT_EQ(queue->getSize(), 0);
    queue->enQueue(2);
    queue->enQueue(3);
    EXPECT_EQ(queue->getSize(), 2);
    EXPECT_EQ(queue->deQueue(), 2);
    EXPECT_EQ(queue->deQueue(), 3);
    EXPECT_EQ(queue->getSize(), 0);
    EXPECT_EQ(queue->deQueue(), std::numeric_limits<int>::min());
}