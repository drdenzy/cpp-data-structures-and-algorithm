#pragma once

#include <istream>


class Node {
public:
    explicit Node(int data);

    ~Node() = default;

    int getData() const;
    void setData(int data);

    Node* getNext() const;
    void setNext(Node* node);

private:
    int data;
    Node* next;
};


class LinkedList {
public:
    explicit LinkedList(int value);

    ~LinkedList();

    void clear(); // For safe clearing of nodes

    LinkedList(const LinkedList& other); // Copy constructor
    LinkedList& operator=(const LinkedList& other); // Copy assignment

    LinkedList(LinkedList&& other) noexcept; // Move constructor
    LinkedList& operator=(LinkedList&& other) noexcept; // Move assignment

    // 🚀 LinkedList APIs
    void append(const int value);

    void deleteLast();

    void deleteFirst();

    void deleteNode(const int index);

    void prepend(const int value);

    Node* get(const int index) const;

    bool set(const int index, const int value);

    bool insert(const int index, const int value);

    void reverse();

    Node* findMiddleNode() const;

    // Floyd's cycle-finding algorithm (aka "tortoise and the hare" algorithm)
    bool hasLoop() const;

    Node* findKthFromEnd(int k) const;

    void removeDuplicates();

    int binaryToDecimal() const;

    void partitionList(const int limit);

    void reverseBetween(const int m, const int n);

    void swapPairs();

    // 👀 Accessors
    Node* getHead() const;
    Node* getTail() const;
    int getLength() const;

    // 🔧 Mutators
    void setHead(Node* node);
    void setTail(Node* node);
    void setLength(int len);

    // Optional convenience
    void incrementLength();
    void decrementLength();

    // Friend declarations for stream operators
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& ll);
    friend std::istream& operator>>(std::istream& stream, const LinkedList& ll);

private:
    Node* head;
    Node* tail;
    int length;
};

std::ostream& operator<<(std::ostream& stream, const LinkedList& ll);

std::istream& operator>>(std::istream& stream, const LinkedList& ll);