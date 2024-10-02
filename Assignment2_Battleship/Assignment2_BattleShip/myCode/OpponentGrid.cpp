/*
 * OpponentGrid.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#include "OpponentGrid.h"
#include "Ship.h"
#include <algorithm>
#include <iterator>
#include <set>

OpponentGrid::OpponentGrid(int rows, int columns):rows(rows),columns(columns)
{

}

int OpponentGrid::getRows() const
{
	return this->rows;
}

int OpponentGrid::getColumns() const
{
	return this->columns;
}

OpponentGrid::~OpponentGrid()
{
	// TODO Auto-generated destructor stub
}

const std::vector<Ship> OpponentGrid::getShunkenShips()
{
	return this->shunkenships;
}



void OpponentGrid::shotResult(const Shot& shot, Shot::Impact impact)
{
    GridPosition shotPosition = shot.getTargetPosition();
    // Add shot result to the shot map for verification
    this->shots.insert({ shotPosition, impact });

    if (impact == Shot::Impact::SUNKEN)
    {
        // If the result shot sinks a ship, find that ship
    	// luckyShip set contains the coordinates of our sunken ship
        std::set<GridPosition> luckyShip;
        std::set<GridPosition> intersectionArea;

        luckyShip.insert(shotPosition);
        intersectionArea.insert(shotPosition);
        std::set<GridPosition> shotMap = this->hitShots();

        // This emergency ship will search around using blockedArea
        // If its blockedArea intersects with the hitShot set, return a set
        // Then, create a new ship with the bow being the begin value of the set
        // and the stern being the end value of the set
        bool shipFound = false;
        while (!shipFound)
        {
            GridPosition bow = *luckyShip.begin();
            // Because the end iterator points one element past the last element
            // of the set -> dereference the previous iterator
            GridPosition stern = *std::prev(luckyShip.end());
            intersectionArea.clear();
            // Extend our ship based on our position find
            Ship emergencyShip{ bow, stern };

            std::set_intersection(emergencyShip.blockedArea().begin(),
                                  emergencyShip.blockedArea().end(),
                                  shotMap.begin(),
                                  shotMap.end(),
                        std::inserter(intersectionArea, intersectionArea.end())
            );
            if (intersectionArea.size() == luckyShip.size() - 1)
            {
                shipFound = true;
            }

            for (const auto& position : intersectionArea)
            {
                luckyShip.insert(position);
            }
        }

        // we have found a final ship.
        // Insert it back into our sunkenShip vector.
        Ship sunkenShip{ *luckyShip.begin(), *std::prev(luckyShip.end()) };
        this->shunkenships.push_back(sunkenShip);
    }
}


std::set<GridPosition> OpponentGrid::hitShots()
{
	std::set <GridPosition> hitPositions;
	for(const auto& entry:shots)
	{
		const GridPosition& position =entry.first;
		const Shot::Impact& impact = entry.second;

		if (impact == Shot::Impact::HIT)
		{
			hitPositions.insert(position);
		}
	}
	return hitPositions;
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt()
{
	return this->shots;
}
