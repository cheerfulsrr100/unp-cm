cmake_minimum_required(VERSION 3.21)
project(unp_cm C)

set(CMAKE_C_STANDARD 99)

add_executable(unp_cm main.c sock_ntop.h)
