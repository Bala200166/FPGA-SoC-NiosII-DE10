# Lab 1 - Nios II PIO and Performance Analysis

## Overview

FPGA/SoC laboratory using the **Nios II soft-core processor** on a **DE10 FPGA platform**, with hardware peripherals configured through **Intel Platform Designer/Qsys**.

The work focused on GPIO/PIO interfacing, memory-mapped hardware access from C, and comparing software execution with FPGA-based hardware acceleration.

> **Team coursework:** Completed as part of a three-member student team. The original report contains the names of all contributors.

## Work Completed

- Controlled FPGA LEDs from a Nios II C application.
- Read slide-switch inputs through Avalon PIO peripherals.
- Transferred switch values to LEDs using memory-mapped I/O.
- Configured PIO peripherals using Platform Designer/Qsys.
- Integrated arithmetic hardware into the FPGA-based SoC.
- Compared software and hardware multiplication/division.
- Measured execution cycles using hardware performance counters.
- Evaluated the impact of Nios II processor configurations and compiler optimization.

## Key Implementation

Memory-mapped Avalon PIO access was performed from C using operations such as:

```c
IOWR_ALTERA_AVALON_PIO_DATA(LEDPIO_BASE, 0xFF);

value = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE);
IOWR_ALTERA_AVALON_PIO_DATA(LEDPIO_BASE, value);
```

This allowed software running on the **Nios II processor** to directly interact with FPGA hardware peripherals.

## Performance Analysis

Software arithmetic operations were compared with hardware-assisted implementations.

Execution cycles were measured using performance counters to study:

- software vs. hardware multiplication
- software vs. hardware-assisted arithmetic
- processor configuration differences
- effect of compiler optimization

This introduced practical concepts of **hardware acceleration and hardware/software trade-offs**.

## Practical Skills Demonstrated

- Nios II embedded C programming
- FPGA hardware/software integration
- GPIO / PIO interfacing
- Avalon memory-mapped I/O
- Platform Designer / Qsys
- Hardware peripheral integration
- Execution-cycle measurement
- Hardware acceleration concepts

## Tools

**Intel Quartus Prime | Platform Designer/Qsys | Nios II | Avalon PIO | Embedded C | DE10 FPGA**

## Result

Successfully implemented processor-to-peripheral communication on the DE10 platform and compared software execution with dedicated FPGA hardware using measured performance data.

## Report

Full implementation details, code extracts, hardware configurations and experimental results are available here:

[Lab1_NiosII_PIO_Performance.pdf](Lab1_NiosII_PIO_Performance.pdf)
