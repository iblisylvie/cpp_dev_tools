This directory contains a demo usage on grpc in c++.
This demo is tested on Ubuntu 16.04 with bazel version 0.27.0.
To run the demo, you should following the next instructions.

1. Follow below page to set up bazel build tool
http://www.bazel.io/docs/install.html

Use "bazel build ..." to build all targets.
Use "bazel test ..." to build all targets and run all test cases.
For more build methods, read bazel's documentation for detail information.

2. To test load balance feature, we could install a local dns server to do the simulation. I found a very useful doc on install local dns on ubuntu 16.04. Please refer to this link https://www.jianshu.com/p/409cd51619d0

3. run bazel build ...

4. run greeter_server on at least two different ip, these two ip should be configured in your local dns server with test domain testing.example.com

5. run bazel-bin/src/greeter_client 
You watch the output from our two server, you will find requests are distributed evenly between the server. You can stop one server, and you will find requests are all on the live one. And you can restart that server and you will find requests are again distributed evenly between the server.