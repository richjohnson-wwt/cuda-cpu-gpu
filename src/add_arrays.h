#pragma once
#include <vector>


#ifdef __CUDACC__
    #define HD __host__ __device__
#else
    #define HD
#endif

HD inline float add_op(float a, float b) {
    return a + b;
}

void add_arrays(const float* a, const float* b, float* result, size_t size);
