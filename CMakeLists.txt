cmake_minimum_required(VERSION 3.20)

project(DTPU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    dtpu
    src/main.cpp
    libtrit/src/trit.cpp
    libtrit/src/vector.cpp
)

target_include_directories(
    dtpu
    PRIVATE
    ${CMAKE_SOURCE_DIR}/libtrit/include
)