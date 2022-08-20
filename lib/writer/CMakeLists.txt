cmake_minimum_required(VERSION 3.14)
project(writer)

add_library(${PROJECT_NAME} STATIC
    "include/writer.h"
    "src/writer.cpp")
    
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "include")