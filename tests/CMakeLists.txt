set(OPENBLAS_DLL "${OPENBLAS_DIR}/bin/libopenblas.dll")
if(NOT EXISTS "${OPENBLAS_DLL}")
    message(FATAL_ERROR "Cannot find OpenBLAS DLL: ${OPENBLAS_DLL}")
endif()

foreach(test_target IN ITEMS openblas_vclib_test openblas_all_routines_test)
    if(test_target STREQUAL "openblas_vclib_test")
        add_executable(${test_target} openblas_vclib_test.c)
    else()
        add_executable(${test_target} openblas_all_routines_test.c)
    endif()
    target_link_libraries(${test_target} PRIVATE rindowopenblas.vclib)
    target_include_directories(${test_target} PRIVATE
        "${PROJECT_SOURCE_DIR}/src"
        "${OPENBLAS_INCLUDE_DIR}"
    )
    add_custom_command(TARGET ${test_target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${OPENBLAS_DLL}" "$<TARGET_FILE_DIR:${test_target}>"
    )
    add_test(NAME ${test_target} COMMAND ${test_target})
endforeach()
