#include <iostream>
#include <ap_int.h>

// Function prototype for the comparator
void comparator(
    ap_uint<4> a,
    ap_uint<4> b,
    bool &eq,
    bool &gt,
    bool &lt);

// Software model of the comparator for verification
void comparator_sw(ap_uint<4> a, ap_uint<4> b, bool &eq_sw, bool &gt_sw, bool &lt_sw) {
    eq_sw = (a == b);
    gt_sw = (a > b);
    lt_sw = (a < b);
}

int main() {
    bool eq_hw, gt_hw, lt_hw;
    bool eq_sw, gt_sw, lt_sw;
    int status = 0;

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            // Convert integers to 4-bit unsigned for hardware simulation
            ap_uint<4> a = i;
            ap_uint<4> b = j;

            // Hardware model invocation
            comparator(a, b, eq_hw, gt_hw, lt_hw);

            // Software model for verification
            comparator_sw(a, b, eq_sw, gt_sw, lt_sw);

            // Check if hardware and software results match
            if (eq_hw != eq_sw || gt_hw != gt_sw || lt_hw != lt_sw) {
                status = -1;
                std::cout << "Error at a = " << a << ", b = " << b
                          << ", HW: eq=" << eq_hw << ", gt=" << gt_hw << ", lt=" << lt_hw
                          << ", SW: eq=" << eq_sw << ", gt=" << gt_sw << ", lt=" << lt_sw << std::endl;
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
