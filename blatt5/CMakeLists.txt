cmake_minimum_required(VERSION 3.20)
project(blatt5)

if(MSVC)
    add_compile_options(/W4 /EHs)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_compile_definitions(EXERCISE_SKIP_WAITING)
add_compile_definitions(EXERCISE_SKIP_PLAYER_INIT)

add_subdirectory(src)
