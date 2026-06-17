#include <cassert>
#include "packed_vector.hpp"

using namespace dtpu;

void test_packed_vector()
{
    PackedTritVector vec;

    vec.push_back(Trit::NEG);
    vec.push_back(Trit::ZERO);
    vec.push_back(Trit::POS);
    vec.push_back(Trit::NEG);
    vec.push_back(Trit::POS);

    assert(vec.size() == 5);

    assert(
        vec.get(0) == Trit::NEG
    );

    assert(
        vec.get(1) == Trit::ZERO
    );

    assert(
        vec.get(2) == Trit::POS
    );

    assert(
        vec.get(3) == Trit::NEG
    );

    assert(
        vec.get(4) == Trit::POS
    );

    PackedTritVector vec2(4);

    vec2.set(0, Trit::POS);
    vec2.set(1, Trit::NEG);
    vec2.set(2, Trit::ZERO);
    vec2.set(3, Trit::POS);

    assert(
        vec2.get(0) == Trit::POS
    );

    assert(
        vec2.get(1) == Trit::NEG
    );

    assert(
        vec2.get(2) == Trit::ZERO
    );

    assert(
        vec2.get(3) == Trit::POS
    );
}
