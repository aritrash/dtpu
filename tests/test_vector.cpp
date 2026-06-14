#include <cassert>

#include "vector.hpp"

using namespace dtpu;

void test_vector()
{
    TritVector vec
    {
        Trit::NEG,
        Trit::ZERO,
        Trit::POS
    };

    assert(
        vec.size() == 3
    );

    assert(
        vec[0] == Trit::NEG
    );

    assert(
        vec[1] == Trit::ZERO
    );

    assert(
        vec[2] == Trit::POS
    );
}