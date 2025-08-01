#include "add_arrays.h"
#include <cuda_runtime.h>
#include <cstdio>

__global__ void add_kernel(const float* a, const float* b, float* result, size_t size) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < size) {
        // result[idx] = a[idx] + b[idx];
        result[idx] = add_op(a[idx], b[idx]);
    }
}

void add_arrays(const float* a, const float* b, float* result, size_t size) {
    printf("I am running on a GPU\n");
    float *d_a, *d_b, *d_result;
    size_t bytes = size * sizeof(float);

    cudaMalloc(&d_a, bytes);
    cudaMalloc(&d_b, bytes);
    cudaMalloc(&d_result, bytes);

    cudaMemcpy(d_a, a, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, bytes, cudaMemcpyHostToDevice);

    int threads = 256;
    int blocks = (size + threads - 1) / threads;
    add_kernel<<<blocks, threads>>>(d_a, d_b, d_result, size);

    cudaMemcpy(result, d_result, bytes, cudaMemcpyDeviceToHost);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_result);
}
