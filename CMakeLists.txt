cmake_minimum_required(VERSION 3.15)
project(AlgorithmIsMyGirlFriend)

set(CMAKE_CXX_STANDARD 11)

add_executable(AlgorithmIsMyGirlFriend main.cpp)

include_directories(
        Tree
        LinkList
        StackAndQueue
        SkillAndThought
        SortAndFind
        Bitwise
        Array
        String
        Other
        Graph)
add_subdirectory(Tree)
add_subdirectory(LinkList)
add_subdirectory(StackAndQueue)
add_subdirectory(SkillAndThought)
add_subdirectory(SortAndFind)
add_subdirectory(Bitwise)
add_subdirectory(Array)
add_subdirectory(String)
add_subdirectory(Other)
add_subdirectory(Graph)

target_link_libraries(AlgorithmIsMyGirlFriend
        Tree
        LinkList
        StackAndQueue
        SkillAndThought
        SortAndFind
        Bitwise
        Array
        String
        Other
        Graph)

add_subdirectory(Google_tests)