cmake_minimum_required(VERSION 3.22)

project(
        cppDataStructuresAlgorithms
        VERSION 1.0.0
        DESCRIPTION "Data Structures and Algorithms using C++"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Append custom cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


option(CODE_COVERAGE "Enable LLVM code coverage reporting" ON)

if (CODE_COVERAGE)
    message(STATUS "Compiling with LLVM coverage instrumentation")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate")
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(dsApp main.cpp)

target_compile_options(dsApp PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(dsApp PRIVATE SinglyLinkedList-lib DoublyLinkedList-lib)

if(CODE_COVERAGE)
    include(LLVMCodeCoverage)

    add_llvm_coverage_target(llvm_coverage1
            ${CMAKE_BINARY_DIR}/bin/singly_linkedlist_test
            coverage-report-singly
    )

    add_llvm_coverage_target(llvm_coverage2
            ${CMAKE_BINARY_DIR}/bin/doubly_linkedlist_test
            coverage-report-doubly
    )
endif()







