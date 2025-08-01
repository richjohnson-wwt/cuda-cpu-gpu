#include "add_arrays.h"
#include <iostream>
#include <vector>

int main() {
    size_t size = 5;
    std::vector<float> a = {1, 2, 3, 4, 5};
    std::vector<float> b = {10, 20, 30, 40, 50};
    std::vector<float> result(size);

    add_arrays(a.data(), b.data(), result.data(), size);

    for (float x : result) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}
