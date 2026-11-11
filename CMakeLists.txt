cmake_minimum_required(VERSION 3.14)
#include (CMakePrintSystemInformation)
#set(CMAKE_CONFIGURATION_TYPES Debug Release)

project(rindow-OpenBLAS-vclib VERSION 0.1.0 LANGUAGES CXX C)
#set(PROJECT_VERSION_MAJOR 0)
#set(PROJECT_VERSION_MINOR 1)
#set(PROJECT_VERSION_PATCH 0)

# OpenBLAS and OpenCL header directories
set(OPENBLAS_DIR "C:/OpenBLAS/OpenBLAS-0.3.33-x64" CACHE PATH "Path to OpenBLAS root directory")
set(OPENBLAS_INCLUDE_DIR "" CACHE PATH "Path to OpenBLAS include directory")

if(NOT OPENBLAS_INCLUDE_DIR)
    if(EXISTS "${OPENBLAS_DIR}/include")
        set(OPENBLAS_INCLUDE_DIR "${OPENBLAS_DIR}/include")
    else()
        set(OPENBLAS_INCLUDE_DIR "${OPENBLAS_DIR}")
    endif()
endif()

message(STATUS "OPENBLAS_DIR: ${OPENBLAS_DIR}")
message(STATUS "OPENBLAS_INCLUDE_DIR: ${OPENBLAS_INCLUDE_DIR}")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Packing)

add_subdirectory(./src)

## If you want to build the Release version, type the following command
#set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
    enable_testing()
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(./tests)
endif()

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CPACK_PACKAGING_INSTALL_PREFIX: ${CPACK_PACKAGING_INSTALL_PREFIX}")
message(STATUS "CPACK_COMPONENTS_ALL: ${CPACK_COMPONENTS_ALL}")
message(STATUS "CPACK_PACKAGE_VERSION: ${CPACK_PACKAGE_VERSION}")
