add_library(DoublyLinkedList-lib STATIC doublylinkedlist.cpp node.cpp)

target_include_directories(DoublyLinkedList-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})