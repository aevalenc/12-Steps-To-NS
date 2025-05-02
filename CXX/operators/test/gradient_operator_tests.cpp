/*
 * @file gradient_operator_tests.cpp
 * @brief Unit tests for the GradientOperator class.
 * @details This file contains unit tests for the GradientOperator class, which is part of the C++ CFD library.
 *
 * @date May 2, 2025
 * @author Alejandro Valencia
 */

#include "CXX/data_types/grid.h"
#include "CXX/data_types/spatial_variable.h"
#include "CXX/operators/gradient.h"
#include "CXX/utilities/grid_generator.h"
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
        const double wave_speed = 1.0;
        operators::GradientOperator nabla(wave_speed);
        nabla_ = nabla;
    }

  protected:
    SpatialVariable u_{};
    geometry::GridGenerator grid_generator_{};
    operators::GradientOperator nabla_{};

  public:
    std::int32_t number_of_grid_nodes_{5};
    double initial_point_x_value_{0.0};
    double end_point_x_value_{1.0};
    double left_boundary_condition_{200.0};
    double right_boundary_condition_{400.0};
    double tolerance_{0.001};
};

TEST_F(BaseClassFixture, GivenValidSetup_ExpectCorrectMatrixGeneration)
{
    // Given
    const auto delta_x = (end_point_x_value_ - initial_point_x_value_) / (number_of_grid_nodes_);

    // Call
    nabla_.GenerateMatrixForSpatialVariable(u_);
    const auto damping_matrix = u_.GetDampingMatrix();

    // Expect
    nm::matrix::PrintMatrix(damping_matrix);
    EXPECT_NEAR(damping_matrix.at(0).at(0), 1.0 / delta_x, tolerance_);
}

}  // namespace

}  // namespace cfd
