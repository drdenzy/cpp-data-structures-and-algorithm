#include "linkedlist.hpp"
#include <iostream>

using namespace std;

int main() {

    auto ll = new LinkedList(3);
    ll->append(14);
    ll->append(5);
    // ll->append(28);
    // ll->append(28);
    ll->append(28);
    ll->append(35);
    ll->append(1000);
    ll->append(4);
    ll->prepend(50);
    // ll->prepend(1000);
    // ll->prepend(1000);

    // partition list
    ll->partitionList(10);
    cout << "Partitioned LinkedList: " << *ll << '\n';
    cout << "LinkedList length: " << ll->getLength() << '\n';
    cout << "Head: " << ll->getHead()->getData() << '\n';
    cout << "Tail: " << ll->getTail()->getData() << '\n';

    

    // // get
    // cout << "Node: " << ll->get(0)->getNext()->getData() << '\n';

    // // set
    // ll->set(4, 77000);
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "LinkedList: " << *ll << '\n';

    // // insert
    // ll->insert(5, 999000);
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "LinkedList: " << *ll << '\n';

    // // find middle node before reversal
    // cout << "Middle Node (before reversal): " << ll->findMiddleNode()->getData() << '\n';


    // // reverse nodes
    // ll->reverse();
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "Reversed LinkedList: " << *ll << '\n';

    // // find middle node after reversal
    // cout << "Middle Node (after reversal): " << ll->findMiddleNode()->getData() << '\n';

    // // check for loops in the linkedList
    // cout << "Has Loop: " << boolalpha << ll->hasLoop() << '\n';

    // // find the kth node
    // cout << "3rd Node from the end: " << ll->findKthFromEnd(3)->getData() << '\n';
    
    // // delete node
    // ll->deleteNode(2);
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "'deleted nodes' LinkedList: " << *ll << '\n';

    // // find middle node after deleting a node
    // cout << "Middle Node (after deleting a node): " << ll->findMiddleNode()->getData() << '\n';

    // // check for loops in the linkedList
    // cout << "Has Loop: " << boolalpha << ll->hasLoop() << '\n';

    // // find the kth node
    // cout << "5th Node from the end: " << ll->findKthFromEnd(5)->getData() << '\n';
    
    // // find and remove nodes with duplicate values
    // ll->removeDuplicates();
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "'de-duplicated' LinkedList: " << *ll << '\n';

    // // swap nodes
    // ll->swapPairs();
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "'swapped' LinkedList: " << *ll << '\n';

    // // reverse nodes in between m and n position
    // ll->reverseBetween(2, 5);
    // cout << "LinkedList length: " << ll->getLength() << '\n';
    // cout << "'reversed between' LinkedList: " << *ll << '\n';

    // deleteFirst
//    while(ll->getLength()){
//        ll->deleteFirst();
//        cout << "LinkedList length: " << ll->getLength() << '\n';
//        cout << "LinkedList: " << *ll << '\n';
//
//    }




//    while(ll->getLength()){
//        ll->deleteLast();
//        cout << "LinkedList length: " << ll->getLength() << '\n';
//        cout << "LinkedList: " << *ll << '\n';
//
//    }
//
//    ll->prepend(1000);
//    cout << "LinkedList length: " << ll->getLength() << '\n';
//    cout << "LinkedList: " << *ll << '\n';

//    for (int i=0; i<=100; i+=7){
//        ll->append(i);
//        cout << "LinkedList length: " << ll->getLength() << '\n';
//        cout << "LinkedList: " << *ll << '\n';
//    }
//
//    while(ll->getLength()){
//        ll->deleteLast();
//        cout << "LinkedList length: " << ll->getLength() << '\n';
//        cout << "LinkedList: " << *ll << '\n';
//
//    }

    return 0;
}