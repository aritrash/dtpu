#include <cassert>
#include "worker.hpp"
#include "vector.hpp"

using namespace dtpu;

void test_worker()
{
    Worker worker;
    Packet request;

    request.header.opcode = Opcode::PING;
    request.header.request_id = 42;
    request.header.payload_length = 0;

    Packet response = worker.execute(request);

    assert(response.header.opcode == Opcode::PING);
    assert(response.header.request_id == 42);
    assert(response.payload.size() == 4);
    assert(response.payload[0] == 'P');
}

void test_worker_dot_product()
{
    Worker worker;
    Packet request;

    request.header.opcode = Opcode::DOT_PRODUCT;
    request.header.request_id = 1;

    request.payload =
    {
        3,
        0,

        static_cast<uint8_t>(Trit::NEG),
        static_cast<uint8_t>(Trit::ZERO),
        static_cast<uint8_t>(Trit::POS),

        static_cast<uint8_t>(Trit::POS),
        static_cast<uint8_t>(Trit::POS),
        static_cast<uint8_t>(Trit::POS)};

    request.header.payload_length = request.payload.size();

    Packet response = worker.execute(request);

    assert(response.header.opcode == Opcode::DOT_PRODUCT);
    assert(response.payload.size() == 4);
}