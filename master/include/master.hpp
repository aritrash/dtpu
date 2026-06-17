#pragma once

#include <cstdint>
#include "packet.hpp"
#include "vector.hpp"

namespace dtpu
{
    class Master
    {
    private:
        uint32_t m_request_id;

    public:
        Master();
        Packet make_ping();
        bool process_ping(
            const Packet& response
        );

        uint32_t next_request_id();

        Packet make_dot_product(
            const TritVector& a,
            const TritVector& b
        );

        int32_t process_dot_product(
            const Packet& response
        );
    };
}