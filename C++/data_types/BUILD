cc_library(
    name = "spatial_variable",
    srcs = ["spatial_variable.cpp"],
    hdrs = ["spatial_variable.h"],
    visibility = ["//C++:__subpackages__"],
    deps = ["//C++/data_types:grid"],
)

cc_library(
    name = "grid",
    srcs = ["grid.cpp"],
    hdrs = ["grid.h"],
    visibility = ["//C++/src:__subpackages__"],
)

cc_library(
    name = "time_variable",
    srcs = ["time_variable.cpp"],
    hdrs = ["time_variable.h"],
    visibility = ["//C++/src:__subpackages__"],
    deps = [":spatial_variable"],
)
