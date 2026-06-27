cmake_minimum_required(VERSION 3.13.4)

# Create the project matching your repository name
project(deltarune-deatheffect)

# CRITICAL: This MUST have a capital "G" so GitHub Actions can find the SDK
find_package(Geode REQUIRED)

# This must match your mod.json ID exactly
setup_geode_mod(studatimeYT.deltarune-deatheffect)

# Links your C++ source code to the project
target_sources(studatimeYT.deltarune-deatheffect PRIVATE src/main.cpp)
