#include "node.hpp"

Node::Node(int data) : data{data}, next{nullptr} {
}

int Node::getData() const { return data; }

Node *Node::getNext() const { return next; }

void Node::setNext(Node *node) { next = node; }

void Node::setData(int data) {
    this->data = data;
}