add_executable(Battleship
                    main.cpp
                    test.cpp test.h
                    init.cpp init.h
                    game.cpp game.inl game.h
                    utils.cpp utils.h)

target_link_libraries(Battleship GameObjects Sea)

target_compile_features(Battleship PRIVATE cxx_std_20)
set_target_properties(Battleship PROPERTIES CXX_STANDARD_REQUIRED ON)
