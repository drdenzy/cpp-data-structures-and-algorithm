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
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)

if (CODE_COVERAGE)
    message(STATUS "Compiling with LLVM coverage instrumentation")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate")
endif ()

if(ENABLE_ASAN)
    message(STATUS "Building with AddressSanitizer enabled")
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(dsApp main.cpp)

target_compile_options(dsApp PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(dsApp PRIVATE SinglyLinkedList-lib DoublyLinkedList-lib Stack-lib Queue-lib)

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

    add_llvm_coverage_target(llvm_coverage3
            ${CMAKE_BINARY_DIR}/bin/stack_test
            coverage-report-stack
    )

    add_llvm_coverage_target(llvm_coverage4
            ${CMAKE_BINARY_DIR}/bin/queue_test
            coverage-report-queue
    )
endif()







