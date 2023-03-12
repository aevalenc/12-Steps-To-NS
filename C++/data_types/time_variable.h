// Author: Alejandro Valencia
// CFD BU Online Course Step 2: 1D Nonlinear convection
// Update: 20 November, 2021

/*
 *
 */

#include "C++/data_types/spatial_variable.h"
#include <vector>

#ifndef CXX_DATA_TYPES_TIME_VARIABLE_H
#define CXX_DATA_TYPES_TIME_VARIABLE_H

namespace cfd
{

enum class TimeDiscretizationMethod
{
    kEulerStep = 0,
    kRungaKutta4,
    kRungaKutta2,
    kInvalid,
};

class TimeVariable
{
  public:
    TimeVariable() : time_discretization_method_{TimeDiscretizationMethod::kInvalid} {}
    TimeVariable(const SpatialVariable& u);

    ~TimeVariable() {}
    TimeVariable(const TimeVariable& other)
        : time_discretization_method_(other.time_discretization_method_),
          u_current_(other.u_current_),
          u_previous_(other.u_previous_){};

    TimeVariable(TimeVariable&& other)
        : time_discretization_method_(other.time_discretization_method_),
          u_current_(other.u_current_),
          u_previous_(other.u_previous_){};

    TimeVariable& operator=(const TimeVariable& other) { return *this = TimeVariable(other); }
    TimeVariable& operator=(TimeVariable&&) { return *this; }

  public:
    void SetTimeDiscretizationMethod(TimeDiscretizationMethod time_discretization_method);
    TimeDiscretizationMethod GetTimeDiscretizationMethod() const;
    void SetStartTime(const double& start_time) { start_time_ = start_time; };
    void SetEndTime(const double& end_time) { end_time_ = end_time; };
    void SetTimeStep(const double& delta_t) { delta_t_ = delta_t; };
    void SetInitialCondition(const std::vector<double>& u_initial) { u_previous_ = u_initial; };
    void Step(const std::vector<double>& wave_speeds);

  private:
    TimeDiscretizationMethod time_discretization_method_;
    std::vector<double> u_current_{};
    std::vector<double> u_previous_{};
    double start_time_{};
    double end_time_{};
    std::size_t delta_t_{};
    SpatialVariable u_{};
};

}  // namespace cfd

#endif  // CXX_DATA_TYPES_TIME_VARIABLE_H
