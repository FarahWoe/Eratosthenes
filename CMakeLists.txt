cmake_minimum_required(VERSION 3.17)
project(Eratosthenes C)

set(CMAKE_C_STANDARD 99)

add_executable(Eratosthenes main.c)

target_link_libraries(Eratosthenes m)