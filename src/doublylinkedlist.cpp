#include "doublylinkedlist.hpp"

#include <iostream>

DoublyLinkedList::DoublyLinkedList(int value) {
  Node* newNode = new Node(value);
  head = newNode;
  tail = newNode;
  length = 1;
}

DoublyLinkedList::~DoublyLinkedList() {
  clear();
}

void DoublyLinkedList::clear() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = tail = nullptr;
  length = 0;
}



int DoublyLinkedList::getLength() const {
    return length;
}

Node* DoublyLinkedList::getHead() const {
    return head;
}

Node* DoublyLinkedList::getTail() const {
    return tail;
}

void DoublyLinkedList::display() const {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "{}\n";
    }
    std::cout << "{";
    while (current) {
        std::cout << current->getData();
        current = current->next;
        if (current) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value);
    // empty list
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++length;
}

void DoublyLinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    ++length;

}