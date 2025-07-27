cmake_minimum_required(VERSION 3.28.3)

project(DataStructures 
        VERSION 0.1.0
        LANGUAGES CXX
)

set(PROJECT_NAMESPACE "DataStructures")

option(ENABLE_STRICT_FLAGS "Enable strict compiler warnings" OFF)
option(BUILD_DOC "Build the documentation" OFF)

# Header-only library
add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

target_include_directories(${PROJECT_NAME}
        INTERFACE
                # Path for top-level project to look for the library's
                # public headers
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                # Path for external projects to look for the library's
                # public headers
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Allow cmake/ as a module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (BUILD_DOC)
        add_subdirectory(doc)
endif()

# Load strict warning flags
include(GCCWarnings)
include(ClangWarnings)
include(MSVCWarnings)

include(GNUInstallDirs)

# Install entire include directory
install(DIRECTORY include/ 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# RUNTIME, LIBRARY, ARCHIVE get default values from GNUInstallDirs
install(TARGETS ${PROJECT_NAME}
        EXPORT "${PROJECT_NAME}Targets"
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# Generate and install export file
install(EXPORT "${PROJECT_NAME}Targets"
        FILE "${PROJECT_NAME}Targets.cmake"
        NAMESPACE ${PROJECT_NAMESPACE}::
        DESTINATION cmake
)

include(CMakePackageConfigHelpers)
# Generatge the version file for the config file
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        VERSION "${version}"
        COMPATIBILITY AnyNewerVersion
)
# Create config file
configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION cmake
)
# Install config files
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION cmake
)

option(BUILD_TESTING "Build the tests" OFF)
# Enable CTest framework
include(CTest)

if(BUILD_TESTING)
        add_subdirectory(tests)
endif()
