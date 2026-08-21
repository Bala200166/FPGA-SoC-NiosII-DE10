# Lab 3 - Custom Peripheral Integration

## Overview

FPGA/SoC laboratory focused on communication between a **Nios II soft-core processor** and a **custom Verilog memory-mapped peripheral** through the Avalon interface on a DE10 FPGA platform.

The work combined embedded C, Verilog peripheral analysis, memory-mapped I/O and internal signal debugging with **Intel SignalTap**.

> **Team coursework:** Completed as part of a three-member student team. The original report contains the names of all contributors.

## Work Completed

- Analyzed the interface between Nios II and a custom Verilog peripheral.
- Studied Avalon control, address and write-data signals.
- Accessed peripheral registers from embedded C using memory-mapped addresses.
- Controlled FPGA LEDs through different peripheral register offsets.
- Observed processor-to-peripheral transactions using SignalTap.
- Related C memory accesses to corresponding hardware bus activity.
- Worked with the custom peripheral structure in Verilog.
- Studied the workflow for modifying the peripheral and reintegrating it through Platform Designer/Qsys.

## Custom Peripheral Interface

The peripheral communication involved signals including:

- `Cpu_ChipSel` — peripheral selection
- `Cpu_Write` — write control
- `Cpu_Addrs` — internal register/address selection
- `Cpu_DataWr` — processor write-data bus

SignalTap was used to observe these signals during processor accesses.

## Key Implementation

Peripheral registers were accessed from Nios II C using memory-mapped offsets.

Example:

```c
*(pled + 8) = 0xFF;
```

Multiple registers were accessed at different offsets:

```c
*(pled + 0)  = 0xFF;
*(pled + 4)  = 0xFF;
*(pled + 8)  = 0xFF;
*(pled + 12) = 0xFF;
```

The values were then changed to control the connected LEDs:

```c
*(pled + 0)  = 0x00;
*(pled + 4)  = 0x00;
*(pled + 8)  = 0x00;
*(pled + 12) = 0x00;
```

This demonstrated how software running on Nios II can directly control registers implemented inside FPGA hardware.

## SignalTap Analysis

SignalTap was used to verify the communication between the processor and peripheral by observing:

- chip-select activity
- write-enable activity
- address values
- write-data values
- timing of peripheral accesses

This connected the software-level C instructions with the corresponding hardware-level Avalon transactions.

## Hardware / Software Integration

The laboratory also covered the workflow around a custom Verilog peripheral:

1. work with the peripheral Verilog description
2. integrate/update the component in Platform Designer/Qsys
3. regenerate the FPGA SoC system
4. compile the Quartus design
5. program the DE10 platform
6. run the Nios II application
7. verify peripheral behaviour

## Practical Skills Demonstrated

- Nios II embedded C programming
- Verilog peripheral analysis
- FPGA hardware/software integration
- Avalon memory-mapped I/O
- Register and address-offset manipulation
- Custom peripheral interfacing
- Platform Designer / Qsys
- SignalTap debugging
- Bus and waveform analysis
- FPGA peripheral control

## Tools

**Intel Quartus Prime | Platform Designer/Qsys | Nios II | Verilog | Avalon | SignalTap | Embedded C | DE10 FPGA**

## Result

Successfully controlled custom peripheral registers from Nios II software and verified the corresponding processor-to-peripheral transactions using SignalTap.

The laboratory provided practical experience linking **embedded software, memory-mapped registers and custom FPGA hardware** within a Nios II-based SoC.

## Report

Full implementation details, Verilog/C code extracts, SignalTap captures and experimental results are available here:

`Lab-3-Custom-Peripheral-Integration.pdf`
