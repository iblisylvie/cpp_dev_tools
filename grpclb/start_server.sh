#! /bin/bash

docker build --rm -t greeter_server:v1.0.0 .

docker run -it --rm --net=host greeter_server:v1.0.0 ./greeter_server