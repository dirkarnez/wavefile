cmake_minimum_required(VERSION 3.14)
project(reader)


add_library(${PROJECT_NAME} STATIC
    "${READER_PUBLIC_HEADERS}"
    "src/reader.cpp"
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    "include")