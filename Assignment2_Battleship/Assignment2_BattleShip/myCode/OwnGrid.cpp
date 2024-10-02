/*
 * OwnGrid.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#include "OwnGrid.h"
#include "Ship.h"

#include <algorithm>
#include <iterator>
#include <set>
OwnGrid::OwnGrid(int rows, int columns):rows(rows),columns(columns)
{

}

int OwnGrid::getRows() const
{
	return this->rows;
}

int OwnGrid::getColumns() const
{
	return this->columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{

	// Check number of ships of a given length
	int length = ship.length();

	if(shipMap[length] <=0)
	{
		// maximum ships had been placed
		return false;
	}
	else
	{
		shipMap[length] -=1;
	}

	// Check the ship to be within the grid
	int bowRow = ship.getBow().getRow() - 'A';
	int bowCol =  ship.getBow().getColumn();

	int sternRow = ship.getStern().getRow()-'A' <= rows;
	int sternCol = ship.getStern().getColumn();

	if ((bowRow>rows)||(bowCol>columns)||
			(sternRow>rows)||(sternCol>columns))
	{
		return false;
	}


	// Check if the ship can be placed
	// check not intersect with current ship
	// check if it;s within the grid
	std::vector<GridPosition> intersection;

	for (const Ship& oldShip:ships)
	{
		std::set<GridPosition> occupiedArea = ship.occupiedArea();
		std::set<GridPosition> blockedArea = oldShip.blockedArea();


		std::set_intersection(occupiedArea.begin(), occupiedArea.end(),
							blockedArea.begin(), blockedArea.end(),
							std::back_inserter(intersection));
	}
	if (intersection.empty())
	{
		ships.push_back(ship);
		return true;
	}
	return false;
}


const std::vector<Ship> OwnGrid::getShips()
{
	return ships;
}



OwnGrid::~OwnGrid()
{
	// TODO Auto-generated destructor stub
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
    GridPosition shotPosition = shot.getTargetPosition();
    Shot::Impact shotResult;
    this->shotAt.insert(shotPosition);

    for (const Ship &ship : ships)
    {
        std::set<GridPosition> occupiedArea = ship.occupiedArea();
        std::set<GridPosition> correctShot;

        // Check if the shot hits the ship
        if (occupiedArea.find(shotPosition) != occupiedArea.end())
        {
            // If the shot position is in the ship's occupied area,
        	// Check if it is a final shot
            std::set_intersection(occupiedArea.begin(), occupiedArea.end(),
                                  this->shotAt.begin(), this->shotAt.end(),
                          std::inserter(correctShot, correctShot.begin()));

            // If the size of the intersection is equal to the ship's length- 1
            // It's a final shot
            if (static_cast<int>(correctShot.size()) == ship.length())
            {
                shotResult = Shot::SUNKEN;
                break;
            }
            else
            {
                shotResult = Shot::HIT;
                break;
            }
        }
        else
        {
            shotResult = Shot::NONE;
        }
    }

    // Record the shot result for the given position
    shotResults.insert({shotPosition, shotResult});

    return shotResult;
}

const std::map<GridPosition, Shot::Impact> OwnGrid::getShotResults()
{
	return this->shotResults;
}


