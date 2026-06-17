#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "trit.hpp"

namespace dtpu
{
    class PackedTritVector
    {
    private:
        std::vector<uint8_t> m_data;
        std::size_t m_size;

    public:
        PackedTritVector();

        explicit PackedTritVector(
            std::size_t size
        );

        std::size_t size() const;

        Trit get(
            std::size_t index
        ) const;

        void set(
            std::size_t index,
            Trit value
        );

        void push_back(
            Trit value
        );

        const std::vector<uint8_t>&
        raw_data() const;
    };

} // namespace dtpu