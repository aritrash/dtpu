#include <iostream>
#include <fstream>
#include <vector>

#include "master.hpp"
#include "vector.hpp"
#include "packet.hpp"

using namespace dtpu;

int main()
{
    Master master;

    //
    // Check if response.bin exists
    //

    std::ifstream response_file(
        "response.bin",
        std::ios::binary
    );

    if(response_file)
    {
        std::vector<uint8_t> bytes;

        bytes.assign(
            std::istreambuf_iterator<char>(
                response_file
            ),
            std::istreambuf_iterator<char>()
        );

        Packet response =
            deserialize(
                bytes
            );

        auto result =
            master.process_dot_product(
                response
            );

        std::cout
        << "[HOST] Result = "
        << result
        << '\n';

        return 0;
    }

    //
    // Otherwise create request
    //

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

    Packet request =
        master.make_dot_product(
            a,
            b
        );

    auto bytes =
        serialize(
            request
        );

    std::cout
    << "[HOST] Created request\n";

    std::ofstream request_file(
        "request.bin",
        std::ios::binary
    );

    request_file.write(
        reinterpret_cast<const char*>(
            bytes.data()
        ),
        bytes.size()
    );

    request_file.close();

    std::cout
    << "[HOST] Wrote request.bin\n";

    return 0;
}