cmake_minimum_required(VERSION  3.16)
project(XTPReader)
add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g")

find_package(pybind11 REQUIRED)

INCLUDE_DIRECTORIES(
        ${pybind11_INCLUDE_DIRS}
        include
)

message(STATUS "CMAKE_INSTALL_LIBDIR" ${CMAKE_INSTALL_LIBDIR})

include_directories(include)

set(CPP_SOURCE_CODE_LIST
        src/XTPReader.cc)

add_library(XTPReader_c
        ${CPP_SOURCE_CODE_LIST})
add_executable(read_test src/main.cc)
target_link_libraries(read_test XTPReader_c pthread)

pybind11_add_module(XTPReader
        src/RD_py.cc
        ${CPP_SOURCE_CODE_LIST})
