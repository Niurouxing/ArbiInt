cmake_minimum_required(VERSION 3.29.0)
project(ArbiInt VERSION 0.1.0 LANGUAGES C CXX)

 
# set C++ 23
set(CMAKE_CXX_STANDARD 23)
 

# all header files in include
include_directories(include)

# 创建可执行文件
add_executable(temp main.cpp)

 