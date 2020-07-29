project(String)

set(HEADER_FILES
        ../common.h
        string_to_int.h
        reverse_string.h
        print_one_to_max_of_n_digits.h
        is_string_represent_number.h)

set(SOURCE_FILES
        string_to_int.cpp
        reverse_string.cpp
        print_one_to_max_of_n_digits.cpp
        is_string_represent_number.cpp)

add_library(String STATIC ${SOURCE_FILES} ${HEADER_FILES})