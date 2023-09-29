cmake_minimum_required(VERSION 3.22)

project(SoftSysProcessesSyscalls
    VERSION 1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Wshadow -Wconversion -Wunreachable-code -O0 -g")

set(CMAKE_C_CLANG_TIDY "clang-tidy")

add_subdirectory(src)
