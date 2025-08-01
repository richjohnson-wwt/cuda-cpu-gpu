#include "add_arrays.h"
#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>

using Catch::Approx;

TEST_CASE("Add arrays", "[add]") {
    float a[3] = {1, 2, 3};
    float b[3] = {4, 5, 6};
    float result[3];

    add_arrays(a, b, result, 3);

    REQUIRE(result[0] == Approx(5));
    REQUIRE(result[1] == Approx(7));
    REQUIRE(result[2] == Approx(9));
}
