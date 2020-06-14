project(Tree)

set(HEADER_FILES
        ../common.h
        tree.h
        get_tree_last_common_parent.h)

set(SOURCE_FILES
        ../common.cpp
        tree.cpp
        get_tree_last_common_parent.cpp
        )

add_library(Tree STATIC ${SOURCE_FILES} ${HEADER_FILES})