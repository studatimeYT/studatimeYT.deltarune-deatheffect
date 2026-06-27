cmake_minimum_required(VERSION 3.13.4)

project(deltarune-explosion)

find_package(geode REQUIRED)

setup_geode_mod(studatimeYT.deltarune-explosion)

target_sources(studatimeYT.deltarune-explosion PRIVATE src/main.cpp)
