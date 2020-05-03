cmake_minimum_required(VERSION 3.10)
project(TicTacToeC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(/usr/include/gtk-3.0)
include_directories(/usr/include/glib-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/glib-2.0/include)
include_directories(/usr/include/gio-unix-2.0)
include_directories(/usr/include/cairo)
include_directories(/usr/include/pango-1.0)
include_directories(/usr/include/harfbuzz)
include_directories(/usr/include/gdk-pixbuf-2.0)
include_directories(/usr/include/atk-1.0)

add_subdirectory(util)
add_subdirectory(gui)
add_subdirectory(test)

add_executable(TicTacToeC main.c)
target_link_libraries(TicTacToeC util gui m)
target_link_libraries(TicTacToeC gtk-3 gio-2.0 gobject-2.0)