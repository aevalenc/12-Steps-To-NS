///
/// Author: Alejandro Valencia
/// Boston University CFD Course: grid class
/// Update: 16 October, 2022
///

#include "C++/data_types/grid_generator.h"

#include "C++/data_types/grid.h"

namespace cfd
{

namespace geometry
{

Grid GridGenerator::Create1DLinearGrid(const std::uint64_t& size,
                                       const double& start, const double& end)
{
    std::vector<Element> elements{};
    for (std::uint64_t idx = 0; idx < size; ++idx)
    {
        if (idx != 0)
        {
            const auto step_size =
                static_cast<std::uint64_t>(end - start) / size;

            Node start_node{static_cast<double>(idx + step_size)};
            Node end_node{static_cast<double>((idx + step_size) + step_size)};

            elements.push_back(std::vector<Node>{start_node, end_node});
        }
    }

    return Grid{elements};
}

}  // namespace geometry

}  // namespace cfd