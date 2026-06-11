add_library(GameObjects
                PlayerSea.cpp PlayerSea_output.cpp PlayerSea.h
                Ship.cpp Ship.h
                DoubleMissile.cpp DoubleMissile.h
        TumblingMissile.cpp TumblingMissile.h
                Missile.cpp Missile.h
                Constants.h
                Output.h)

target_include_directories(GameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GameObjects Sea)

target_compile_features(GameObjects PRIVATE cxx_std_20)
set_target_properties(GameObjects PROPERTIES CXX_STANDARD_REQUIRED ON)
