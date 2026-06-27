cmake_minimum_required(VERSION 3.13.4)

project(deltarune-deatheffect LANGUAGES CXX)


include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG v3.0.0-beta.1
)
FetchContent_MakeAvailable(Geode)


setup_geode_mod(studatimeYT.deltarune-deatheffect)


target_sources(studatimeYT.deltarune-deatheffect PRIVATE src/main.cpp)
