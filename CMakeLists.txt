cmake_minimum_required(VERSION 3.5.1)

project(xdiff VERSION "0.1" LANGUAGES C)

file(GLOB SRC "*.c" "*.h")
list(SORT SRC)

set(CMAKE_C_FLAGS "-DXDL_HAVE_REGEX")

add_library(xdiff STATIC ${SRC})
