cmake_minimum_required(VERSION 3.5)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_SOURCES main.cpp Promemoria.cpp Promemoria.h ListaMemo.cpp ListaMemo.h)

add_executable(LaboratorioProgrammazione main.cpp)

add_library(newlib ${PROJECT_SOURCES})

target_link_libraries(LaboratorioProgrammazione newlib)

add_subdirectory(tests)