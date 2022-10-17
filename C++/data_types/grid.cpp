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

std::uint64_t Grid::GetSize() const { return elements_.size(); }

}  // namespace geometry

}  // namespace cfd