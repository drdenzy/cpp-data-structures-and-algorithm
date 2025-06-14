add_library(SinglyLinkedList-lib STATIC linkedlist.cpp)
add_library(DoublyLinkedList-lib STATIC doublylinkedlist.cpp)
add_library(Stack-lib STATIC stack.cpp)
add_library(Queue-lib STATIC queue.cpp)

target_include_directories(SinglyLinkedList-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DoublyLinkedList-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Stack-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Queue-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
