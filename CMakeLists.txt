cmake_minimum_required(VERSION 3.10)
project(ToDoList)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
link_directories(${FLTK_LIBRARY_DIR})

add_executable(ToDoList src/main.cpp src/ToDoList.cpp)
target_link_libraries(ToDoList ${FLTK_LIBRARIES})
