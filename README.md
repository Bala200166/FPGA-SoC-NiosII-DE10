# FPGA & SoC Development - Nios II / DE10

FPGA and embedded-SoC coursework completed as part of the **Electronic Microsystems (IE.2409)** module.

The repository covers practical work with **Intel Quartus Prime, Nios II, Platform Designer/Qsys, Avalon memory-mapped interfaces, Verilog, SignalTap and embedded C** on DE10 FPGA platforms.

## Repository Contents

| Work | Main Topics |
|---|---|
| [Lab 1 - Nios II PIO and Performance](./Lab-1-NiosII-PIO-Performance/) | GPIO/PIO, LEDs, switches, memory-mapped I/O, execution-performance analysis |
| [Lab 2 - Avalon Bus and SignalTap](./Lab-2-Avalon-Bus-SignalTap/) | Avalon bus, custom memory-mapped IP, SignalTap, internal FPGA signal analysis |
| [Lab 3 - Custom Peripheral Integration](./Lab-3-Custom-Peripheral-Integration/) | Verilog peripheral, Nios II integration, register addressing, hardware/software communication |
| [Lab 4 - LCD Graphics and Image Processing](./Lab-4-LCD-Graphics-Image-Processing/) | LCD interfacing, pixel-level graphics, RGB/BGR manipulation, image display |
| [Lab 5 - Image Processing and Performance Optimization](./Lab-5-Image-Processing-Performance-Optimization/) | Camera processing, grayscale/contrast, Q8 fixed-point arithmetic, Verilog IP, Nios II optimization |
| [Mini Project - FPGA Camera Color Transformation](./Mini-Project-Camera-Performance-Benchmark/) | Live camera processing, RGB channel remapping, framebuffer access, processor/IP performance comparison |

## Technical Areas Demonstrated

- Embedded C development on **Nios II**
- FPGA-based hardware/software integration
- **Verilog** custom peripheral and image-processing logic
- **Avalon memory-mapped** communication
- Platform Designer / Qsys system integration
- SignalTap logic analysis and debugging
- GPIO, switches and LED interfacing
- Camera and graphical LCD interfacing
- Direct framebuffer and pixel manipulation
- RGB/BGR and grayscale image processing
- Q8 fixed-point arithmetic
- Execution-cycle and frames-per-second benchmarking
- Nios II/e and Nios II/f performance comparison

## Tools

**Intel Quartus Prime | Platform Designer/Qsys | Nios II | Verilog | Embedded C | SignalTap | DE10 FPGA**

## Selected Performance Work

Lab 5 explored software and processor optimizations for image processing, including conversion from floating-point to fixed-point arithmetic and compiler optimization.

The mini-project implemented live camera color-channel transformation and compared multiple Nios II configurations, with the **Nios II/f software release configuration reaching approximately 12 FPS** in the reported measurements.

## Documentation

Each folder contains a concise README together with the available laboratory/project report and relevant source or configuration files.

> All laboratory and mini-project work in this repository was completed as part of three-member student teams. Team-work attribution is stated in the corresponding documentation.
