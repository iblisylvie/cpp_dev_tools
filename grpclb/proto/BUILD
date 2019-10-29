package(default_visibility = ["//visibility:public"])

load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cc_proto_library")

cc_proto_library(
    name = 'helloworld_proto',
    protos = [
    	    'helloworld.proto',
    	],
    verbose = 0,
	with_grpc = True,
)
