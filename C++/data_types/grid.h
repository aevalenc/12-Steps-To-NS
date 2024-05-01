// Author: Alejandro Valencia
// CFD BU Online Course: 1D grid class
// Update: 20 November, 2021

/*
 *
 */

#include <cstdint>
#include <optional>
#include <vector>

#ifndef C___DATA_TYPES_GRID_H
#define C___DATA_TYPES_GRID_H

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

  public:
    const std::vector<std::optional<double>> GetValues() const;
    const bool IsOnBoundary() const;
    void SetBoundaryBoolean(const bool is_on_boundary);

  private:
    bool is_on_boundary_{false};
    std::optional<double> x_{std::nullopt};
    std::optional<double> y_{std::nullopt};
    std::optional<double> z_{std::nullopt};
};

class Element
{
    using ElementEntity = std::vector<Node>;

  public:
    Element(){};
    Element(ElementEntity nodes) : nodes_(nodes){};

    ElementEntity GetElement() const { return nodes_; };
    std::uint8_t GetDimension() const { return dimension_; };
    FiniteElementOrder GetOrder() const { return order_; };
    const bool IsOnBoundary() const;
    void SetBoundaryBoolean(const bool is_on_boundary);

  private:
    ElementEntity nodes_{};
    std::uint8_t dimension_{};
    FiniteElementOrder order_{};
    bool is_on_boundary_{false};
};

class Grid
{
  public:
    Grid(){};
    Grid(std::vector<Element> elements) : elements_(elements){};

  public:
    std::uint8_t GetDimension() const { return dimension_; }
    void SetDimension(const std::uint8_t& dimension) { dimension_ = dimension; }
    std::uint64_t GetSize() const;

    std::vector<Element> GetElementsMutable() const { return elements_; }
    const std::vector<Element>& GetElements() const { return elements_; }
    std::int32_t number_of_boundaries_{};

  private:
    std::vector<Element> elements_{};
    std::uint8_t dimension_{};
};

}  // namespace geometry

}  // namespace cfd

#endif  // C___DATA_TYPES_GRID_H
