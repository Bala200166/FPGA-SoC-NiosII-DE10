# Lab 5 - Image Processing and Performance Optimization

## Overview

FPGA/SoC laboratory using the **Nios II soft-core processor** on a **DE10 FPGA platform** for camera-based image processing, execution-time measurement and performance optimization.

The work combined embedded C image processing, fixed-point arithmetic, processor/compiler optimization and custom Verilog image-processing IP.

> **Team coursework:** Completed as part of a three-member student team. The original report contains the names of all contributors.

## Work Completed

- Acquired camera images and displayed them on the DE10 graphical screen.
- Copied image pixels between display regions using embedded C.
- Measured processing time using the Nios II hardware performance counter.
- Calculated execution cycles and image-processing throughput in images/second.
- Converted RGB pixels to grayscale using luminance calculations.
- Implemented contrast enhancement using minimum/maximum luminance normalization.
- Replaced floating-point grayscale coefficients with **Q8 fixed-point arithmetic**.
- Compared execution performance using **Nios II/e and Nios II/f** processor configurations.
- Evaluated compiler optimization using **`-O3`**.
- Worked with custom Verilog IP for grayscale conversion, contrast enhancement and spatial filtering.

## Key Software Implementation

The Nios II hardware performance counter was used to measure execution cycles:

```c
PERF_BEGIN(PERFCOUNTER_BASE, 1);

My_Copy();

PERF_END(PERFCOUNTER_BASE, 1);

counter = perf_get_section_time(
    (void *)PERFCOUNTER_BASE, 1
);
```

Image pixels were accessed directly through memory addresses:

```c
pix = *adpixin++;
npix = pix;
*adpixout++ = npix;
```

This provided a software baseline for measuring image-processing performance.

## Grayscale and Contrast Processing

RGB-to-grayscale conversion was studied using the luminance equation:

```text
Y = 0.299 × R + 0.587 × G + 0.114 × B
```

For faster integer processing, the coefficients were converted to **Q8 fixed-point values**:

```text
0.299 → 77
0.587 → 150
0.114 → 29
```

The resulting implementation uses:

```c
Y = (77 * R + 150 * G + 29 * B) >> 8;
```

Contrast enhancement was performed using min/max normalization:

```text
Ynew = ((Y - Ymin) / (Ymax - Ymin)) × 255
```

This demonstrated the replacement of floating-point image-processing operations with more efficient fixed-point arithmetic.

## Performance Optimization

Execution time was measured while changing processor and compiler configurations.

The laboratory demonstrated improvements through:

- floating-point to fixed-point conversion
- Nios II processor configuration
- hardware-supported multiplication
- processor pipelining
- compiler optimization with `-O3`

Measured results reported in the laboratory included approximately:

| Configuration | Execution cycles | Throughput |
|---|---:|---:|
| Nios II/e | ~45.0 million | ~1.1 images/s |
| Nios II/f | ~12.5 million | ~4.0 images/s |
| Nios II/f + `-O3` | ~9.8 million | ~5.1 images/s |

These measurements illustrate the effect of processor architecture and compiler optimization on embedded image-processing performance.

## Custom Verilog Image-Processing IP

The laboratory project also included custom Verilog modules for hardware-oriented pixel processing.

The examined IP included:

- CPU-accessible memory-mapped interfaces
- RGB pixel input handling
- Q8 grayscale conversion
- contrast normalization
- state-machine-based processing
- line buffers
- 3×3 spatial filtering

Example grayscale calculation used in the Verilog implementation:

```verilog
Y <= (77 * re + 150 * gr + 29 * bl) >> 8;
```

The work provided practical exposure to integrating image-processing functions into an FPGA-based Nios II SoC.

## Practical Skills Demonstrated

- Embedded C on Nios II
- FPGA hardware/software integration
- Camera and LCD interfacing
- Memory-based pixel processing
- Performance-counter benchmarking
- Execution-cycle analysis
- RGB-to-grayscale conversion
- Contrast enhancement
- Q8 fixed-point arithmetic
- Verilog image-processing IP
- State-machine-based hardware processing
- Spatial filtering concepts
- Nios II/e vs Nios II/f performance comparison
- Compiler optimization

## Tools

**Intel Quartus Prime | Platform Designer/Qsys | Nios II | Verilog | Embedded C | DE10 FPGA | Performance Counter**

## Result

Successfully implemented and benchmarked camera-based image-processing operations on a Nios II FPGA platform.

Software and processor optimizations reduced the measured execution time from approximately **45 million cycles to 9.8 million cycles**, with reported throughput increasing from approximately **1.1 to 5.1 images/second**.

The laboratory also provided experience with custom Verilog image-processing IP for fixed-point grayscale, contrast and spatial filtering operations.

## Report

Full implementation details, source-code extracts, hardware results and performance measurements are available here:

`Lab-5-Image-Processing-Performance-Optimization.pdf`
