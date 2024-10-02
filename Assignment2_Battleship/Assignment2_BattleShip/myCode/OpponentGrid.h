/*
 * OpponentGrid.h
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <vector>
#include "Ship.h"
#include "Shot.h"
#include <map>

/**
 * @brief Represents the opponent's grid in a game.
 *
 */
class OpponentGrid {
private:
    int rows; /**< Number of rows in the grid. */
    int columns; /**< Number of columns in the grid. */
    std::vector<Ship> shunkenships; ///< Vector of sunken ships.
    std::map<GridPosition, Shot::Impact> shots; /**< Map storing shots position
    										and impact results of shots. */

    /**
     * @brief Retrieves the set of shot positions that hit a ship.
     * @return A set containing shot positions that hit the ship.
     */
    std::set<GridPosition> hitShots();

public:
    /**
     * @brief Constructor for the OpponentGrid class.
     * @param rows Number of rows in the grid.
     * @param columns Number of columns in the grid.
     */
    OpponentGrid(int rows, int columns);

    /**
     * @brief Destructor for the OpponentGrid class.
     */
    virtual ~OpponentGrid();

    /**
     * @brief Gets the number of rows in the grid.
     * @return The number of rows in the grid.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the grid.
     * @return The number of columns in the grid.
     */
    int getColumns() const;

    /**
     * @brief Gets the vector of sunken ships.
     * @return The vector of sunken ships.
     */
    const std::vector<Ship> getShunkenShips();

    /**
     * @brief Updates the opponent's grid based on shot result.
     * @param shot The shot fired.
     * @param impact The impact of the shot.
     */
    void shotResult(const Shot& shot, Shot::Impact impact);

    /**
     * @brief Gets the map of shot positions and their impacts.
     * @return The map of shot positions and their impacts.
     */
    const std::map<GridPosition, Shot::Impact>& getShotsAt();
};

#endif /* OPPONENTGRID_H_ */
