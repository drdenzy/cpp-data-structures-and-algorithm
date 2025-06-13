#include "node2.hpp"

Node2::Node2(int data)
    : data{data},
      next{nullptr} {
}

int Node2::getData() const {
    return data;
}

Node2* Node2::getNext() const {
    return next;
}

void Node2::setNext(Node2* node) {
    next = node;
}

void Node2::setData(int data) {
    this->data = data;
}