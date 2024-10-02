// Standard (system) header files
#include <iostream>
#include <cstdlib>

#include <string>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"


// Main program
/**
 * @enum GameState
 * @brief Enumeration for the different states of a Reversi game.
 *

 */
enum class GameState
{
	BLACK_TURN,
	WHITE_TURN,
	GAME_OVER
};
/**
 * @brief Return the name of the player
 * @param[in] player
 * @return[out] Name of the player
 */
const std::string turnName(pointState player){
	switch(player)
	{
	case pointState::PLAYER_BLACK:
		return "Player Black";
	case pointState::PLAYER_WHITE:
		return "Player White";
	default:
		return "Random";
	}
}
int main ()
{
	// Fixed board size
	ReversiBoard board(8);
	ReversiConsoleView view(&board);
	view.printRule();

	// Black always moves first
	pointState playerTurn = pointState::PLAYER_BLACK;
	GameState gameState = GameState::BLACK_TURN;
	// Get valid move and update possible move of current player
	board.getValidMoves(playerTurn);

	while(gameState != GameState::GAME_OVER)
	{



		// Check game over condition
		if (board.getValidMoves(playerTurn) ==0)
		{
			// Switch player turn
			if(playerTurn == pointState::PLAYER_BLACK)
			{
				playerTurn = pointState::PLAYER_WHITE;
			}
			else
			{
				playerTurn = pointState::PLAYER_BLACK;
			}
			// Check if the other player also has no valid moves
			if (board.getValidMoves(playerTurn) ==0)
			{
				gameState =GameState::GAME_OVER;
				int noBlack, noWhite, noPossibleMove;
				board.scoreBoard(noBlack, noWhite, noPossibleMove);

				// Announce winner or tie game
				if (noBlack > noWhite)
				{
					std::cout << "The winner is Black!" << std::endl;
				}
				else if ( noWhite > noBlack)
				{
					std::cout << "The winner is White!" << std::endl;
					std::cout << "Number of white" << noWhite << std::endl;
				}
				else
				{
					std::cout << "Tie" << std::endl;
				}
				return 0;
			}
		}
		// Print out the current state of the board
		view.printBoard();

		// Get player input
		std::cout << turnName(playerTurn);
		std::cout << ", enter your move(column and row): ";
		int x,y;
		std::cin>> x >> y;

		// Validate input and flip that row if that is a valid move
		if (!board.tryMoveAndFlip(x,y,playerTurn, true))
		{
			std::cout << "Invalid move, try again. "<<std::endl;
			continue;
		}
		// Set the board with the valid player's move
		board.setField(x,y, playerTurn);

		// switch turn after player finish their move
		if (playerTurn == pointState::PLAYER_BLACK)
		{
			playerTurn = pointState::PLAYER_WHITE;
		}
		else
		{
			playerTurn = pointState::PLAYER_BLACK;
		}
		// Print out the current scoreboard
		view.printScore();
	}
}
