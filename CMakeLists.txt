cmake_minimum_required(VERSION 3.27)
project(n)

set(CMAKE_CXX_STANDARD 23)

add_executable(n main.cpp
        Network/matrixMath/matrixMath.cpp
        Network/matrixMath/matrixMath.h
        Network/Network.cpp
        Network/Network.h
        "user Interface/Menu.cpp"
        "user Interface/Menu.h"
        settings/paths.h
)
