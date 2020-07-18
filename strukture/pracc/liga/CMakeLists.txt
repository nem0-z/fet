cmake_minimum_required(VERSION 3.16)

project(liga)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

set(HEADERS
  include/liga.hpp
)

set(SOURCES
  src/liga.cpp
)

add_library(core ${HEADERS} ${SOURCES})

target_include_directories(core
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

add_executable(liga main.cpp)

target_link_libraries(liga
  core
)
