#pragma once

class QNode {
public:
    QNode* next;
    int data;

    QNode(int data)
        : next{nullptr},
          data{data} {
    };
    ~QNode() = default;
};

class Queue {
private:
    int size;
    QNode* first;
    QNode* last;

public:
    explicit Queue(int value);
    ~Queue();

    void enQueue(int value);
    int deQueue(); // uses INT_MIN as sentinel value
    int getSize() const;
    int peek() const; // uses INT_MIN as sentinel value
    void display() const;
    void clear();
};