licenses(["notice"])

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "mysql-connector",
    srcs = [
        "lib64_release/libmysqlcppconn-static.a"
    ],
    hdrs = glob([
        "include/*.h",
        "include/**/*.h",
    ]),
    linkopts = [
        "-ldl",
        "-lpthread",
    ],
    includes = ["include/"],
)
