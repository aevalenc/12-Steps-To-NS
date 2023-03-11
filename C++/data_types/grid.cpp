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

std::uint64_t Grid::GetSize() const
{
    return elements_.size();
}

const std::vector<std::optional<double>> Node::GetValues() const
{
    return std::vector<std::optional<double>>{x_, y_, z_};
};

}  // namespace geometry

}  // namespace cfd
