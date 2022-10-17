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
    visibility = ["//C++:__subpackages__"],
)

cc_library(
    name = "grid_generator",
    srcs = ["grid_generator.cpp"],
    hdrs = ["grid_generator.h"],
    visibility = ["//C++:__subpackages__"],
    deps = [":grid"],
)
