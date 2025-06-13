#include "linkedlist.hpp"
#include <gtest/gtest.h>

// Base fixture for common setup/teardown
class BaseLinkedListTest : public ::testing::Test {
protected:
    LinkedList* ll = nullptr;

    void TearDown() override {
        if (ll) {
            ll->clear();
            delete ll;
            ll = nullptr;
        }
    }
};

// Fixture for empty list state
class EmptyLinkedListTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(42); // Create temp node
        ll->deleteFirst(); // Results in empty list
    }
};

// Fixture for single-node list
class SingleNodeLinkedListTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(10);
    }
};

// Fixture for multi-node list (reusable for most tests)
class MultiNodeLinkedListTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(10);
        ll->append(20);
        ll->append(30);
    }
};

// Fixture for special cases (loops, duplicates, etc.)
class ComplexLinkedListTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(1);
        ll->append(2);
        ll->append(2); // Duplicate
        ll->append(3);
        ll->append(4);
    }
};

// Fixtures for Even Length Linked List cases
class EvenLengthListTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(1);
        ll->append(2);
        ll->append(3);
        ll->append(4); // 4 nodes: 1->2->3->4
    }
};

// Fixture for Binary To Decimal Test
class BinaryListTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(1);
        ll->append(0);
        ll->append(1); // Binary: 101 = 5
    }
};

// Fixture for Copy and Move test cases
class CopyMoveTest : public BaseLinkedListTest {
protected:
    void SetUp() override {
        ll = new LinkedList(10);
        ll->append(20);
        ll->append(30);
    }
};


// ------ Append Tests ------
TEST_F(EmptyLinkedListTest, Append_ToEmptyList) {
    ll->append(5);
    EXPECT_EQ(ll->getLength(), 1);
    EXPECT_EQ(ll->getHead()->getData(), 5);
    EXPECT_EQ(ll->getTail()->getData(), 5);
}

TEST_F(SingleNodeLinkedListTest, Append_ToSingleNodeList) {
    ll->append(20);
    EXPECT_EQ(ll->getLength(), 2);
    EXPECT_EQ(ll->getTail()->getData(), 20);
}

// ------ Prepend Tests ------
TEST_F(EmptyLinkedListTest, Prepend_ToEmptyList) {
    ll->prepend(5);
    EXPECT_EQ(ll->getLength(), 1);
    EXPECT_EQ(ll->getHead()->getData(), 5);
}

// ------ Delete Tests ------
TEST_F(SingleNodeLinkedListTest, DeleteLast_OnSingleNode) {
    ll->deleteLast();
    EXPECT_EQ(ll->getLength(), 0);
    EXPECT_EQ(ll->getHead(), nullptr);
}

TEST_F(MultiNodeLinkedListTest, DeleteNode_MiddleIndex) {
    ll->deleteNode(1); // Delete 20
    EXPECT_EQ(ll->getLength(), 2);
    EXPECT_EQ(ll->getHead()->getNext()->getData(), 30);
}

// ------ Get/Set Tests ------
TEST_F(MultiNodeLinkedListTest, Get_ValidIndex) {
    Node* node = ll->get(1);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->getData(), 20);
}

TEST_F(MultiNodeLinkedListTest, Set_InvalidIndex) {
    EXPECT_FALSE(ll->set(5, 100));
}

// ------ Insert Tests ------
TEST_F(MultiNodeLinkedListTest, Insert_AtHead) {
    EXPECT_TRUE(ll->insert(0, 5));
    EXPECT_EQ(ll->getHead()->getData(), 5);
}

// ------ Reverse Tests ------
TEST_F(MultiNodeLinkedListTest, Reverse_FullList) {
    ll->reverse();
    EXPECT_EQ(ll->getHead()->getData(), 30);
    EXPECT_EQ(ll->getTail()->getData(), 10);
}

// ------ Reverse Between Tests ------
TEST_F(MultiNodeLinkedListTest, ReverseBetween_PartialReverse) {
    ll->reverseBetween(1, 2); // Reverse 20->30 to 30->20
    EXPECT_EQ(ll->getHead()->getData(), 10);
    EXPECT_EQ(ll->getHead()->getNext()->getData(), 30);
    EXPECT_EQ(ll->getTail()->getData(), 20);
}

// ------ Duplicate Removal Tests ------
TEST_F(ComplexLinkedListTest, RemoveDuplicates) {
    ll->removeDuplicates();
    EXPECT_EQ(ll->getLength(), 4); // Original had 5 with duplicate
}

TEST_F(ComplexLinkedListTest, RemoveDuplicates_RemovesDuplicates) {
    ll->removeDuplicates();
    Node* current = ll->getHead();
    while (current && current->getNext()) {
        EXPECT_NE(current->getData(), current->getNext()->getData());
        current = current->getNext();
    }
}

// ------ Kth From End Tests ------
TEST_F(MultiNodeLinkedListTest, FindKthFromEnd_ValidK) {
    Node* node = ll->findKthFromEnd(2);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->getData(), 20);
}

TEST_F(MultiNodeLinkedListTest, FindKthFromEnd_InvalidK) {
    EXPECT_EQ(ll->findKthFromEnd(-1), nullptr); // Negative K
    EXPECT_EQ(ll->findKthFromEnd(10), nullptr); // K > length
}

// ------ Partition Tests ------
TEST_F(MultiNodeLinkedListTest, PartitionList) {
    ll->partitionList(25);
    // Verify all nodes <25 come before nodes >=25
    Node* current = ll->getHead();
    while (current && current->getData() < 25) {
        current = current->getNext();
    }
    while (current) {
        EXPECT_GE(current->getData(), 25);
        current = current->getNext();
    }
}

// ------ Find Middle Node in an Even Length ListTests ------
TEST_F(EvenLengthListTest, FindMiddleNode) {
    Node* middle = ll->findMiddleNode();
    ASSERT_NE(middle, nullptr);
    EXPECT_EQ(middle->getData(), 3); // Middle element is 3
}

// ------ Swap Pairs in an Even Length List ------
TEST_F(EvenLengthListTest, SwapPairs_EvenLength) {
    ll->swapPairs();
    EXPECT_EQ(ll->getHead()->getData(), 2);
    EXPECT_EQ(ll->getHead()->getNext()->getData(), 1);
    EXPECT_EQ(ll->getHead()->getNext()->getNext()->getData(), 4);
    EXPECT_EQ(ll->getTail()->getData(), 3);
}

// ------ Swap Pairs in an Odd Length List ------
TEST_F(MultiNodeLinkedListTest, SwapPairs_OddLength) {
    ll->swapPairs(); // 10->20->30 becomes 20->10->30
    EXPECT_EQ(ll->getHead()->getData(), 20);
    EXPECT_EQ(ll->getHead()->getNext()->getData(), 10);
    EXPECT_EQ(ll->getTail()->getData(), 30);
}

// ------ Binary To Decimal Test ------
TEST_F(BinaryListTest, BinaryToDecimal) {
    EXPECT_EQ(ll->binaryToDecimal(), 5); // 101 (binary) = 5 (decimal)
}


// ----- DeleteNode_InvalidIndex -----
TEST_F(EmptyLinkedListTest, DeleteNode_InvalidIndex) {
    EXPECT_NO_THROW(ll->deleteNode(-1)); // Negative index
    EXPECT_NO_THROW(ll->deleteNode(100)); // Out-of-bounds
}

TEST_F(MultiNodeLinkedListTest, DeleteNode_InvalidIndex) {
    EXPECT_NO_THROW(ll->deleteNode(-1)); // Negative index
    EXPECT_NO_THROW(ll->deleteNode(100)); // Out-of-bounds
    EXPECT_EQ(ll->getLength(), 3); // Length unchanged
}


// ----- Insert_NegativeIndex -----
TEST_F(EmptyLinkedListTest, Insert_NegativeIndex) {
    EXPECT_FALSE(ll->insert(-1, 5)); // Should fail gracefully
    EXPECT_EQ(ll->getLength(), 0);
}

TEST_F(MultiNodeLinkedListTest, Insert_NegativeIndex) {
    EXPECT_FALSE(ll->insert(-5, 5)); // Should fail gracefully
    EXPECT_EQ(ll->getLength(), 3);
}


// ----- CopyConstructor_Independence -----
TEST_F(CopyMoveTest, CopyConstructor_Independence) {
    LinkedList copy(*ll); // Copy constructor
    ll->deleteFirst(); // Modify original

    // Verify copy unchanged
    EXPECT_EQ(copy.getLength(), 3);
    EXPECT_EQ(copy.getHead()->getData(), 10);
    EXPECT_EQ(copy.getTail()->getData(), 30);

    // Verify original modified
    EXPECT_EQ(ll->getLength(), 2);
    EXPECT_EQ(ll->getHead()->getData(), 20);
}

// ----- MoveConstructor_SourceIsNull -----
TEST_F(CopyMoveTest, MoveConstructor_SourceIsNull) {
    LinkedList moved(std::move(*ll)); // Move constructor

    // Verify moved object
    EXPECT_EQ(moved.getLength(), 3);
    EXPECT_EQ(moved.getHead()->getData(), 10);
    EXPECT_EQ(moved.getTail()->getData(), 30);

    // Verify source is empty
    EXPECT_EQ(ll->getHead(), nullptr);
    EXPECT_EQ(ll->getTail(), nullptr);
    EXPECT_EQ(ll->getLength(), 0);
}