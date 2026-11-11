file(GLOB_RECURSE srcfiles.vclib RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

if(MSVC)
    add_library(rindowopenblas.vclib STATIC ${srcfiles.vclib})
    set_target_properties(rindowopenblas.vclib PROPERTIES OUTPUT_NAME rindowopenblas)
    target_compile_options(rindowopenblas.vclib PRIVATE /Zl)
    target_include_directories(rindowopenblas.vclib PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
        "${CLBLAST_INCLUDE_DIR}"
        "${OPENCL_INCLUDE_DIR}"
    )
endif()

if(MSVC)
    install(
        TARGETS rindowopenblas.vclib
        ARCHIVE DESTINATION lib
        RENAME rindowopenblas.lib
        COMPONENT ${PROJECT_NAME}
    )
endif()
