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

SpatialDiscretizationMethod SpatialVariable::GetSpatialDiscretizationMethod() const
{
    return spatial_discretization_method_;
}

void SpatialVariable::SetSpatialDiscretizationMethod(SpatialDiscretizationMethod spatial_discretization_method)
{
    spatial_discretization_method_ = spatial_discretization_method;
}

void SpatialVariable::SetGrid(const cfd::geometry::Grid& grid)
{
    spatial_grid_ = grid;
}

geometry::Grid SpatialVariable::GetGrid() const
{
    return spatial_grid_;
}

}  // namespace cfd
