cmake_minimum_required(VERSION 3.23)
project(vex)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE CPP_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_executable(vex ${CPP_SOURCE_FILES})

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG)
endif ()

target_include_directories(vex PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/include/)
target_link_directories(vex PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/lib/x64/)

target_link_libraries(vex PUBLIC pugixml spdlog glfw3)

if (UNIX)
    target_link_libraries(vex PUBLIC dl pthread)
endif (UNIX)
