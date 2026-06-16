#include "sim_transport.hpp"

namespace dtpu
{
    void SimTransport::send(const std::vector<uint8_t>& bytes)
    {
        m_wire = bytes;
    }

    std::vector<uint8_t> SimTransport::receive()
    {
        return m_wire;
    }
}