/*
 * Ship.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#include "Ship.h"
#include "GridPosition.h"
#include <cmath>
#include <iostream>





Ship::Ship(const GridPosition &bow, const GridPosition &stern)
    : bow(bow), stern(stern)
{
}


bool Ship::isValid() const
{
    int shipLength = this->length();

	// Check if bow and stern input are valid
	if( !bow.isValid() || !stern.isValid() )
	{
		return false;
	}

    // Check if the ship is placed either horizontally or vertically
    // and has a valid length (1 < l < 6)

    bool isHorizontal = bow.getRow() == stern.getRow();
	bool isVertical =  bow.getColumn() == stern.getColumn();
    bool isLengthValid = (shipLength > 1) && (shipLength < 6);

    return (isHorizontal||isVertical) && isLengthValid;
}
GridPosition Ship::getBow() const
{
	return this->bow;
}

GridPosition Ship::getStern() const
{
	return this->stern;
}


int Ship::length() const
{
    // Calculate the length of the ship based on bow and stern positions
    if (bow.getRow() == stern.getRow())
    {
        return std::abs(stern.getColumn() - bow.getColumn()) + 1;
    }
    else if (bow.getColumn() == stern.getColumn())
    {
        return std::abs(stern.getRow() - bow.getRow()) + 1;
    }
    else
    {
        return 0; // Or an error value if bow and stern are not aligned
    }
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedArea;

	// For vertical ship
	if (bow.getColumn() == stern.getColumn())
	{
		char startRow = std::min(bow.getRow(), stern.getRow());
		char endRow = std::max(bow.getRow(), stern.getRow());
		for (char row=startRow; row<=endRow; row++)
		{
			occupiedArea.insert(GridPosition(row,bow.getColumn()));
		}

	} // for horizontal ship
	else if (bow.getRow() == stern.getRow())
	{
		int startCol = std::min(bow.getColumn(), stern.getColumn());
		int endCol = std::max(bow.getColumn(), stern.getColumn());
		for (int col=startCol; col<=endCol; col++)
		{
			occupiedArea.insert(GridPosition(bow.getRow(),col));
		}
	}

	return occupiedArea;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> result;

	/*
	 For each grid position from occupied area, add that position and all
	eight surrounding positions to the result set
	*/
	for(const GridPosition& position: this->occupiedArea())
	{
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
		for (int i=0; i<8; i++)
		{
			// delta x is the step in x direction(column)
			int deltaX = checkDirections[i][0];
			// delta y is the step in y direction(row)
			char deltaY = checkDirections[i][1];

			int col = position.getColumn();
			char row = position.getRow();

			int newCol = col+ deltaX;
			char newRow = row+ deltaY;

			result.insert(GridPosition(newRow, newCol));
		}
		result.insert(position);

	}

	return result;
}

Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}

