cmake_minimum_required(VERSION 3.25)

project(deltarune-deatheffect VERSION 1.0.0 LANGUAGES CXX)

# 🚀 THE FIX: Dynamically download and look up the Geode SDK if it isn't found locally
include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG        main # Or point to a specific stable tag if needed
)
FetchContent_MakeAvailable(Geode)

find_package(Geode REQUIRED)

add_geode_mod(
    studatimeYT.deltarune-deatheffect
    VERSION 1.0.0
    DEPENDS
    SOURCES src/main.cpp
)
