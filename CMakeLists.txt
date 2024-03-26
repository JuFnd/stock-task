cmake_minimum_required(VERSION 3.12)
project(StockBook)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES sources/*.cpp)
file(GLOB HEADERS includes/*.h)

add_executable(StockBook ${SOURCES} ${HEADERS})

target_include_directories(StockBook PUBLIC includes)
