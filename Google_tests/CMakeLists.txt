project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run
        CompleteBSTTest.cpp
        OnlyLeftNodeBSTTest.cpp
        OnlyRightNodeBSTTest.cpp
        EmptyBinaryTreeTest.cpp
        OneNodeBinaryTreeTest.cpp
        CompleteBinaryTreeTest.cpp
        NonCompleteBinaryTreeTest.cpp
        OnlyLeftNodeBinaryTreeTest.cpp
        OnlyRightNodeBinaryTreeTest.cpp
        OtherBinaryTreeTest.cpp
        NonCompleteBSTTest.cpp
        BinaryTreeIsSymmetricalTest.cpp
        TreeTest.cpp
        NormalLinkListTest.cpp
        TwoNodesLinkListTest.cpp
        OneNodeLinkListTest.cpp
        EmptyLinkListTest.cpp
        LinkListDeleteDuplicationTest.cpp
        MergeLinkListTest.cpp
        FindFirstCommonNodeOfLinkListTest.cpp
        OtherLinkListTest.cpp)

# linking Google_Tests_run with BinaryTree which will be tested
target_link_libraries(Google_Tests_run
        BinaryTree
        Tree
        LinkList)

target_link_libraries(Google_Tests_run gtest gtest_main)
