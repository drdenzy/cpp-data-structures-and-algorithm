#pragma once

class DNode {
public:
    int value;
    DNode* next;
    DNode* prev;
    DNode(int value);
    ~DNode() = default;

    // accessors
    int getData() const;
};

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
    DNode* get(int index) const;
    bool set(int index, int newValue);
    bool insertNode(int index, int value);
    void deleteNode(int index);


    // accessors
    int getLength() const;
    DNode* getHead() const;
    DNode* getTail() const;

private:
    DNode* head;
    DNode* tail;
    int length;
};