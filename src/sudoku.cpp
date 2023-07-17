#include "sudoku.h"
#include <iostream>
#include <cstdlib>
//#include <sstream>


Sudoku::Sudoku() {
    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            solvedBoard[i][j] = 0;
            //board[i][j] = 0;
        }
    }
}

void Sudoku::printBoard(std::ostream& out = std::cout) {
    /*out << "  ";
    for (unsigned int i = 0; i < 9; i++) {
        out << i << " ";
    }
    */
    out << std::endl;
    unsigned int counter = 0;
    for (unsigned int i = 0; i < 9; i++) {
        //out << counter << " ";
        counter++;
        for (unsigned int j = 0; j < 9; j++) {
            out << std::abs(solvedBoard[i][j]) << " ";
        }
        out << std::endl;
    }
}

bool Sudoku::setPosition(int num, unsigned int row, unsigned int col) {
    if (solvedBoard[row][col] == 0) {
        solvedBoard[row][col] = num;
        return true;
    }
    return false;
}

bool Sudoku::erasePosition(unsigned int row, unsigned int col) {
    //checks if the number is not a starting number
    if (solvedBoard[row][col] >= 0) {
        solvedBoard[row][col] = 0;
        return true;
    }
    return false;
}

void Sudoku::makeTestStartingBoard() {
    solvedBoard[0][0] = -8;
    solvedBoard[0][4] = -4;
    solvedBoard[0][6] = -9;
    solvedBoard[0][7] = -1;
    solvedBoard[1][2] = -3;
    solvedBoard[1][3] = -5;
    solvedBoard[2][6] = -2;
    solvedBoard[3][0] = -5;
    solvedBoard[3][1] = -8;
    solvedBoard[3][2] = -6;
    solvedBoard[4][5] = -9;
    solvedBoard[5][4] = -7;
    solvedBoard[5][8] = -8;
    solvedBoard[6][4] = -3;
    solvedBoard[6][6] = -7;
    solvedBoard[6][8] = -6;
    solvedBoard[7][2] = -9;
    solvedBoard[7][8] = -5;
    solvedBoard[8][0] = -3;
    solvedBoard[8][1] = -7;
    solvedBoard[8][4] = -2;
}

bool Sudoku::solveBoard() {
    return solveBoard(0,0);
}


bool Sudoku::isValidPos(unsigned int row, unsigned int col) {
    //checks the position is not a starting position or an empty square
    if (solvedBoard[row][col] <= 0) return true;
    if (validBox(row, col) && validRow(row, col) && validCol(row, col)) return true;
    return false;
}

bool Sudoku::validBox(unsigned int checkingrow, unsigned int checkingcol) {
    unsigned int startingrow = row - (row % 3);
    unsigned int startingcol = col - (col % 3);
    int element = solvedBoard[checkingrow][checkingcol];
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            unsigned int row = startingrow + i;
            unsigned int col = startingcol + j;
            if (row != checkingrow && col != checkingcol) {
                if (solvedBoard[row][col] == element) return false;
            }
        }
    }
    return true;
}

bool Sudoku::validCol(unsigned int checkingrow, unsigned int checkingcol) {
    for (unsigned int i = 0; i < 9; i++) {
        if (i != checkingrow) {
            if (solvedBoard[i][checkingcol] == solvedBoard[checkingrow][checkingcol]) return false;
        }
    }
    return true;
}


bool Sudoku::validRow(unsigned int checkingrow, unsigned int checkingcol) {
    for (unsigned int i = 0; i < 9; i++) {
        if (i != checkingcol) {
            if (solvedBoard[checkingrow][i] == solvedBoard[checkingrow][checkingcol]) return false;
        }
    }
    return true;
}

bool Sudoku::isValidBoard() {
    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            if (!isValidPos(i,j)) return false;
        }
    }
    return true;
}

bool Sudoku::solveBoard(unsigned int row, unsigned int col) {

}