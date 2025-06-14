#pragma once

class SNode {
public:
    int data;
    SNode* next;

    explicit SNode(const int data)
        : data{data},
          next{nullptr} {
    };
    ~SNode() = default;
};

class Stack {
public:
    explicit Stack(int data);
    ~Stack();
    void clear();
    void display() const;
    int getTop() const;
    int getHeight() const;
    // main Stack APIs
    void push(int value);
    int pop(); // uses INT_MIN as sentinel value
    int peek() const; // uses INT_MIN as sentinel value

private:
    SNode* top;
    int height;
};