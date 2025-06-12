include(FetchContent)


option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)


add_executable(doublylinkedlist_test doublylinkedlist_test.cpp)


target_link_libraries(doublylinkedlist_test
        PRIVATE
        GTest::gtest_main
        DoublyLinkedList-lib)


include(GoogleTest)

gtest_discover_tests(doublylinkedlist_test)