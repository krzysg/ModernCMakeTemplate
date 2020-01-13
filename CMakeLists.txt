cmake_minimum_required(VERSION 3.13)
project(ModernCmakeTemplate VERSION 1.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

# ----------------- Use LibA and LibB as a subprojects
add_subdirectory("LibA")
add_subdirectory("LibB")

# ----------------- Add test executable
add_executable(main src/main.cpp)
target_link_libraries(main LibA::libA LibB::libB)
