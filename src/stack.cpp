#include "stack.hpp"
#include <iostream>

Stack::Stack(const int data) {
    top = new SNode(data);
    height = 1;
}

Stack::~Stack() {
    clear();
}


void Stack::clear() {
    SNode* current = top;

    while (current) {
        SNode* next = current->next;
        delete current;
        current = next;
    }
    top = nullptr;
    height = 0;
}

void Stack::display() const {
    std::cout << "{";
    const SNode* current = top;
    while (current) {
        std::cout << current->data;
        current = current->next;
        if (current) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

int Stack::getTop() const {
    return top->data;
}

int Stack::getHeight() const {
    return height;
}

void Stack::push(const int value) {
    auto* newNode = new SNode(value);
    newNode->next = top;
    top = newNode;
    ++height;
}

int Stack::pop() {
    if (height == 0) return INT_MIN;
    SNode* temp = top;
    const int poppedValue = top->data;
    top = top->next;
    delete temp;
    --height;
    return poppedValue;
}

int Stack::peek() const {
    if (height == 0) return INT_MIN;
    return top->data;
}