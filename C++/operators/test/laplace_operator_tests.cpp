// Alejandro Valencia
// CFD BU Online Course
// Update: 20 November, 2021

/*
 * ***********************************************************************
 * This program uses a finite difference method to solve the 1D
 * diffusion equation as Step 3 of 12 of the online BU CFD course taught
 * by Lorena Barba
 *
 * ***********************************************************************
 */

#include "C++/data_types/grid.h"
#include "C++/data_types/spatial_variable.h"
#include "C++/operators/laplace.h"
#include "C++/utilities/grid_generator.h"
#include <gtest/gtest.h>

namespace cfd
{

namespace
{

class BaseClassFixture : public testing::Test
{
  public:
    void SetUp() override
    {
        const geometry::Grid grid_ =
            grid_generator_.Create1DLinearGrid(number_of_grid_nodes_, initial_point_x_value_, end_point_x_value_);
        u_.SetGrid(grid_);
        operators::LaplaceOperator delta(u_);
        delta_ = std::move(delta);
    }

  protected:
    SpatialVariable u_{};
    geometry::GridGenerator grid_generator_{};
    operators::LaplaceOperator delta_;

  public:
    std::uint64_t number_of_grid_nodes_{5};
    double initial_point_x_value_{0.0};
    double end_point_x_value_{1.0};
    double left_boundary_condition_{200.0};
    double right_boundary_condition_{400.0};
    double tolerance_{0.001};
};

TEST_F(BaseClassFixture, GivenValidSetup_ExpectCorrectMatrixGeneration)
{
    const auto result = delta_.GenerateMatrix();
    nm::matrix::PrintMatrix(result);
    EXPECT_NEAR(result.at(0).at(0), 2.0, tolerance_);
}

}  // namespace

}  // namespace cfd
