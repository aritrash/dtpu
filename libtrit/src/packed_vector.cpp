#include "packed_vector.hpp"
#include <stdexcept>

namespace dtpu
{
    PackedTritVector::PackedTritVector()
        : m_size(0)
    {
    }

    PackedTritVector::PackedTritVector(
        std::size_t size
    )
        : m_size(size)
    {
        const std::size_t bytes =
            (size + 3) / 4;

        m_data.resize(bytes, 0);
    }

    std::size_t
    PackedTritVector::size() const
    {
        return m_size;
    }

    Trit PackedTritVector::get(
        std::size_t index
    ) const
    {
        if(index >= m_size)
        {
            throw std::out_of_range(
                "PackedTritVector::get"
            );
        }

        const std::size_t byte_index =
            index / 4;

        const std::size_t offset =
            (index % 4) * 2;

        const uint8_t raw =
            (m_data[byte_index] >> offset)
            & 0b11;

        switch(raw)
        {
            case 0b00:
                return Trit::ZERO;

            case 0b01:
                return Trit::POS;

            case 0b10:
                return Trit::NEG;

            default:
                throw std::runtime_error(
                    "Invalid Trit encoding"
                );
        }
    }

    void PackedTritVector::set(
        std::size_t index,
        Trit value
    )
    {
        if(index >= m_size)
        {
            throw std::out_of_range(
                "PackedTritVector::set"
            );
        }

        const std::size_t byte_index =
            index / 4;

        const std::size_t offset =
            (index % 4) * 2;

        m_data[byte_index] &=
            ~(0b11 << offset);

        m_data[byte_index] |=
            (
                static_cast<uint8_t>(value)
                << offset
            );
    }

    void PackedTritVector::push_back(
        Trit value
    )
    {
        if((m_size % 4) == 0)
        {
            m_data.push_back(0);
        }

        const std::size_t index =
            m_size;

        ++m_size;

        set(index, value);
    }

    const std::vector<uint8_t>&
    PackedTritVector::raw_data() const
    {
        return m_data;
    }

} // namespace dtpu