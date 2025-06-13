#include <gtest/gtest.h>
#include <sstream>
#include "doublylinkedlist.hpp"


// Helper class to redirect std::cout
class CoutRedirect {
private:
    std::ostringstream buffer;
    std::streambuf* old;

public:
    CoutRedirect()
        : buffer(), old(std::cout.rdbuf(buffer.rdbuf())) {
    }

    ~CoutRedirect() {
        std::cout.rdbuf(old);
    }

    std::string getString() const {
        return buffer.str();
    }
};

// Base fixture for common setup/teardown
class BaseDoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList* dll = nullptr;

    void TearDown() override {
        if (dll) {
            dll->clear();
            delete dll;
            dll = nullptr;
        }
    }

    // Helper to capture output from display()
    std::string captureDisplay() {
        CoutRedirect cr;
        dll->display();
        return cr.getString();
    }
};

// Fixture for empty list state
class EmptyDoublyLinkedListTest : public BaseDoublyLinkedListTest {
protected:
    void SetUp() override {
        dll = new DoublyLinkedList(42); // Create temp node
        dll->deleteLast(); // Results in empty list
    }
};

// Fixture for single-node list
class SingleNodeDoublyLinkedListTest : public BaseDoublyLinkedListTest {
protected:
    void SetUp() override {
        dll = new DoublyLinkedList(10);
    }
};

// Fixture for multi-node list (reusable for most tests)
class MultiNodeDoublyLinkedListTest : public BaseDoublyLinkedListTest {
protected:
    void SetUp() override {
        dll = new DoublyLinkedList(10);
        dll->append(20);
        dll->append(30);
    }
};

// ------ Display ------ 

TEST_F(EmptyDoublyLinkedListTest, Display_OutputsEmptyListFormat) {
    std::string output = captureDisplay();
    EXPECT_EQ(output, "{}\n");
}

TEST_F(SingleNodeDoublyLinkedListTest, Display_OutputsSingleNodeFormat) {
    std::string output = captureDisplay();
    EXPECT_EQ(output, "{10}\n");
}

TEST_F(MultiNodeDoublyLinkedListTest, Display_OutputsMultiNodeFormat) {
    std::string output = captureDisplay();
    EXPECT_EQ(output, "{10, 20, 30}\n");
}

// ------ Append ------

TEST_F(SingleNodeDoublyLinkedListTest, Append_ToSingleNodeDLL) {
    dll->append(20);
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 10);
    ASSERT_EQ(dll->getTail()->getData(), 20);
}

TEST_F(EmptyDoublyLinkedListTest, Append_ToEmptyDLL) {
    ASSERT_EQ(dll->getLength(), 0);
    dll->append(21);
    ASSERT_EQ(dll->getLength(), 1);
    dll->append(22);
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 21);
    ASSERT_EQ(dll->getTail()->getData(), 22);
}

// ------ Prepend ------

TEST_F(SingleNodeDoublyLinkedListTest, Prepend_ToSingleNodeDLL) {
    dll->prepend(5);
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 5);
    ASSERT_EQ(dll->getTail()->getData(), 10);
}

TEST_F(EmptyDoublyLinkedListTest, Prepend_ToEmptyDLL) {
    ASSERT_EQ(dll->getLength(), 0);
    dll->prepend(5);
    ASSERT_EQ(dll->getLength(), 1);
    dll->prepend(10);
    ASSERT_EQ(dll->getHead()->getData(), 10);
    ASSERT_EQ(dll->getTail()->getData(), 5);
    ASSERT_EQ(dll->getLength(), 2);
}

// ------- DeleteLast ------

TEST_F(SingleNodeDoublyLinkedListTest, DeleteLast_FromSingleNodeDLL) {
    dll->deleteLast();
    ASSERT_EQ(dll->getLength(), 0);
}

TEST_F(MultiNodeDoublyLinkedListTest, DeleteLast_FromMultiNodeDLL) {
    dll->deleteLast();
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 10);
    ASSERT_EQ(dll->getTail()->getData(), 20);

    while (dll->getLength() != 0) {
        dll->deleteLast();
    }
    ASSERT_EQ(dll->getLength(), 0);
}

TEST_F(EmptyDoublyLinkedListTest, DeleteLast_FromEmptyDLL) {
    ASSERT_EQ(dll->getLength(), 0);
    dll->deleteLast();
    ASSERT_EQ(dll->getLength(), 0);
}

// ------- DeleteFirst ------

TEST_F(SingleNodeDoublyLinkedListTest, DeleteFirst_FromSingleNodeDLL) {
    dll->deleteFirst();
    ASSERT_EQ(dll->getLength(), 0);
}

TEST_F(MultiNodeDoublyLinkedListTest, DeleteFirst_FromMultiNodeDLL) {
    dll->deleteFirst();
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 20);
    ASSERT_EQ(dll->getTail()->getData(), 30);

    while (dll->getLength() != 0) {
        dll->deleteFirst();
    }
    ASSERT_EQ(dll->getLength(), 0);
}

TEST_F(EmptyDoublyLinkedListTest, DeleteFirst_FromEmptyDLL) {
    ASSERT_EQ(dll->getLength(), 0);
    dll->deleteFirst();
    ASSERT_EQ(dll->getLength(), 0);
}