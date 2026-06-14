#include "benchmark_dot_product.hpp"

#include <chrono>
#include <random>

#include "vector.hpp"
#include "packed_vector.hpp"
#include "ops.hpp"

using namespace dtpu;

namespace
{
    Trit random_trit(std::mt19937& rng)
    {
        std::uniform_int_distribution<int> dist(-1, 1);

        switch(dist(rng))
        {
            case -1:
                return Trit::NEG;

            case 0:
                return Trit::ZERO;

            case 1:
                return Trit::POS;

            default:
                return Trit::ZERO;
        }
    }
}

void benchmark_dot_product(
    std::size_t vector_size,
    std::size_t iterations,
    std::ofstream& csv
)
{
    std::mt19937 rng(42);

    TritVector a(vector_size);
    TritVector b(vector_size);

    PackedTritVector pa(vector_size);
    PackedTritVector pb(vector_size);

    //
    // Generate identical datasets
    //
    for(std::size_t i = 0; i < vector_size; ++i)
    {
        Trit ta = random_trit(rng);
        Trit tb = random_trit(rng);

        a[i] = ta;
        b[i] = tb;

        pa.set(i, ta);
        pb.set(i, tb);
    }

    volatile int32_t sink = 0;

    //
    // Unpacked Benchmark
    //
    auto unpacked_start =
        std::chrono::high_resolution_clock::now();

    for(std::size_t i = 0;
        i < iterations;
        ++i)
    {
        sink ^= dot_product(a, b);
    }

    auto unpacked_end =
        std::chrono::high_resolution_clock::now();

    //
    // Packed Benchmark
    //
    auto packed_start =
        std::chrono::high_resolution_clock::now();

    for(std::size_t i = 0;
        i < iterations;
        ++i)
    {
        sink ^= dot_product(pa, pb);
    }

    auto packed_end =
        std::chrono::high_resolution_clock::now();

    const auto unpacked_us =
        std::chrono::duration_cast<
            std::chrono::microseconds
        >(
            unpacked_end - unpacked_start
        ).count();

    const auto packed_us =
        std::chrono::duration_cast<
            std::chrono::microseconds
        >(
            packed_end - packed_start
        ).count();

    const double avg_unpacked =
        static_cast<double>(unpacked_us)
        / iterations;

    const double avg_packed =
        static_cast<double>(packed_us)
        / iterations;

    const double throughput_unpacked =
        static_cast<double>(
            vector_size * iterations
        )
        /
        (
            static_cast<double>(unpacked_us)
            / 1'000'000.0
        );

    const double throughput_packed =
        static_cast<double>(
            vector_size * iterations
        )
        /
        (
            static_cast<double>(packed_us)
            / 1'000'000.0
        );

    //
    // CSV Output
    //
    csv
        << vector_size << ","
        << "Unpacked" << ","
        << iterations << ","
        << avg_unpacked << ","
        << unpacked_us << ","
        << throughput_unpacked
        << '\n';

    csv
        << vector_size << ","
        << "Packed" << ","
        << iterations << ","
        << avg_packed << ","
        << packed_us << ","
        << throughput_packed
        << '\n';
}