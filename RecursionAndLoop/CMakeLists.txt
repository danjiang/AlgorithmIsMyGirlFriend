project(RecursionAndLoop)

set(HEADER_FILES
        ../common.h
        fibonacci.h
        print_dice_probability.h)

set(SOURCE_FILES
        fibonacci.cpp
        print_dice_probability.cpp)

add_library(RecursionAndLoop STATIC ${SOURCE_FILES} ${HEADER_FILES})