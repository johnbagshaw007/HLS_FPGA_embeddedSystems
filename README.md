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


#HLS 8-bit Adder Project


![1000010041](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/cd6d6575-c39d-4874-bfbf-1efc0eb8f8c9)
![Screenshot 2024-02-16 011056](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/740c5b1b-e2b3-4b2c-8ecf-9d16ff1d88ed)
![Screenshot 2024-02-16 010325](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/c381fb29-08b1-4871-a059-53abb4d1daab)
![Screenshot 2024-02-16 004105](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/f9f0f6d2-f3d6-46d9-b223-620dbfa43473)
![Screenshot 2024-02-16 003544](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/803b724f-9e70-4911-a217-884faa879215)
![Screenshot 2024-02-16 003355](https://github.com/johnbagshaw007/HLS_FPGA_embeddedSystems/assets/151597980/26779e38-c6e3-4299-8627-5796eecc8032)


Welcome to the repository showcasing our HLS 8-bit Adder design, a detailed implementation of an FPGA-based arithmetic unit capable of performing 8-bit integer addition. This project serves as a benchmark for demonstrating the practical application of High-Level Synthesis (HLS) in the development of digital hardware.

Project Overview

This repository contains all the necessary components of the HLS design flow:


HLS Design Implementation: HLS_8bit_adder.cpp and HLS_8bit_adder.h describe the core logic of our 8-bit adder in a synthesizable C++ code format suitable for HLS tools, allowing us to maintain high readability and maintainability of the design.

RTL IP Generation and Export: Our HLS toolchain takes the high-level C++ description and compiles it into RTL (Register Transfer Level) IP (Intellectual Property). This process encapsulates the complex addition logic into a reusable hardware module.

Simulation Testbench: The HLS_8bit_adder_TB.cpp file contains our rigorously developed testbench, ensuring comprehensive validation of the adder's functionality within the HLS simulation environment.

Design Constraints: We've crafted specific XDC (Xilinx Design Constraints) files to articulate pin assignments and timing constraints tailored for our target FPGA board. This ensures the synthesized design seamlessly integrates with the board's specifications.

Bitstream Generation: After synthesizing the design, we proceed to the implementation phase to generate a bitstream file. This binary file is essential for configuring the FPGA with our design.

On-Board (HIL) Design Verification: The ultimate test of our design's efficacy comes with the final bitstream being loaded onto an FPGA board for Hardware-in-the-Loop (HIL) testing. This step confirms real-time operational verification and demonstrates the design's effectiveness in a live setting.

Key Design Features
Low Latency: Engineered for rapid computation, our adder provides immediate responses, crucial for real-time systems.

High Speed: Optimized for the fastest possible clock rates without compromising stability or accuracy.

Low Power Consumption: Through careful coding and HLS pragma directives, we've minimized power usage, making our adder suitable for energy-sensitive applications.

Exportability: The RTL IP is fully prepared for export, facilitating easy integration into larger systems or for use as a standalone component.

Ideal Use Cases
Our 8-bit adder is perfect for educational environments to illustrate HLS methodologies or as a fundamental building block in larger, more complex FPGA-based systems. The complete design flow—from HLS coding to on-board verification—offers a transparent view into modern FPGA system design practices.

For a deeper dive into each file and the design process, please refer to the documentation provided in the repository. Contributions and feedback are always welcome as we continue to refine and enhance our HLS implementations
