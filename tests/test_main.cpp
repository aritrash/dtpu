#include <iostream>

void test_trit();
void test_vector();
void test_ops();
void test_packed_vector();
void test_packet();
void test_worker();
void test_worker_dot_product();
void test_master_ping();
void test_master_dot_product();

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

    std::cout << "[TEST] Worker Dot Product\n";
    test_worker_dot_product();
    std::cout << "[PASS] Worker Dot Product\n";

    std::cout << "[TEST] Master\n";
    test_master_ping();
    std::cout << "[PASS] Master\n";

    std::cout << "[TEST] Master Dot Product\n";
    test_master_dot_product();
    std::cout << "[PASS] Master Dot Product\n";

    std::cout << "\nAll tests passed.\n";

    return 0;
}