/*
 * Board.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#include "Board.h"


Board::Board(int rows, int columns):
opponentGrid(rows, columns),ownGrid(rows, columns)
{
	// TODO Auto-generated constructor stub

}

int Board::getRows() const
{
	return this->ownGrid.getRows();
}


int Board::getColumns() const
{
	return this->ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return this->ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return this->opponentGrid;
}
Board::~Board()
{
	// TODO Auto-generated destructor stub
}
