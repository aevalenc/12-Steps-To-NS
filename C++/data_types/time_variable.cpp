// Author: Alejandro Valencia
// 12-Steps-To-Navier-Stokes: Base Spatial Variable Class
// Update: 9 October, 2022

/*
 * This file serves as the implementation of member functions of the class
 * TimeVariable
 */

#include "C++/data_types/time_variable.h"

#include <cassert>
#include <iterator>

namespace cfd
{

TimeVariable::TimeVariable(const SpatialVariable& u)
    : time_discretization_method_(TimeDiscretizationMethod::kInvalid), u_(u)
{
    u_current_ = u_.GetDiscretizedVariable();
    u_previous_ = u_current_;
}

TimeDiscretizationMethod TimeVariable::GetTimeDiscretizationMethod() const
{
    return time_discretization_method_;
}

void TimeVariable::SetTimeDiscretizationMethod(
    TimeDiscretizationMethod time_discretization_method)
{
    time_discretization_method_ = time_discretization_method;
}

void TimeVariable::Step(const std::vector<double>& wave_speeds)
{
    assert(start_time_ != end_time_);
    assert(delta_t_ != 0.0);

    const auto number_of_steps =
        static_cast<std::size_t>((end_time_ - start_time_) / delta_t_);

    if (time_discretization_method_ == TimeDiscretizationMethod::kEulerStep)
    {
        for (std::size_t n = 0; n < number_of_steps; ++n)
        {
            for (std::size_t i = 0; i < std::size(u_current_); ++i)
            {
                u_current_[i] = u_previous_[i] + wave_speeds.front() * delta_t_;
            }
        }
    }
}

}  // namespace cfd