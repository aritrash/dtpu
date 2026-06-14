#include <cassert>
#include "ops.hpp"

using namespace dtpu;

void test_ops()
{
    TritVector a
    {
        Trit::NEG,
        Trit::ZERO,
        Trit::POS
    };

    TritVector b
    {
        Trit::POS,
        Trit::POS,
        Trit::POS
    };

    assert(
        dot_product(a, b) == 0
    );

    TritVector c
    {
        Trit::POS,
        Trit::POS,
        Trit::POS
    };

    TritVector d
    {
        Trit::POS,
        Trit::POS,
        Trit::POS
    };

    assert(
        dot_product(c, d) == 3
    );
}