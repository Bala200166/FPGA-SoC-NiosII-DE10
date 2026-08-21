# Lab 2 - Avalon Bus and SignalTap Analysis

## Overview

This laboratory focuses on FPGA-based SoC communication using the **Nios II soft-core processor** and the **Avalon bus** on a DE10 FPGA platform.

The work covers the integration of a custom memory-mapped component, analysis of Avalon bus transactions, and observation of internal FPGA signals using **Intel SignalTap Logic Analyzer**.

This coursework was completed as part of a three-member group assignment.

## Objectives

- Understand communication between the Nios II processor and FPGA peripherals.
- Configure components using Intel Platform Designer/Qsys.
- Work with memory-mapped peripherals and address spaces.
- Perform memory read and write operations from C.
- Observe Avalon bus transactions inside the FPGA.
- Configure SignalTap triggers and capture internal signals.
- Analyze address, data, control and memory-interface waveforms.

## FPGA / SoC Architecture

The implemented system includes:

- Nios II soft-core processor
- System clock and reset
- On-chip memory
- JTAG UART
- Custom memory-mapped IP (`TST_IP`)
- Avalon memory-mapped interconnect
- SignalTap Logic Analyzer

Platform Designer/Qsys was used to configure the system architecture and connect the processor, memory and peripherals through the Avalon bus.

## Memory-Mapped I/O

The lab explores access to FPGA peripherals through memory-mapped addresses.

Example operations include:

- reading values from a hardware memory location;
- writing hexadecimal values to specific offsets;
- writing sequences of data to successive addresses;
- observing the resulting Avalon bus activity.

Example concept:

```c
pTable = (int*)TST_IP_BASE;
*(pTable + 56) = 0xAA55AA55;
