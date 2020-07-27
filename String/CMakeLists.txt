project(String)

set(HEADER_FILES
        ../common.h
        string_to_int.h
        reverse_string.h)

set(SOURCE_FILES
        string_to_int.cpp
        reverse_string.cpp)

add_library(String STATIC ${SOURCE_FILES} ${HEADER_FILES})