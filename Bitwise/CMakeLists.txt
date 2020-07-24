project(Bitwise)

set(HEADER_FILES
        ../common.h
        count_one_of_number.h
        find_numbers_appear_once.h
        add_with_bitwise.h)

set(SOURCE_FILES
        count_one_of_number.cpp
        find_numbers_appear_once.cpp
        add_with_bitwise.cpp)

add_library(Bitwise STATIC ${SOURCE_FILES} ${HEADER_FILES})