add_library(Sea Coordinates.cpp Coordinates.h Object.cpp Object.h)

target_include_directories(Sea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(Sea PRIVATE cxx_std_20)
set_target_properties(Sea PROPERTIES CXX_STANDARD_REQUIRED ON)
