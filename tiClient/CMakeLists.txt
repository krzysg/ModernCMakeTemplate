cmake_minimum_required(VERSION 3.13)
project(testInstall VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)


find_package(libInstall)

# ----------------- Add test executable
add_executable(testInstall src/main.cpp)
target_link_libraries(testInstall xyz::libInstall)

