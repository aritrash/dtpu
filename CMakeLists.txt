cmake_minimum_required(VERSION 3.20)

project(DTPU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    dtpu
    src/main.cpp
    protocol/src/packet.cpp
    worker/src/worker.cpp
    master/src/master.cpp
    libtrit/src/trit.cpp
    libtrit/src/vector.cpp
    libtrit/src/ops.cpp
    libtrit/src/packed_vector.cpp
)

add_executable(
    dtpu_tests

    tests/test_main.cpp
    tests/test_trit.cpp
    tests/test_vector.cpp
    tests/test_ops.cpp
    tests/test_packedvector.cpp
    tests/test_packet.cpp
    tests/test_worker.cpp
    tests/test_master.cpp
    protocol/src/packet.cpp
    worker/src/worker.cpp
    master/src/master.cpp
    libtrit/src/trit.cpp
    libtrit/src/vector.cpp
    libtrit/src/ops.cpp
    libtrit/src/packed_vector.cpp
)

add_executable(
    dtpu_bench

    benchmarks/benchmark_main.cpp
    benchmarks/benchmark_dot_product.cpp
    protocol/src/packet.cpp
    worker/src/worker.cpp
    master/src/master.cpp
    libtrit/src/trit.cpp
    libtrit/src/vector.cpp
    libtrit/src/packed_vector.cpp
    libtrit/src/ops.cpp
)

target_include_directories(
    dtpu_tests
    PRIVATE
    ${CMAKE_SOURCE_DIR}/libtrit/include
    ${CMAKE_SOURCE_DIR}/protocol/include
    ${CMAKE_SOURCE_DIR}/worker/include
    ${CMAKE_SOURCE_DIR}/master/include
)

target_include_directories(
    dtpu_bench
    PRIVATE
    ${CMAKE_SOURCE_DIR}/libtrit/include
    ${CMAKE_SOURCE_DIR}/protocol/include
    ${CMAKE_SOURCE_DIR}/worker/include
    ${CMAKE_SOURCE_DIR}/master/include
    ${CMAKE_SOURCE_DIR}/benchmarks
)

target_include_directories(
    dtpu
    PRIVATE
    ${CMAKE_SOURCE_DIR}/libtrit/include
    ${CMAKE_SOURCE_DIR}/protocol/include
    ${CMAKE_SOURCE_DIR}/worker/include
    ${CMAKE_SOURCE_DIR}/master/include
)