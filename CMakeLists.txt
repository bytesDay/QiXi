cmake_minimum_required(VERSION 2.6)
project (QiXi)

set (QiXi_VERSION_MAJOR 1)
set (QiXi_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/QiXiConfig.h.in"
    "${PROJECT_BINARY_DIR}/QiXiConfig.h"
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=${CMAKE_C_STANDARD} -Wall -lm")

include_directories("${PROJECT_BINARY_DIR}")

add_executable(QiXi qixi.c)
target_link_libraries(QiXi m)


