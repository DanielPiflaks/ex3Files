/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#include "Board.h"
#include "Player.h"
#include "GameParameters.h"
#include "HumanPlayer.h"
#include "StandartGameLogic.h"
#include "MiniMaxSimulator.h"
#include "AIPlayer.h"

GameParameters::GameParameters(PlayerOptions player1Type, char player1Symbol, PlayerOptions player2Type,
                               char player2Symbol,
                               int numRows, int numColumns, StartFirstOptions startFirst,
                               GameLogicOptions gameLogicOption)
        : gameBoard(gameBoard), startFirst(startFirst) {
    //Create new game board.
    gameBoard = new Board(numRows, numColumns);

    //Create game logic by input.
    switch (gameLogicOption) {
        case StandartGame: {
            gameLogic = new StandartGameLogic(gameBoard);
            break;
        }
    }

    //Create 2 simulator in case that one of players is computer.
    MiniMaxSimulator *simulatorPlayer1 = new MiniMaxSimulator(gameLogic);
    MiniMaxSimulator *simulatorPlayer2 = new MiniMaxSimulator(gameLogic);

    //Create player 1 by it's symbol and type.
    switch (player1Type) {
        case HumanPlayerOp: {
            player1 = new HumanPlayer(player1Symbol, gameBoard, gameLogic);
            break;
        }
        case AlPlayerOp: {
            player1 = new AIPlayer(player1Symbol, gameBoard, gameLogic, simulatorPlayer1);
            break;
        }
        case NetPlayerOp:
            break;
        default:
            break;
    }
    //Create player 2 by it's symbol and type.
    switch (player2Type) {
        case HumanPlayerOp: {
            player2 = new HumanPlayer(player2Symbol, gameBoard, gameLogic);
            break;
        }
        case AlPlayerOp: {
            player2 = new AIPlayer(player2Symbol, gameBoard, gameLogic, simulatorPlayer2);
            break;
        }
        case NetPlayerOp:
            break;
        default:
            break;
    }

    //Check if first player is computer player
    if (player1Type == AlPlayerOp) {
        //Set players for simulators.
        simulatorPlayer1->setOpponent(player2);
        simulatorPlayer1->setComputerPlayer(player1);
    } else {
        //If not, delete the simulator.
        delete simulatorPlayer1;
    }
    //Check if second player is computer player
    if (player2Type == AlPlayerOp) {
        //Set players for simulators.
        simulatorPlayer2->setOpponent(player1);
        simulatorPlayer2->setComputerPlayer(player2);
    } else {
        //If not, delete the simulator.
        simulatorPlayer2;
    }

}


Board *GameParameters::getGameBoard() {
    return gameBoard;
}


Player *GameParameters::getPlayer2() const {
    return player2;
}

GameParameters::StartFirstOptions GameParameters::getStartFirst() const {
    return startFirst;
}

Player *GameParameters::getPlayer1() const {
    return player1;
}

GameParameters::~GameParameters() {
    delete gameBoard;
    delete gameLogic;
    delete player1;
    delete player2;
}
