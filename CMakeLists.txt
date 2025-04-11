cmake_minimum_required(VERSION 3.10)
project(gameOfLife VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML directory for macOS with Homebrew
set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

# Find SFML package
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

# Include directories
include_directories(include ${SFML_INCLUDE_DIR})

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Add custom target for cleaning
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    COMMENT "Cleaning all build files"
)

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
