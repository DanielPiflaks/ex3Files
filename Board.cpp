/******************************************
Student name: Daniel Piflaks
Student ID: 311322986
Course Exercise Group: 05
Exercise name: Ex2
******************************************/
#include "Board.h"

/************************************************************************
function name: Board.
The Input: int numRows, int numCols.
The output: none.
The Function operation: Constructor of board.
*************************************************************************/
Board::Board(int numRows, int numCols) : numRows(numRows), numCols(numCols) {
    boardMatrix = new char *[numRows];
    for (int i = 0; i < numRows; ++i) {
        boardMatrix[i] = new char[numCols];
    }

    for (int j = 0; j < numRows; j++) {
        for (int i = 0; i < numCols; i++) {
            boardMatrix[j][i] = ' ';
        }
    }
}

Board::Board(const Board &oldBoard) {
    boardMatrix = new char *[oldBoard.getNumCols()];
    numRows = oldBoard.numRows;
    numCols = oldBoard.numCols;
    for (int i = 0; i < oldBoard.getNumRows(); ++i) {
        boardMatrix[i] = new char[oldBoard.getNumCols()];
    }

    for (int j = 0; j < oldBoard.numRows; j++) {
        for (int i = 0; i < oldBoard.numCols; i++) {
            putSymbolOnBoard(j + 1, i + 1, oldBoard.getSymbolByPlace(j + 1, i + 1));
        }
    }

    numCols = oldBoard.numCols;
    numRows = oldBoard.numRows;
}


/************************************************************************
function name: drawBoard.
The Input: none.
The output: none.
The Function operation: Draws board.
*************************************************************************/
void Board::drawBoard() const {
    //Print columns.
    for (int j = 0; j <= numCols; j++) {
        if (j == 0) {
            cout << " | ";
        } else {
            cout << j << " | ";
        }
    }
    cout << endl;

    //Print rows.
    for (int i = 1; i <= numRows; i++) {
        for (int k = 0; k < (numCols * 4) + 2; ++k) {
            cout << "-";
        }
        cout << endl;
        cout << i << "|";
        for (int j = 1; j <= numCols; j++) {
            cout << " " << boardMatrix[i - 1][j - 1] << " |";
        }
        cout << endl;
    }
    for (int k = 0; k < (numCols * 4) + 2; ++k) {
        cout << "-";
    }
    cout << endl;
}

void Board::freeBoardMatrix() {
    for (int i = 0; i < numCols; ++i) {
        delete[] boardMatrix[i];
    }
    delete[] boardMatrix;
}

void Board::putSymbolOnBoard(int row, int column, char symbol) {

    if ((row < 0) || (row > numRows)) {
        cout << "Invalid row number." << endl;
        if ((column < 0) || (column > numCols)) {
            cout << "Invalid column number." << endl;
        }
    } else {
        if ((column < 0) || (column > numCols)) {
            cout << "Invalid column number." << endl;
        } else {
            boardMatrix[row - 1][column - 1] = symbol;
        }
    }
}

Board::~Board() {
    freeBoardMatrix();
}

int Board::getNumRows() const {
    return numRows;
}

int Board::getNumCols() const {
    return numCols;
}

char Board::getSymbolByPlace(int row, int column) const {
    if (!isOnBoard(row, column)) {
        throw "Invalid place!";
    }
    return boardMatrix[row - 1][column - 1];
}

bool Board::isOnBoard(int row, int column) const{
    return ((row > 0) && (row <= numRows) && (column > 0) && (column <= numCols));
}

bool Board::operator==(const Board &board) const {
    if ((numRows == board.getNumRows() && (numCols == board.getNumCols()))) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (getSymbolByPlace(i + 1, j + 1) != (board.getSymbolByPlace(i + 1, j + 1))) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}



