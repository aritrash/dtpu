#pragma once
#include "packet.hpp"

namespace dtpu
{
    class Worker
    {
    public:

        Packet execute(
            const Packet& request
        );
    };
}