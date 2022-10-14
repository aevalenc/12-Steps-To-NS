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

TEST(BaseClassTests,
     GivenDefaultInstantiation_ExpectDefaultSpatialDiscretizationMethod)
{
    const SpatialVariable u;
    const auto result = u.GetSpatialDiscretizationMethod();
    EXPECT_TRUE(result == SpatialDiscretizationMethod::kFiniteDifferenceMethod);
}

TEST(BaseClassTests,
     GivenDefaultInstantiation_WhenSettingDiscretizationMethod_ExpectValid)
{
    SpatialVariable u;
    u.SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod::kFiniteElementMethod);
    EXPECT_TRUE(u.GetSpatialDiscretizationMethod() ==
                SpatialDiscretizationMethod::kFiniteElementMethod);
}

TEST(
    BaseClassTests,
    GivenFiniteElementDiscretization_WhenCopiedConstructed_ExpectFiniteElementSpatialDiscretization)
{
    SpatialVariable u1;
    u1.SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod::kFiniteElementMethod);
    const SpatialVariable u2(u1);
    EXPECT_TRUE(u1.GetSpatialDiscretizationMethod() ==
                u2.GetSpatialDiscretizationMethod());
}

TEST(
    BaseClassTests,
    GivenFiniteElementDiscretization_WhenCopiedAssigned_ExpectFiniteElementSpatialDiscretization)
{
    SpatialVariable u1;
    u1.SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod::kFiniteElementMethod);
    const auto u2 = u1;
    EXPECT_TRUE(u1.GetSpatialDiscretizationMethod() ==
                u2.GetSpatialDiscretizationMethod());
}

}  // namespace

}  // namespace cfd