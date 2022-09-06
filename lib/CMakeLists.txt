cmake_minimum_required(VERSION 3.14)
project(lib)

add_subdirectory(reader)
add_subdirectory(writer)

set(WAVEFILE_LIB "wavefile_lib")

set(WAVEFILE_LIB_PUBLIC_HEADERS
    ${PROJECT_SOURCE_DIR}/reader/include/reader.h
    ${PROJECT_SOURCE_DIR}/writer/include/writer.h
)

add_library(${WAVEFILE_LIB} STATIC
    "${WAVEFILE_LIB_PUBLIC_HEADERS}"
    ${PROJECT_SOURCE_DIR}/reader/src/reader.cpp
    ${PROJECT_SOURCE_DIR}/writer/src/writer.cpp
)

set_target_properties(${WAVEFILE_LIB} PROPERTIES PUBLIC_HEADER "${WAVEFILE_LIB_PUBLIC_HEADERS}")

target_include_directories(${WAVEFILE_LIB}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/reader/include
    ${PROJECT_SOURCE_DIR}/writer/include
)

install(TARGETS ${WAVEFILE_LIB}
    ARCHIVE
    PUBLIC_HEADER
)