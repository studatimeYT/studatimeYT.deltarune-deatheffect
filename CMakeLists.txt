cmake_minimum_required(VERSION 3.13.4)

project(studatimeYT.deltarune-deatheffect LANGUAGES CXX)

find_package(Geode REQUIRED)

setup_geode_mod(studatimeYT.deltarune-deatheffect)

target_sources(studatimeYT.deltarune-deatheffect PRIVATE src/main.cpp)
