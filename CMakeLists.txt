cmake_minimum_required(VERSION 3.15)
project(AlgorithmIsMyGirlFriend)

set(CMAKE_CXX_STANDARD 11)

add_executable(AlgorithmIsMyGirlFriend main.cpp)

include_directories(
        BinaryTree
        Tree
        LinkList
        StackAndQueue
        RecursionAndLoop
        SortAndFind
        Bitwise
        HashTable)
add_subdirectory(BinaryTree)
add_subdirectory(Tree)
add_subdirectory(LinkList)
add_subdirectory(StackAndQueue)
add_subdirectory(RecursionAndLoop)
add_subdirectory(SortAndFind)
add_subdirectory(Bitwise)
add_subdirectory(HashTable)

target_link_libraries(AlgorithmIsMyGirlFriend
        BinaryTree
        Tree
        LinkList
        StackAndQueue
        RecursionAndLoop
        SortAndFind
        Bitwise
        HashTable)

add_subdirectory(Google_tests)