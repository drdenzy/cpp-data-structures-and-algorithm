cmake_minimum_required(VERSION 3.22)

project(
        LinkedListsDemo
        VERSION 1.0.0
        DESCRIPTION "C++ Classes"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Append custom cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

## Option to enable coverage
#option(CODE_COVERAGE "Enable code coverage reporting" ON)
#
## Apply coverage flags only when requested and using GCC/Clang
#if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#    message(STATUS "✔ Code coverage instrumentation enabled")
#    add_compile_options(--coverage -O0 -g)
#    add_link_options(--coverage)
##    link_libraries(gcov)
#endif()

option(CODE_COVERAGE "Enable LLVM code coverage reporting" ON)

if(CODE_COVERAGE)
    message(STATUS "Compiling with LLVM coverage instrumentation")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(LinkedListsApp main.cpp)

target_compile_options(LinkedListsApp PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(LinkedListsApp PRIVATE LinkedList-lib)

# Add coverage report target
#if(CODE_COVERAGE)
#    include(CodeCoverage)
#    add_coverage_target(coverage coverage-report)
#endif()

if(CODE_COVERAGE)
    include(LLVMCodeCoverage)
    add_llvm_coverage_target(llvm_coverage ${CMAKE_BINARY_DIR}/bin/linkedlist_test coverage-report)
endif()