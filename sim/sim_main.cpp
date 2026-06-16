#include <iostream>

#include "master.hpp"
#include "worker.hpp"
#include "vector.hpp"
#include "packet.hpp"
#include "sim_transport.hpp"

using namespace dtpu;

int main()
{
    Master master;
    Worker worker;
    SimTransport transport;

    TritVector a {Trit::NEG, Trit::ZERO, Trit::POS};
    TritVector b{Trit::POS, Trit::POS, Trit::POS};

    Packet request = master.make_dot_product(a, b);
    std::cout << "[MASTER] Created DOT_PRODUCT request\n";

    auto outbound = serialize(request);
    transport.send(outbound);
    auto worker_request = deserialize(transport.receive());
    std::cout << "[WIRE] " << outbound.size() << " bytes sent\n";

    Packet worker_response = worker.execute(worker_request);
    std::cout << "[WORKER] Executed DOT_PRODUCT\n";

    auto inbound = serialize(worker_response);
    transport.send(inbound);
    auto master_response = deserialize(transport.receive());
    auto result = master.process_dot_product(master_response);
    std::cout << "[MASTER] Result = " << result << '\n';

    return 0;
}