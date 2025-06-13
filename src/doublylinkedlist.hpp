#pragma once
#include "node.hpp"

class DoublyLinkedList {
public:
    explicit DoublyLinkedList(int value);
    ~DoublyLinkedList();
    void clear();
    void display() const;
    void append(int value);
    void prepend(int value);
    void deleteLast();
    void deleteFirst();
    Node* get(int index) const;
    bool set(int index, int newValue);
    bool insertNode(int index, int value);
    void deleteNode(int index);


    // accessors
    int getLength() const;
    Node* getHead() const;
    Node* getTail() const;

private:
    Node* head;
    Node* tail;
    int length;
};

