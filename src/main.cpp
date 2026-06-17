#include <iostream>

#include "vector.hpp"

using namespace dtpu;

int main()
{
    TritVector vec
    {
        Trit::NEG,
        Trit::ZERO,
        Trit::POS
    };

    for(std::size_t i = 0;
        i < vec.size();
        ++i)
    {
        std::cout
            << static_cast<int>(
                to_int(vec[i])
            )
            << ' ';
    }

    std::cout << '\n';

    return 0;
}