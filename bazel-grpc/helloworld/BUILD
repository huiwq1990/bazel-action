package(default_visibility = ["//visibility:public"])

# proto rules
load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cc_proto_library")
load("@org_pubref_rules_protobuf//python:rules.bzl", "py_proto_library")

# docker image rules
load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")
load("@io_bazel_rules_docker//python:image.bzl", "py_image")

cc_proto_library(
    name = "helloworld_proto",
    protos = ["helloworld.proto"],
    with_grpc = True,
)

cc_binary(
    name = "greeter_async_client",
    srcs = ["greeter_async_client.cc"],
    deps = [
        ":helloworld_proto",
    ],
)

cc_binary(
    name = "greeter_async_server",
    srcs = ["greeter_async_server.cc"],
    deps = [
        ":helloworld_proto",
    ],
)

#cc_image(
#    name = "echo_server_image",
#    srcs = ["echo_server.cc"],
#    deps = [
#        ":cc_echo_proto",
#    ],
#)
#

#
#
#cc_binary(
#    name = "echo_async",
#    srcs = ["echo_async.cc"],
#    deps = [
#        ":cc_echo_proto",
#    ],
#)