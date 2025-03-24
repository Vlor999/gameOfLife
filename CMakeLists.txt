cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

# Indiquer le chemin vers SFML 2
set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")

# Trouver SFML 2.5 avec les composants nécessaires
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# Définir les fichiers sources
set(SOURCES 
    src/main.cpp
    src/creationTableau.cpp
)

# Définir les répertoires d'inclusion
include_directories(${CMAKE_SOURCE_DIR})

# Ajouter l'exécutable
add_executable(GameOfLife ${SOURCES})

# Lier SFML à l'exécutable
target_link_libraries(GameOfLife sfml-graphics sfml-window sfml-system)
