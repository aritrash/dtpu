#pragma once

#include <vector>
#include <cstdint>

#include "transport.hpp"

namespace dtpu
{
    class SPITransport : public ITransport
    {
    public:
        explicit SPITransport(
            uint32_t clock_hz = 1000000
        );

        void send(
            const std::vector<uint8_t>& bytes
        ) override;

        std::vector<uint8_t> receive() override;
        uint32_t clock_hz() const;

    private:
        uint32_t m_clock_hz;
        std::vector<uint8_t> m_buffer;
    };
}