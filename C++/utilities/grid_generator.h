///
/// Author: Alejandro Valencia
/// Boston University CFD Course: grid class
/// Update: 16 October, 2022
///

#include "C++/data_types/grid.h"

#ifndef CXX_DATA_TYPES_GRID_GENERATOR_H
#define CXX_DATA_TYPES_GRID_GENERATOR_H

namespace cfd
{

namespace geometry
{

class GridGenerator
{
  public:
    Grid GetGrid() { return grid_; };
    Grid Create1DLinearGrid(const std::uint64_t& size, const double& start,
                            const double& end);

  private:
    Grid grid_{};
};

}  // namespace geometry

}  // namespace cfd

#endif  // CXX_DATA_TYPES_GRID_GENERATOR_H
