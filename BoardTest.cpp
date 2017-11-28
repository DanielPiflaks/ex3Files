#include <gtest/gtest.h>
#include "../src/Board.h"

//Check that copy constructor of board works.
TEST(BoardTest, CopyConstructorCheck) {
    const int boardRow = 4;
    const int boardColumn = 4;
    Board firstBoard(boardRow, boardColumn);
    firstBoard.putSymbolOnBoard(3, 2, 'x');
    firstBoard.putSymbolOnBoard(1, 1, 'o');
    Board copyBoard = firstBoard;
    EXPECT_EQ(copyBoard, firstBoard);
}
//Check that we can't go to invalid place in board.
TEST(BoardTest, NotValidPlaceCheck) {
    const int boardRow = 4;
    const int boardColumn = 4;
    Board boardToCheck(boardRow, boardColumn);

    EXPECT_FALSE(boardToCheck.isOnBoard(-1, -1));
    EXPECT_FALSE(boardToCheck.isOnBoard(314, -1));
    EXPECT_FALSE(boardToCheck.isOnBoard(-34, 34));
    //We want that boar will be inside of the matrix, without 0 0
    EXPECT_FALSE(boardToCheck.isOnBoard(0, 0));

    EXPECT_TRUE(boardToCheck.isOnBoard(4, 4));
    EXPECT_TRUE(boardToCheck.isOnBoard(1, 1));

    EXPECT_ANY_THROW(boardToCheck.getSymbolByPlace(-1, -1));
}