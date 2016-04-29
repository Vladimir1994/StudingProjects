project(MatrixTask)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

FILE(GLOB_RECURSE HppFiles "*.hpp")
add_custom_target(headers SOURCES ${HppFiles})
FILE(GLOB_RECURSE TppFiles "*.tpp")
add_custom_target(templates SOURCES ${TppFiles})

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})


