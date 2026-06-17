#pragma once

#include <cstdint>
#include <vector>

#include "opcode.hpp"

namespace dtpu
{
    struct PacketHeader
    {
        Opcode opcode;
        uint16_t payload_length;
        uint32_t request_id;
    };

    struct Packet
    {
        PacketHeader header;
        std::vector<uint8_t> payload;
    };

    std::vector<uint8_t>
    serialize(
        const Packet& packet
    );

    Packet deserialize(
        const std::vector<uint8_t>& bytes
    );

}