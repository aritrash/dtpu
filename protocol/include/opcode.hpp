#pragma once

#include <cstdint>

namespace dtpu
{
    enum class Opcode : uint8_t
    {
        // System
        NOP   = 0x00,
        PING  = 0x01,
        ERROR = 0xFF,
        
        // Compute
        DOT_PRODUCT = 0x10,
        VECTOR_ADD  = 0x11,
        VECTOR_SUB  = 0x12,
        REDUCE_SUM  = 0x13
    };

}