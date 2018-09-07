cmake_minimum_required(VERSION 3.10)
project(demogdb)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_SOURCE_DIR .)

# 配置gdb调试
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g3 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 指定生成目标

add_executable(demogdb main.cpp)