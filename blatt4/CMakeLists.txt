cmake_minimum_required(VERSION 3.20)
project(blatt4)

if(MSVC)
    add_compile_options(/W4 /EHs)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()


add_subdirectory(src)
