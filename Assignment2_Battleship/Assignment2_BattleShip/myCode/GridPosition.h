/*
 * GridPosition.h
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

/**
 * @class GridPosition
 * @brief Represents a position on a grid
 * with a row character and column number.
 */
class GridPosition
{
private:
    char row;    ///< Row character (A <= row <= Z)
    int column;  ///< Column number (column > 0)

public:
    /**
     * @brief Constructor that takes input from specified row and column.
     * @param row Row character.
     * @param column Column number.
     */
    GridPosition(char row, int column);

    /**
     * @brief Constructor that takes input from a string such as "B10".
     * @param position The grid position on the board as a string.
     */
    GridPosition(std::string position);

    /**
     * @brief Destructor for the GridPosition class.
     */
    virtual ~GridPosition();

    /**
     * @brief Checks if the GridPosition object is valid
     * (A <= row <= Z and column > 0).
     * @return True if the position is valid.
     */
    bool isValid() const;

    /**
     * @brief Gets the row character of the object.
     * @return Row character.
     */
    char getRow() const;

    /**
     * @brief Gets the column number of the object.
     * @return Column number.
     */
    int getColumn() const;

    // Operator overloading

    /**
     * @brief Overloaded cast to string to return
     * the concatenation (e.g., "B10").
     * @return The concatenation of the row and the column as a string.
     */
    operator std::string() const;

    /**
     * @brief Overloaded equal operator to compare two GridPositions.
     * @param rhs The GridPosition to compare with.
     * @return True if the GridPositions are similar.
     */
    bool operator==(const GridPosition& rhs) const;

    /**
     * @brief Overloaded less than operator to compare two GridPositions.
     *
     * This operator is used by std::set in Ship::occupiedArea() const
     * for ordering elements.
     *
     * @param rhs The GridPosition to compare with.
     * @return True if this GridPosition is less than the provided GridPosition.
     */
    bool operator<(const GridPosition& rhs) const;
};

#endif /* GRIDPOSITION_H_ */
