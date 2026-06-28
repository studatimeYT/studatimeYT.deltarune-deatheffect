cmake_minimum_required(VERSION 3.25)

project(deltarune-deatheffect VERSION 1.0.0 LANGUAGES CXX)

find_package(Geode REQUIRED)

add_geode_mod(
    studatimeYT.deltarune-deatheffect
    VERSION 1.0.0
    DEPENDS
    SOURCES src/main.cpp
)
