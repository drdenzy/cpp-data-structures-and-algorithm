#pragma once

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int value);
    ~Node() = default;

    // accessors
    int getData() const;
};