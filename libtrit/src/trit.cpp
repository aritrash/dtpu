#include "trit.hpp"
#include <stdexcept>

namespace dtpu
{
    int8_t to_int(Trit t)
    {
        switch (t)
        {
            case Trit::NEG:
                return -1;

            case Trit::ZERO:
                return 0;

            case Trit::POS:
                return 1;

            default:
                throw std::runtime_error("Invalid Trit value");
        }
    }

    Trit from_int(int8_t value)
    {
        switch (value)
        {
            case -1:
                return Trit::NEG;

            case 0:
                return Trit::ZERO;

            case 1:
                return Trit::POS;

            default:
                throw std::runtime_error(
                    "Value cannot be represented as a Trit"
                );
        }
    }

    bool is_valid(uint8_t raw)
    {
        return (
            raw == static_cast<uint8_t>(Trit::NEG)  ||
            raw == static_cast<uint8_t>(Trit::ZERO) ||
            raw == static_cast<uint8_t>(Trit::POS)
        );
    }

    Trit trit_mul(Trit a, Trit b)
    {
        const int8_t result =
            to_int(a) *
            to_int(b);

        return from_int(result);
    }

    int32_t trit_mac(
        Trit a,
        Trit b,
        int32_t acc
    )
    {
        return acc +
            (to_int(a) * to_int(b));
    }

}
