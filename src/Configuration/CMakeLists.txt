cmake_minimum_required(VERSION 3.2)
project(Configuration C CXX)

set(SOURCE_FILES
    Configuration.h
    Configuration.cpp
)

add_library(Configuration SHARED STATIC ${SOURCE_FILES})

install(TARGETS Configuration DESTINATION ${TRAKOR_INSTALL_LIB_DIR})
install(FILES Configuration.h DESTINATION ${TRAKOR_INSTALL_INCLUDE_DIR})