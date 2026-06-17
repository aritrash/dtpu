#include <fstream>
#include <iostream>

#include "packet.hpp"
#include "worker.hpp"

using namespace dtpu;

int main()
{
    Worker worker;

    std::ifstream input(
        "request.bin",
        std::ios::binary
    );

    if(!input)
    {
        std::cerr
        << "request.bin missing\n";

        return 1;
    }

    std::vector<uint8_t> bytes;

    bytes.assign(
        std::istreambuf_iterator<char>(
            input
        ),
        std::istreambuf_iterator<char>()
    );

    Packet request =
        deserialize(
            bytes
        );

    Packet response =
        worker.execute(
            request
        );

    auto output =
        serialize(
            response
        );

    std::ofstream file(
        "response.bin",
        std::ios::binary
    );

    file.write(
        reinterpret_cast<const char*>(
            output.data()
        ),
        output.size()
    );

    file.close();

    std::cout
    << "response.bin written\n";

    return 0;
}