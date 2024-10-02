/*
 * ConsoleView.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */
#include "Board.h"

#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView(Board *Board):board(Board)
{
	int rows = board->getRows();
	int cols = board->getColumns();
	ownGridState.resize(rows * cols, '~');
	opponentGridState.resize(rows * cols, '~');
}

ConsoleView::~ConsoleView()
{

	// TODO Auto-generated destructor stub
}

void ConsoleView::setOwnGridState()
{
    // No ship
    // Have our ship there
    OwnGrid ownGrid = board->getOwnGrid();

    std::fill(ownGridState.begin(), ownGridState.end(), '~');

    for (const auto& ship : ownGrid.getShips())
    {
        for (const auto& gridPosition : ship.occupiedArea())
        {
            // convert char to int type
            // since input is A B C D .. Z -> 0 1 ...
            int row = gridPosition.getRow() - 'A';
            // since our grid start from 1 not zero
            int col = gridPosition.getColumn() - 1;
            ownGridState[this->calcIndex1D(row, col)] = '#';
        }
    }

    // Set shot impact to the grid
    const auto& shotResults = ownGrid.getShotResults();
    this->setShotMap(shotResults, 0);
}
void ConsoleView::setShotMap(const std::map<GridPosition,
									Shot::Impact>& shotMap
							,bool opponent)
{
    for (const auto& shot : shotMap)
    {
        int row = shot.first.getRow() - 'A';
        int col = shot.first.getColumn() - 1;

        // Set appropriate character based on shot impact
        switch (shot.second)
        {
        case Shot::HIT:
        	if(opponent)
        		opponentGridState[this->calcIndex1D(row, col)] = 'O';
        	else
        		ownGridState[calcIndex1D(row,col)] ='O';

            break;
        case Shot::NONE:
        	if(opponent)
        		opponentGridState[this->calcIndex1D(row, col)] = '^';
        	else
        		ownGridState[calcIndex1D(row,col)] ='^';
            break;
        default:
        	break;
        }
    }
}



void ConsoleView::setOpponentGridState()
{
	std::fill(opponentGridState.begin(), opponentGridState.end(), '~');
    OpponentGrid opponentGrid = board->getOpponentGrid();

    const auto& shotResults = opponentGrid.getShotsAt();
    this->setShotMap(shotResults, 1);

    for (const auto& ship : opponentGrid.getShunkenShips())
    {
        for (const auto& gridPosition : ship.occupiedArea())
        {
            // convert char to int type
            // since input is A B C D .. Z -> 0 1 ...
            int row = gridPosition.getRow() - 'A';
            // since our grid start from 1 not zero
            int col = gridPosition.getColumn() - 1;
            opponentGridState[this->calcIndex1D(row, col)] = '#';
        }
    }

}

int ConsoleView::calcIndex1D(const int& row,const int& column)
{
	return row*board->getColumns() + column;
}



void ConsoleView::printFirstDigitColumnHeader(const int& cols) const
{
    // Print the first digit, if it's one digit, leave it as empty space
	 for (int col = 1; col <= cols; col++)
	 {
		if (col <10)
		{
			std::cout << " " << " ";
		}
		else
		{
			std::cout << (col/ 10) << " ";
		}
	 }
}
void ConsoleView::printSecondDigitColumnHeader(const int& cols) const
{
	//Print the second digit
   for (int col = 1; col <= cols; col++)
   {
       std::cout << col % 10 << " ";
   }
}


void ConsoleView::printRowHeader(const int& row) const
{
	std::cout << static_cast<char>('A'+row) << " ";
}

void ConsoleView::print()
{
	//Get each grid state

	int rows = board->getRows();
	int cols = board->getColumns();
	this->setOwnGridState();
	this->setOpponentGridState();

	if (rows>100 || cols > 100)
	{
		std::cout << "Current console is not supported" << std::endl;
	}
	std::cout << "Left Grid: " << "Own" << std::endl;
	std::cout << "Right Grid: " << "Opponent" << std::endl;


	// Print column header of Own Grid
	std::cout << "  ";
	this->printFirstDigitColumnHeader(cols);
	std::cout << "   ";
	this->printFirstDigitColumnHeader(cols);
	std::cout << std::endl;

	// Print column header of Opponent Grid
	std::cout << "  ";
	this->printSecondDigitColumnHeader(cols);
	std::cout << "   ";
	this->printSecondDigitColumnHeader(cols);
    std::cout << std::endl;


	for (int row=0; row<rows;row++)
	{
		// Print row header for Own Grid
		this->printRowHeader(row);
		// Update value and print own grid and component grid

		for (int col=0; col<cols; col++)
		{
			std::cout << ownGridState[this->calcIndex1D(row, col)] << " ";
		}
		std:: cout << " ";

		// Print row header for Opponent Grid
		this->printRowHeader(row);
		for (int col=0; col<cols; col++)
		{
			std::cout << opponentGridState[this->calcIndex1D(row, col)]<< " ";
		}
		std::cout << std::endl;
	}

}
