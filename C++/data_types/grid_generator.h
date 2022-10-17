///
/// Author: Alejandro Valencia
/// Boston University CFD Course: grid class
/// Update: 16 October, 2022
///

#include "C++/data_types/grid.h"

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