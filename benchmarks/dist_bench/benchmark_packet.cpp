#include "benchmark_packet.hpp"

#include "packet.hpp"

#include <filesystem>
#include <chrono>
#include <fstream>
#include <iostream>

using namespace dtpu;

void benchmark_packet()
{
    std::filesystem::create_directories(
        "../benchmarks/results/distributed"
    );

    std::ofstream csv(
        "../benchmarks/results/distributed/packet_benchmark.csv"
    );

    if(!csv)
    {
        throw std::runtime_error(
            "Could not create packet benchmark CSV"
        );
    }

    csv
    << "PayloadSize,Serialize_us,Deserialize_us\n";

    std::vector<std::size_t>
    payload_sizes
    {
        3,
        32,
        64,
        128,
        255
    };

    constexpr int iterations =
        10000;

    for(
        auto size :
        payload_sizes
    )
    {
        Packet packet;

        packet.header.opcode =
            Opcode::PING;

        packet.header.request_id =
            1;

        packet.payload.assign(
            size,
            42
        );

        packet.header.payload_length =
            static_cast<uint16_t>(
                packet.payload.size()
            );

        //
        // Serialize
        //

        auto start =
            std::chrono::high_resolution_clock::now();

        for(
            int i = 0;
            i < iterations;
            ++i
        )
        {
            auto bytes =
                serialize(
                    packet
                );

            (void)bytes;
        }

        auto end =
            std::chrono::high_resolution_clock::now();

        double serialize_us =
            std::chrono::duration<double,std::micro>(
                end - start
            ).count()
            /
            iterations;

        //
        // Deserialize
        //

        auto bytes =
            serialize(
                packet
            );

        start =
            std::chrono::high_resolution_clock::now();

        for(
            int i = 0;
            i < iterations;
            ++i
        )
        {
            auto reconstructed =
                deserialize(
                    bytes
                );

            (void)reconstructed;
        }

        end =
            std::chrono::high_resolution_clock::now();

        double deserialize_us =
            std::chrono::duration<double,std::micro>(
                end - start
            ).count()
            /
            iterations;

        csv
        << size
        << ","
        << serialize_us
        << ","
        << deserialize_us
        << "\n";

        std::cout
        << "[PACKET] "
        << size
        << '\n';
    }
}