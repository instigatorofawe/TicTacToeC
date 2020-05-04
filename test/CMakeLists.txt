add_executable(run_unit_tests test_board.cpp test_game_tree.cpp test_game.cpp test_monte_carlo.cpp)

target_link_libraries(run_unit_tests gtest gtest_main pthread util m)