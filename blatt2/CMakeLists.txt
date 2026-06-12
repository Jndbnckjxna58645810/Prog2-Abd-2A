cmake_minimum_required(VERSION 3.20)
project(blatt2)

add_executable(blatt2 main.cpp euroCheck.cpp euroCheck.h test.h)
target_compile_features(blatt2 PRIVATE cxx_std_20)
set_target_properties(blatt2 PROPERTIES CXX_STANDARD_REQUIRED ON)