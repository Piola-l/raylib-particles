cmake_minimum_required(VERSION 3.16)
project(raylib-particles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/particle.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Optionally, link extra libraries for Linux
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread dl m)
endif()