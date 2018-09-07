# Stage 3

In this stage we step it up and showcase how to integrate multiple ```cc_library``` targets from different packages.

Below, we see a similar configuration from Stage 2, except that this BUILD file is in a subdirectory called lib. In Bazel, subdirectories containing BUILD files are known as packages. The new property ```visibility``` will tell Bazel which package(s) can reference this target, in this case the ```//main``` package can use ```hello-time``` library. 

```
cc_library(
    name = "hello-time",
    srcs = ["hello-time.cc"],
    hdrs = ["hello-time.h"],
    visibility = ["//main:__pkg__"],
)
```

To use our ```hello-time``` libary, an extra dependency is added in the form of //path/to/package:target_name, in this case, it's ```//lib:hello-time```

```
cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = [
        ":hello-greet",
        "//lib:hello-time",
    ],
)
```

To build this example you use (notice that 3 slashes are required in windows)
```
bazel build //main:hello-world

# In Windows, note the three slashes

bazel build ///main:hello-world
```


### bazel debug

bazel build ... --compilation_mode=dbg -s

gdbtui bazel-bin/main/hello-world


gdbserver 0.0.0.0:1234 bazel-bin/main/hello-world

gdbserver 0.0.0.0:1234 bazel-out/k8-dbg/bin/main/hello-world

gdb  bazel-bin/main/hello-world


bazel build --tool_tag=ijwb:CLion --compilation_mode=dbg --copt=-O0 --copt=-g --strip=never --dynamic_mode=off --curses=no --color=yes --experimental_ui=no ///main:hello-world



Command: bazel build --tool_tag=ijwb:CLion --compilation_mode=dbg --copt=-O0 --copt=-g --strip=never --dynamic_mode=off --curses=no --color=yes --experimental_ui=no --progress_in_terminal_title=no --build_event_binary_file=/tmp/intellij-bep-80ee286c-af16-4392-968c-fdeefff7d21e --nobuild_event_binary_file_path_conversion -- //main:hello-world
