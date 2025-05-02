/*
 * Author: Alejandro Valencia
 * CFD BU Online Course: Laplace Operator
 * Update: April 13, 2024
 */

#include "C++/data_types/grid.h"
#include "C++/data_types/spatial_variable.h"
#include "external/numerical_methods/matrix_solvers/utilities.h"
#include <cstdint>
#include <memory>
#include <vector>

#ifndef C___OPERATORS_LAPLACE_H
#define C___OPERATORS_LAPLACE_H

namespace cfd
{

namespace operators
{

class LaplaceOperator
{
  public:
    const nm::matrix::Matrix<double> GenerateMatrix();
    void GenerateMatrixForSpatialVariable(SpatialVariable& u);
    void SetSpatialVariable(const SpatialVariable& u_in);

  public:
    LaplaceOperator(){};
    LaplaceOperator(const SpatialVariable& u_in);

  private:
    const SpatialVariable* u_{};
    std::int8_t dimension_{1};
    std::int32_t matrix_size_{};
};

}  // namespace operators

}  // namespace cfd

#endif  // C___OPERATORS_LAPLACE_H
