project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run
        BinaryTree/CompleteBSTTest.cpp
        BinaryTree/OnlyLeftNodeBSTTest.cpp
        BinaryTree/OnlyRightNodeBSTTest.cpp
        BinaryTree/EmptyBinaryTreeTest.cpp
        BinaryTree/OneNodeBinaryTreeTest.cpp
        BinaryTree/CompleteBinaryTreeTest.cpp
        BinaryTree/NonCompleteBinaryTreeTest.cpp
        BinaryTree/OnlyLeftNodeBinaryTreeTest.cpp
        BinaryTree/OnlyRightNodeBinaryTreeTest.cpp
        BinaryTree/OtherBinaryTreeTest.cpp
        BinaryTree/NonCompleteBSTTest.cpp
        BinaryTree/BinaryTreeIsSymmetricalTest.cpp
        TreeTest.cpp
        LinkList/NormalLinkListTest.cpp
        LinkList/TwoNodesLinkListTest.cpp
        LinkList/OneNodeLinkListTest.cpp
        LinkList/EmptyLinkListTest.cpp
        LinkList/LinkListDeleteDuplicationTest.cpp
        LinkList/MergeLinkListTest.cpp
        LinkList/FindFirstCommonNodeOfLinkListTest.cpp
        LinkList/OtherLinkListTest.cpp
        StackAndQueue/QueueTest.cpp
        StackAndQueue/StackTest.cpp
        StackAndQueue/IsPopOrderOfStackTest.cpp
        RecursionAndLoop/FibonacciTest.cpp
        RecursionAndLoop/PrintDiceProbabilityTest.cpp
        SortAndFind/UnsortArrayTest.cpp
        SortAndFind/CountingSortTest.cpp
        SortAndFind/DistinctSortedArrayTest.cpp
        SortAndFind/SqrtTest.cpp
        SortAndFind/RepeatSortedArrayTest.cpp
        SortAndFind/DistinctRotatedArrayTest.cpp
        SortAndFind/RepeatRotatedArrayTest.cpp
        SortAndFind/BinarySearch2Test.cpp
        Bitwise/CountOneOfNumberTest.cpp
        Bitwise/FindNumbersAppearOnce.cpp
        Bitwise/AddWithBitwiseTest.cpp
        HashTable/CharHashTableTest.cpp
        Array/FindDuplicateNumberOfArrayTest.cpp
        Array/FindNumberOfMatrixTest.cpp
        Array/DivideArrayTest.cpp
        String/StringToIntTest.cpp
        String/ReverseStringTest.cpp
        BinaryTree/BinarySearchTreeTest.cpp)

# linking Google_Tests_run with BinaryTree which will be tested
target_link_libraries(Google_Tests_run
        BinaryTree
        Tree
        LinkList
        StackAndQueue
        RecursionAndLoop
        SortAndFind
        Bitwise
        HashTable
        Array
        String)

target_link_libraries(Google_Tests_run gtest gtest_main)
