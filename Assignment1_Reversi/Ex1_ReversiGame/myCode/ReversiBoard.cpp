/*
 * ReversiBoard.cpp
 *
 *  Created on: Nov 8, 2023
 *      Author: Nguyen Tien Anh Ha- 1127956
 */

#include "ReversiBoard.h"
#include <iostream>
#include <assert.h>





/**
 * @brief Creates a ReversiBoard object with specified columns and rows.
 * @param size Size of the Board.
 */
ReversiBoard::ReversiBoard(int size)
{
	assert(size>0);
	this->size = size;
	pointBoard = new pointState [size*size];
	// Set all field to Empty

	this->resetBoard();
	// Set the initial 4 pieces
	this->setField((size/2-1),(size/2-1),pointState::PLAYER_BLACK);
	this->setField((size/2),(size/2),pointState::PLAYER_BLACK);
	this->setField((size/2-1),(size/2),pointState::PLAYER_WHITE);
	this->setField((size/2),(size/2-1),pointState::PLAYER_WHITE);

}

/**
 * @brief Destructor for ReversiBoard.
 *        Frees up the memory allocated for the board.
 */


ReversiBoard::~ReversiBoard()
{
	delete []pointBoard;

}

/**
 * @brief Sets the state of a specific field on the board.
 * @param col The column index of the field.
 * @param row The row index of the field.
 * @param State The new state to be set for the field.
 */



void ReversiBoard::setField(int col, int row, pointState State)
{
	//check valid move
	assert(col>=0 && row >=0 && col < this->size && row < this->size);
	this->pointBoard[this->calcIndex(col, row)] = State;

}



/**
 * @brief Calculates the 1D array index for a given (x,y) board position.
 * @param col The column index of the position.
 * @param row The row index of the position.
 * @return The calculated index in the 1D board array.
 */


int ReversiBoard::calcIndex(int col, int row)
{
	return this->size *(row)+col;
}


/**
 * @brief Resets the board to the initial state, with all fields empty.
 */
void ReversiBoard::resetBoard()
{
	for (int i=0; i<size*size ; i++)
	{
		this->pointBoard[i] = pointState::EMPTY;
	}
}



/**
 * @brief Attempts to place a piece at a specified location, 
 * flipping opponent's pieces if the move is valid.
 * @param col The column index where the piece is to be placed.
 * @param row The row index where the piece is to be placed.
 * @param player The player (color) making the move.
 * @param flipBetween If true, flips the opponent's pieces between the new piece
 * and existing pieces of the player.
 * @return True if the move is valid, false otherwise.
 */

bool ReversiBoard::tryMoveAndFlip(int col, int row,
		pointState player, bool flipBetween)

{
	assert(col>=0 && row >=0 && col < this->size && row < this->size);

	// Determine the opponent's color

	pointState opponent;
	if (player == pointState::PLAYER_BLACK)
	{
		opponent = pointState::PLAYER_WHITE;
	}
	else
	{
		opponent = pointState::PLAYER_BLACK;
	}


	// check if the move is on the player field
	if (this->pointBoard[calcIndex(col,row)] == pointState::PLAYER_BLACK ||
			this->pointBoard[calcIndex(col,row)] == pointState::PLAYER_WHITE)
	{
		return false;
	}


	// Create table check for 8 directions around the selected point 
	// Up Left, Up, Up Right, 
	// Left, 			Right, 
	// Down Left, Down, Down Right
	const int checkDirections[8][2] =
	{
			{-1,-1},{0,-1}, {1,-1},
			{-1,0} ,	    {1,0},
			{-1,1} ,{0,1} , {1,1}
	};


	// check in 8 directions if there's a valid move
	bool isValidMove = false;	

	for (int i=0; i<8; i++)
	{
		// delta x is the step in x direction(column)
		int deltaX = checkDirections[i][0];
		// delta y is the step in y direction(row)
		int deltaY = checkDirections[i][1];
		
		// Increase column and column in delta x and y step
		int x = col + deltaX;
		int y = row + deltaY;

		bool hasOpponent = false;

		//check if it's adjacent is opponent field and move until the end
		while (x>=0 && x< this->size && y>=0 && y< this->size &&
				this->pointBoard[calcIndex(x,y)] == opponent)
		{
			hasOpponent = true;
			x+=deltaX;
			y+=deltaY;
		}

		// check if the next field is the player's field
		if (hasOpponent && x>=0 && x<this->size && y>=0 && y<this->size &&
				this->pointBoard[calcIndex(x,y)] == player)
		{

			isValidMove = true;
			// Flip the opponent field if it's enabled
			if (flipBetween)
			{
				// flip the opponent's field, go back until original move
				while (x!=col || y!=row)
				{
					x -= deltaX;
					y -= deltaY;
					this->pointBoard[calcIndex(x,y)] = player;

				}
			}
		}
	}
	// do not have any possible move
	return isValidMove;

}

/**
 * @brief Calculates the current score for each player.
 * @param [out] noBlack Reference to store the count of black pieces.
 * @param [out] noWhite Reference to store the count of white pieces.
 * @param [out] noPossibleMove Reference to store the count of possiblemoves
 */

void ReversiBoard::scoreBoard(int &noBlack, int &noWhite, int &noPossibleMove)
{

	// check if the move is on the empty field
	for (int i=0; i<this->size; i++)
	{
		for (int j=0; j<this->size; j++)
		{
			pointState boardIndex = this->getField(i, j);

			switch(boardIndex)
			{
				case pointState::PLAYER_BLACK:
					noBlack++;
					break;
				case pointState::PLAYER_WHITE:
					noWhite++;
					break;
				case pointState::POSSIBLE_MOVE:
					noPossibleMove++;
					break;
				default:
					break;
			}

		}

	}
}

/**
 * @brief Scans the board to update possible moves for the current player.
 * @param playerTurn The player whose turn it is to move.
 * @return True if there are possible moves, false otherwise.
 */

bool ReversiBoard::getValidMoves(pointState playerTurn)
{
	bool hasPossibleMove =0;
	//Clear previous possible moves
    for (int i = 0; i < this->size; i++) 
	{
        for (int j = 0; j < this->size; j++) 
		{
            if (this->pointBoard[calcIndex(i, j)] == pointState::POSSIBLE_MOVE) 
			{
                this->pointBoard[calcIndex(i, j)] = pointState::EMPTY;
            }
        }
    }
	// Update possible move

	for (int i=0; i<this->size; i++)
	{
		for (int j=0; j<this->size; j++)
		{
			if (this->tryMoveAndFlip(i,j,playerTurn,false))
			{
				this->pointBoard[calcIndex(i,j)] = pointState::POSSIBLE_MOVE;
				hasPossibleMove =1;

			}
		}

	}
	if (hasPossibleMove ==1)
		return true;
	return 0;
}

/**
 * @brief Return the size of the board.
 * @return [out] Size of the board.
 */
int ReversiBoard::getSize()
{
	return this->size;
}
/**
 * @brief Retrieves the state of the field at a specified position.
 * @param col  The column index of the position.
 * @param row  The row index of the position.
 * @return The state of the field at the specified position.
 */

pointState ReversiBoard::getField(int col, int row)
{
	return this->pointBoard[calcIndex(col,row)];
}

