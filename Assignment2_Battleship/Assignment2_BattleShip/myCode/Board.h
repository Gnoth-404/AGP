/*
 * Board.h
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OpponentGrid.h"
#include "OwnGrid.h"

/**
 * @class Board
 * @brief Represents a game board with an opponent grid and an own grid.
 */
class Board
{
private:
    OpponentGrid opponentGrid;
    OwnGrid ownGrid;

public:
    /**
     * @brief Constructor for the Board class.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     */
    Board(int rows, int columns);

    /**
     * @brief Destructor for the Board class.
     */
    virtual ~Board();

    /**
     * @brief Gets the number of rows in the board.
     * @return The number of rows.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the board.
     * @return The number of columns.
     */
    int getColumns() const;

    /**
     * @brief Gets a reference to the player's own grid.
     * @return A reference to the OwnGrid instance.
     */
    OwnGrid& getOwnGrid();

    /**
     * @brief Gets a reference to the opponent's grid.
     * @return A reference to the OpponentGrid instance.
     */
    OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
