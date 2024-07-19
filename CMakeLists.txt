cmake_minimum_required(VERSION 3.21)
project(stdutil)

if(NOT UNIX)
    message(FATAL_ERROR "Invalid Operating System '${CMAKE_SYSTEM_NAME}'. You must use a Unix based Operating System.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

file(GLOB SRC_FILES CMAKE_CONFIGURE_DEPENDS "src/*.c")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(libsrc ${SRC_FILES})

add_library(objlib OBJECT ${libsrc})

set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)


add_library(stdutil_shared SHARED $<TARGET_OBJECTS:objlib>)
set_property(TARGET stdutil_shared PROPERTY OUTPUT_NAME stdutil)


add_library(stdutil_static STATIC $<TARGET_OBJECTS:objlib>)
set_property(TARGET stdutil_static PROPERTY OUTPUT_NAME stdutil)