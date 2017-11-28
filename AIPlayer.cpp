//
// Created by danielpiflaks on 26/11/17.
//

#include "BoardCoordinates.h"
#include "AIPlayer.h"

vector<BoardCoordinates> AIPlayer::playOneTurn() {
    bool firstTime = true;
    //Get map of all possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves = gameLogic->getPossibleGameMoves(playerMoves,
                                                                                                     symbol);
    //Initialize move to default.
    BoardCoordinates wantedMove(0, 0);
    //Set max to be zero.
    int min = 0;
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        //Check on each possible move.
        for (int i = 0; i < moves->second.size(); i++) {
            //Get single move.
            BoardCoordinates singleMove = moves->second[i];
            //Get delta of moves.
            int delta = simulator->getScoreByMove(possibleMoves, singleMove);
            if (firstTime) {
                wantedMove = singleMove;
                min = delta;
                firstTime = false;
            }

            //Check if delta
            if (delta < min) {
                wantedMove = singleMove;
                min = delta;
            }
        }
    }

    vector<BoardCoordinates> flippedSymbols;

    if (board->isOnBoard(wantedMove.getRow(), wantedMove.getColumn())) {
        //Get flipped symbols vector.
        flippedSymbols = gameLogic->flipSymbols(possibleMoves,
                                                wantedMove, getSymbol());
        cout << endl;

        cout << getSymbol() << " Played" << wantedMove << endl;
        cout << endl;
        return flippedSymbols;
    } else {
        cout << "No possible moves." << endl;
        cout << endl;
        //Return empty vector.
        return flippedSymbols;
    }
}

AIPlayer::~AIPlayer() {
    delete simulator;
}