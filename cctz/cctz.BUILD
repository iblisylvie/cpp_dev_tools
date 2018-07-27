package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
    name = "civil_time",
    srcs = ["src/civil_time_detail.cc"],
    hdrs = [
        "include/cctz/civil_time.h",
    ],
    includes = ["include"],
    textual_hdrs = ["include/cctz/civil_time_detail.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "time_zone",
    srcs = [
        "src/time_zone_fixed.cc",
        "src/time_zone_fixed.h",
        "src/time_zone_format.cc",
        "src/time_zone_if.cc",
        "src/time_zone_if.h",
        "src/time_zone_impl.cc",
        "src/time_zone_impl.h",
        "src/time_zone_info.cc",
        "src/time_zone_info.h",
        "src/time_zone_libc.cc",
        "src/time_zone_libc.h",
        "src/time_zone_lookup.cc",
        "src/time_zone_posix.cc",
        "src/time_zone_posix.h",
        "src/tzfile.h",
        "src/zone_info_source.cc",
    ],
    hdrs = [
        "include/cctz/time_zone.h",
        "include/cctz/zone_info_source.h",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = [":civil_time"],
)