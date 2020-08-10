project(Other)

set(HEADER_FILES
        ../common.h
        power.h
        josephuse_circle.h)

set(SOURCE_FILES
        power.cpp
        josephuse_circle.cpp)

add_library(Other STATIC ${SOURCE_FILES} ${HEADER_FILES})