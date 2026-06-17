#include "uart_transport.hpp"

namespace dtpu
{
    UARTTransport::UARTTransport(
        uint32_t baud_rate
    )
        :
        m_baud_rate(
            baud_rate
        )
    {
    }

    void UARTTransport::send(
        const std::vector<uint8_t>& bytes
    )
    {
        m_buffer = bytes;
    }

    std::vector<uint8_t>
    UARTTransport::receive()
    {
        return m_buffer;
    }

    uint32_t UARTTransport::baud_rate() const
    {
        return m_baud_rate;
    }
}