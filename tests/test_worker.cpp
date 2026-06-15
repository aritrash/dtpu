#include <cassert>
#include "worker.hpp"

using namespace dtpu;

void test_worker()
{
    Worker worker;

    Packet request;

    request.header.opcode =
        Opcode::PING;

    request.header.request_id =
        42;

    request.header.payload_length =
        0;

    Packet response =
        worker.execute(
            request
        );

    assert(
        response.header.opcode
        ==
        Opcode::PING
    );

    assert(
        response.header.request_id
        ==
        42
    );

    assert(
        response.payload.size()
        ==
        4
    );

    assert(
        response.payload[0]
        ==
        'P'
    );
}