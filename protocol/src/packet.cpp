#include "packet.hpp"
#include <stdexcept>

namespace dtpu
{
    std::vector<uint8_t>
    serialize(
        const Packet& packet
    )
    {
        std::vector<uint8_t> bytes;

        bytes.reserve(
            7 +
            packet.payload.size()
        );

        //
        // Opcode
        //

        bytes.push_back(
            static_cast<uint8_t>(
                packet.header.opcode
            )
        );

        //
        // Payload Length
        //

        bytes.push_back(
            packet.header.payload_length
            & 0xFF
        );

        bytes.push_back(
            (
                packet.header.payload_length
                >> 8
            )
            & 0xFF
        );

        //
        // Request ID
        //

        bytes.push_back(
            packet.header.request_id
            & 0xFF
        );

        bytes.push_back(
            (
                packet.header.request_id
                >> 8
            )
            & 0xFF
        );

        bytes.push_back(
            (
                packet.header.request_id
                >> 16
            )
            & 0xFF
        );

        bytes.push_back(
            (
                packet.header.request_id
                >> 24
            )
            & 0xFF
        );

        //
        // Payload
        //

        bytes.insert(
            bytes.end(),
            packet.payload.begin(),
            packet.payload.end()
        );

        return bytes;
    }

    Packet deserialize(
        const std::vector<uint8_t>& bytes
    )
    {
        if(bytes.size() < 7)
        {
            throw std::runtime_error(
                "Packet too small"
            );
        }

        Packet packet;

        //
        // Opcode
        //

        packet.header.opcode =
            static_cast<Opcode>(
                bytes[0]
            );

        //
        // Payload Length
        //

        packet.header.payload_length =
            static_cast<uint16_t>(
                bytes[1]
            )
            |
            (
                static_cast<uint16_t>(
                    bytes[2]
                )
                << 8
            );

        //
        // Request ID
        //

        packet.header.request_id =
            static_cast<uint32_t>(
                bytes[3]
            )
            |
            (
                static_cast<uint32_t>(
                    bytes[4]
                )
                << 8
            )
            |
            (
                static_cast<uint32_t>(
                    bytes[5]
                )
                << 16
            )
            |
            (
                static_cast<uint32_t>(
                    bytes[6]
                )
                << 24
            );

        //
        // Size Check
        //

        if(
            bytes.size()
            !=
            7 +
            packet.header.payload_length
        )
        {
            throw std::runtime_error(
                "Payload mismatch"
            );
        }

        //
        // Copy Payload
        //

        packet.payload.assign(
            bytes.begin() + 7,
            bytes.end()
        );

        return packet;
    }
}