cmake_minimum_required(VERSION 3.5)

project(include)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/clib/*.h)

install(FILES ${HEADERS} DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clib")

