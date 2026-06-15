# DTPU

> Distributed Ternary Processing Unit

![C++20](https://img.shields.io/badge/C%2B%2B-20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Distributed Runtime](https://img.shields.io/badge/Architecture-Distributed_Runtime-1D3557?style=for-the-badge&logo=serverfault&logoColor=white)
![Ternary Computing](https://img.shields.io/badge/Research-Ternary_Computing-6A1B9A?style=for-the-badge&logo=databricks&logoColor=white)
![Edge AI](https://img.shields.io/badge/Domain-Edge_AI-00897B?style=for-the-badge&logo=tensorflow&logoColor=white)
![Simulator First](https://img.shields.io/badge/Development-Simulator_First-2E7D32?style=for-the-badge&logo=qemu&logoColor=white)
![RP2350B Roadmap](https://img.shields.io/badge/Future-RP2350B_Migration-C62828?style=for-the-badge&logo=raspberrypi&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active_Development-F57C00?style=for-the-badge&logo=git&logoColor=white)

>
> A distributed AI inference accelerator architecture exploring ternary-encoded computation, memory density optimisation, and sustainable AI infrastructure using commodity hardware.

---

## Overview

DTPU is an ongoing research and engineering project focused on bridging the gap between resource-constrained edge devices and modern AI inference workloads.

The project investigates whether conventional binary silicon can emulate ternary computation to increase information density while maintaining acceptable computational overhead.

Instead of building a monolithic accelerator, DTPU adopts a distributed architecture consisting of orchestrator nodes and lightweight compute workers interconnected through a private network.

The long-term objective is to build a scalable, low-power AI inference infrastructure suitable for edge deployments, offline environments, and sustainable computing applications.

---

## Core Idea

Traditional systems store information in binary.

DTPU explores **ternary-encoded binary storage**, where a single trit is represented using two bits.

| Trit | Binary Encoding |
|------|----------------|
| -1 | 10 |
| 0 | 00 |
| +1 | 01 |
| Error State | 11 |

The unused `11` state is reserved for error detection.

This encoding allows significantly higher semantic information density while remaining compatible with conventional hardware.

---

## System Architecture

```text
                     Raspberry Pi Cluster

                             │
                   Network Orchestration
                             │

                ┌──────── Private Ethernet ────────┐

                             │

                    ESP8266 Master Node

                             │

                    Packet-Based Runtime

                             │

                      ESP32 Worker Node

                             │

                    Ternary Compute Engine
```

The software stack is intentionally hardware-agnostic.

Every layer is first validated inside a software simulator before deployment to physical hardware.

---

## Software Stack

```text
Compute Layer
=============

Trit
 ↓
Vector
 ↓
PackedTritVector
 ↓
Operations


Communication Layer
==================

Packet Protocol


Execution Layer
===============

Master
 ↓
Worker


Simulation Layer
================

Master
 ↓
Serialize
 ↓
Deserialize
 ↓
Worker
 ↓
Serialize
 ↓
Deserialize
 ↓
Master
```

---

## Current Features

### Compute Runtime

- Trit arithmetic
- Packed ternary storage
- Dot product kernels
- Packed dot product kernels

### Distributed Runtime

- Packet protocol
- Worker runtime
- Master runtime
- End-to-end simulation

### Development Infrastructure

- Unit testing framework
- Benchmarking suite
- Performance analysis tooling

---

## Benchmark Results

### Throughput Scaling

![Throughput Scaling](docs/throughput_scaling.png)

Observed host performance:

| Vector Size | Unpacked MTrit/s | Packed MTrit/s |
|------------|-----------------|----------------|
| 256 | 74.9 | 75.1 |
| 1K | 49.7 | 57.1 |
| 4K | 47.2 | 41.4 |
| 16K | 46.5 | 32.7 |
| 64K | 47.5 | 37.9 |
| 256K | 46.2 | 37.6 |
| 1M | 46.6 | 39.4 |
| 10M | 47.3 | 39.6 |

### Key Observation

Packed ternary storage achieves approximately **4× information density** while maintaining approximately **80–85% of the throughput** of the unpacked implementation for large workloads.

---

## Hardware Roadmap

### Rev 0 (Current)

- Raspberry Pi Cluster
- ESP8266 Master Nodes
- ESP32 Worker Nodes
- Ethernet Switch Backplane
- Software-first validation approach

### Rev 1 (Planned)

The project will progressively migrate towards a dedicated hardware implementation built around the Raspberry Pi RP2350B microcontroller.

Planned additions include:

- RP2350B Master Controllers
- RP2350B Compute Workers
- Dedicated SRAM Scratchpads
- High-density custom PCBs
- Modular accelerator boards

---

## Repository Structure

```text
libtrit/
├── include/
└── src/

protocol/
├── include/
└── src/

master/
├── include/
└── src/

worker/
├── include/
└── src/

benchmarks/

tests/

sim/

src/
```

---

## Development Philosophy

DTPU follows a simulator-first development model.

New features are developed and validated on a host machine before being deployed to embedded hardware.

This approach enables rapid iteration, reproducible testing, and significantly reduces hardware debugging overhead.

---

## Project Status

Active Development

Current Milestone:

###  v0.4 Milestones

- Expanded protocol support from 255 trits to 32766 trits
- Characterized protocol scalability limits
- Added distributed runtime benchmarking
- Added runtime scaling and overhead analysis

---

## Contributors

- Aritrash Sarkar 
- Ayush Jain

---

## License

To be decided.