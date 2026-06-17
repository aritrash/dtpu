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

    PackedTritVector pa;
    PackedTritVector pb;

    pa.push_back(Trit::NEG);
    pa.push_back(Trit::ZERO);
    pa.push_back(Trit::POS);

    pb.push_back(Trit::POS);
    pb.push_back(Trit::POS);
    pb.push_back(Trit::POS);

    assert(
        dot_product(pa, pb) == 0
    );

    {
        TritVector a
        {
            Trit::NEG,
            Trit::POS,
            Trit::ZERO,
            Trit::NEG,
            Trit::POS
        };

        TritVector b
        {
            Trit::POS,
            Trit::NEG,
            Trit::POS,
            Trit::NEG,
            Trit::ZERO
        };

        PackedTritVector pc;
        PackedTritVector pd;

        for(std::size_t i = 0;
            i < a.size();
            ++i)
        {
            pc.push_back(a[i]);
            pd.push_back(b[i]);
        }

        assert(
            dot_product(a, b)
            ==
            dot_product(pc, pd)
        );
    }
}