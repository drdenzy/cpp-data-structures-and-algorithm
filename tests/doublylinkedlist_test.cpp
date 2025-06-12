#include <gtest/gtest.h>

#include "doublylinkedlist.hpp"

// Base fixture for common setup/teardown
class BaseDoublyLinkedListTest : public ::testing::Test
{
protected:
    DoublyLinkedList* dll = nullptr;

    void TearDown() override
    {
        if (dll) {
            dll->clear();
            delete dll;
            dll = nullptr;
        }
    }
};

// Fixture for empty list state
// class EmptyLinkedListTest : public BaseLinkedListTest
// {
// protected:
//     void SetUp() override
//     {
//         dll = new DoublyLinkedList(42); // Create temp node
//         dll->deleteFirst(); // Results in empty list
//     }
// };

// Fixture for single-node list
class SingleNodeDoublyLinkedListTest : public BaseDoublyLinkedListTest
{
protected:
    void SetUp() override
    {
        dll = new DoublyLinkedList(10);
    }
};

// Fixture for multi-node list (reusable for most tests)
class MultiNodeDoublyLinkedListTest : public BaseDoublyLinkedListTest
{
protected:
    void SetUp() override
    {
        dll = new DoublyLinkedList(10);
        dll->append(20);
        dll->append(30);
    }
};

// ------ Append ------

TEST_F(SingleNodeDoublyLinkedListTest, Append_ToSingleNodeDLL){
    dll->append(20);
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 10);
    ASSERT_EQ(dll->getTail()->getData(), 20);
}

// ------ Prepend ------

TEST_F(SingleNodeDoublyLinkedListTest, Prepend_ToSingleNodeDLL){
    dll->prepend(5);
    ASSERT_EQ(dll->getLength(), 2);
    ASSERT_EQ(dll->getHead()->getData(), 5);
    ASSERT_EQ(dll->getTail()->getData(), 10);
}
