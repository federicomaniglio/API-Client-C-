cmake_minimum_required(VERSION 3.27)
project(API)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/curl/include)
include_directories(${PROJECT_SOURCE_DIR}/json-3.11.3/single_include)

link_directories(${PROJECT_SOURCE_DIR}/curl/lib)

add_executable(API main.cpp)

target_link_libraries(API ${PROJECT_SOURCE_DIR}/curl/lib/libcurl.dll.a)


