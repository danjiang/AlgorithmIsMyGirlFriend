cmake_minimum_required(VERSION 3.15)
project(AlgorithmIsMyGirlFriend)

set(CMAKE_CXX_STANDARD 11)

add_executable(AlgorithmIsMyGirlFriend main.cpp)

include_directories(BinaryTree)
add_subdirectory(BinaryTree)

target_link_libraries(AlgorithmIsMyGirlFriend BinaryTree)

add_subdirectory(Google_tests)