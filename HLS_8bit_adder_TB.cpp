/************************************************
Copyright (c) 2024, John Bagshaw
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2024, John Bagshaw.
************************************************/

#include "HLS_8bit_adder.h" // Ensure this header matches your setup
#include <iostream>

// Update or ensure this function can handle splitting 8-bit integers into boolean arrays.
void split_bits(int value, bool bits[8]) {
    for (int i = 0; i < 8; ++i) {
        bits[i] = value & 1;
        value >>= 1;
    }
}

// Update the software adder model to work with 8 bits
void adder_software(int a, int b, int &sum, bool &c) {
    int temp_sum = a + b;
    c = (temp_sum >= 256); // Check for carry beyond 8 bits
    sum = temp_sum % 256;  // Modulo to fit into 8 bits
}

int main() {
    int status = 0;
    bool bits_a[8], bits_b[8];
    int a, b;

    for (a = 0; a < 256 && status == 0; a++) {
        for (b = 0; b < 256 && status == 0; b++) {
            ap_uint<8> sum_hw;
            bool cout_hw;
            int sum_sw;
            bool cout_sw;

            // Convert integers to bit arrays for HW simulation
            split_bits(a, bits_a);
            split_bits(b, bits_b);

            // Hardware model invocation
            HLS_8bit_adder(a, b, &sum_hw, &cout_hw);

            // Software model for verification
            adder_software(a, b, sum_sw, cout_sw);

            // Convert software sum to ap_uint for comparison
            ap_uint<8> sum_sw_ap_uint = sum_sw;

            // Check if hardware and software results match
            if (sum_hw != sum_sw_ap_uint || cout_hw != cout_sw) {
                status = -1;
                std::cout << "Mismatch detected at a = " << a << ", b = " << b << std::endl;
            }
        }
    }

    if (status == 0) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return status;
}
