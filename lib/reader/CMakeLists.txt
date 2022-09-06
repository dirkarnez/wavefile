cmake_minimum_required(VERSION 3.14)
project(reader)

set(READER_PUBLIC_HEADERS
    ${PROJECT_SOURCE_DIR}/include/reader.h
)

add_library(${PROJECT_NAME} STATIC
    "${READER_PUBLIC_HEADERS}"
    "src/reader.cpp"
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${READER_PUBLIC_HEADERS}")

target_include_directories(${PROJECT_NAME}
    PUBLIC
    "include")

install(TARGETS ${PROJECT_NAME}
    ARCHIVE
    PUBLIC_HEADER
)