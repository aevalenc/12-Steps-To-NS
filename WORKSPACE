load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    sha256 = "6e85b4467b6fe974ba7b6f2556654ef18f794ed7c73c06c1bfaefe5aa8561f6b",
    strip_prefix = "googletest-391ce627def20c1e8a54d10b12949b15086473dd",
    urls = ["https://github.com/google/googletest/archive/391ce627def20c1e8a54d10b12949b15086473dd.zip"],
)

http_archive(
    name = "nlohmann_json",
    sha256 = "a22461d13119ac5c78f205d3df1db13403e58ce1bb1794edc9313677313f4a9d",
    url = "https://github.com/nlohmann/json/releases/download/v3.11.3/include.zip",
)

http_archive(
    name = "numerical_methods",
    strip_prefix = "Numerical-Methods-master",
    url = "https://github.com/aevalenc/Numerical-Methods/archive/refs/heads/master.tar.gz",
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    sha256 = "10b5f7a36252ce0dd3396c289ba0138779adb6436c187266f6a93de505f3434f",
    strip_prefix = "bazel-compile-commands-extractor-07c307ab34d458cf0a4187a15ce1f6a2b72c408c",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/07c307ab34d458cf0a4187a15ce1f6a2b72c408c.tar.gz",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
