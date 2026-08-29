cmake_minimum_required(VERSION 3.20)
project(custoprint LANGUAGES C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CONFIGURATION_TYPES
Debug ReleaseFast ReleaseSafe ReleaseSmall
    CACHE STRING "Available build types" FORCE)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_C_FLAGS_DEBUG   "-O0 -g")
set(CMAKE_C_FLAGS_RELEASEFAST   "-O3 -s -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASESAFE  "-O2 -DNDEBUG -D_FORTIFY_SOURCE=2 -fstack-protector-strong -fstack-clash-protection")
set(CMAKE_C_FLAGS_RELEASESMALL    "-Os -s -DNDEBUG")
add_executable(${PROJECT_NAME}
    src/main.c)
target_compile_options(${PROJECT_NAME} PRIVATE
    -pedantic
    -Wall
    -Wextra
    -Wconversion
    -Wsign-conversion)
