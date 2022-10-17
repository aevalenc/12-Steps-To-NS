// Alejandro Valencia
// CFD BU Online Course Step 1: 1D conduction
// Update: 20 November, 2021

/************************************************************************
 * This program uses a finite difference method to solve the 1D
 ** diffusion equation as Step 3 of 12 of the online BU CFD course * taught by
 *Lorena Barba
 **
 ************************************************************************/

#include "C++/data_types/grid.h"

#include <gtest/gtest.h>

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
}

}  // namespace

}  // namespace geometry

}  // namespace cfd