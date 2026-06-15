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
}