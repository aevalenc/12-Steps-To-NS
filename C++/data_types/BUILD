"""
BUILD file for the C++ data types library.
"""

cc_library(
    name = "grid",
    srcs = ["grid.cpp"],
    hdrs = ["grid.h"],
    visibility = ["//C++:__subpackages__"],
)

cc_library(
    name = "time_variable",
    srcs = ["time_variable.cpp"],
    hdrs = ["time_variable.h"],
    visibility = ["//C++:__subpackages__"],
    deps = [":spatial_variable"],
)

cc_library(
    name = "discretization_lib",
    hdrs = [
        "discretization_methods.h",
        "finite_difference_schemas.h",
    ],
)

cc_library(
    name = "spatial_variable",
    srcs = ["spatial_variable.cpp"],
    hdrs = ["spatial_variable.h"],
    visibility = ["//C++:__subpackages__"],
    deps = [
        ":discretization_lib",
        "//C++/data_types:grid",
        "@numerical_methods//matrix_solvers:utilities",
        "@numerical_methods//matrix_solvers/iterative_solvers:jacobi_method",
    ],
)

cc_library(
    name = "time_variable",
    srcs = ["time_variable.cpp"],
    hdrs = ["time_variable.h"],
    visibility = ["//C++:__subpackages__"],
    deps = [":spatial_variable"],
)
