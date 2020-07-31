project(BinaryTree)

set(HEADER_FILES
        ../common.h
        binary_tree.h
        find_kth_node_in_bst.h
        construct_binary_tree_with_preorder_inorder_walk_result.h
        top_to_bottom_binary_tree_walk.h
        mirror_binary_tree.h
        binary_tree_contain_sub_tree.h
        is_postorder_sequence_of_bst.h
        find_summary_path_in_binary_tree.h
        bst_to_link_list.h
        serialize_binary_tree.h
        binary_tree_depth.h
        binary_tree_is_balance.h
        binary_tree_is_symmetrical.h
        get_binary_tree_inorder_walk_next.h
        binary_search_tree.h
        heap.h
        get_middle_number_of_stream.h)

set(SOURCE_FILES
        binary_tree.cpp
        find_kth_node_in_bst.cpp
        construct_binary_tree_with_preorder_inorder_walk_result.cpp
        top_to_bottom_binary_tree_walk.cpp
        mirror_binary_tree.cpp
        binary_tree_contain_sub_tree.cpp
        is_postorder_sequence_of_bst.cpp
        find_summary_path_in_binary_tree.cpp
        bst_to_link_list.cpp
        serialize_binary_tree.cpp
        binary_tree_depth.cpp
        binary_tree_is_balance.cpp
        binary_tree_is_symmetrical.cpp
        get_binary_tree_inorder_walk_next.cpp
        binary_search_tree.cpp
        heap.cpp
        get_middle_number_of_stream.cpp)

add_library(BinaryTree STATIC ${SOURCE_FILES} ${HEADER_FILES})
