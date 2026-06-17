#include "vector.hpp"

namespace dtpu
{
    TritVector::TritVector()
    {
    }

    TritVector::TritVector(
        std::size_t size
    )
        : m_data(size, Trit::ZERO)
    {
    }

    TritVector::TritVector(
        std::initializer_list<Trit> values
    )
        : m_data(values)
    {
    }

    std::size_t TritVector::size() const
    {
        return m_data.size();
    }

    Trit& TritVector::operator[](
        std::size_t index
    )
    {
        return m_data[index];
    }

    const Trit& TritVector::operator[](
        std::size_t index
    ) const
    {
        return m_data[index];
    }

    void TritVector::push_back(
        Trit value
    )
    {
        m_data.push_back(value);
    }

    const std::vector<Trit>&
    TritVector::data() const
    {
        return m_data;
    }

} // namespace dtpu