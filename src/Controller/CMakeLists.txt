cmake_minimum_required(VERSION 3.2)
project(Controller C CXX)

set(SOURCE_FILES
    SearchController.h
    SearchController.cpp
)

add_library(Controller SHARED STATIC ${SOURCE_FILES})

install(TARGETS Controller DESTINATION ${TRAKOR_INSTALL_LIB_DIR})
install(FILES SearchController.h DESTINATION ${TRAKOR_INSTALL_INCLUDE_DIR})