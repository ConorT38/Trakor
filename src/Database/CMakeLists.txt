cmake_minimum_required(VERSION 3.2)
project(Database C CXX)

set(SOURCE_FILES
    Connection.h
    Connection.cpp
)

add_library(Database SHARED STATIC ${SOURCE_FILES})
target_include_directories(Database PUBLIC "../Configuration")

install(TARGETS Database DESTINATION ${TRAKOR_INSTALL_LIB_DIR})
install(FILES Connection.h DESTINATION ${TRAKOR_INSTALL_INCLUDE_DIR})


