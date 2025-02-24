cmake_minimum_required(VERSION 3.0)

project(stormcraft)

FILE(GLOB SOURCE_FILES Source/*.c)

add_executable(
    Stormcraft
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

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_mixer REQUIRED SDL2_mixer)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_mixer_INCLUDE_DIRS})

if(MINGW)
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH}
        "C:/Program Files/CURL/lib" "C:/Program Files (x86)/CURL/lib")
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH}
        "C:/Program Files/CURL/include" "C:/Program Files (x86)/CURL/include")
endif()

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

# Link libraries
if(APPLE)
    target_link_libraries(craft glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2_mixer_LIBRARIES})
endif()
