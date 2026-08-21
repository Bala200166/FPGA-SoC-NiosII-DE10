# Lab 4 - LCD Graphics and Image Processing

## Overview

FPGA/SoC laboratory using the **Nios II soft-core processor** on a **DE10 platform** to control a graphical LCD from embedded C.

This coursework was completed as part of a **three-member group assignment**.

## Work Completed

- Controlled LCD pixels using X/Y coordinates and encoded colour values.
- Generated graphical regions using nested `for` loops.
- Displayed a French tricolour flag by dividing a pixel region into three vertical sections.
- Generated coloured regions with different intensity levels.
- Displayed a stored Lena image on the DE10 LCD.
- Manipulated RGB/BGR pixel data using bitwise operations.
- Studied brightness/contrast adjustment and RGB-to-grayscale conversion.

## Key Implementation

Individual pixels were written using:

```c
DE10Affi_WritPixel(x, y, color);
```

The LCD uses a packed colour format:

```text
0x00BBGGRR
```

Example pixel reconstruction:

```c
color = (blue << 16) | (green << 8) | red;
```

RGB-to-grayscale conversion studied in the laboratory:

```text
Gray = 0.299 × R + 0.587 × G + 0.114 × B
```

## Practical Skills Demonstrated

- Embedded C on Nios II
- FPGA hardware/software integration
- LCD interfacing
- Pixel-level graphics programming
- RGB/BGR colour manipulation
- Bitwise operations
- Basic embedded image processing

## Tools

**Intel Quartus Prime | Nios II | DE10 FPGA | C**

## Results

Successfully implemented pixel-level graphical output, colour patterns, French flag rendering, intensity variation and image display on the DE10 LCD.

Screenshots, source-code extracts and hardware results are provided in the laboratory report.

## Report

`Lab-4-LCD-Graphics-Image-Processing.pdf`
