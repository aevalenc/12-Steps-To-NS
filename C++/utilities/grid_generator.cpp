///
/// Author: Alejandro Valencia
/// Boston University CFD Course: grid class
/// Update: 16 October, 2022
///

#include "C++/utilities/grid_generator.h"

#include "C++/data_types/grid.h"

namespace cfd
{

namespace geometry
{

Grid GridGenerator::Create1DLinearGrid(const std::uint64_t& size,
                                       const double& start, const double& end)
{
    std::vector<Element> elements{};
    const auto step_size = static_cast<std::uint64_t>(end - start) / size;

    for (std::uint64_t idx = 0; idx < size; ++idx)
    {
        Node start_node{static_cast<double>(idx)};
        Node end_node{static_cast<double>((idx + step_size))};
        elements.push_back(std::vector<Node>{start_node, end_node});
    }

    Grid grid{elements};
    grid.SetDimension(1);

    return grid;
    // comment for clang-tidy check
}

}  // namespace geometry

}  // namespace cfd
