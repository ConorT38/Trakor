cmake_minimum_required(VERSION 3.2)

add_subdirectory(Controller)
#add_subdirectory(Database)
add_subdirectory(Trakor)

set(SOURCE_FILES Main.cpp)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(trakor ${SOURCE_FILES})

target_link_libraries(trakor PUBLIC PkgConfig::Pistache)
target_link_libraries(trakor   PUBLIC Controller)
#target_link_libraries(trakor   PUBLIC Database)
target_link_libraries(trakor   PUBLIC Trakor)

    
target_link_libraries(trakor PUBLIC ${TRAKOR_INSTALL_LIB_DIR}/libConLogger.a)

install(TARGETS trakor DESTINATION ${TRAKOR_INSTALL_BIN_DIR})
