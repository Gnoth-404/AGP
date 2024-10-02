/*
 * ReversiConsoleView.cpp
 *
 *  Created on: Nov 9, 2023
 *      Author: tiena
 */

#include "ReversiConsoleView.h"
#include "ReversiBoard.h"
#include <iostream>


/**
 * @brief Prints the board to the console.
 */
void ReversiConsoleView::printBoard() const
{
	int size = board->getSize();

	std::cout << "  ";
	// Print  the column number
	for (int col = 0; col < size; col++)
	{
		std::cout << col << " ";
	}
	
	std::cout << std::endl;
	for (int row = 0; row < size; row++)
	{
		// Print the row number
		std::cout << row << " ";
		for (int col = 0; col < size; col++)
		{
			pointState boardIndex = board->getField(col, row);

			switch (boardIndex)
			{
				case pointState::PLAYER_BLACK:
					std::cout << "X ";
					break;
				case pointState::PLAYER_WHITE:
					std::cout << "O ";
					break;
				case pointState::POSSIBLE_MOVE:
					std::cout << "* ";
					break;
				case pointState::EMPTY:
					std::cout << ". ";
					break;
				default:
					break;
			}
		}
		std::cout << std::endl;
		
	}

}

/**
 * @brief Prints the rule of the game to the console.
 * 
 */

void ReversiConsoleView::printRule() const
{
	std::cout << "Welcome to Reversi game! \n";
	std::cout << "The game is played on an 8x8 board \n";
	std::cout << "Four pieces are placed in the middle of the board:\n";
	std::cout << "Black Player goes first\n";
	std::cout << "The game is over when neither player has a move.\n";
	std::cout << "x: Black Player \n";
	std::cout << "o: White Player \n";
	std::cout << "*: Possible Move \n";
	std::cout << "=========================================" << std::endl;

}
/**
 * @brief Prints the final score to the console.
 */

void ReversiConsoleView::printScore() const
{
	int noBlack = 0;
	int noWhite = 0;
	int noPossibleMove = 0;
	board->scoreBoard(noBlack, noWhite, noPossibleMove);
	std::cout << "Black Player: " << noBlack << std::endl;
	std::cout << "White Player: " << noWhite << std::endl;
	std::cout << "Possible Move: " << noPossibleMove << std::endl;
	std::cout << "=========================================" << std::endl;
}
