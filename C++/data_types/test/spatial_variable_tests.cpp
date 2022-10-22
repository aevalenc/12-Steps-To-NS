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

class BaseClassFixture : public testing::Test
{
  protected:
    SpatialVariable u_{};
};

TEST_F(BaseClassFixture,
       GivenDefaultInstantiation_ExpectDefaultSpatialDiscretizationMethod)
{
    const auto result = u_.GetSpatialDiscretizationMethod();
    EXPECT_TRUE(result == SpatialDiscretizationMethod::kInvalid);
}

TEST_F(BaseClassFixture,
       GivenDefaultInstantiation_WhenSettingDiscretizationMethod_ExpectValid)
{
    u_.SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod::kFiniteElementMethod);
    EXPECT_TRUE(u_.GetSpatialDiscretizationMethod() ==
                SpatialDiscretizationMethod::kFiniteElementMethod);
}

TEST_F(
    BaseClassFixture,
    GivenFiniteElementDiscretization_WhenCopiedConstructed_ExpectFiniteElementSpatialDiscretization)
{
    u_.SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod::kFiniteElementMethod);
    const SpatialVariable u2(u_);
    EXPECT_TRUE(u_.GetSpatialDiscretizationMethod() ==
                u2.GetSpatialDiscretizationMethod());
}

TEST_F(
    BaseClassFixture,
    GivenFiniteElementDiscretization_WhenCopiedAssigned_ExpectFiniteElementSpatialDiscretization)
{
    u_.SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod::kFiniteElementMethod);
    const auto u2 = u_;
    EXPECT_TRUE(u_.GetSpatialDiscretizationMethod() ==
                u2.GetSpatialDiscretizationMethod());
}

}  // namespace

}  // namespace cfd