project(Array)

set(HEADER_FILES
        ../common.h
        array_util.h
        find_duplicate_number_of_array.h
        find_number_of_matrix.ho
        divide_array.h)

set(SOURCE_FILES
        array_util.cpp
        find_duplicate_number_of_array.cpp
        find_number_of_matrix.cpp
        divide_array.cpp)

add_library(Array STATIC ${SOURCE_FILES} ${HEADER_FILES})