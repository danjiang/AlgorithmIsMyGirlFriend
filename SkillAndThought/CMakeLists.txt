project(SkillAndThought)

set(HEADER_FILES
        ../common.h
        fibonacci.h
        print_dice_probability.h
        count_inverse_pairs.h
        print_8_queens.h
        fill_bag.h
        simple_regular_expression2.h
        has_string_path_in_matrix.h
        simple_robot_move.h
        yang_hui_triangle.h
        move_on_matrix.h
        coin_change.h
        string_edit_distance.h
        longest_increase_subsequence.h)

set(SOURCE_FILES
        fibonacci.cpp
        print_dice_probability.cpp
        count_inverse_pairs.cpp
        print_8_queens.cpp
        fill_bag.cpp
        simple_regular_expression2.cpp
        has_string_path_in_matrix.cpp
        simple_robot_move.cpp
        yang_hui_triangle.cpp
        move_on_matrix.cpp
        coin_change.cpp
        string_edit_distance.cpp
        longest_increase_subsequence.cpp)

add_library(SkillAndThought STATIC ${SOURCE_FILES} ${HEADER_FILES})