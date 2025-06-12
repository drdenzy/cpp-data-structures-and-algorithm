cmake_minimum_required(VERSION 3.22)

project(
        DoublyLinkedListDemo
        VERSION 1.0.0
        DESCRIPTION "C++ Classes"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(DoublyLinkedListsApp main.cpp)

target_compile_options(DoublyLinkedListsApp PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(DoublyLinkedListsApp PRIVATE DoublyLinkedList-lib)


