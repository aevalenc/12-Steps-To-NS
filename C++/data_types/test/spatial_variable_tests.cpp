// Alejandro Valencia
// CFD BU Online Course Step 1: 1D conduction
// Update: 20 November, 2021

/************************************************************************
 * This program uses a finite difference method to solve the 1D
 ** diffusion equation as Step 3 of 12 of the online BU CFD course * taught by
 *Lorena Barba
 **
 ************************************************************************/

#include <gtest/gtest.h>

#include "C++/data_types/spatial_variable.h"

namespace cfd
{

namespace
{

TEST(BaseClassTests, GivenInstantiation_ExpectDefaultFDM)
{
    const SpatialVariable u;
    const auto result = u.GetSpatialDiscretizationMethod();
    EXPECT_TRUE(result == SpatialDiscretizationMethod::kFiniteDifferenceMethod);
}

}  // namespace

}  // namespace cfd