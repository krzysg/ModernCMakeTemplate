cmake_minimum_required(VERSION 3.13)
project(testInstall VERSION 1.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)


# ----------------- Create library
set(LIB_NAME libInstall)
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_options(${LIB_NAME} INTERFACE -Werror)

# ----------------- Add test executable
add_executable(testInstall src/main.cpp)
target_link_libraries(testInstall libInstall)

# ----------------- Install
include(GNUInstallDirs)

# copy includes
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# generate target target file
set(TARGET_FILE_NAME ${LIB_NAME}Targets)
install(TARGETS ${LIB_NAME} EXPORT ${TARGET_FILE_NAME} INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT ${LIB_NAME}Targets  NAMESPACE xyz:: DESTINATION lib/cmake/libInstall)

# generate version config version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${LIB_NAME}ConfigVersion.cmake
        VERSION ${CMAKE_PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

# generate config file
configure_file(${LIB_NAME}Config.cmake.in ${LIB_NAME}Config.cmake @ONLY)

install(FILES
            ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}ConfigVersion.cmake
        DESTINATION
            lib/cmake/libInstall)
