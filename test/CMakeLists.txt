cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

aux_source_directory(. SOURCES)

add_executable(clibtest ${SOURCES})

target_link_directories(clibtest PUBLIC ${CMAKE_BINARY_DIR}/src)

target_link_libraries(clibtest clib)
