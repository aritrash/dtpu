#include <stdexcept>
#include "master.hpp"

namespace dtpu
{
    Master::Master()
        :
        m_request_id(1)
    {
    }

    uint32_t
    Master::next_request_id()
    {
        return m_request_id++;
    }

    Packet
    Master::make_ping()
    {
        Packet request;

        request.header.opcode =
            Opcode::PING;

        request.header.payload_length =
            0;

        request.header.request_id =
            next_request_id();

        return request;
    }

    bool
    Master::process_ping(
        const Packet& response
    )
    {
        if(
            response.header.opcode
            !=
            Opcode::PING
        )
        {
            return false;
        }

        if(
            response.payload.size()
            !=
            4
        )
        {
            return false;
        }

        return
        (
            response.payload[0] == 'P'
            &&
            response.payload[1] == 'O'
            &&
            response.payload[2] == 'N'
            &&
            response.payload[3] == 'G'
        );
    }

    Packet
    Master::make_dot_product(
        const TritVector& a,
        const TritVector& b
    )
    {
        if(
            a.size()
            !=
            b.size()
        )
        {
            throw std::runtime_error(
                "Vector size mismatch"
            );
        }

        Packet request;

        request.header.opcode =
            Opcode::DOT_PRODUCT;

        request.header.request_id =
            next_request_id();

        //
        // Payload layout
        //
        // Byte 0
        // Vector length
        //
        // Then:
        // Vector A
        // Vector B
        //

        request.payload.push_back(
            static_cast<uint8_t>(
                a.size()
            )
        );

        for(
            std::size_t i = 0;
            i < a.size();
            ++i
        )
        {
            request.payload.push_back(
                static_cast<uint8_t>(
                    a[i]
                )
            );
        }

        for(
            std::size_t i = 0;
            i < b.size();
            ++i
        )
        {
            request.payload.push_back(
                static_cast<uint8_t>(
                    b[i]
                )
            );
        }

        request.header.payload_length =
            static_cast<uint16_t>(
                request.payload.size()
            );

        return request;
    }

    int32_t
    Master::process_dot_product(
        const Packet& response
    )
    {
        if(
            response.header.opcode
            !=
            Opcode::DOT_PRODUCT
        )
        {
            throw std::runtime_error(
                "Invalid response"
            );
        }

        if(
            response.payload.size()
            !=
            4
        )
        {
            throw std::runtime_error(
                "Invalid payload"
            );
        }

        int32_t result = 0;

        result |= response.payload[0];

        result |=
        (
            response.payload[1]
            << 8
        );

        result |=
        (
            response.payload[2]
            << 16
        );

        result |=
        (
            response.payload[3]
            << 24
        );

        return result;
    }
}