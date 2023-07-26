# Conway's Game of Life in C

## Introduction

This is an implementation of Conway's Game of Life in C. The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game that evolves based on its initial state and follows simple rules to create fascinating patterns and behaviors.

## Rules of the Game

The Game of Life is played on a 2D grid, where each cell can be either alive or dead. The game evolves in generations, and the next generation is determined by the following rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation).
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies (overpopulation).
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

## Getting Started

### Prerequisites

Ensure you have a C compiler installed on your system. This project was tested with [GCC](https://gcc.gnu.org/), but other C compilers should work as well.

### Compiling the Code

To compile the Game of Life, use the following command in the root directory of the project:

```bash
gcc src/* -o game_of_life
```

### Running the Game

To run the Game of Life, use the following command in the root directory of the project:

```bash
./game_of_life
```


