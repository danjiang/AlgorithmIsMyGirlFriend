project(Graph)

set(HEADER_FILES
        ../common.h
        graph.h)

set(SOURCE_FILES
        graph.cpp)

add_library(Graph STATIC ${SOURCE_FILES} ${HEADER_FILES})