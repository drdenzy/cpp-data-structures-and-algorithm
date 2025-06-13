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

    dll->deleteLast();
    dll->display();
    std::cout << "DoublyLL Length: " << dll->getLength() << '\n';

    dll->append(11);
    dll->append(12);
    dll->append(13);
    dll->display();
    // while (dll->getLength() != 0) {
    //     dll->deleteFirst();
    //     dll->display();
    // }
    while (dll->getLength() != 0) {
        dll->deleteLast();
        dll->display();
    }
}