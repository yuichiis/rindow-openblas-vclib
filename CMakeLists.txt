cmake_minimum_required(VERSION 3.14)

project(rindow-openblas-vclib VERSION 0.1.0 LANGUAGES C)

set(OPENBLAS_DIR "C:/OpenBLAS/OpenBLAS-0.3.33-x64" CACHE PATH "OpenBLAS SDK directory")
if(EXISTS "${OPENBLAS_DIR}/include/cblas.h")
    set(OPENBLAS_INCLUDE_DIR "${OPENBLAS_DIR}/include")
elseif(EXISTS "${OPENBLAS_DIR}/cblas.h")
    set(OPENBLAS_INCLUDE_DIR "${OPENBLAS_DIR}")
else()
    message(FATAL_ERROR "Cannot find cblas.h under OPENBLAS_DIR=${OPENBLAS_DIR}")
endif()

if(NOT WIN32 OR NOT MSVC)
    message(FATAL_ERROR "This project builds the Windows MSVC DLL wrapper library")
endif()

add_subdirectory(src)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

install(TARGETS rindowopenblas.vclib ARCHIVE DESTINATION lib)
install(FILES src/vclib.h DESTINATION include)
