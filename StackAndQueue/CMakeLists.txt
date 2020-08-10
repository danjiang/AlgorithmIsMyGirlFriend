project(StackAndQueue)

set(HEADER_FILES
        ../common.h
        queue.h
        stack.h
        is_pop_order_of_stack.h
        queue_with_max.h)

set(SOURCE_FILES
        queue.cpp
        stack.cpp
        is_pop_order_of_stack.cpp
        queue_with_max.cpp)

add_library(StackAndQueue STATIC ${SOURCE_FILES} ${HEADER_FILES})