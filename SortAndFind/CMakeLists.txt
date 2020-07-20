project(SortAndFind)

set(HEADER_FILES
        ../common.h
        bubble_sort.h
        array_util.h
        insertion_sort.h
        selection_sort.h
        merge_sort.h
        quick_sort.h
        find_max_kth_in_unsorted_array.h)

set(SOURCE_FILES
        bubble_sort.cpp
        array_util.cpp
        insertion_sort.cpp
        selection_sort.cpp
        merge_sort.cpp
        quick_sort.cpp
        find_max_kth_in_unsorted_array.cpp)

add_library(SortAndFind STATIC ${SOURCE_FILES} ${HEADER_FILES})