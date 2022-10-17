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
    Node();
    Node(double x) : x_(x){};
    Node(double x, double y) : x_(x), y_(y){};
    Node(double x, double y, double z) : x_(x), y_(y), z_(z){};
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
    Element(){};
    Element(ElementEntity nodes) : nodes_(nodes){};
    Element GetElement() const { return nodes_; };
    std::uint8_t GetDimension() const { return dimension_; };
    FiniteElementOrder GetOrder() const { return order_; };

  private:
    ElementEntity nodes_{};
    std::uint8_t dimension_{};
    FiniteElementOrder order_{};
};

class Grid
{
  public:
    Grid(){};
    Grid(std::vector<Element> elements) : elements_(elements){};

  public:
    std::uint8_t GetDimension() const { return dimension_; };
    void SetDimension(const std::uint8_t& dimension)
    {
        dimension_ = dimension;
    };
    std::uint64_t GetSize() const;

  private:
    std::vector<Element> elements_{};
    std::uint8_t dimension_{};
};

}  // namespace geometry

}  // namespace cfd

#endif  // CXX_DATA_TYPES_GRID_H
