cmake_minimum_required(VERSION 3.10)

project(DungeonGen)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Raylib setup
set(RAYLIB_DIR "path/to/raylib")  # Update with the path where Raylib is installed

find_package(Raylib REQUIRED)

# Add the executable target
add_executable(DungeonGen src/main.cpp src/player.cpp src/tilemanager.cpp src/camera.cpp src/bow.cpp src/enemy.cpp)

# Link Raylib
target_link_libraries(DungeonGen raylib)
