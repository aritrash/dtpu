#pragma once

#include <vector>
#include <cstdint>

#include "transport.hpp"

namespace dtpu
{
    class SimTransport : public ITransport
    {
    public:
        void send(const std::vector<uint8_t>& bytes) override;
        std::vector<uint8_t> receive() override;

    private:
        std::vector<uint8_t> m_wire;
    };
}