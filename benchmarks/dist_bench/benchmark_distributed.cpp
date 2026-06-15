#include "benchmark_distributed.hpp"
#include "master.hpp"
#include "worker.hpp"
#include "packet.hpp"
#include "vector.hpp"
#include "ops.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace dtpu;

void benchmark_distributed()
{
    std::filesystem::create_directories("../benchmarks/results/distributed");
    std::ofstream csv("../benchmarks/results/distributed/distributed_benchmark.csv");

    if(!csv)
    {
        throw std::runtime_error("Could not create distributed benchmark CSV");
    }

    csv << "Size,Direct_us,Distributed_us,Overhead_percent\n";
    Master master;
    Worker worker;
    std::vector<std::size_t>
    sizes
    {
        32,
        64,
        128,
        255,
        1024,
        4096,
        16384,
        32766
    };

    for(auto size : sizes)
    {
        TritVector a;
        TritVector b;

        int iterations;
        if(size <= 255) iterations = 5000;
        else if(size <= 1024) iterations = 2000;
        else if(size <= 4096) iterations = 500;
        else if(size <= 16384) iterations = 100;
        else iterations = 20;

        for(std::size_t i = 0; i < size; ++i)
        {
            a.push_back(Trit::POS);
            b.push_back(Trit::POS);
        }

        // Direct
        auto start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i)
        {
            auto result = dot_product(a, b);
            (void)result;
        }

        auto end = std::chrono::high_resolution_clock::now();
        double direct_us = std::chrono::duration<double,std::micro>(end - start).count()/iterations;

        // Distributed
        start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i)
        {
            Packet request = master.make_dot_product(a, b);
            auto wire = serialize(request);
            auto worker_request = deserialize(wire);
            auto worker_response = worker.execute(worker_request);
            auto return_wire = serialize(worker_response);
            auto master_response = deserialize(return_wire);
            auto result = master.process_dot_product(master_response);
            (void)result;
        }

        end = std::chrono::high_resolution_clock::now();
        double distributed_us = std::chrono::duration<double,std::micro>(end - start).count()/iterations;
        double overhead = ((distributed_us - direct_us) / direct_us) * 100.0;
        
        csv << size << "," << iterations << "," << direct_us << "," << distributed_us << "," << overhead << "\n";
        std::cout
        << "[DIST] "
        << size
        << " trits ("
        << iterations
        << " iterations)"
        << '\n';
    }
}