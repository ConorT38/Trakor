cmake_minimum_required(VERSION 3.2)

add_subdirectory(Configuration)
add_subdirectory(Controller)
add_subdirectory(Http)
add_subdirectory(Database)
add_subdirectory(Trakor)

set(SOURCE_FILES Main.cpp)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(trakor ${SOURCE_FILES} "../trakor.cfg")

target_link_libraries(trakor PUBLIC PkgConfig::Pistache)
target_link_libraries(trakor PUBLIC Controller)
target_link_libraries(trakor PUBLIC Database)
target_link_libraries(trakor PUBLIC Trakor)
target_link_libraries(trakor PUBLIC Http)
target_link_libraries(trakor PUBLIC Configuration)
target_link_libraries(trakor PUBLIC mysqlcppconn)

    
target_link_libraries(trakor PUBLIC ${TRAKOR_INSTALL_LIB_DIR}/libConLogger.a)

install(TARGETS trakor DESTINATION ${TRAKOR_INSTALL_BIN_DIR})
