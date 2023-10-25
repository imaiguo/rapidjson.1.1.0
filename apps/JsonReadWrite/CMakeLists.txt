cmake_minimum_required(VERSION 3.15)

project (JsonParse LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

add_executable(${PROJECT_NAME}
        main.cc
    )

include_directories(
        D:\\workspace\\rapidjson.1.1.0\\include
    )