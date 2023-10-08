cmake_minimum_required(VERSION 3.23)

project(prog3_ueb_asteroids_lab01)
set(CMAKE_C_STANDARD 17)
find_package(raylib 4.0 REQUIRED)

include("${CMAKE_CURRENT_SOURCE_DIR}/01_Asteroids/CMakeLists.txt")