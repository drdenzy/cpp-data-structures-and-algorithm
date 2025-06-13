add_library(SinglyLinkedList-lib STATIC linkedlist.cpp)
add_library(DoublyLinkedList-lib STATIC doublylinkedlist.cpp)

target_include_directories(SinglyLinkedList-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DoublyLinkedList-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
