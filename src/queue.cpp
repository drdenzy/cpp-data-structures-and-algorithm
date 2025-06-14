#include "queue.hpp"
#include <climits>
#include <iostream>

Queue::Queue(int value) {
    first = last = new QNode(value);
    size = 1;
}

Queue::~Queue() {
    clear();
}

void Queue::display() const {
    std::cout << "{";

    QNode* current = first;

    while (current) {
        std::cout << current->data;
        current = current->next;
        if (current) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}


void Queue::clear() {
    if (size == 0)
        return;

    QNode* current = first;
    while (current) {
        QNode* next = current->next;
        delete current;
        current = next;
    }
    first = last = nullptr;
    size = 0;
}

void Queue::enQueue(int value) {
    QNode* newNode = new QNode(value);

    if (size == 0) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    ++size;
}

int Queue::deQueue() {
    if (size == 0) return INT_MIN;

    QNode* temp = first;
    const int dequeuedValue = first->data;
    first = first->next;
    delete temp;
    --size;

    return dequeuedValue;
}

int Queue::getSize() const {
    return size;
}

int Queue::peek() const {
    if (size == 0) return INT_MIN;

    return first->data;
}