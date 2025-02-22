cmake_minimum_required(VERSION 3.0)

project(Stormcraft)

FILE(GLOB SOURCE_FILES Source/*.c)

add_executable(
    craft
    ${SOURCE_FILES}
    Deps/glew/src/glew.c
    Deps/lodepng/lodepng.c
    Deps/noise/noise.c
    Deps/sqlite/sqlite3.c
    Deps/tinycthread/tinycthread.c)

add_definitions(-std=c99 -O3)

add_subdirectory(Deps/glfw)
include_directories(Deps/glew/include)
include_directories(Deps/glfw/include)
include_directories(Deps/lodepng)
include_directories(Deps/noise)
include_directories(Deps/sqlite)
include_directories(Deps/tinycthread)

if(APPLE)
    target_link_libraries(craft glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(UNIX)
    target_link_libraries(craft dl glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(MINGW)
    target_link_libraries(craft ws2_32.lib glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()
