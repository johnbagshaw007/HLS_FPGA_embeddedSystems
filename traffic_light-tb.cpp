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
#include "traffic_light-tb.h"
#include <iostream>

void traffic_light_software(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor, bool *ns_light, bool *ew_light) {
    // Simplify the logic based on the combined rules
    *ew_light = (l_sensor && r_sensor) || (!(u_sensor && d_sensor) && (l_sensor || r_sensor)) || !(l_sensor || r_sensor || u_sensor || d_sensor);
    *ns_light = ((u_sensor && d_sensor) && !(l_sensor && r_sensor)) || (!(l_sensor || r_sensor) && (u_sensor ^ d_sensor));
}

int main() {
    int status = 0;

    // Simplify loop initialization and condition checks
    for (int l = 0; l < 2 && status == 0; l++) {
        for (int r = 0; r < 2 && status == 0; r++) {
            for (int u = 0; u < 2 && status == 0; u++) {
                for (int d = 0; d < 2 && status == 0; d++) {

                    bool ns_light_hw, ew_light_hw, ns_light_sw, ew_light_sw;
                    traffic_light(l, r, u, d, &ns_light_hw, &ew_light_hw);
                    traffic_light_software(l, r, u, d, &ns_light_sw, &ew_light_sw);

                    if (ns_light_hw != ns_light_sw || ew_light_hw != ew_light_sw) {
                        status = -1;
                        std::cout << "Mismatch detected: l_sensor=" << l
                                  << ", r_sensor=" << r
                                  << ", u_sensor=" << u
                                  << ", d_sensor=" << d
                                  << ", HW: NS=" << ns_light_hw << ", EW=" << ew_light_hw
                                  << ", SW: NS=" << ns_light_sw << ", EW=" << ew_light_sw << std::endl;
                    }
                }
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
