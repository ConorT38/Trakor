cmake_minimum_required(VERSION 3.2)

project(trakor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

set(TRAKOR_INSTALL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TRAKOR_INSTALL_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(TRAKOR_INSTALL_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

include_directories(${TRAKOR_INSTALL_INCLUDE_DIR})
include_directories(${TRAKOR_INSTALL_LIB_DIR})
link_directories(${TRAKOR_INSTALL_LIB_DIR})

add_subdirectory(src)

