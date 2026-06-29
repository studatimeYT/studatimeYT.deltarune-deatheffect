cmake_minimum_required(VERSION 3.25)

project(deltarunedeatheffect VERSION 1.0.0 LANGUAGES CXX)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    ${PROJECT_VERSION}
    SOURCES src/main.cpp
)
