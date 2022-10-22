// Author: Alejandro Valencia
// CFD BU Online Course Step 2: 1D Nonlinear convection
// Update: 20 November, 2021

/*
 *
 */

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

class SpatialVariable
{
  public:
    SpatialVariable()
        : spatial_discretization_method_{SpatialDiscretizationMethod::kInvalid}
    {
    }

    ~SpatialVariable() {}
    SpatialVariable(const SpatialVariable& other)
        : spatial_discretization_method_(other.spatial_discretization_method_),
          dummy_vector_(other.dummy_vector_){};
    SpatialVariable(SpatialVariable&& other)
        : spatial_discretization_method_(other.spatial_discretization_method_),
          dummy_vector_(other.dummy_vector_){};
    SpatialVariable& operator=(const SpatialVariable& other)
    {
        return *this = SpatialVariable(other);
    }
    SpatialVariable& operator=(SpatialVariable&&) { return *this; }

    void SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod spatial_discretization_method);
    SpatialDiscretizationMethod GetSpatialDiscretizationMethod() const;

  private:
    SpatialDiscretizationMethod spatial_discretization_method_;
    std::vector<double> dummy_vector_{};
};

}  // namespace cfd

#endif  // CXX_DATA_TYPES_SPATIAL_VARIABLE_H
