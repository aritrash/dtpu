#include "worker.hpp"
#include <stdexcept>

namespace dtpu
{
    Packet Worker::execute(
        const Packet& request
    )
    {
        Packet response;

        //
        // Echo request id
        //

        response.header.request_id =
            request.header.request_id;

        switch(
            request.header.opcode
        )
        {
            case Opcode::PING:
            {
                response.header.opcode =
                    Opcode::PING;

                response.payload =
                {
                    'P',
                    'O',
                    'N',
                    'G'
                };

                response.header.payload_length =
                    static_cast<uint16_t>(
                        response.payload.size()
                    );

                break;
            }

            case Opcode::DOT_PRODUCT:
            {
                //
                // Placeholder for now
                //

                response.header.opcode =
                    Opcode::DOT_PRODUCT;

                response.payload =
                {
                    0
                };

                response.header.payload_length =
                    1;

                break;
            }

            default:
            {
                response.header.opcode =
                    Opcode::ERROR;

                response.payload =
                {
                    'I',
                    'N',
                    'V',
                    'A',
                    'L',
                    'I',
                    'D'
                };

                response.header.payload_length =
                    static_cast<uint16_t>(
                        response.payload.size()
                    );

                break;
            }
        }

        return response;
    }

}