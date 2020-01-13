cmake_minimum_required(VERSION 3.13)
project(ModernCmakeTemplate VERSION 1.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

# Remember to set CMAKE_PREFIX_PATH if libA and libB are not in default system directories
find_package("libA")
find_package("libB")

# ----------------- Add test executable
add_executable(main src/main.cpp)
target_link_libraries(main LibA::libA LibB::libB)
