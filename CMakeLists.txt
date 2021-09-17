cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 11)

include_directories(minilibx-linux)

add_library(minilibx-linux/libmlx_Linux.a)

add_executable(so_long
        minilibx-linux/mlx.h
        minilibx-linux/mlx_init.c
        minilibx-linux/mlx_int.h
        main.c)
