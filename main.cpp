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

    std::cout << "Index 0: " << dll->get(0)->getData() << '\n';
    std::cout << "Index 1: " << dll->get(1)->getData() << '\n';
    std::cout << "Index (length of list - 1): " << dll->get(dll->getLength()-1)->getData() << '\n';

    dll->set(0, 111);
    dll->set(1, 222);
    dll->set(dll->getLength()-1, 333);

    std::cout << "Index 0: " << dll->get(0)->getData() << '\n';
    std::cout << "Index 1: " << dll->get(1)->getData() << '\n';
    std::cout << "Index (length of list - 1): " << dll->get(dll->getLength()-1)->getData() << '\n';

    // while (dll->getLength() != 0) {
    //     dll->deleteLast();
    //     dll->display();
    // }

    dll->insertNode(0, 1690);
    dll->display();
    dll->insertNode(dll->getLength(), 1999);
    dll->display();
    dll->insertNode(dll->getLength()/2, 18880);
    dll->display();

    dll->deleteNode(dll->getLength()/2);
    dll->display();
}