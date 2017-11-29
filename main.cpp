/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#include <limits>
#include "GameParameters.h"
#include "Game.h"

int main() {
    const int numberRows = 8;
    const int numberColumns = 8;

    //Create bool parameter for while loop to get player wanted player.
    bool waitingForInput = true;
    GameParameters::PlayerOptions player2Type;
    int input;
    while (waitingForInput) {
        cout << "choose your opponent(press 1 or 2 then enter):" << endl;
        cout << "1. Al player" << endl << "2. human player" << endl;

        cin >> input;
        //If input is 1, then the game is against al player.
        if (input == 1) {
            //If input is 1, then the game is against al player.
            player2Type = GameParameters::AlPlayerOp;
            waitingForInput = false;
        } else if (input == 2) {
            //If input is 2, then the game is against human player.
            player2Type = GameParameters::HumanPlayerOp;
            waitingForInput = false;
        }
        //Clear not valid input.
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    //Create game parameters.
    GameParameters gameParameters(GameParameters::HumanPlayerOp, 'x',
                                  GameParameters::PlayerOptions(player2Type), 'o',
                                  numberRows, numberColumns);
    //Create game with those parameters.
    Game game(gameParameters);
    //Run single game.
    game.RunSingleGame();

    return 0;
}