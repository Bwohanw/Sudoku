#ifndef SUDOKU
#define SUDOKU

#include <iostream>
//#include <sstream>
#include <string>

class Sudoku {
    public:
    Sudoku();
    
    //prints the state of the current board
    void printBoard(std::ostream& out = std::cout);
    bool setPosition(int num, unsigned int row, unsigned int col);
    bool erasePosition(unsigned int row, unsigned int col);


    //bool compareBoard();

    void makeTestStartingBoard();

    bool solveBoard();

    private:

    //board for the sudoku, each entry is a square in the puzzle. A zero represents an empty square,
    //a positive number is a filled in number, and
    //a negative number is a starting number.
    int solvedBoard[9][9];
    //commented out: the board that would be displayed to the player
    //int board[9][9];


    bool validBox(unsigned int checkingrow, unsigned int checkingcol);
    bool validCol(unsigned int checkingrow, unsigned int checkingcol)
    bool validRow(unsigned int checkingrow, unsigned int checkingcol)


    bool isValidPos(unsigned int row, unsigned int col);
    bool isValidBoard();


    bool solveBoard(unsigned int row, unsigned int col);

};

#endif