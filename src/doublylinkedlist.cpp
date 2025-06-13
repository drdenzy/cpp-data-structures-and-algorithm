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
    const Node* current = head;

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

void DoublyLinkedList::append(const int value) {
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

void DoublyLinkedList::prepend(const int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    ++length;
}

void DoublyLinkedList::deleteLast() {
    if (length == 0)
        return; // empty list

    Node* temp = tail;
    if (length == 1) {
        // single node list
        head = nullptr;
        tail = nullptr;
    } else {
        // multi-node list
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    --length;
}

void DoublyLinkedList::deleteFirst() {
    if (length == 0)
        return; // empty list
    Node* temp = head;
    if (length == 1) {
        // single node list
        head = nullptr;
        tail = nullptr;
    } else {
        // multi-node list
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    --length;
}

Node* DoublyLinkedList::get(const int index) const {
    // validate index bounds
    if (index < 0 || index >= length)
        return nullptr;

    /*
        * Optimized traversal based on index position:
        * - If the target index is in the first half of the list, start from the head.
        * - If it's in the second half, start from the tail.
        * This reduces traversal time from O(n) to O(n/2) in the average case.
    */
    Node* target = head;
    if (index < length / 2) {
        for (int i = 0; i < index; ++i) {
            target = target->next;
        }
    } else {
        target = tail;
        for (int i = length - 1; i > index; --i) {
            target = target->prev;
        }
    }
    return target;
}

bool DoublyLinkedList::set(int index, int newValue) {
  // the get method will serve as a helper
    Node* target = get(index);
    if (target) {
        target->value = newValue;
        return true;
    }
    return false;
}