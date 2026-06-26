cmake_minimum_required(VERSION 3.13)

project(DeltaruneDeathEffect)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    VERSION 1.0.0
    CONFFILE mod.json
    SOURCES
        src/main.cpp
)
