cmake_minimum_required(VERSION 3.10)

# Project name
project(SFML_Project)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Link SFML libraries
set(SFML_DIR "lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add the executable
add_executable(SFML_Project src/main.cpp)

# Link the executable to the SFML libraries
target_link_libraries(SFML_Project sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
