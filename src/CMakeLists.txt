add_library(LinkedList-lib STATIC linkedlist.cpp node.cpp)

target_include_directories(LinkedList-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})