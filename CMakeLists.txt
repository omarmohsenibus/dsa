cmake_minimum_required(VERSION 4.2)
project(dsa C)

add_compile_options(-Wall -Werror -O0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


include_directories(include)

add_library(dsa_core STATIC
        src/vector/vector.c
)

# --- Vector Test ---
add_executable(test_vector tests/vector/test_vector.c)
target_link_libraries(test_vector dsa_core)
