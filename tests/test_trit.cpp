#include <cassert>

#include "trit.hpp"

using namespace dtpu;

void test_trit()
{
    assert(
        trit_mul(
            Trit::NEG,
            Trit::NEG
        ) == Trit::POS
    );

    assert(
        trit_mul(
            Trit::NEG,
            Trit::POS
        ) == Trit::NEG
    );

    assert(
        trit_mul(
            Trit::ZERO,
            Trit::POS
        ) == Trit::ZERO
    );

    assert(
        to_int(Trit::NEG) == -1
    );

    assert(
        to_int(Trit::ZERO) == 0
    );

    assert(
        to_int(Trit::POS) == 1
    );
}