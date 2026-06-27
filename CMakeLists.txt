cmake_minimum_required(VERSION 3.13.4)

# Create your project match tracking name
project(studatimeYT.deltarune-deatheffect)

# 🚀 THE FIX: This forces CMake to look at the automated Geode SDK location
list(APPEND CMAKE_MODULE_PATH CMAKE_CURRENT_SOURCE_PATH)

find_package(Geode REQUIRED)

setup_geode_mod(studatimeYT.deltarune-deatheffect)

target_sources(studatimeYT.deltarune-deatheffect PRIVATE src/main.cpp)
