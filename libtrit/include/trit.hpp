#pragma once
#include <cstdint>

namespace dtpu
{
    enum class Trit: uint8_t
    {
        ZERO = 0b00,
        POS  = 0b01,
        NEG  = 0b10
    };

    int8_t to_int(Trit t);
    Trit from_int(int8_t value);
    bool is_valid(uint8_t raw);
    Trit trit_mul(Trit a, Trit b);
    int32_t trit_mac(Trit a, Trit b, int32_t acc);
}