cc_library(
    name = 'file',
    srcs = [
        'file.cc',
    ],
    hdrs = glob([
        'file.h', 
    ]),
    deps = [
        "@com_github_glog_glog//:glog",
        "//base:base"
    ],
)

cc_test(
    name = "file_test",
    srcs = [
        "file_test.cc",
    ],
    data = ["testdata/testfile.txt"],
    deps = [
    	    ":file",
        "@com_google_googletest//:gtest_main",
    ],
)
