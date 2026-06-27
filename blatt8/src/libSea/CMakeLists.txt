add_library(Sea
                Grid2D.inl Grid2D.h
                Object.cpp Object.h
                Coordinates.inl Coordinates.h)

target_include_directories(Sea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(Sea PRIVATE cxx_std_20)
set_target_properties(Sea PROPERTIES CXX_STANDARD_REQUIRED ON)