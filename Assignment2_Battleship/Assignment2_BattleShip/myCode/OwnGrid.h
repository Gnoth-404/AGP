/**
 * OwnGrid.h
 * @date Dec 26, 2024
 * @author Tiena
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <vector>
#include <memory>
#include <map>
#include "Ship.h"
#include "Shot.h"

/**
 * @class OwnGrid
 * @brief Represents a player's own grid in a Battleship game.
 */
class OwnGrid {
private:
    //! Number of rows in the grid.
	int rows;

    //! Number of columns in the grid.
    int columns;

    //! Vector containing ships in the grid.
    std::vector<Ship> ships;

    /**
     * @brief Map representing the count of each type of ship.
     *
     * The map contains entries for different types of ships
     * and their corresponding count: 1 Carrier (5), 2 Battleships (4),
     * 3 Destroyers (3), 4 Submarines (2).
     */
    std::map<int, int> shipMap{{5, 1}, {4, 2}, {3, 3}, {2, 4}};

    std::map<GridPosition, Shot::Impact> shotResults; /**< Map storing
    										impact results of shots. */

    std::set<GridPosition> shotAt; /**< Set of positions targeted by shots. */

public:
    /**
     * @brief Constructor for OwnGrid.
     * @param rows Number of rows in the grid.
     * @param columns Number of columns in the grid.
     */
    OwnGrid(int rows, int columns);

    /**
     * @brief Destructor for OwnGrid.
     */
    virtual ~OwnGrid();

    /**
     * @brief Gets the number of rows in the grid.
     * @return Number of rows.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the grid.
     * @return Number of columns.
     */
    int getColumns() const;

    /**
     * @brief Places a ship on the grid.
     * @param ship The Ship object to be placed.
     * @return True if the ship is successfully placed, false otherwise.
     */
    bool placeShip(const Ship& ship);

    /**
     * @brief Retrieves the vector of ships on the grid.
     * @return Vector containing Ship objects.
     */
    const std::vector<Ship> getShips();

    /**
     * @brief Handles the impact of a shot on the own grid.
     * @param shot The Shot object representing the targeted position.
     * @return The impact result of the shot:
     * NONE (miss), HIT (hit), or SUNKEN (final shot sinking a ship).
     */
    Shot::Impact takeBlow(const Shot& shot);

    /**
     * @brief Gets the set of positions that have been targeted by shots.
     * @return Set of shot positions.
     */
    const std::set<GridPosition> getShotAt();

    /**
     * @brief Gets the map of shot positions and their  impact results.
     * @return A map of shot positions and shot results.
     */
    const std::map<GridPosition, Shot::Impact> getShotResults();
};

#endif /* OWNGRID_H_ */
