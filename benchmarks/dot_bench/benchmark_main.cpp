#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "benchmark_dot_product.hpp"

int main()
{
    //
    // Generate timestamp
    //
    auto now =
        std::chrono::system_clock::now();

    auto time =
        std::chrono::system_clock::to_time_t(now);

    std::tm local_time{};

#ifdef _WIN32
    localtime_s(&local_time, &time);
#else
    localtime_r(&time, &local_time);
#endif

    std::ostringstream timestamp_stream;

    timestamp_stream
        << std::put_time(
            &local_time,
            "%Y-%m-%d_%H-%M-%S"
        );

    //
    // Create timestamped filename
    //
    const std::string filename =
        "benchmark_results_"
        + timestamp_stream.str()
        + ".csv";

    //
    // Open CSV
    //
    std::ofstream csv(filename);

    if(!csv.is_open())
    {
        std::cerr
            << "Failed to create benchmark file.\n";

        return 1;
    }

    //
    // CSV Header
    //
    csv
        << "Size,"
        << "Implementation,"
        << "Iterations,"
        << "Average_us,"
        << "Total_us,"
        << "Throughput_TritsPerSec\n";

    std::cout
        << "=====================================\n"
        << " DTPU Runtime Benchmark Suite\n"
        << "=====================================\n";

    //
    // Small Benchmarks
    //
    std::cout
        << "[BENCH] 256 Trits\n";

    benchmark_dot_product(
        256,
        1000,
        csv
    );

    std::cout
        << "[BENCH] 1024 Trits\n";

    benchmark_dot_product(
        1024,
        1000,
        csv
    );

    std::cout
        << "[BENCH] 4096 Trits\n";

    benchmark_dot_product(
        4096,
        500,
        csv
    );

    //
    // Medium Benchmarks
    //
    std::cout
        << "[BENCH] 16384 Trits\n";

    benchmark_dot_product(
        16384,
        200,
        csv
    );

    std::cout
        << "[BENCH] 65536 Trits\n";

    benchmark_dot_product(
        65536,
        50,
        csv
    );

    //
    // Large Benchmarks
    //
    std::cout
        << "[BENCH] 262144 Trits\n";

    benchmark_dot_product(
        262144,
        10,
        csv
    );

    //
    // Very Large Benchmarks
    //
    std::cout
        << "[BENCH] 1 Mt (1,048,576 Trits)\n";

    benchmark_dot_product(
        1048576,
        5,
        csv
    );

    std::cout
        << "[BENCH] 10 Mt (10,485,760 Trits)\n";

    benchmark_dot_product(
        10485760,
        1,
        csv
    );

    csv.close();

    std::cout
        << "\nBenchmark completed.\n"
        << "Results saved to:\n"
        << filename
        << '\n';

    return 0;
}