cmake_minimum_required(VERSION 3.16)
project(TicTacToeC C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(util)

add_executable(TicTacToeC main.c)
target_link_libraries(TicTacToe util)