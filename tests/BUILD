# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_test
cc_test(
    name = "tests",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//src/Soundex:Soundex",
        "//src/RetweetCollection:RetweetCollection",
        "//src/Tweet:Tweet",
        "@googletest//:gtest_main",
    ],
)