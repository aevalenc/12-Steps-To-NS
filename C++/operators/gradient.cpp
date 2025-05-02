/*
 * Author: Alejandro Valencia
 * 12-Steps-To-NS: Gradient Operator
 * Update: May 1, 2025
 */

#include "C++/operators/gradient.h"

namespace cfd {

namespace operators {

GradientOperator::GradientOperator(const double wave_speed)
    : wave_speed_(wave_speed) {}

void GradientOperator::GenerateMatrixForSpatialVariable(SpatialVariable &u) {
  static_assert(std::is_base_of<SpatialVariable, SpatialVariable>::value,
                "GradientOperator can only be used with SpatialVariable or its "
                "derived classes.");

  // Get spatial variable
  matrix_size_ = u.GetGrid().GetSize();
  const auto matrix_dimension = u.GetGrid().GetDimension();
  auto ux = u.GetGrid().GetElementsMutable();

  double delta_x{};
  if (matrix_dimension == 1) {
    delta_x = ux.at(1).GetElement().at(0).GetValues().at(0).value() -
              ux.at(0).GetElement().at(0).GetValues().at(0).value();
  }

  // Generate the gradient matrix
  nm::matrix::Matrix<double> gradient_matrix{};

  gradient_matrix.resize(matrix_size_);

  // Fill the gradient matrix with finite difference coefficients
  for (std::int32_t i = 0; i < matrix_size_; ++i) {
    gradient_matrix.at(i).resize(matrix_size_);

    if (i == 0) {
      gradient_matrix.at(i).at(i) = wave_speed_ / delta_x;
      gradient_matrix.at(i).at(i + 1) = -wave_speed_ / delta_x;
      continue;
    }

    if (i == matrix_size_ - 1) {
      gradient_matrix.at(i).at(i - 1) = wave_speed_ / delta_x;
      gradient_matrix.at(i).at(i) = -wave_speed_ / delta_x;
      continue;
    }

    gradient_matrix.at(i).at(i - 1) = 0.0;
    gradient_matrix.at(i).at(i) = wave_speed_ / delta_x;
    gradient_matrix.at(i).at(i + 1) = -wave_speed_ / delta_x;
  }

  u.SetDampingMatrix(gradient_matrix);
}

} // namespace operators

} // namespace cfd