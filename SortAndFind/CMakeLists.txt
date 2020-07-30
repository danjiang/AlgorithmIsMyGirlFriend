project(SortAndFind)

set(HEADER_FILES
        ../common.h
        bubble_sort.h
        insertion_sort.h
        selection_sort.h
        merge_sort.h
        quick_sort.h
        find_max_kth_in_unsorted_array.h
        counting_sort.h
        binary_search.h
        sqrt.h
        rotated_array.h
        binary_search2.h
        find_more_than_half_number_in_unsorted_array.h
        find_min_kth_in_unsorted_array.h
        heap_sort.h)

set(SOURCE_FILES
        bubble_sort.cpp
        insertion_sort.cpp
        selection_sort.cpp
        merge_sort.cpp
        quick_sort.cpp
        find_max_kth_in_unsorted_array.cpp
        counting_sort.cpp
        binary_search.cpp
        sqrt.cpp
        rotated_array.cpp
        binary_search2.cpp
        find_more_than_half_number_in_unsorted_array.cpp
        find_min_kth_in_unsorted_array.cpp
        heap_sort.cpp)

add_library(SortAndFind STATIC ${SOURCE_FILES} ${HEADER_FILES})