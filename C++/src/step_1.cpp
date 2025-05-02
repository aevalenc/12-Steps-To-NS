///
/// Author: Alejandro Valencia
/// Update: 13 November, 2022
///

#include "C++/data_types/spatial_variable.h"
#include "C++/data_types/time_variable.h"
#include "C++/utilities/grid_generator.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

int main(int argc, char* argv[])
{
    // Read input file
    std::ifstream input_file("C++/src/step_1.json");
    const auto input_data = nlohmann::json::parse(input_file);

    // Setup grid
    const auto grid_inputs = input_data["grid"];
    cfd::geometry::GridGenerator grid_generator{};
    cfd::geometry::Grid mesh{};

    if (!grid_inputs["import"])
    {
        if (grid_inputs["size"].is_null() || grid_inputs["x_start"].is_null() || grid_inputs["x_end"].is_null())
        {
            std::cerr << "Error: Missing grid parameters\n";
            return 1;
        }
        mesh = grid_generator.Create1DLinearGrid(grid_inputs["size"], grid_inputs["x_start"], grid_inputs["x_end"]);
    }

    if (mesh.GetElements().empty())
    {
        std::cerr << "Error: No elements in the grid\n";
        return 1;
    }
    for (const auto& element : mesh.GetElements())
    {
        std::cout << element << std::endl;
    }

    std::cout << "Grid generated successfully\n";

    // Initialize spatial variable
    const auto spatial_inputs = input_data["spatial_inputs"];
    cfd::SpatialVariable u_x{};

    u_x.SetSpatialDiscretizationMethod(spatial_inputs["discretization_method"]);
    u_x.SetGrid(mesh);
    std::cout << "Spatial variable initialized with grid\n";

    // Initialize time variable
    const auto time_inputs = input_data["time_inputs"];
    cfd::TimeVariable u_t(u_x);
    u_t.SetTimeDiscretizationMethod(time_inputs["discretization_method"]);
    std::cout << "Time variable constructed with spatial variable\n";

    // Exit
    std::cout << "End of program" << std::endl;
    return 0;
}
