This directory contains a demo usage on gflags in c++.
This demo is tested on Ubuntu 14.04 with bazel version 0.13.0
To run the demo, you should following the next instructions.

1. Follow below page to set up bazel build tool
http://www.bazel.io/docs/install.html

Use "bazel build ..." to build all targets.
Use "bazel test ..." to build all targets and run all test cases.
For more build methods, read bazel's documentation for detail information.

2. run bazel build ...
3. bazel-bin/src/gflag_demo --big_menu=true --languages=cn