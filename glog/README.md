This directory contains a demo usage on glog in c++, ported from https://github.com/google/or-tools
This demo is tested on Ubuntu 14.04 with bazel version 0.13.0.
To run the demo, you should following the next instructions.

1. Follow below page to set up bazel build tool
http://www.bazel.io/docs/install.html

Use "bazel build ..." to build all targets.
Use "bazel test ..." to build all targets and run all test cases.
For more build methods, read bazel's documentation for detail information.

2. run bazel build ...
3. GLOG_v=1 GLOG_stderrthreshold=0 GLOG_logtostderr=1 bazel-bin/src/glog_demo

NOTICE: currently verbose log is not supported, need to check the reason later.
