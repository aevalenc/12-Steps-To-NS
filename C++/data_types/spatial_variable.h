// Author: Alejandro Valencia
// CFD BU Online Course Step 2: 1D Nonlinear convection
// Update: 20 November, 2021

/*
 *
 */

#include "C++/data_types/discretization_methods.h"
#include "C++/data_types/finite_difference_schemas.h"
#include "C++/data_types/grid.h"
#include "external/numerical_methods/matrix_solvers/utilities.h"
#include <vector>

#ifndef C___DATA_TYPES_SPATIAL_VARIABLE_H
#define C___DATA_TYPES_SPATIAL_VARIABLE_H

namespace cfd
{

// Should be in Numerical Methods
enum class MatrixSolverEnum : std::int32_t
{
    kJacobi = 0,
    kGaussSeidel = 1,
    kLUSolve = 2,
    kInvalid = 255,
};

inline MatrixSolverEnum MatrixSolverEnumFromString(const std::string& str)
{
    if (str == "Jacobi")
    {
        return MatrixSolverEnum::kJacobi;
    }
    if (str == "GaussSeidel")
    {
        return MatrixSolverEnum::kGaussSeidel;
    }
    if (str == "LUSolve")
    {
        return MatrixSolverEnum::kLUSolve;
    }
    return MatrixSolverEnum::kInvalid;
};

inline std::string MatrixSolverEnumToString(const MatrixSolverEnum method)
{
    switch (method)
    {
        case MatrixSolverEnum::kJacobi:
            return "Jacobi";
        case MatrixSolverEnum::kGaussSeidel:
            return "GaussSeidel";
        case MatrixSolverEnum::kLUSolve:
            return "LUSolve";
        default:
            return "Invalid";
    }
}

class SpatialVariable
{
  public:
    SpatialVariable() : spatial_discretization_method_{SpatialDiscretizationMethod::kInvalid} {}

    ~SpatialVariable() {}
    SpatialVariable(const SpatialVariable& other)
        : spatial_discretization_method_(other.spatial_discretization_method_),
          discretized_variable_(other.discretized_variable_){};
    SpatialVariable(SpatialVariable&& other) noexcept
        : spatial_discretization_method_(other.spatial_discretization_method_),
          discretized_variable_(other.discretized_variable_){};
    SpatialVariable& operator=(const SpatialVariable& other) { return *this = SpatialVariable(other); }
    SpatialVariable& operator=(SpatialVariable&&) noexcept { return *this; }

  public:
    void SetSpatialDiscretizationMethod(SpatialDiscretizationMethod spatial_discretization_method);
    SpatialDiscretizationMethod GetSpatialDiscretizationMethod() const;

    void SetDiscretizationSchema(FiniteDifferenceSchema discretization_schema);
    FiniteDifferenceSchema GetDiscretizationSchema() const { return discretization_schema_; };

    std::vector<double>& GetDiscretizedVariable() { return discretized_variable_; };

    void SetGrid(const cfd::geometry::Grid& grid);
    geometry::Grid GetGrid() const;

    void SetDirichletBoundaryCondition(const double value, const std::string_view& boundary_name);
    void SetDirichletBoundaryCondition(const double value, const std::int32_t boundary_index);

    void SetStiffnessMatrix(nm::matrix::Matrix<double> K);
    void SetDampingMatrix(nm::matrix::Matrix<double> C);
    void SetForceVector(std::vector<double> f);

    nm::matrix::Matrix<double> GetStiffnessMatrix() const { return K_; }
    nm::matrix::Matrix<double> GetDampingMatrix() const { return C_; }
    std::vector<double> GetForceVector() const { return f_; };

    void SetMatrixSolver(const MatrixSolverEnum matrix_solver);

    void Solve(const std::int32_t max_iterations, const double tolerance);

  private:
    SpatialDiscretizationMethod spatial_discretization_method_{};
    FiniteDifferenceSchema discretization_schema_{};
    std::vector<double> discretized_variable_{};
    nm::matrix::Matrix<double> K_{};
    nm::matrix::Matrix<double> C_{};
    std::vector<double> f_{};
    MatrixSolverEnum matrix_solver_{MatrixSolverEnum::kInvalid};
    geometry::Grid spatial_grid_{};
};

}  // namespace cfd

#endif  // C___DATA_TYPES_SPATIAL_VARIABLE_H
