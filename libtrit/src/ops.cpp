#include "ops.hpp"
#include <stdexcept>
#include "trit.hpp"

namespace dtpu
{
    int32_t dot_product(
        const TritVector& a,
        const TritVector& b
    )
    {
        if(a.size() != b.size())
        {
            throw std::invalid_argument(
                "Vector sizes must match"
            );
        }

        int32_t accumulator = 0;

        for(std::size_t i = 0;
            i < a.size();
            ++i)
        {
            accumulator =
                trit_mac(
                    a[i],
                    b[i],
                    accumulator
                );
        }

        return accumulator;
    }

    int32_t dot_product(
        const PackedTritVector& a,
        const PackedTritVector& b
    )
    {
        if(a.size() != b.size())
        {
            throw std::invalid_argument(
                "Vector sizes must match"
            );
        }

        int32_t accumulator = 0;

        for(std::size_t i = 0;
            i < a.size();
            ++i)
        {
            accumulator =
                trit_mac(
                    a.get(i),
                    b.get(i),
                    accumulator
                );
        }

        return accumulator;
    }

} // namespace dtpu
