// Author: Alejandro Valencia
// CFD BU Online Course Step 2: 1D Nonlinear convection
// Update: 20 November, 2021

/*
 *
 */

#ifndef SPATIAL_VARIABLE_H
#define SPATIAL_VARIABLE_H

namespace cfd
{

enum SpatialDiscretizationMethod
{
    kFiniteDifferenceMethod,
    kFiniteVolumeMethod,
    kFiniteElementMethod,
};

class SpatialVariable
{
  public:
    void SetSpatialDiscretizationMethod(
        SpatialDiscretizationMethod spatial_discretization_method);
    SpatialDiscretizationMethod GetSpatialDiscretizationMethod();

  private:
    SpatialDiscretizationMethod spatial_discretization_method_{
        SpatialDiscretizationMethod::kFiniteDifferenceMethod};
};

}  // namespace cfd

#endif
