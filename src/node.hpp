#pragma once

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
