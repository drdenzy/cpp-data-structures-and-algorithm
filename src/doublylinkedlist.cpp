#include "doublylinkedlist.hpp"

#include <iostream>

DNode::DNode(int value)
    : value{value},
      next{nullptr},
      prev{nullptr} {
};


int DNode::getData() const {
    return this->value;
}

DoublyLinkedList::DoublyLinkedList(int value) {
    DNode* newNode = new DNode(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::clear() {
    DNode* current = head;
    while (current != nullptr) {
        DNode* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}


int DoublyLinkedList::getLength() const {
    return length;
}

DNode* DoublyLinkedList::getHead() const {
    return head;
}

DNode* DoublyLinkedList::getTail() const {
    return tail;
}

void DoublyLinkedList::display() const {
    const DNode* current = head;

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
    DNode* newNode = new DNode(value);
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
    DNode* newNode = new DNode(value);
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

    DNode* temp = tail;
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
    DNode* temp = head;
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

DNode* DoublyLinkedList::get(const int index) const {
    // validate index bounds
    if (index < 0 || index >= length)
        return nullptr;

    /*
        * Optimized traversal based on index position:
        * - If the target index is in the first half of the list, start from the head.
        * - If it's in the second half, start from the tail.
        * This reduces traversal time from O(n) to O(n/2) in the average case.
    */
    DNode* target = head;
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
    DNode* target = get(index);
    if (target) {
        target->value = newValue;
        return true;
    }
    return false;
}

bool DoublyLinkedList::insertNode(int index, int value) {
    // validate index bounds
    if (index < 0 || index > length)
        return false;

    if (index == 0) {
        prepend(value);
        return true;
    }

    if (index == length) {
        append(value);
        return true;
    }

    DNode* newNode = new DNode(value);
    DNode* before = get(index - 1);
    DNode* after = before->next;

    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;

    ++length;

    return true;
}

void DoublyLinkedList::deleteNode(int index) {
    if (index < 0 || index >= length)
        return;

    if (index == 0)
        return deleteFirst();

    if (index == length - 1)
        return deleteLast();

    // option 1: beginner-friendly but more verbose
    // DNode* target = get(index);
    // if (!target) return;
    // DNode* before = target->prev;
    // DNode* after = target->next;
    //
    // before->next = after;
    // after->prev = before;
    //
    // delete target;
    // --length;

    // option 2: Unlink the target node by updating its neighbors
    DNode* target = get(index);
    if (!target)
        return;

    target->next->prev = target->prev;
    target->prev->next = target->next;
    delete target;
    --length;
}