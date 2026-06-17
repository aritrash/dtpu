#pragma once

#include <vector>
#include <cstdint>

namespace dtpu
{
    class ITransport
    {
    public:
        virtual ~ITransport() = default;
        virtual void send(const std::vector<uint8_t>& bytes) = 0;
        virtual std::vector<uint8_t> receive() = 0;
    };
}