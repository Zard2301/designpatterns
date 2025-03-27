cmake_minimum_required(VERSION 3.16)

project(DesignPatterns)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DP_TYPE "ALL" CACHE STRING "Select Design Patterns example")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -Wall -O3 -g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -O3 -g3")

if (BUILD_DP_TYPE STREQUAL "SP")
    message("Select Strategy Patterns example: Duck")
    add_subdirectory(Duck)
elseif (BUILD_DP_TYPE STREQUAL "OP")
    message("Select Observer Patterns example: WeatherData")
    add_subdirectory(WeatherData)
else()
    message("Select all of the example")
    add_subdirectory(Duck)
    add_subdirectory(WeatherData)
endif()
