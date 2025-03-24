cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

# Indiquer le chemin vers SFML 2
set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")

# Trouver SFML 2.5 avec les composants nécessaires
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# Définir les fichiers sources
file(GLOB SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
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
file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Add test executables
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
    if(${TEST_NAME} STREQUAL "test_gameInfo")
        target_link_libraries(${TEST_NAME} sfml-graphics sfml-window sfml-system)
    endif()
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
