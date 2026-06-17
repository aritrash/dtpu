#include "worker.hpp"
#include "vector.hpp"
#include "ops.hpp"
#include <stdexcept>

namespace dtpu
{
    Packet Worker::execute(const Packet& request)
    {
        Packet response;

        //
        // Echo request id
        //

        response.header.request_id = request.header.request_id;

        switch(request.header.opcode)
        {
            case Opcode::PING:
            {
                response.header.opcode = Opcode::PING;
                response.payload = {'P', 'O', 'N', 'G'};
                response.header.payload_length = static_cast<uint16_t>(response.payload.size());
                break;
            }

            case Opcode::DOT_PRODUCT:
            {
                if(request.payload.empty()) throw std::runtime_error("Empty payload");
                if(request.payload.size()< 2) throw std::runtime_error("Payload too small");
                uint16_t length = static_cast<uint16_t>(request.payload[0])|(static_cast<uint16_t>(request.payload[1])<< 8);
                std::size_t payload_size = static_cast<std::size_t>(length);
                if(request.payload.size() != 2 + (2 * payload_size)) throw std::runtime_error("Invalid payload size");

                TritVector a;
                TritVector b;

                //
                // Reconstruct A
                //

                for(std::size_t i = 0; i < payload_size; ++i)
                {
                    a.push_back(static_cast<Trit>(request.payload[2 + i]));
                }

                //
                // Reconstruct B
                //

                for(std::size_t i = 0; i < payload_size; ++i)
                {
                    b.push_back(static_cast<Trit>(request.payload[2 + length + i]));
                }

                int32_t result = dot_product(a,b);
                response.header.opcode = Opcode::DOT_PRODUCT;

                //
                // 4-byte int32 result
                //
                response.payload.clear();
                response.payload.push_back(result & 0xFF);
                response.payload.push_back((result >> 8)& 0xFF);
                response.payload.push_back((result >> 16)& 0xFF);
                response.payload.push_back((result >> 24)& 0xFF);
                response.header.payload_length = static_cast<uint16_t>(response.payload.size());
                break;
            }

            default:
            {
                response.header.opcode = Opcode::ERROR;
                response.payload = {'I', 'N', 'V', 'A', 'L', 'I', 'D'};
                response.header.payload_length = static_cast<uint16_t>(response.payload.size());
                break;
            }
        }
        return response;
    }

}