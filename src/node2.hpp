#pragma once

class Node2 {
public:
    explicit Node2(int data);

    ~Node2() = default;

    int getData() const;
    void setData(int data);

    Node2* getNext() const;
    void setNext(Node2* node);

private:
    int data;
    Node2* next;
};