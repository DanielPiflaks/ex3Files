//
// Created by danielpiflaks on 26/11/17.
//

#ifndef EX3_ALPLAYER_H
#define EX3_ALPLAYER_H


#include "Player.h"
#include "MiniMaxSimulator.h"

class AIPlayer : public Player {
public:
    /**
    * Human player constructor bbbbb.
    * @param symbol player symbol
    * @param board board to play on.
    * @param gameLogic game logic to play by.
    */
    AIPlayer(char symbol, Board *board, GameLogic *gameLogic, MiniMaxSimulator *wantedSimulator)
            : Player(symbol, board,
                     gameLogic) {simulator = wantedSimulator;};

    /**
     * Destructor.
     */
    ~AIPlayer();

    /**
     * Plays one turn and returns vector of board coordinates that has been flipped.
     * @return vector of board coordinates that has been flipped
     */
    virtual vector<BoardCoordinates> playOneTurn();

private:
    MiniMaxSimulator *simulator;
};


#endif //EX3_ALPLAYER_H
