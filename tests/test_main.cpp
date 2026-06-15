#include <iostream>

void test_trit();
void test_vector();
void test_ops();
void test_packed_vector();
void test_packet();
void test_worker();

int main()
{
    std::cout << "[TEST] Trit\n";
    test_trit();
    std::cout << "[PASS] Trit\n";

    std::cout << "[TEST] Vector\n";
    test_vector();
    std::cout << "[PASS] Vector\n";

    std::cout << "[TEST] Ops\n";
    test_ops();
    std::cout << "[PASS] Ops\n";

    std::cout << "[TEST] PackedTritVector\n";
    test_packed_vector();
    std::cout << "[PASS] PackedTritVector\n";

    std::cout << "[TEST] Packet\n";
    test_packet();
    std::cout << "[PASS] Packet\n";

    std::cout << "[TEST] Worker\n";
    test_worker();
    std::cout << "[PASS] Worker\n";

    std::cout << "\nAll tests passed.\n";

    return 0;
}