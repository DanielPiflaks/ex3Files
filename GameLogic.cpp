/******************************************
Student name: Daniel Piflaks
Student ID: 311322986
Course Exercise Group: 05
Exercise name: Ex2
******************************************/

#include "GameLogic.h"

GameLogic::GameLogic(GameLogic *gameLogic) {
    board = new Board(*gameLogic->board);
}

GameLogic::GameLogic(Board *board) :
        board(board) {
}

GameLogic::~GameLogic() {

}

Board &GameLogic::getBoard() {
    return *board;
}

void GameLogic::flipOnBoard(vector<BoardCoordinates> coordinatesToFlip, char symbol) {
    for (int i = 0; i < coordinatesToFlip.size(); i++) {
        board->putSymbolOnBoard(coordinatesToFlip[i].getRow(),
                                coordinatesToFlip[i].getColumn(), symbol);
    }
}