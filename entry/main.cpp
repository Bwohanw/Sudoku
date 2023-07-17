#include <iostream>
#include "../src/sudoku.h"

int main() {
    Sudoku sudoku = Sudoku();
    sudoku.makeTestStartingBoard();
    sudoku.printGrid();
}