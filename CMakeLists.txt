cmake_minimum_required(VERSION 3.10)
project(TicTacToeC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_subdirectory(util)
add_subdirectory(test)

add_executable(TicTacToeC main.c)
target_link_libraries(TicTacToeC util)