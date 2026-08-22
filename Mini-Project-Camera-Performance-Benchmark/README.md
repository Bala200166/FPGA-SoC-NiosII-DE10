# Mini Project - FPGA Camera Color Transformation

## Overview

FPGA/SoC mini-project using the **Nios II processor** on a **DE10 platform** to modify a live camera stream by remapping color channels:

- Red → Green
- Green → Blue
- Blue → Red

The project also compared different Nios II processor and build configurations using measured frame-processing performance.

> **Team coursework:** Completed as part of a three-member student team.

## Key Implementation

Camera pixels were separated into RGB components:

```c
unsigned char blue  =  curpix & 0x000000FF;
unsigned char green = (curpix & 0x0000FF00) >> 8;
unsigned char red   = (curpix & 0x00FF0000) >> 16;
```

The channels were then remapped:

```c
unsigned char new_red   = green;
unsigned char new_green = blue;
unsigned char new_blue  = red;

newpix = (new_red << 16) | (new_green << 8) | new_blue;
```

The transformed pixels were written back to the display frame buffer in real time.

## Performance Comparison

| Configuration | Reported Performance |
|---|---:|
| Nios II/e - Soft Debug Float | ~0.81 FPS |
| Nios II/e - Soft Debug Int | 0 FPS reported |
| Nios II/e - Soft Release Int | ~4 FPS |
| Nios II/e - IP Release | Integration unsuccessful |
| Nios II/f - Soft Release | ~12 FPS |
| Nios II/f - IP Release | ~7 FPS |

The best measured software result was approximately **12 FPS using Nios II/f in release mode**.

## Practical Skills Demonstrated

- Embedded C on Nios II
- FPGA hardware/software integration
- Camera and LCD interfacing
- Frame-buffer memory access
- RGB/BGR pixel manipulation
- Bitwise operations
- Performance-counter benchmarking
- Nios II/e vs Nios II/f comparison
- Platform Designer/Qsys

## Tools

**Intel Quartus Prime | Platform Designer/Qsys | Nios II | Embedded C | DE10 FPGA**

## Result

Successfully implemented and validated live color-channel transformation of the camera stream and measured the effect of processor/build configuration on processing performance.

## Project Files

- `Test_Project.c`
- `APP_CamParam.h`
- `Sys_Project.qsys`
- `DE10_PROJECT.qpf`
- `DE10_PROJECT.qsf`
