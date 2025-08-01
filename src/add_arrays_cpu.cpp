#include "add_arrays.h"
#include <iostream>

void add_arrays(const float* a, const float* b, float* result, size_t size) {
    std::cout << "I am running on your CPU" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
}
