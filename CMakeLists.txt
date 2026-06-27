cmake_minimum_required(VERSION 3.13.4)

# Force the project name to match your exact Mod ID string
project(studatimeYT.deltarune-deatheffect)

find_package(Geode REQUIRED)

setup_geode_mod(studatimeYT.deltarune-deatheffect)

target_sources(studatimeYT.deltarune-deatheffect PRIVATE src/main.cpp)
