#include <cassert>

#include "spi_transport.hpp"

using namespace dtpu;

void test_spi()
{
    SPITransport spi;

    std::vector<uint8_t> bytes {10, 20, 30};
    spi.send(bytes);

    auto received = spi.receive();
    assert(received == bytes);
    assert(spi.clock_hz() == 1000000);
}