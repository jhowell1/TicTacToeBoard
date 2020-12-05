/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

// toggleTurn
TEST(TicTacToeBoardTest, toggleTurn_getX)
{
	TicTacToeBoard obj;
	obj.setLastTurn(O);
	ASSERT_TRUE(obj.getTurn() == X);
}

TEST(TicTacToeBoardTest, toggleTurn_getO)
{
	TicTacToeBoard obj;
	obj.setLastTurn(O);
	ASSERT_TRUE(obj.getTurn() == O);
}

TEST(TicTacToeBoardTest, toggleTurn_error)
{
	TicTacToeBoard obj;
	obj.setLastTurn(Blank);
	ASSERT_TRUE(obj.getTurn() == Invalid);
}

// placePiece
TEST(TicTacToeBoardTest, placePiece_gameOver)
{
	TicTacToeBoard obj;
	obj.setStatus(true); //set to game over
	ASSERT_TRUE(obj.placePiece(0,0) == Invalid);
}

TEST(TicTacToeBoardTest, placePiece_spotTaken)
{
	TicTacToeBoard obj;
	Piece p = obj.placePiece(0,0);
	Piece spot = obj.getPiece(0,0);
	p = obj.placePiece(0,0);
	ASSERT_TRUE(spot == p);
}

// getPiece
TEST(TicTacToeBoardTest, getPiece_setX)
{
	TicTacToeBoard obj;
	Piece p = obj.placePiece(0,0);
	Piece placedPiece = obj.getLastTurn();
	ASSERT_TRUE(obj.getPiece(0,0) == placedPiece);
}

//TEST(TicTacToeBoardTest, )
//{
//}
