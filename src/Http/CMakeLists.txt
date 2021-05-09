cmake_minimum_required(VERSION 3.2)
project(Http C CXX)

set(SOURCE_FILES
    Routes.h
    Routes.cpp
)

add_library(Http SHARED STATIC ${SOURCE_FILES})
target_include_directories(Http PUBLIC "../Controller")

install(TARGETS Http DESTINATION ${TRAKOR_INSTALL_LIB_DIR})
install(FILES Routes.h DESTINATION ${TRAKOR_INSTALL_INCLUDE_DIR})