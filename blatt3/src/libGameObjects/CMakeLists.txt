# TODO Aufgabe 1:
#  Fügt dem Projekt die Bibliothek `GameObjects` hinzu, mit den Dateien im Verzeichnis src/libGameObjects/ und der Bibliothek `Sea`.
#
add_library(GameObjects Constants.h Missile.cpp Missile.h PlayerSea.cpp PlayerSea.h Ship.cpp Ship.h)

target_link_libraries(GameObjects PUBLIC Sea)

target_include_directories(GameObjects PUBLIC .)
#
