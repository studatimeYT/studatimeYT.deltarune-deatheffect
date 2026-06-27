cmake_minimum_required(VERSION 3.13.4)

project(deltarune-deatheffect)

find_package(geode REQUIRED)

setup_geode_mod(studatimeYT.deltarune-deatheffect)

target_sources(studatimeYT.deltarune-deatheffect PRIVATE src/main.cpp)
