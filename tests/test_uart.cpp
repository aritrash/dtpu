#include <cassert>

#include "uart_transport.hpp"

using namespace dtpu;

void test_uart()
{
    UARTTransport uart;

    std::vector<uint8_t> bytes {1, 2, 3};
    uart.send(bytes);

    auto received = uart.receive();

    assert(received == bytes);
    assert(uart.baud_rate() == 115200);
}