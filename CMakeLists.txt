cmake_minimum_required(VERSION 3.10)
project(SFML_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set the path to the SFML libraries
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/cmake/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib/cmake/SFML" ${CMAKE_MODULE_PATH})

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add the executable
add_executable(SFML_Project src/main.cpp)

# Link the executable to the SFML libraries
target_link_libraries(SFML_Project sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Set the RPATH to use the local SFML libraries
set(CMAKE_INSTALL_RPATH "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# Custom command to copy the assets directory
add_custom_command(TARGET SFML_Project POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:SFML_Project>/assets)
