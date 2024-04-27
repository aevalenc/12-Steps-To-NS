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

const bool Element::IsOnBoundary() const
{
    return is_on_boundary_;
}

const bool Node::IsOnBoundary() const
{
    return is_on_boundary_;
}

void Node::SetBoundaryBoolean(const bool is_on_boundary)
{
    is_on_boundary_ = is_on_boundary;
}

void Element::SetBoundaryBoolean(const bool is_on_boundary)
{
    is_on_boundary_ = is_on_boundary;
}

}  // namespace geometry

}  // namespace cfd
