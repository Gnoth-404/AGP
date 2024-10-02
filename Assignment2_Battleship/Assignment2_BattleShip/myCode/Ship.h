/*
 * Ship.h
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <set>
#include "GridPosition.h"

/**
 * @class Ship
 * @brief Represents a ship in a game with a bow and stern position on the grid
 */
class Ship
{
private:
    GridPosition bow;   //!< The position of the bow of the ship.
    GridPosition stern; //!< The position of the stern of the ship.

public:
    /**
     * @brief Constructor for the Ship class.
     * @param bow The position of the bow of the ship.
     * @param stern The position of the stern of the ship.
     */
    Ship(const GridPosition& bow, const GridPosition& stern);

    /**
     * @brief Checks if the ship is a valid configuration.
     * @return True if the ship is valid, otherwise false.
     */
    bool isValid() const;

    /**
     * @brief Gets the position of the bow of the ship.
     * @return The position of the bow as a GridPosition.
     */
    GridPosition getBow() const;

    /**
     * @brief Gets the position of the stern of the ship.
     * @return The position of the stern as a GridPosition.
     */
    GridPosition getStern() const;

    /**
     * @brief Calculates the length of the ship
     * from the distance of bow and stern.
     * @return The length of the ship.
     */
    int length() const;

    /**
     * @brief Gets the set of grid positions occupied by the ship.
     * e.g Ship's bow is at B2 and stern at E2 -> return B2, C2, D2 , E2
     * @return A set of GridPosition objects representing the occupied area.
     */
    const std::set<GridPosition> occupiedArea() const;

    /**
     * @brief Gets the set of grid positions occupied by the ship and all the
     * surrounding grid positions
     * This method is used for implementing the "Ship mustn't touch rule"
     * @return A set of GridPosition objects representing the blocked area.
     */
    const std::set<GridPosition> blockedArea() const;

    /**
     * @brief Destructor for the Ship class.
     */
    virtual ~Ship();
};

#endif /* SHIP_H_ */
