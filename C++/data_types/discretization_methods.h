/*
 * Author: Alejandro Valencia
 * 12-Steps-to-NS: Discretization Methods
 * Update: May 1, 2025
 */

#include <cstdint>
#include <string>

#ifndef C___DATA_TYPES_DISCRETIZATION_METHODS_H
#define C___DATA_TYPES_DISCRETIZATION_METHODS_H

namespace cfd
{

enum class SpatialDiscretizationMethod : std::int32_t
{
    kFiniteDifferenceMethod = 0,
    kFiniteVolumeMethod = 1,
    kFiniteElementMethod = 2,
    kInvalid = 255,
};

inline SpatialDiscretizationMethod SpatialDiscretizationMethodFromString(const std::string& str)
{
    if (str == "FiniteDifferenceMethod")
    {
        return SpatialDiscretizationMethod::kFiniteDifferenceMethod;
    }
    if (str == "FiniteVolumeMethod")
    {
        return SpatialDiscretizationMethod::kFiniteVolumeMethod;
    }
    if (str == "FiniteElementMethod")
    {
        return SpatialDiscretizationMethod::kFiniteElementMethod;
    }
    return SpatialDiscretizationMethod::kInvalid;
}

inline std::string SpatialDiscretizationMethodToString(const SpatialDiscretizationMethod method)
{
    switch (method)
    {
        case SpatialDiscretizationMethod::kFiniteDifferenceMethod:
            return "FiniteDifferenceMethod";
        case SpatialDiscretizationMethod::kFiniteVolumeMethod:
            return "FiniteVolumeMethod";
        case SpatialDiscretizationMethod::kFiniteElementMethod:
            return "FiniteElementMethod";
        default:
            return "Invalid";
    }
}

}  // namespace cfd

#endif  // C___DATA_TYPES_DISCRETIZATION_METHODS_H