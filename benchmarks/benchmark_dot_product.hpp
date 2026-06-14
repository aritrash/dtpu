#pragma once

#include <cstddef>
#include <fstream>

void benchmark_dot_product(
    std::size_t vector_size,
    std::size_t iterations,
    std::ofstream& csv
);