#pragma once

#include <cstdint>
#include "vector.hpp"
#include "packed_vector.hpp"

namespace dtpu
{
    /**
     * Computes:
     *
     * Σ(Ai × Bi)
     */
    int32_t dot_product(
        const TritVector& a,
        const TritVector& b
    );

    int32_t dot_product(
        const PackedTritVector& a,
        const PackedTritVector& b
    );
}