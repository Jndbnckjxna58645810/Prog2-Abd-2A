cmake_minimum_required (VERSION 3.20)
project (hello)

add_executable (hello main.cpp)
target_compile_features (hello PRIVATE cxx_std_20)
set_target_properties (hello PROPERTIES CXX_STANDARD_REQUIRED ON)