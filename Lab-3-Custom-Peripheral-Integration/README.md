# Lab 3 - Custom Peripheral Integration

## Overview

This laboratory focuses on the integration and control of a **custom Verilog peripheral** within an FPGA-based SoC system using the **Nios II soft-core processor** and the **Avalon bus** on a DE10 FPGA platform.

The work combines hardware design in Verilog with embedded C software to understand how a processor communicates with a custom memory-mapped peripheral.

This coursework was completed as part of a **three-member group assignment**.

---

## Objectives

- Understand the interface signals between a Nios II processor and a custom peripheral.
- Analyze Avalon bus read/write transactions.
- Implement a custom peripheral in Verilog.
- Access peripheral registers through memory-mapped addresses.
- Control FPGA LEDs from Nios II embedded C software.
- Observe internal bus and peripheral signals using SignalTap.
- Modify the hardware design and reintegrate the peripheral into the SoC system.

---

## Hardware and Software

- **FPGA platform:** DE10
- **Processor:** Nios II soft-core processor
- **HDL:** Verilog
- **Software:** Embedded C
- **FPGA development:** Intel Quartus Prime
- **System integration:** Platform Designer / Qsys
- **Bus:** Avalon
- **Debugging / signal analysis:** SignalTap Logic Analyzer

---

## Custom Peripheral Interface

The custom peripheral communicates with the Nios II processor through several Avalon-related signals.

### `Cpu_ChipSel`

Chip-select signal used to activate the custom peripheral when the processor addresses it.

### `Cpu_Write`

Write-enable signal indicating that the processor is performing a write operation.

### `Cpu_Addrs`

Address signal used to select the internal register of the custom peripheral.

### `Cpu_DataWr`

Data bus carrying the value written by the processor to the selected peripheral register.

---

## Avalon Bus Analysis

SignalTap was used to observe the communication between the Nios II processor and the custom peripheral.

The analysis included:

- chip-select activity
- write-enable activity
- address bus values
- write-data values
- timing of processor-to-peripheral transactions

This helped relate the embedded C memory accesses to the corresponding hardware-level Avalon bus activity.

---

## Memory-Mapped Peripheral Access

The custom peripheral contains internal registers mapped at different offsets from its base address.

For example:

```c
*(pled + 8) = 0xFF;
