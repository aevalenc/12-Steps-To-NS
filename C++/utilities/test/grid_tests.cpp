///
/// Author: Alejandro Valencia
/// Grid Generator tests
/// Update: 20 November, 2021
///

#include <gtest/gtest.h>

#include "C++/data_types/grid.h"
#include "C++/utilities/grid_generator.h"

namespace cfd
{

namespace geometry
{

namespace
{

TEST(OneDimensionLinearGridTests, GivenValidStartAndEnd_ExpectValidGrid)
{
    // Given
    GridGenerator grid_generator{};
    const std::uint64_t size{11};
    const double start{0.0};
    const double end{1.0};
    const double tolerance{0.001};

    // Call
    const auto result = grid_generator.Create1DLinearGrid(size, start, end);

    // Expect
    EXPECT_EQ(result.GetSize(), 11);
    EXPECT_EQ(result.GetDimension(), 1);
    EXPECT_NEAR(2.3, 3.4, tolerance);
}

}  // namespace

}  // namespace geometry

}  // namespace cfd
