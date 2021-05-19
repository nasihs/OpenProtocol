cmake_minimum_required(VERSION 3.17)
project(MCTS C)

set(CMAKE_C_STANDARD 99)

add_executable(MCTS main.c MonteCarloTreeSearch.c MonteCarloTreeSearch.h moduleA.c moduleA.h moduleB.c moduleB.h game.c game.h)