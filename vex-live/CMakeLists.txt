set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE VEX_LIVE_SOURCE_FILES src/*.cpp src/*.h)

add_executable(vex-live ${VEX_LIVE_SOURCE_FILES})

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(vex-live PUBLIC -D_DEBUG)
endif ()

target_include_directories(vex-live PUBLIC ${PROJECT_SOURCE_DIR}/vex/src/)
target_link_libraries(vex-live PUBLIC vex)
