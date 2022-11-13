///
/// Author: Alejandro Valencia
/// Update: 13 November, 2022
///

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "C++/data_types/spatial_variable.h"
#include "C++/data_types/time_variable.h"
#include "C++/utilities/grid_generator.h"

int main(int argc, char *argv[])
{
    // Read input file
    std::ifstream input_file("C++/src/step_1.json");
    const auto input_data = nlohmann::json::parse(input_file);

    // Setup grid
    const auto grid_inputs = input_data["grid"];
    if (!grid_inputs["import"])
    {
        cfd::geometry::GridGenerator grid_generator{};
        grid_generator.Create1DLinearGrid(
            grid_inputs["size"], grid_inputs["x_start"], grid_inputs["x_end"]);
    }

    // Initialize spatial variable
    const auto spatial_inputs = input_data["spatial_inputs"];
    cfd::SpatialVariable u_x{};

    u_x.SetSpatialDiscretizationMethod(spatial_inputs["discretization_method"]);

    // Exit
    std::cout << "End of program\n";
    return 0;
}
