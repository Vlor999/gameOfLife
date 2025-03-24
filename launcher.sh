#!/bin/sh

echo "Starting the build process for Game of Life..."

if ! command -v cmake > /dev/null 2>&1; then
    echo "Error: cmake is not installed. Please install cmake and try again."
    exit 1
fi

if ! command -v make > /dev/null 2>&1; then
    echo "Error: make is not installed. Please install make and try again."
    exit 1
fi

if [ -d "build" ]; then
    echo "Cleaning up existing build directory..."
    rm -rf build
fi

echo "Creating build directory..."
mkdir -p build && cd build

echo "Running cmake..."
if ! cmake ..; then
    echo "Error: cmake configuration failed."
    exit 1
fi

echo "Running make..."
if ! make; then
    echo "Error: build failed."
    exit 1
fi

echo "Running Game of Life with arguments: $@"
if ! ./GameOfLife "$@"; then
    echo "Error: failed to run Game of Life."
    exit 1
fi

echo "Build and execution completed successfully."