project(LinkList)

set(HEADER_FILES
        ../common.h
        link_list.h
        print_link_list_reverse.h
        link_list_append_node.h
        link_list_remove_node.h
        find_middle_node_of_link_list.h
        intersect_two_sorted_link_list.h
        find_kth_to_tail_of_link_list.h
        entry_node_of_loop_link_list.h
        reverse_link_list.h
        merge_link_list.h
        find_first_common_node_of_link_list.h
        find_node_of_cache_in_link_list.h
        check_palindromic_string_in_link_list.h)

set(SOURCE_FILES
        link_list.cpp
        print_link_list_reverse.cpp
        link_list_append_node.cpp
        link_list_remove_node.cpp
        find_middle_node_of_link_list.cpp
        intersect_two_sorted_link_list.cpp
        find_kth_to_tail_of_link_list.cpp
        entry_node_of_loop_link_list.cpp
        reverse_link_list.cpp
        merge_link_list.cpp
        find_first_common_node_of_link_list.cpp
        find_node_of_cache_in_link_list.cpp
        check_palindromic_string_in_link_list.cpp)

add_library(LinkList STATIC ${SOURCE_FILES} ${HEADER_FILES})