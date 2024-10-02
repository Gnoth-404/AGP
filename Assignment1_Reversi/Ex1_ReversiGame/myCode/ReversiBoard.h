/*
 * ReversiBoard.h
 *
 *  Created on: Nov 8, 2023
 *      Author: tiena
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @brief Enum class for the state of a point on the Reversi Board
 */
enum class pointState
{
	PLAYER_WHITE, // 
	PLAYER_BLACK,
	EMPTY,
	POSSIBLE_MOVE
};
/**
 * @brief ReversiBoard class implements the board for the Reversi game.
 * 
 */
class ReversiBoard
{
private:
	int size; /**< Size of the board. */
	pointState *pointBoard; /**< Pointer to 1D array of the board. */

	/**
	 * @brief Calculates the 1D array index for a given (x,y) board position.
	 * @param col The column index of the position.
	 * @param row The row index of the position.
	 * @return The calculated index in the 1D board array.
	 */
	int calcIndex(int col, int row);

public:
	/**
	 * @brief Creates a ReversiBoard object with specified columns and rows.
	 * @param size Size of the Board.
	 */
	ReversiBoard(int size);
	/**
	 * @brief Destructor for ReversiBoard.
	 *        Frees up the memory allocated for the board.
	 */

	~ReversiBoard();

	/**
	 * @brief Sets the state of a specific field on the board.
	 * @param col The column index of the field.
	 * @param row The row index of the field.
	 * @param State The new state to be set for the field.
	 */
	void setField(int col, int row, pointState State);

	/**
	 * @brief Retrieves the state of the field at a specified position.
	 * @param col  The column index of the position.
	 * @param row  The row index of the position.
	 * @return The state of the field at the specified position.
	 */
	pointState getField(int col, int row);
	
	/**
	 * @brief Calculates the current score for each player.
	 * @param [out] noBlack Reference to store the count of black pieces.
	 * @param [out] noWhite Reference to store the count of white pieces.
	 * @param [out] noPossibleMove Reference to store the count of possiblemoves
	 */
	void scoreBoard(int &noBlack, int &noWhite, int &noPossibleMove);
	/**
	 * @brief Scans the board to update possible moves for the current player.
	 * @param playerTurn The player whose turn it is to move.
	 * @return True if there are possible moves, false otherwise.
	 */

	bool getValidMoves(pointState playerTurn);
	/**
	 * @brief Return the size of the board.
	 * @return [out] Size of the board.
	 */
	int getSize();

	/**
	 * @brief Resets the board to the initial state, with all fields empty.
	 */
	void resetBoard();

	/**
	 * @brief Attempts to place a piece at a specified location, 
	 * flipping opponent's pieces if the move is valid.
	 * @param col The column index where the piece is to be placed.
	 * @param row The row index where the piece is to be placed.
	 * @param player The player (color) making the move.
	 * @param flipBetween If true, flips the opponent's pieces between the
	 * new piece and existing pieces of the player.
	 * @return True if the move is valid, false otherwise.
	 */

	bool tryMoveAndFlip(int col, int row, pointState player, bool flipBetween);


	


};

#endif /* REVERSIBOARD_H_ */
