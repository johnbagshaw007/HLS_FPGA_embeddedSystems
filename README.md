![Screenshot 2024-02-15 190723](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/0b7baadc-cb9a-4ff5-b1c8-d8d48497861c)
![Screenshot 2024-02-15 203656](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/38b0e379-3e47-439e-aa59-5a9c0373b44a)
![Screenshot 2024-02-15 204206](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/8a2d166a-61b9-4c4e-a74a-d3c989475741)
![Screenshot 2024-02-15 204552](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/73c9f0c4-a74e-4646-9e8d-ededda947e94)
![Screenshot 2024-02-15 210805](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/21ffa6b1-2b1c-4511-aad6-26fc31e6ddef)
![1000010038](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/847f8f1e-d3f2-4027-a0bf-d66b4ad81a0a)
![1000010039](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/b3f46541-cde3-438d-9506-a5fd13fe53dd)

FPGA-Based Traffic Light Controller

This repository contains a High-Level Synthesis (HLS) implementation of an FPGA-based traffic light control system, 
designed to provide an efficient solution for traffic management at intersections. The HLS design flow facilitates a high abstraction level, 
allowing for a design that is both easily readable and maintainable.

Key Components:
HLS Design Implementation: traffic_light.cpp and traffic_light.h describe the logic of the traffic light controller using C++ in a synthesizable manner suitable for HLS.

RTL IP Generation: The HLS tool compiles the high-level C++ code into RTL (Register Transfer Level) IP (Intellectual Property), which is a hardware description of the traffic light controller.

Simulation Testbench: traffic_light-tb.cpp and traffic_light-tb.h serve as the testbench files to verify the functionality of the design within the HLS simulation environment.

Design Constraints: Accompanying XDC (Xilinx Design Constraints) files specify pin assignments and timing constraints tailored for the target FPGA board, ensuring that the synthesized design adheres to the board's requirements.

Bitstream Generation: Post-synthesis, the design undergoes implementation phases where a bitstream file is generated. This file contains the configuration data for the FPGA.

On-Board Verification: The final bitstream is loaded onto an FPGA board for Hardware-in-the-Loop (HIL) testing, providing real-time design verification and demonstrating the design's effectiveness in a live environment.

Design Features:
Low Latency: The design is optimized for quick response times, ensuring rapid signal changes in response to traffic conditions.

High Speed: With careful consideration for the target FPGA's resources, the design achieves high clock frequencies.

Low Power: HLS pragmas and efficient coding practices reduce the design's power consumption, making it suitable for extended operational periods.

Exportability: The project is configured to allow easy export of the RTL IP for integration into larger systems or for standalone use.

This traffic light controller is ideal for educational purposes, showcasing the HLS design methodology, and for practical deployment in traffic management systems. 

The complete design flow from HLS coding to on-board verification provides a comprehensive view of modern FPGA-based system design.
