add_executable(openblas_vclib_test openblas_vclib_test.c)
target_link_libraries(openblas_vclib_test PRIVATE rindowopenblas.vclib)
target_include_directories(openblas_vclib_test PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
    "${OPENBLAS_INCLUDE_DIR}"
)

set(OPENBLAS_DLL "${OPENBLAS_DIR}/bin/libopenblas.dll")
if(NOT EXISTS "${OPENBLAS_DLL}")
    message(FATAL_ERROR "Cannot find OpenBLAS DLL: ${OPENBLAS_DLL}")
endif()
add_custom_command(TARGET openblas_vclib_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${OPENBLAS_DLL}" "$<TARGET_FILE_DIR:openblas_vclib_test>"
)
add_test(NAME openblas_vclib_test COMMAND openblas_vclib_test)
