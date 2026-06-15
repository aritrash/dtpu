#include <iostream>

#include "master.hpp"
#include "worker.hpp"
#include "packet.hpp"
#include "vector.hpp"

using namespace dtpu;

int main()
{
    Master master;

    Worker worker;

    TritVector a
    {
        Trit::NEG,
        Trit::ZERO,
        Trit::POS
    };

    TritVector b
    {
        Trit::POS,
        Trit::POS,
        Trit::POS
    };

    //
    // Master builds request
    //

    Packet request =
        master.make_dot_product(
            a,
            b
        );

    std::cout
        << "[MASTER] Created DOT_PRODUCT request\n";

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
        << "[WORKER] Executed DOT_PRODUCT\n";

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

    int32_t result =
        master.process_dot_product(
            master_response
        );

    std::cout
        << "[MASTER] Result = "
        << result
        << '\n';

    return 0;
}