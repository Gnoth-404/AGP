/*
 * ReversiConsoleView.h
 *
 *  Created on: Nov 9, 2023
 *      Author: tiena
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_
class ReversiBoard;

/**
 * @brief ReversiConsoleView Class
 * provides a console view for the Reversi game.
 * Responsible for printing the board and the final score to the console.
 * 
 */
class ReversiConsoleView
{
private:
	ReversiBoard* board; /**< Pointer to the ReversiBoard object. */
public:
	/**
	 * @brief Create a ReversiConsoleView object.
	 * @param pBoard Board Pointer to the ReversiBoard object.
	 */

	ReversiConsoleView(ReversiBoard *pBoard):board(pBoard){};

	/**
	 * @brief Destructor
	 */
	~ReversiConsoleView(){};

	/**
	 * @brief Prints the board to the console.
	 */
	void printBoard() const;

	/**
	 * @brief Prints the final score to the console.
	 */
	void printScore() const;

	/**
	 * @brief Prints the rule of the game to the console.
	 */
	void printRule() const;
};

#endif /* REVERSICONSOLEVIEW_H_ */
