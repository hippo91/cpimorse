cmake_minimum_required( VERSION 3.1...3.16 )

project( CPiMorse VERSION 1.0 LANGUAGES C )

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

set( CMAKE_C_STANDARD_REQUIRED ON )

add_subdirectory( ${CMAKE_CURRENT_LIST_DIR}/morse_alphabet )

add_executable( cpimorse main.c )
target_compile_features( cpimorse PRIVATE c_std_11 )
target_compile_options( cpimorse PRIVATE -Werror -Wall -Wextra )
target_link_libraries( cpimorse PRIVATE 
  gpiod
  morse_alphabet )