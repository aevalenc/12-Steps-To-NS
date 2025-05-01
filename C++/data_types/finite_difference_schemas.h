/*
 * Author: Alejandro Valencia
 * 12-Steps-to-NS: Finite Difference Discretization Schemas
 * Update: May 1, 2025
 */

#include <cstdint>
#include <string>

#ifndef C___DATA_TYPES_FINITE_DIFFERENCE_SCHEMAS_H
#define C___DATA_TYPES_FINITE_DIFFERENCE_SCHEMAS_H

namespace cfd
{

enum class FiniteDifferenceSchema : std::int32_t
{
    kBackwardsDifference = 0,
    kForwardsDifference = 1,
    kCentralDifference = 2,
    kInvalid = 255,
};

inline FiniteDifferenceSchema FiniteDifferenceSchemaFromString(const std::string& str)
{
    if (str == "BackwardsDifference")
    {
        return FiniteDifferenceSchema::kBackwardsDifference;
    }
    if (str == "ForwardsDifference")
    {
        return FiniteDifferenceSchema::kForwardsDifference;
    }
    if (str == "CentralDifference")
    {
        return FiniteDifferenceSchema::kCentralDifference;
    }
    return FiniteDifferenceSchema::kInvalid;
}

inline std::string FiniteDifferenceSchemaToString(const FiniteDifferenceSchema method)
{
    switch (method)
    {
        case FiniteDifferenceSchema::kBackwardsDifference:
            return "BackwardsDifference";
        case FiniteDifferenceSchema::kForwardsDifference:
            return "ForwardsDifference";
        case FiniteDifferenceSchema::kCentralDifference:
            return "CentralDifference";
        default:
            return "Invalid";
    }
}

}  // namespace cfd

#endif  // C___DATA_TYPES_FINITE_DIFFERENCE_SCHEMAS_H