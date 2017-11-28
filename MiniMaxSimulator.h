//
// Created by danielpiflaks on 26/11/17.
//

#ifndef EX3_MINIMAXSIMULATOR_H
#define EX3_MINIMAXSIMULATOR_H


#include "Player.h"

class MiniMaxSimulator {
public:
    MiniMaxSimulator(GameLogic *gameLogic);

    ~MiniMaxSimulator();

    int getScoreByMove(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                       BoardCoordinates move);

    void setComputerPlayer(Player *computerPlayer);

    void setOpponent(Player *opponent);

private:
    Player *computerPlayer;
    Player *opponent;
    GameLogic *gameLogic;

    void copyBoardContent(Board oldBoard, Board *currentBoard);
};


#endif //EX3_MINIMAXSIMULATOR_H
