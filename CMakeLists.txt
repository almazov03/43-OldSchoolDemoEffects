cmake_minimum_required(VERSION 3.22)
project(43_OldSchoolDemoEffects)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(. Effects)
add_executable(43_OldSchoolDemoEffects main.cpp Video.cpp Effects/PlasmaEffect.cpp Effects/TunnelEffect.cpp Effects/FireEffect.cpp Effects/Effect.cpp Palette.cpp Palette.h)

target_link_libraries(43_OldSchoolDemoEffects sfml-graphics)