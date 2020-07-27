project(HashTable)

set(HEADER_FILES
        ../common.h
        char_hash_table.h)

set(SOURCE_FILES
        char_hash_table.cpp)

add_library(HashTable STATIC ${SOURCE_FILES} ${HEADER_FILES})