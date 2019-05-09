This directory contains a demo usage on mysql in c++.
This demo is tested on Ubuntu 16.04 with bazel version 0.25.0.
To run the demo, you should following the next instructions.

1. Follow below page to set up bazel build tool
http://www.bazel.io/docs/install.html

Use "bazel build ..." to build all targets.
Use "bazel test ..." to build all targets and run all test cases.
For more build methods, read bazel's documentation for detail information.

2. First run
mysql -h 127.0.0.1 -u root -p123456 < create_table.sql
to create table.
3. Run bazel build ...
4. Run bazel-bin/src/mysql_demo

