cmake_minimum_required(VERSION 3.5)
project(todolist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES ToDoList.cpp ToDoList.h)
add_executable(todolist main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(todolist core)