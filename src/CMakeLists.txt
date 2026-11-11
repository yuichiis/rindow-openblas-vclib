file(GLOB wrapper_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_library(rindowopenblas.vclib STATIC ${wrapper_sources})
set_target_properties(rindowopenblas.vclib PROPERTIES OUTPUT_NAME rindowopenblas)

target_include_directories(rindowopenblas.vclib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${OPENBLAS_INCLUDE_DIR}"
)
target_compile_options(rindowopenblas.vclib PRIVATE /Zl)
