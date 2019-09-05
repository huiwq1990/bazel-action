

bazel build //example:echo_server --compilation_mode=dbg

gdbtui bazel-bin/bin/example/echo_server


bazel run --script_path=/tmp/helloclient //example:echo_client && /tmp/helloclient

bazel run --script_path=/tmp/helloserver //example:echo_server && /tmp/helloserver


bazel run --script_path=/tmp/greeter_async_client //helloworld:greeter_async_client && /tmp/greeter_async_client

bazel run --script_path=/tmp/greeter_async_server //helloworld:greeter_async_server && /tmp/greeter_async_server