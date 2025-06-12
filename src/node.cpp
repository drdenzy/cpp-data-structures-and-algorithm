#include "node.hpp"

Node::Node(int value)
  : value{value},
    next{nullptr},
    prev{nullptr} {
};




int Node::getData() const {
    return this->value;
}