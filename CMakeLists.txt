cmake_minimum_required(VERSION 3.15)
project(AlgorithmIsMyGirlFriend)

set(CMAKE_CXX_STANDARD 11)

add_executable(AlgorithmIsMyGirlFriend main.cpp)

include_directories(BinaryTree Tree)
add_subdirectory(BinaryTree)
add_subdirectory(Tree)

target_link_libraries(AlgorithmIsMyGirlFriend BinaryTree Tree)

add_subdirectory(Google_tests)