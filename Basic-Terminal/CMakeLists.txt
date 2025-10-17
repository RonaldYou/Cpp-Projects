cmake_minimum_required(VERSION 3.10)

# Project name
project(BasicTerminal)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory for headers
include_directories(include)

# Gather source files
set(SOURCES
    main.cpp
    src/basic-terminal.cpp
)

# Build executable
add_executable(basicterminal ${SOURCES})