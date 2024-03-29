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
#include "traffic_light.h"

// Inline definitions of rule_1 through rule_5 for visibility within traffic_light function
inline bool rule_1(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor) {

    return l_sensor && r_sensor;
}

inline bool rule_2(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor) {

    return (l_sensor ^ r_sensor) && !(u_sensor && d_sensor);
}

inline bool rule_3(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor) {

    return !(l_sensor && r_sensor) && (u_sensor && d_sensor);
}

inline bool rule_4(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor) {

    return !(l_sensor || r_sensor) && (u_sensor ^ d_sensor);
}

inline bool rule_5(bool l_sensor, bool r_sensor, bool u_sensor, bool d_sensor) {

    return !(l_sensor || r_sensor) && !(u_sensor || d_sensor);
}


void traffic_light(
    bool l_sensor,
    bool r_sensor,
    bool u_sensor,
    bool d_sensor,
    bool *ns_light,
    bool *ew_light) {

#pragma HLS INTERFACE ap_none port=l_sensor
#pragma HLS INTERFACE ap_none port=r_sensor
#pragma HLS INTERFACE ap_none port=u_sensor
#pragma HLS INTERFACE ap_none port=d_sensor
#pragma HLS INTERFACE ap_none port=ns_light
#pragma HLS INTERFACE ap_none port=ew_light
#pragma HLS INTERFACE ap_ctrl_none port=return

#pragma HLS PIPELINE II=1

    bool ew_rule_1 = rule_1(l_sensor, r_sensor, u_sensor, d_sensor);
    bool ew_rule_2 = rule_2(l_sensor, r_sensor, u_sensor, d_sensor);
    bool ns_rule_3 = rule_3(l_sensor, r_sensor, u_sensor, d_sensor);
    bool ns_rule_4 = rule_4(l_sensor, r_sensor, u_sensor, d_sensor);
    bool ew_rule_5 = rule_5(l_sensor, r_sensor, u_sensor, d_sensor);

    *ew_light = ew_rule_1 || ew_rule_2 || ew_rule_5;
    *ns_light = ns_rule_3 || ns_rule_4;
}
