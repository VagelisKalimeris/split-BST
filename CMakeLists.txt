cmake_minimum_required(VERSION 3.22)
project(splitBST C)

set(CMAKE_C_STANDARD 99)

add_executable(splitBST SRC/main.c SRC/print_by_layer.c SRC/tree_node.c)
