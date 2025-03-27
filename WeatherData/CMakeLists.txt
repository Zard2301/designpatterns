cmake_minimum_required(VERSION 3.16)

set(APP_NAME WeatherData)
project(${APP_NAME})
set(MAIN_EXECUTABLE ${APP_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE weatherdata_src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
list(APPEND ${MAIN_EXECUTABLE}_src ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

set(ALL_COMPILE_SRC ${${MAIN_EXECUTABLE}_src} ${weatherdata_src})

add_executable(${APP_NAME} ${ALL_COMPILE_SRC})

install(TARGETS ${APP_NAME} RUNTIME DESTINATION output/${APP_NAME}/bin)