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

# Enable testing
enable_testing()

# Add tests
add_executable(test_example tests/test_example.cpp)
add_executable(test_tableau tests/test_tableau.cpp)
add_executable(test_gameInfo tests/test_gameInfo.cpp)
add_executable(test_CLIDatas tests/test_CLIDatas.cpp)

# Include directories for tests
target_include_directories(test_example PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(test_tableau PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(test_gameInfo PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(test_CLIDatas PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link SFML to test_gameInfo
target_link_libraries(test_gameInfo sfml-graphics sfml-window sfml-system)

add_test(NAME ExampleTest COMMAND test_example)
add_test(NAME TableauTest COMMAND test_tableau)
add_test(NAME GameInfoTest COMMAND test_gameInfo)
add_test(NAME CLIDatasTest COMMAND test_CLIDatas)
