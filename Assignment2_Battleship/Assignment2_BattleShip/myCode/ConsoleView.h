/*
 * ConsoleView.h
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include <vector>

class Board;

/**
 * @brief Represents the console view for the game.
 *
 * The ConsoleView class provides methods to display the game board
 * and its state on the console.
 */
class ConsoleView {
private:
	Board* board; /**< Pointer the game Board */
	std::vector<char> ownGridState;/**< State of the own grid */
	std::vector<char> opponentGridState; /**< State of the opponent grid */

    /**
     * @brief Sets the shot map for a specific grid.
     * @param shotMap Map of shot positions and their impacts.
     * @param Opponent Flag whether opponent / own grid map
     */
    void setShotMap(const std::map<GridPosition, Shot::Impact>& shotMap,
    		bool Opponent);

    /**
     * @brief Calculates the 1D index for a given row and column.
     * @param row The row index.
     * @param column The column index.
     * @return The 1D index calculated from the row and column.
     */
    int calcIndex1D(const int& row, const int& column);

public:
    /**
     * @brief Constructor for the ConsoleView class.
     * @param Board Pointer to the game board.
     */
    ConsoleView(Board* Board);

    /**
     * @brief Destructor for the ConsoleView class.
     */
    virtual ~ConsoleView();

    /**
     * @brief Sets the state of the player's own grid.
     */
    void setOwnGridState();

    /**
     * @brief Sets the state of the opponent's grid.
     */
    void setOpponentGridState();

    /**
     * @brief Prints the console view.
     */
    void print();

    /**
     * @brief Prints the header for a specific row.
     * @param row The row index.
     */
    void printRowHeader(const int& row) const;

    /**
     * @brief Prints the header for the first digit of the column.
     * @param cols The number of columns.
     */
    void printFirstDigitColumnHeader(const int& cols) const;

    /**
     * @brief Prints the header for the second digit of the column.
     * @param cols The number of columns.
     */
    void printSecondDigitColumnHeader(const int& cols) const;
};

#endif /* CONSOLEVIEW_H_ */
