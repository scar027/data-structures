# data-structures
Library containing documented implementations of internal workings of commonly used data structures.

The currently implemented data structures available in [include/data_structures/](./include/data_structures) are:
1. Dynamic Arrays.
1. Singly Linked Lists.
1. Doubly Linked Lists.
1. Stack.
1. Queue.
1. Circular Array.
1. Deque.

## Flags to be set while configuring the library
1. Use `--preset` to set your compiler for the build(GCC, Clang, MSVC).
1. `CMAKE_INSTALL_PREFIX` - Path where you want your library to be installed.
1. `ENABLE_STRICT_FLAGS` - To enable the strict warning flags from [GCCWarnings.cmake](./cmake/GCCWarnings.cmake), [ClangWarnings.cmake](./cmake/ClangWarnings.cmake) or [MSVCWarnings.cmake](./cmake/MSVCWarnings.cmake)
1. `CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=ON` for shared library Windows installation. Windows will require you to explicitly put the `.dll` either to the same folder where the executable is or somewhere in PATH.
1. `BUILD_TESTING=ON` to build the tests for the library.
1. `BUILD_DOC=ON` for building the documentation.

## Requirements to build the documentation
The documentation relies on Doxygen, Breathe and Sphinx.
1. Installation instructions for Doxygen and Sphinx can be found here:
    1. [Doxygen](https://www.doxygen.nl/manual/install.html)
    1. [Sphinx](https://www.sphinx-doc.org/en/master/usage/installation.html)
1. Breathe and the Read the Docs Sphinx Theme can be downloaded system-wide with the following command on Linux:
    ```bash
    sudo apt install python3-breathe python3-sphinx-rtd-theme python3-exhale
    ```
    You may also choose to create a virtual environment and use these packages instead.

## Configuring and generating the library
1. Follow these steps from the root directory of the library to configure the project.
    ```bash
    mkdir build
    cd build
    ```
2. To configure, run the following from the build directory with the appropriate compiler mentioned in the `--preset` flag:
    ```bash
    cmake --preset=gcc -DCMAKE_INSTALL_PREFIX="/path/to/install/directory" -DENABLE_STRICT_FLAGS=ON ..
    ```
    For Windows:
    ```bash
    cmake --preset=msvc -DCMAKE_INSTALL_PREFIX="C:/your/install/path" -DENABLE_STRICT_FLAGS=ON -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=ON ..
    ```
    **Note:** Add the `BUILD_DOC=ON` flag to the above to build the documentation and the `BUILD_TESTING=ON` for the tests.

## Building and installing the library
Follow these steps from the build directory:
```bash
cmake --build . --target install
```
This will build and install the library artifacts to the install path you specified earlier.

## Running tests
Tests can be built using the `BUILD_TESTING=ON` flag. To list the tests use `ctest -N`. To run the tests simply use:
```bash
ctest
```
Optionally you may use the `--output-on-failure` or `-V` flags to see all output from the tests.

## Linking the library through CMake in external projects
1. After installing the library as shown in the previous steps, you can simply link the library in your external project from the root `CMakeLists.txt` using:
    ```cmake
    find_package(DataStructures 0.1.0 CONFIG REQUIRED)
    ```
    and
    ```cmake
    target_link_libraries(${PROJECT_NAME}
            PRIVATE
                    DataStructures::DataStructures
    )
    ```
1. Set the `CMAKE_PREFIX_PATH` - Path to the directory where the library is installed while building your external project.

## Linking the library through CMake in internal projects
1. Copy the contents of this repository to `lib/data_structures` in the source tree of your internal project. 
    ```bash
    rsync -av path/to/cloned/data-structures/ lib/data_structures/
    ```
1. In the root `CMakeLists.txt`:
    ```cmake
    add_subdirectory(lib)
    ```
    and
    ```cmake
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
                DataStructures
    )
    ```
1. In `lib/CMakeLists.txt`:
    ```cmake
    add_subdirectory(data_structures)
    ```
1. Now you can configure/generate and build the project from the build directory:
    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```
    This will generate the required target by properly linking the library.

