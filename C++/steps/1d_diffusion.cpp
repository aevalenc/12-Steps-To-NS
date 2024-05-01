/*
 * Author: Alejandro Valencia
 * CFD BU Online Course Step 4: Burgers Equation
 * Update: 20 November, 2021
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
    }

  protected:
    SpatialVariable u_{};
    geometry::GridGenerator grid_generator_{};
    operators::LaplaceOperator delta_;

  public:
    std::uint64_t number_of_grid_nodes_{11};
    double initial_point_x_value_{0.0};
    double end_point_x_value_{1.0};
    double left_boundary_condition_{200.0};
    double right_boundary_condition_{400.0};
    double tolerance_{0.001};
};

TEST_F(BaseClassFixture, GivenValidSetup_ExpectCorrectMatrixGeneration)
{
    // Given
    operators::LaplaceOperator delta{};
    delta.GenerateMatrixForSpatialVariable(u_);

    u_.SetDirichletBoundaryCondition(left_boundary_condition_, 0);
    u_.SetDirichletBoundaryCondition(right_boundary_condition_, u_.GetGrid().GetSize() - 1);
    u_.SetMatrixSolver(MatrixSolverEnum::kJacobi);

    // Call
    u_.Solve(1000, 0.001);

    nm::matrix::PrintVector(u_.GetDiscretizedVariable());

    EXPECT_NEAR(u_.GetDiscretizedVariable().front(), 200.0, tolerance_);
    EXPECT_NEAR(u_.GetDiscretizedVariable().back(), 400.0, tolerance_);
}

}  // namespace

}  // namespace cfd
