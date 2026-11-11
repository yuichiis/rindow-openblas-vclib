set(OPENBLAS_DLL "${OPENBLAS_DIR}/bin/libopenblas.dll")
if(NOT EXISTS "${OPENBLAS_DLL}")
    message(FATAL_ERROR "Cannot find OpenBLAS DLL: ${OPENBLAS_DLL}")
endif()

add_executable(openblas_tests openblas_all_routines_test.cpp)
target_link_libraries(openblas_tests PRIVATE
    rindowopenblas.vclib
    GTest::gtest_main
)
target_include_directories(openblas_tests PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
    "${OPENBLAS_INCLUDE_DIR}"
)
target_compile_options(openblas_tests PRIVATE /EHsc)
add_custom_command(TARGET openblas_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${OPENBLAS_DLL}" "$<TARGET_FILE_DIR:openblas_tests>"
)

include(GoogleTest)
gtest_discover_tests(openblas_tests)
