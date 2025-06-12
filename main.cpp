#include <iostream>

#include "doublylinkedlist.hpp"

int main() {
    auto dll = new DoublyLinkedList(10);

    // std::cout << "DoublyLL Length: " << dll->getLength() << '\n';
    // dll->display();

    dll->append(5);
    dll->append(7);
    dll->display();
    std::cout << "DoublyLL Length: " << dll->getLength() << '\n';

    dll->prepend(3);
    dll->display();
    std::cout << "DoublyLL Length: " << dll->getLength() << '\n';
}