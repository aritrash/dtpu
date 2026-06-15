#include <cassert>
#include "packet.hpp"

using namespace dtpu;

void test_packet()
{
    Packet packet;

    packet.header.opcode =
        Opcode::DOT_PRODUCT;

    packet.header.payload_length =
        4;

    packet.header.request_id =
        123;

    packet.payload =
    {
        10,
        20,
        30,
        40
    };

    auto bytes =
        serialize(packet);

    Packet reconstructed =
        deserialize(bytes);

    assert(
        reconstructed.header.opcode
        ==
        Opcode::DOT_PRODUCT
    );

    assert(
        reconstructed.header.payload_length
        ==
        4
    );

    assert(
        reconstructed.header.request_id
        ==
        123
    );

    assert(
        reconstructed.payload
        ==
        packet.payload
    );
}