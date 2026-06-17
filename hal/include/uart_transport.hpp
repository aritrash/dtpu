#pragma once

#include <vector>
#include <cstdint>

#include "transport.hpp"

namespace dtpu
{
    class UARTTransport : public ITransport
    {
    public:

        explicit UARTTransport(
            uint32_t baud_rate = 115200
        );

        void send(
            const std::vector<uint8_t>& bytes
        ) override;

        std::vector<uint8_t> receive() override;
        uint32_t baud_rate() const;

    private:
        uint32_t m_baud_rate;
        std::vector<uint8_t> m_buffer;
    };
}