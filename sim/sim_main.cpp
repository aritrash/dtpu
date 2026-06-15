#include <iostream>
#include "master.hpp"
#include "worker.hpp"
#include "packet.hpp"

using namespace dtpu;

int main()
{
    Master master;

    Worker worker;

    //
    // Build request
    //

    Packet request =
        master.make_ping();

    std::cout
        << "[MASTER] Created request "
        << request.header.request_id
        << '\n';

    //
    // Simulate wire
    //

    auto wire =
        serialize(
            request
        );

    std::cout
        << "[WIRE] "
        << wire.size()
        << " bytes sent\n";

    //
    // Worker receives
    //

    Packet worker_request =
        deserialize(
            wire
        );

    Packet worker_response =
        worker.execute(
            worker_request
        );

    std::cout
        << "[WORKER] Executed packet\n";

    //
    // Return wire
    //

    auto return_wire =
        serialize(
            worker_response
        );

    Packet master_response =
        deserialize(
            return_wire
        );

    bool success =
        master.process_ping(
            master_response
        );

    if(success)
    {
        std::cout
            << "[MASTER] PING SUCCESS\n";
    }
    else
    {
        std::cout
            << "[MASTER] PING FAILED\n";
    }

    return 0;
}