// Author: Alejandro Valencia
// CFD BU Online Course Step 2: 1D Nonlinear convection
// Update: 20 November, 2021

/*
 *
 */

#include "C++/data_types/grid.h"
#include "external/numerical_methods/matrix_solvers/utilities.h"
#include <vector>

#ifndef CXX_DATA_TYPES_SPATIAL_VARIABLE_H
#define CXX_DATA_TYPES_SPATIAL_VARIABLE_H

namespace cfd
{

enum class SpatialDiscretizationMethod
{
    kFiniteDifferenceMethod,
    kFiniteVolumeMethod,
    kFiniteElementMethod,
    kInvalid,
};

// Should be in Numerical Methods
enum class MatrixSolverEnum : std::int32_t
{
    kJacobi = 0,
    kGaussSeidel = 1,
    kLUSolve = 2,
    kInvalid = 255,
};

class SpatialVariable
{
  public:
    SpatialVariable() : spatial_discretization_method_{SpatialDiscretizationMethod::kInvalid} {}

    ~SpatialVariable() {}
    SpatialVariable(const SpatialVariable& other)
        : spatial_discretization_method_(other.spatial_discretization_method_),
          discretized_variable_(other.discretized_variable_){};
    SpatialVariable(SpatialVariable&& other)
        : spatial_discretization_method_(other.spatial_discretization_method_),
          discretized_variable_(other.discretized_variable_){};
    SpatialVariable& operator=(const SpatialVariable& other) { return *this = SpatialVariable(other); }
    SpatialVariable& operator=(SpatialVariable&&) { return *this; }

  public:
    void SetSpatialDiscretizationMethod(SpatialDiscretizationMethod spatial_discretization_method);
    SpatialDiscretizationMethod GetSpatialDiscretizationMethod() const;
    std::vector<double>& GetDiscretizedVariable() { return discretized_variable_; };

    void SetGrid(const cfd::geometry::Grid& grid);
    geometry::Grid GetGrid() const;

    void SetDirichletBoundaryCondition(const double value, const std::string_view& boundary_name);
    void SetDirichletBoundaryCondition(const double value, const std::int32_t boundary_index);

    void SetStiffnessMatrix(nm::matrix::Matrix<double> K);
    void SetForceVector(std::vector<double> f);

    void SetMatrixSolver(const MatrixSolverEnum matrix_solver);

    void Solve(const std::int32_t max_iterations, const double tolerance);

  private:
    SpatialDiscretizationMethod spatial_discretization_method_{};
    std::vector<double> discretized_variable_{};
    nm::matrix::Matrix<double> K_{};
    std::vector<double> f_{};
    MatrixSolverEnum matrix_solver_{MatrixSolverEnum::kInvalid};
    geometry::Grid spatial_grid_{};
};

}  // namespace cfd

#endif  // CXX_DATA_TYPES_SPATIAL_VARIABLE_H
