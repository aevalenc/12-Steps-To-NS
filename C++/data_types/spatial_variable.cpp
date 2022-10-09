// Author: Alejandro Valencia
// 12-Steps-To-Navier-Stokes: Base Spatial Variable Class
// Update: 9 October, 2022

/*
 * This file serves as the implementation of member functions of the class
 * SpatialVariable
 */

#include "C++/data_types/spatial_variable.h"

namespace cfd
{

SpatialDiscretizationMethod SpatialVariable::GetSpatialDiscretizationMethod()
{
    return spatial_discretization_method_;
};

}  // namespace cfd