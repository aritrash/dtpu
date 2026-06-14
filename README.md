# DTPU

Distributed Trit Processing Unit

A distributed ternary inference accelerator architecture
designed for edge AI systems.

## Trit Encoding

| Trit | Binary |
|--------|--------|
| -1 | 10 |
| 0 | 00 |
| +1 | 01 |

11 is reserved as an invalid state.

## Current Status

- Trit arithmetic
- Trit vectors
- CMake build system

## Planned Features

- Dot product kernels
- Matrix operations
- Worker protocol
- UART transport
- SPI transport
- RP2350 hardware implementation