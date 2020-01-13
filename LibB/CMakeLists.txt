cmake_minimum_required(VERSION 3.10)
project(LibB VERSION 1.0.0 LANGUAGES CXX)

option(LIBB_TESTS "Should tests be build?" OFF)


# ----------------- Create library
set(LIB_NAMESPACE LibB)
set(LIB_NAME libB)

add_library(${LIB_NAME} src/LibB/libB.cpp)
target_include_directories(${LIB_NAME} PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_options(${LIB_NAME} INTERFACE -Werror -Wall -pedantic)


# ----------------- Install
include(GNUInstallDirs)

# copy includes
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# generate target target file
set(TARGET_FILE_NAME ${LIB_NAME}Targets)
install(TARGETS ${LIB_NAME}
        EXPORT ${TARGET_FILE_NAME}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(EXPORT ${LIB_NAME}Targets  NAMESPACE ${LIB_NAMESPACE}:: DESTINATION lib/cmake/${LIB_NAME})

# generate version config version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${LIB_NAME}ConfigVersion.cmake
        VERSION ${CMAKE_PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

# generate config file
configure_file(cmake/${LIB_NAME}Config.cmake.in ${LIB_NAME}Config.cmake @ONLY)

install(FILES
            ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}ConfigVersion.cmake
        DESTINATION
            lib/cmake/${LIB_NAME})

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(${LIB_NAMESPACE}::${LIB_NAME} ALIAS ${LIB_NAME})


# ----------------- Test
if (LIBB_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
