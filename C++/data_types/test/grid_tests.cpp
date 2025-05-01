// Alejandro Valencia
// CFD BU Online Course Step 1: 1D conduction
// Update: 20 November, 2021

/************************************************************************
 * This program uses a finite difference method to solve the 1D
 ** diffusion equation as Step 3 of 12 of the online BU CFD course * taught by
 *Lorena Barba
 **
 ************************************************************************/

#include "C++/data_types/grid.h"
#include <gtest/gtest.h>

namespace cfd
{

namespace geometry
{
namespace
{
class BaseClassFixture : public testing::Test
{
  protected:
    Grid grid_{};
};

TEST_F(BaseClassFixture, GivenValidGrid_ExpectCorrectDisplay)
{
    // Given
    Node node1(1.0);
    Node node2(2.0);

    Element element({node1, node2});

    std::cout << element << std::endl;  // Should invoke operator<<

    std::vector<Element> elements = {element};
    grid_ = Grid(elements);

    // Act
    const auto& elements_vector = grid_.GetElements();
    for (const auto& element : elements_vector)
    {
        std::cout << "Element: " << element << std::endl;  // Should invoke operator<<
    }

    // Assert
    EXPECT_EQ(elements_vector.size(), 1);
}

}  // namespace
}  // namespace geometry

}  // namespace cfd