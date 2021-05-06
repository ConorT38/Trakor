cmake_minimum_required(VERSION 3.2)
project(Trakor C CXX)

set(SOURCE_FILES
    Leech.h
    Leech.cpp
    Peer.h
    Peer.cpp
    Seeder.h
    Seeder.cpp
)

add_library(Trakor SHARED STATIC ${SOURCE_FILES})

install(TARGETS Trakor DESTINATION ${TRAKOR_INSTALL_LIB_DIR})
install(FILES Leech.h Peer.h Seeder.h DESTINATION ${TRAKOR_INSTALL_INCLUDE_DIR})
