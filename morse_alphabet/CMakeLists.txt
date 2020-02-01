add_library( morse_alphabet SHARED )

target_sources( morse_alphabet PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/morse_alphabet.c 
                ${CMAKE_CURRENT_LIST_DIR}/morse_alphabet.h )

target_include_directories( morse_alphabet PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_compile_options( morse_alphabet PRIVATE -Werror -Wall -Wextra )

target_compile_features( morse_alphabet PRIVATE c_std_11)
