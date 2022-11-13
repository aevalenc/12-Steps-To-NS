// Author: Alejandro Valencia
// CFD BU Online Course: 1D grid class
// Update: 20 November, 2021

/*
 *
 */

#include <cstdint>
#include <vector>

#ifndef CXX_DATA_TYPES_GRID_H
#define CXX_DATA_TYPES_GRID_H

namespace cfd
{

namespace geometry
{

enum class FiniteElementOrder
{
    kLinear,
    kQuadratic,
    kCubic,
};

class Node
{
  public:
    // Node();
    // ~Node();
    // Node(const Node& other);
    // Node(Node&& other);
    // Node& operator=(const Node& other);
    // Node& operator=(Node&& other);

  private:
    double x_{};
    double y_{};
    double z_{};
};

class Element
{
    using ElementEntity = std::vector<Node>;

  public:
    ElementEntity GetElement() { return nodes_; };
    std::uint8_t GetDimension() { return dimension_; };
    FiniteElementOrder GetOrder() { return order_; };

  private:
    ElementEntity nodes_{};
    std::uint8_t dimension_{};
    FiniteElementOrder order_{};
};

class Grid
{
  public:
    std::uint8_t GetDimension() { return dimension_; };

  private:
    std::vector<Element> elements_{};
    std::uint8_t dimension_{};
};

}  // namespace geometry

}  // namespace cfd

#endif  // CXX_DATA_TYPES_GRID_H
