cmake_minimum_required(VERSION 3.29)
project(Songlist)

set(CMAKE_CXX_STANDARD 20)


# Add SFML
set(SFML_DIR "/opt/homebrew/opt/sfml/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Songlist main.cpp
        Songs.h
        Songs.cpp)

target_link_libraries(Songlist sfml-graphics sfml-window sfml-system)





