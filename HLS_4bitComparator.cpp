#include "hls_stream.h"
#include <ap_int.h>

void comparator(
    ap_uint<4> a,
    ap_uint<4> b,
    bool &eq,
    bool &gt,
    bool &lt) {

#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=b
#pragma HLS INTERFACE ap_none port=eq
#pragma HLS INTERFACE ap_none port=gt
#pragma HLS INTERFACE ap_none port=lt
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE II=1

    // Optimized comparison using bitwise operations
    eq = (a == b);
    gt = (a > b);
    lt = (a < b);
}

