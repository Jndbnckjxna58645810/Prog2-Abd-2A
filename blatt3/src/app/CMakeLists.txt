# TODO Aufgabe 1:
#  Fügt dem Projekt die Anwendung `Battleship` hinzu, mit den Dateien im Verzeichnis src/app/ und der Bibliothek `GameObjects`.
#
add_executable(Battleship game.cpp game.h init.cpp init.h main.cpp test.cpp test.h)

target_link_libraries(Battleship PRIVATE GameObjects Sea)

target_include_directories(Battleship PUBLIC .)

target_compile_features(Battleship PRIVATE cxx_std_20)
set_target_properties(Battleship PROPERTIES CXX_STANDARD_REQUIRED ON)
#
