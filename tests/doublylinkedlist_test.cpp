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
        : buffer(),
          old(std::cout.rdbuf(buffer.rdbuf())) {
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

// ------- Get -------
TEST_F(EmptyDoublyLinkedListTest, Get_FromEmptyDLL) {
    ASSERT_EQ(dll->get(0), nullptr);
}

TEST_F(SingleNodeDoublyLinkedListTest, Get_FromSingleNodeDLL) {
    ASSERT_EQ(dll->get(0)->getData(), 10);
}

TEST_F(MultiNodeDoublyLinkedListTest, Get_FromMultiNodeDLL) {
    ASSERT_EQ(dll->get(0)->getData(), 10);
    ASSERT_EQ(dll->get(1)->getData(), 20);
    ASSERT_EQ(dll->get(2)->getData(), 30);
}

// ------- Set -------

TEST_F(EmptyDoublyLinkedListTest, Set_FromEmptyDLL) {
    ASSERT_EQ(dll->set(-1, 100), false);
    ASSERT_EQ(dll->set(0, 200), false);
}

TEST_F(SingleNodeDoublyLinkedListTest, Set_FromSingleNodeDLL) {
    ASSERT_EQ(dll->set(0, 1000), true);
    ASSERT_EQ(dll->get(0)->getData(), 1000);
}

TEST_F(MultiNodeDoublyLinkedListTest, Set_FromMultiNodeDLL) {
    ASSERT_EQ(dll->set(0, 11), true);
    ASSERT_EQ(dll->get(0)->getData(), 11);
    ASSERT_EQ(dll->set(1, 22), true);
    ASSERT_EQ(dll->get(1)->getData(), 22);
    ASSERT_EQ(dll->set(2, 33), true);
    ASSERT_EQ(dll->get(2)->getData(), 33);
    ASSERT_EQ(dll->set(3, 44), false);
}


// ------- Insert Node -------

TEST_F(EmptyDoublyLinkedListTest, InsertNode_IntoEmptyDLL) {
    ASSERT_EQ(dll->insertNode(0, 100), true);
    ASSERT_EQ(dll->getLength(), 1);
    ASSERT_EQ(dll->getHead()->getData(), 100);
    ASSERT_EQ(dll->getTail()->getData(), 100);
}

TEST_F(SingleNodeDoublyLinkedListTest, InsertNode_IntoSingleNodeDLL) {
    ASSERT_EQ(dll->insertNode(0, 100), true);
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 100);
    ASSERT_EQ(dll->getTail()->getData(), 10);
}

TEST_F(MultiNodeDoublyLinkedListTest, InsertNode_IntoMultiNodeDLL) {
    ASSERT_EQ(dll->insertNode(0, 100), true);
    ASSERT_EQ(dll->insertNode(dll->getLength(), 200), true);
    ASSERT_EQ(dll->insertNode(dll->getLength()/2, 999), true);
}


// ------- Delete Node -------

TEST_F(EmptyDoublyLinkedListTest, DeleteNode_FromEmptyDLL) {
    dll->deleteNode(-1); // Invalid negative index
    dll->deleteNode(0); // Invalid index (empty)
    dll->deleteNode(1); // Invalid out-of-range index
    EXPECT_EQ(dll->getLength(), 0);
    EXPECT_EQ(dll->getHead(), nullptr);
    EXPECT_EQ(dll->getTail(), nullptr);
}

TEST_F(SingleNodeDoublyLinkedListTest, DeleteNode_FromSingleNodeDLL) {
    // Test invalid indices
    dll->deleteNode(-1);
    EXPECT_EQ(dll->getLength(), 1);
    dll->deleteNode(1);
    EXPECT_EQ(dll->getLength(), 1);

    // Test valid deletion
    dll->deleteNode(0);
    EXPECT_EQ(dll->getLength(), 0);
    EXPECT_EQ(dll->getHead(), nullptr);
    EXPECT_EQ(dll->getTail(), nullptr);
}

TEST_F(MultiNodeDoublyLinkedListTest, DeleteNode_FromMultiNodeDLL) {
    // Test invalid indices
    dll->deleteNode(-1);
    EXPECT_EQ(dll->getLength(), 3);
    dll->deleteNode(3); // Out of bounds
    EXPECT_EQ(dll->getLength(), 3);

    // Delete head (index 0)
    dll->deleteNode(0);
    EXPECT_EQ(dll->getLength(), 2);
    EXPECT_EQ(dll->getHead()->getData(), 20);
    EXPECT_EQ(dll->getTail()->getData(), 30);
    EXPECT_EQ(dll->getHead()->prev, nullptr);

    // Reset list for next test
    dll->prepend(10);

    // Delete tail (index 2)
    dll->deleteNode(2);
    EXPECT_EQ(dll->getLength(), 2);
    EXPECT_EQ(dll->getHead()->getData(), 10);
    EXPECT_EQ(dll->getTail()->getData(), 20);
    EXPECT_EQ(dll->getTail()->next, nullptr);

    // Reset list for next test
    dll->append(30);

    // Delete middle node (index 1)
    dll->deleteNode(1);
    EXPECT_EQ(dll->getLength(), 2);
    EXPECT_EQ(dll->getHead()->getData(), 10);
    EXPECT_EQ(dll->getTail()->getData(), 30);

    // Verify pointers are correctly updated
    EXPECT_EQ(dll->getHead()->next, dll->getTail());
    EXPECT_EQ(dll->getTail()->prev, dll->getHead());

    // Delete all nodes sequentially
    dll->deleteNode(0);
    EXPECT_EQ(dll->getLength(), 1);
    EXPECT_EQ(dll->getHead()->getData(), 30);

    dll->deleteNode(0);
    EXPECT_EQ(dll->getLength(), 0);
    EXPECT_EQ(dll->getHead(), nullptr);
    EXPECT_EQ(dll->getTail(), nullptr);
}