#ifndef SUDOKU
#define SUDOKU

#include <iostream>
//#include <sstream>
#include <string>

class Sudoku {
    public:
    Sudoku();    
    void printGrid(std::ostream& out = std::cout);
    bool setPosition(int num, unsigned int row, unsigned int col);
    bool erasePosition(unsigned int row, unsigned int col);
    bool setStartingPosition(int num, unsigned int row, unsigned int col);
    bool compareBoard();

    void makeTestStartingBoard();

    private:
    int solvedBoard[9][9];
    int board[9][9];


    bool isValidPos(unsigned int row, unsigned int col);
    bool isValidBoard();

    void solveGrid();

};

#endif