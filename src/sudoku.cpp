#include "sudoku.h"
#include <iostream>
//#include <sstream>


Sudoku::Sudoku() {
    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            solvedBoard[i][j] = 0;
            board[i][j] = 0;
        }
    }
}

void Sudoku::printGrid(std::ostream& out = std::cout) {
    out << "  ";
    for (unsigned int i = 0; i < 9; i++) {
        out << i << " ";
    }
    out << std::endl;
    unsigned int counter = 0;
    for (unsigned int i = 0; i < 9; i++) {
        out << counter << " ";
        counter++;
        for (unsigned int j = 0; j < 9; j++) {
            out << solvedBoard[i][j] << " ";
        }
        out << std::endl;
    }
}