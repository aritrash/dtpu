#include <cassert>

#include "master.hpp"

using namespace dtpu;

void test_master_ping()
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

void test_master_dot_product()
{
    Master master;

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

    Packet request =
        master.make_dot_product(
            a,
            b
        );

    assert(
        request.header.opcode
        ==
        Opcode::DOT_PRODUCT
    );

    assert(
        request.header.request_id
        ==
        1
    );

    assert(
        request.payload.size()
        ==
        7
    );

    //
    // Vector length
    //

    assert(
        request.payload[0]
        ==
        3
    );

    //
    // Vector A
    //

    assert(
        request.payload[1]
        ==
        static_cast<uint8_t>(
            Trit::NEG
        )
    );

    assert(
        request.payload[2]
        ==
        static_cast<uint8_t>(
            Trit::ZERO
        )
    );

    assert(
        request.payload[3]
        ==
        static_cast<uint8_t>(
            Trit::POS
        )
    );

    //
    // Vector B
    //

    assert(
        request.payload[4]
        ==
        static_cast<uint8_t>(
            Trit::POS
        )
    );

    assert(
        request.payload[5]
        ==
        static_cast<uint8_t>(
            Trit::POS
        )
    );

    assert(
        request.payload[6]
        ==
        static_cast<uint8_t>(
            Trit::POS
        )
    );
}