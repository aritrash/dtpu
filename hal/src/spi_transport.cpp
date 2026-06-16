#include "spi_transport.hpp"

namespace dtpu
{
    SPITransport::SPITransport(
        uint32_t clock_hz
    )
        :
        m_clock_hz(
            clock_hz
        )
    {
    }

    void SPITransport::send(
        const std::vector<uint8_t>& bytes
    )
    {
        m_buffer = bytes;
    }

    std::vector<uint8_t>
    SPITransport::receive()
    {
        return m_buffer;
    }

    uint32_t SPITransport::clock_hz() const
    {
        return m_clock_hz;
    }
}