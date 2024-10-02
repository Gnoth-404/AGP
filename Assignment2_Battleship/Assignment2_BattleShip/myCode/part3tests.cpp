/*
 * part3tests.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: tiena
 */



#include "tests.h"
#include "Shot.h"
#include "Board.h"
#include "ConsoleView.h"



void part3tests()
{
	Board board3(10,10);
	OwnGrid& ownGrid= board3.getOwnGrid(); // Get a reference to the OwnGrid
	OpponentGrid& opponentGrid=board3.getOpponentGrid();
	// Length 5
    ownGrid.placeShip(Ship{GridPosition{"A1"}, GridPosition{"A5"}});
    // Length 4
    ownGrid.placeShip(Ship{GridPosition{"C10"}, GridPosition{"F10"}});
    ownGrid.placeShip(Ship{GridPosition{"C1"}, GridPosition{"F1"}});
    // Length 3
    ownGrid.placeShip(Ship{GridPosition{"H4"}, GridPosition{"H6"}});
    ownGrid.placeShip(Ship{GridPosition{"J8"}, GridPosition{"J10"}});
    ownGrid.placeShip(Ship{GridPosition{"C6"}, GridPosition{"E6"}});
    // Length 2
    ownGrid.placeShip(Ship{GridPosition{"H9"}, GridPosition{"H10"}});
    ownGrid.placeShip(Ship{GridPosition{"J1"}, GridPosition{"J2"}});
    ownGrid.placeShip(Ship{GridPosition{"F8"}, GridPosition{"G8"}});
    ownGrid.placeShip(Ship{GridPosition{"A9"}, GridPosition{"A10"}});

	std::cout <<"\n Own Grid gets shots...\n";



	assertTrue(ownGrid.takeBlow(Shot{ GridPosition{"J8"}}) == Shot::HIT,
								"Shot at J8 not HIT");
	assertTrue(ownGrid.takeBlow(Shot{ GridPosition{"J9"}}) == Shot::HIT,
								"Shot at J9 not HIT");
	assertTrue(ownGrid.takeBlow(Shot{ GridPosition{"J10"}}) == Shot::SUNKEN,
								"Shot at J10 not SUNKEN");

	assertTrue(ownGrid.takeBlow(Shot{ GridPosition{"C4"}}) == Shot::NONE,
								"Shot at C4 not MISS");

	assertTrue(ownGrid.takeBlow(Shot{ GridPosition{"D4"}}) == Shot::NONE,
								"Shot at D4 not MISS");

	std::cout <<"\n Own Grid passes shots test...\n";

	ConsoleView console(&board3);
	console.print();

	std::cout <<"\n Opponent Grid gets shots...\n";

	opponentGrid.shotResult(Shot{GridPosition{"C2"}}, Shot::Impact::NONE);

	opponentGrid.shotResult(Shot{GridPosition{"C3"}}, Shot::Impact::HIT);

	opponentGrid.shotResult(Shot{GridPosition{"C5"}}, Shot::Impact::HIT);

	opponentGrid.shotResult(Shot{GridPosition{"C4"}}, Shot::Impact::SUNKEN);

	opponentGrid.shotResult(Shot{GridPosition{"F5"}}, Shot::Impact::NONE);

	opponentGrid.shotResult(Shot{GridPosition{"G4"}}, Shot::Impact::NONE);

	opponentGrid.shotResult(Shot{GridPosition{"G5"}}, Shot::Impact::HIT);

	opponentGrid.shotResult(Shot{GridPosition{"G6"}}, Shot::Impact::HIT);

	opponentGrid.shotResult(Shot{GridPosition{"I5"}}, Shot::Impact::NONE);


     //Check if sunken ship pos are C3 C4 C5
	bool sunkenFind;
	for(const auto& ship:opponentGrid.getShunkenShips())
	{
		if (ship.occupiedArea() == std::set<GridPosition>{GridPosition{"C3"},
													GridPosition{"C4"},
													GridPosition{"C5"}})
		{
			sunkenFind = true;
			break;
		}
	}
	assertTrue(sunkenFind,"Wrong sunken ship has been found");


	console.print();
}
