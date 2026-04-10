cmake_minimum_required(VERSION 3.10)

project(MySDLApp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(app ${SRC_FILES})

target_include_directories(app PRIVATE
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/SDL3/include"
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/components"
)

target_link_directories(app PRIVATE SDL3/lib)
target_link_libraries(app SDL3)