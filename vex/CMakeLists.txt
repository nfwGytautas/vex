set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE VEX_SOURCE_FILES src/*.cpp src/*.h)

add_library(vex SHARED ${VEX_SOURCE_FILES})

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(vex PUBLIC -D_DEBUG)
endif ()

target_compile_definitions(vex PUBLIC -DGLFW_INCLUDE_NONE)
target_include_directories(vex PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/include/)
target_include_directories(vex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)
target_link_directories(vex PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/lib/x64/)

target_link_libraries(vex PUBLIC pugixml spdlog glfw3 glad efsw glm_static)

if (UNIX)
    target_link_libraries(vex PUBLIC dl pthread)
endif (UNIX)