cmake_minimum_required(VERSION 3.22)
project(43_OldSchoolDemoEffects)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(43_OldSchoolDemoEffects main.cpp Video.cpp PlasmaEffect.cpp TunnelEffect.cpp)

target_link_libraries(43_OldSchoolDemoEffects sfml-graphics)