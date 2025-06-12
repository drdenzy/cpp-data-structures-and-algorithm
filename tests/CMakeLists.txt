include(FetchContent)


option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)


add_executable(linkedlist_test linkedlist_test.cpp)


target_link_libraries(linkedlist_test
        PRIVATE
        GTest::gtest_main
        LinkedList-lib)


include(GoogleTest)

gtest_discover_tests(linkedlist_test)