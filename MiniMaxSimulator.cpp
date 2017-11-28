//
// Created by danielpiflaks on 26/11/17.
//

#include "MiniMaxSimulator.h"

MiniMaxSimulator::MiniMaxSimulator(GameLogic *gameLogic) : gameLogic(gameLogic) {}


MiniMaxSimulator::~MiniMaxSimulator() {

}

int MiniMaxSimulator::getScoreByMove(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                     BoardCoordinates move) {
    Board savedBoard = gameLogic->getBoard();
    //Get flipped symbols vector.
    vector<BoardCoordinates> flippedSymbols = gameLogic->flipSymbols(allChoices,
                                                                     move, computerPlayer->getSymbol());

    opponent->updatePlayerSymbolRemoved(flippedSymbols);
    computerPlayer->updatePlayerSymbolAdd(flippedSymbols);
    int scoreOpponent = opponent->getScore();
    int scoreComputer = computerPlayer->getScore();

    map<BoardCoordinates, vector<BoardCoordinates> > opponentPossibleMoves = gameLogic->getPossibleGameMoves(
            opponent->getPlayerMoves(),
            opponent->getSymbol());

    int max = 0;
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = opponentPossibleMoves.begin();
         moves != opponentPossibleMoves.end(); ++moves) {
        for (int i = 0; i < moves->second.size(); i++) {
            BoardCoordinates singleMove = moves->second[i];
            int numberOfPossibleFlips = gameLogic->numberOfPossibleFlips(opponentPossibleMoves,
                                                                         singleMove,
                                                                         opponent->getSymbol());
            int scoreOpponentAfterChange = scoreOpponent + numberOfPossibleFlips;
            int scoreComputerAfterChange = scoreComputer - numberOfPossibleFlips + 1;
            int delta = scoreOpponentAfterChange - scoreComputerAfterChange;
            if (delta > max) {
                max = delta;
            }
        }
    }

    opponent->updatePlayerSymbolAdd(flippedSymbols);
    computerPlayer->updatePlayerSymbolRemoved(flippedSymbols);
    copyBoardContent(savedBoard, &gameLogic->getBoard());
    return max;
}

void MiniMaxSimulator::setComputerPlayer(Player *computerPlayer) {
    MiniMaxSimulator::computerPlayer = computerPlayer;
}

void MiniMaxSimulator::setOpponent(Player *opponent) {
    MiniMaxSimulator::opponent = opponent;
}

void MiniMaxSimulator::copyBoardContent(Board oldBoard, Board *currentBoard) {
    for (int i = 0; i < oldBoard.getNumRows(); ++i) {
        for (int j = 0; j < oldBoard.getNumCols(); ++j) {
            currentBoard->putSymbolOnBoard(i + 1, j + 1, oldBoard.getSymbolByPlace(i + 1, j + 1));
        }
    }
}