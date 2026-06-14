#pragma once

#include <cstdint>
#include "vector.hpp"

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
}