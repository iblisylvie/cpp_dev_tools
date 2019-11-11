package(default_visibility = ["//visibility:public"])

load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")

proto_library(
    name = "protos",
    srcs = [
        "helloworld.proto",
    ],
    visibility = [
        "//visibility:public",
    ],
)

cpp_grpc_library(
    name = "helloworld_proto",
    deps = [":protos"],
)
