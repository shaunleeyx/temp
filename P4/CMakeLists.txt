cmake_minimum_required(VERSION 3.14)
project(P2)

set(CMAKE_CXX_STANDARD 11)

add_executable(P2 main.cpp actuator.cpp actuator.h robot.cpp robot.h sensor.cpp sensor.h)