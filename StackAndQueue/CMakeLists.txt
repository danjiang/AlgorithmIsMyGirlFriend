project(StackAndQueue)

set(HEADER_FILES
        ../common.h
        queue.h
        stack.h
        is_pop_order_of_stack.h)

set(SOURCE_FILES
        ../common.cpp
        queue.cpp
        stack.cpp
        is_pop_order_of_stack.cpp)

add_library(StackAndQueue STATIC ${SOURCE_FILES} ${HEADER_FILES})