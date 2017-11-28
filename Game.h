/******************************************
Student name: Daniel Piflaks
Student ID: 311322986
Course Exercise Group: 05
Exercise name: Ex2
******************************************/

#ifndef EX2_GAME_H
#define EX2_GAME_H

using namespace std;

#include <iostream>
#include <list>
#include <vector>
#include "Player.h"
#include "GameParameters.h"
#include "BoardCoordinates.h"

class Game {
public:
    /**
     * Game constructor.
     * @param gameParameters game parameters know how to play.
     */
    Game(GameParameters &gameParameters);

    /**
     * Game destructor.
     */
    ~Game();

    /**
     * Runs single game by input game parameters.
     */
    void RunSingleGame();

    /**
     * Puts player symbols to start position.
     */
    void putSymbolsStartPosition();

private:
    Board *gameBoard;
    Player *firstPlayer;
    Player *secondPlayer;
};

#endif //EX2_GAME_H
