cmake_minimum_required(VERSION 3.17)
project(CN_CA3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Main Source/main.cpp Source/Node.cpp Source/Node.h Source/Network.cpp Source/Network.h Source/CommandParser.cpp Source/CommandParser.h)