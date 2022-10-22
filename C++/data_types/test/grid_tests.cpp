///
/// Author: Alejandro Valencia
/// Grid Generator tests
/// Update: 20 November, 2021
///

#include <gtest/gtest.h>

#include "C++/data_types/grid.h"
#include "C++/data_types/grid_generator.h"

namespace cfd
{

namespace geometry
{

namespace
{

TEST(OneDimensionLinearGridTests, GivenValidStartAndEnd_ExpectValidGrid)
{
    GridGenerator grid_generator{};
    const auto result = grid_generator.Create1DLinearGrid(11, 0.0, 1.0);
    EXPECT_EQ(result.GetSize(), 11);
    EXPECT_EQ(result.GetDimension(), 1);
}

}  // namespace

}  // namespace geometry

}  // namespace cfd