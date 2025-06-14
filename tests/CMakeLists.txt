include(FetchContent)


option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(singly_linkedlist_test linkedlist_test.cpp)

add_executable(doubly_linkedlist_test doublylinkedlist_test.cpp)

add_executable(stack_test stack_test.cpp)


target_link_libraries(singly_linkedlist_test
        PRIVATE
        GTest::gtest_main
        SinglyLinkedList-lib)


target_link_libraries(doubly_linkedlist_test
        PRIVATE
        GTest::gtest_main
        DoublyLinkedList-lib)

target_link_libraries(stack_test
        PRIVATE
        GTest::gtest_main
        Stack-lib)


include(GoogleTest)

gtest_discover_tests(singly_linkedlist_test)
gtest_discover_tests(doubly_linkedlist_test)
gtest_discover_tests(stack_test)
