#include <cassert>
#include "master.hpp"

using namespace dtpu;

void test_master()
{
    Master master;

    Packet request =
        master.make_ping();

    assert(
        request.header.opcode
        ==
        Opcode::PING
    );

    assert(
        request.header.request_id
        ==
        1
    );

    Packet response;

    response.header.opcode =
        Opcode::PING;

    response.payload =
    {
        'P',
        'O',
        'N',
        'G'
    };

    assert(
        master.process_ping(
            response
        )
    );
}