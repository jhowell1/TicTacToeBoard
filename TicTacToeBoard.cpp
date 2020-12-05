#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
	
	//for(int i = 0; i < 2; ++i)
	//	lastCoordinates[i] = 0;
	lastTurn = Blank;
	gameOver = false;
}

bool TicTacToeBoard::getStatus()
{
	return gameOver;
}

void TicTacToeBoard::setStatus(bool newStatus)
{
	gameOver = newStatus;
}

Piece** TicTacToeBoard::getBoard()
{
	Piece** ptr = 0;
	for(int i = 0; i < BOARDSIZE; ++i)
		for(int j = 0; j < BOARDSIZE; ++j)
			ptr[i][j] = board[i][j];

	return ptr;
}

void TicTacToeBoard::setBoard(Piece** &arr)
{
	for(int i = 0; i < BOARDSIZE; ++i)
		for(int j = 0; j < BOARDSIZE; ++j)
			board[i][j] = **(arr + i + j * BOARDSIZE);
}

Piece TicTacToeBoard::getTurn()
{
	return turn;
}

void TicTacToeBoard::setTurn(Piece newTurn)
{
	turn = newTurn;
}

Piece TicTacToeBoard::getLastTurn()
{
	return lastTurn;
}

void TicTacToeBoard::setLastTurn(Piece newLast)
{
	lastTurn = newLast;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
	if(lastTurn != X) // last move was from O
		return X;
	else
		return O;
	
  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	// Check if game is ongoing
	if(gameOver)
	{
		//cout << lastTurn << endl;
		return Invalid;
	}

	if(row < 0 || row >= BOARDSIZE || column < 0 || column >= BOARDSIZE)
		return Invalid;

  Piece place;
	if((place = getPiece(row, column)) != Blank) // place already taken
		return place;
	else // place empty
	{
		board[row][column] = turn; // set place
		// check for winner
		lastTurn = turn;
		Piece returnPiece = getWinner(); // get winner if there is one, else get next turn

		return returnPiece;
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	//return lastTurn;
	// horizontal check
	int tally = 1;
	for(int i = 0; i < BOARDSIZE; ++i)
	{
		Piece currentPiece = board[i][0];
		if(currentPiece != X || currentPiece != O)
			continue;

		for(int j = 1; j < BOARDSIZE; ++j)
		{
			if(board[i][j] != currentPiece)
			{
				tally = 1;
				break;
			}

			if(++tally == 3)
			{
				gameOver = true;
				return currentPiece;
			}
		}
	}

	// vertical check
	for(int j = 0; j < BOARDSIZE; ++j)
  {
    Piece currentPiece = board[j][0];
    if(currentPiece != X || currentPiece != O)
		  continue;

    for(int i = 1; i < BOARDSIZE; ++i)
    {
      if(board[i][j] != currentPiece)
      {
        tally = 1;
        break;
			}

      if(++tally == 3)
      {
        gameOver = true;
				return currentPiece;
      }
		}
	}

	// diagonal checks
	tally = 1;
	Piece currentPiece = board[0][0];
	for(int i = 1; i < BOARDSIZE; ++i)
	{
		if(currentPiece != X || currentPiece != O)
			continue;

		if(board[i][i] != currentPiece)
		{
			tally = 1;
			break;
		}

		if(++tally == 3)
		{
			gameOver = true;
			return currentPiece;
		}
	}

  tally = 1;
  currentPiece = board[2][0];
	for(int j = 1; j < BOARDSIZE; ++j)
	{
    if(currentPiece != X || currentPiece != O)
		  continue;

    if(board[2][j] != currentPiece)
    {
      tally = 1;
      break;
    }

    if(++tally == 3)
    {
      gameOver = true;
      return currentPiece;
    }
  }

	// no winner, return nex turn
	return toggleTurn();
}
