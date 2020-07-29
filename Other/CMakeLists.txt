project(Other)

set(HEADER_FILES
        ../common.h
        power.h)

set(SOURCE_FILES
        power.cpp)

add_library(Other STATIC ${SOURCE_FILES} ${HEADER_FILES})