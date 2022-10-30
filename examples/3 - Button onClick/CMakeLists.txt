cmake_minimum_required(VERSION 3.22)
project(App)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../vex/src/)

file(GLOB_RECURSE CPP_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_library(app SHARED ${CPP_SOURCE_FILES})

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG)
endif ()

target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/include/)

add_custom_command(TARGET app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:app> ${CMAKE_CURRENT_SOURCE_DIR}
        )
