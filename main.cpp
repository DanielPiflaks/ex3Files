/******************************************
Student name: Daniel Piflaks
Student ID: 311322986
Course Exercise Group: 05
Exercise name: Ex2
******************************************/
#include <limits>
#include "GameParameters.h"
#include "Game.h"

int main() {
    const int numberRows = 4;
    const int numberColumns = 4;

    bool waitingForInput = true;
    GameParameters::PlayerOptions player2Type;
    int input;
    while (waitingForInput) {
        cout << "choose your opponent(press 1 or 2 then enter):" << endl;
        cout << "1. Al player" << endl << "2. human player" << endl;

        cin >> input;

        if (input == 1) {
            player2Type = GameParameters::AlPlayerOp;
            waitingForInput = false;
        } else if (input == 2) {
            player2Type = GameParameters::HumanPlayerOp;
            waitingForInput = false;
        }
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