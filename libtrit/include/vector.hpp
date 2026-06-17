#pragma once

#include <cstddef>
#include <vector>

#include "trit.hpp"

namespace dtpu
{
    class TritVector
    {
    private:
        std::vector<Trit> m_data;

    public:
        TritVector();

        explicit TritVector(std::size_t size);

        TritVector(
            std::initializer_list<Trit> values
        );

        std::size_t size() const;

        Trit& operator[](
            std::size_t index
        );

        const Trit& operator[](
            std::size_t index
        ) const;

        void push_back(Trit value);

        const std::vector<Trit>& data() const;
    };

} 