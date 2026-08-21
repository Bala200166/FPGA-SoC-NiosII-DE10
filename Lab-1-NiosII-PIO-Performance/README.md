# Lab 1 – Nios II PIO and Performance Analysis

Coursework completed as part of the **Electronic Microsystems** module.

> **Team coursework:** This laboratory was completed as part of a three-member student team. The original report contains the names of all contributors.

## Overview

This laboratory focused on hardware/software interaction on an FPGA-based SoC using the **Nios II soft-core processor** on a **DE10 FPGA platform**.

The work involved configuring peripherals in **Intel Platform Designer/Qsys**, accessing hardware from C through memory-mapped I/O, controlling LEDs and switches, integrating arithmetic hardware, and measuring execution performance.

## Main Activities

### GPIO / PIO Interfacing

- Controlled FPGA LEDs from a Nios II C application.
- Modified software delay values to observe different LED blinking periods.
- Worked with FPGA slide switches through a 4-bit PIO input.
- Read switch states from software and copied the corresponding values to the LEDs.
- Used Altera Avalon PIO access macros for memory-mapped peripheral communication.

Example operations used during the laboratory:

```c
IOWR_ALTERA_AVALON_PIO_DATA(LEDPIO_BASE, 0xFF);
IOWR_ALTERA_AVALON_PIO_DATA(LEDPIO_BASE, 0x00);

value = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE);
IOWR_ALTERA_AVALON_PIO_DATA(LEDPIO_BASE, value);
