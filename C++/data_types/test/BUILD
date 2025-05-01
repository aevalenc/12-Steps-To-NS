load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "grid_tests",
    srcs = ["grid_tests.cpp"],
    deps = [
        "//C++/data_types:grid",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "spatial_variable_tests",
    srcs = ["spatial_variable_tests.cpp"],
    deps = [
        "//C++/data_types:spatial_variable",
        "@com_google_googletest//:gtest_main",
    ],
)
