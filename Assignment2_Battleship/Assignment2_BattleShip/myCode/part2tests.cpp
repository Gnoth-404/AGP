/*
 * part2tests.cpp
 *
 *  Created on: Jan 7, 2024
 *      Author: tiena
 */

#include "tests.h"
#include "Board.h"
#include "ConsoleView.h"


void part2Displaytests()
{
	Board board(10,10);
	OwnGrid& ownGrid= board.getOwnGrid(); // Get a reference to the OwnGrid

	std::vector<Ship> shipTests;

    // Create a ship and place it on the grid
    Ship testShip(GridPosition{"B2"}, GridPosition{"B4"});
    ownGrid.placeShip(testShip);


    // Retrieve ships from the grid
    std::vector<Ship> ships = ownGrid.getShips();
    std::set<GridPosition> testShipArea = testShip.occupiedArea();

    // Check if the placed ship is in the retrieved ships list
    bool shipFound = false;
    for (auto ship:ships) {
        if (ship.occupiedArea() == testShipArea) {
            shipFound = true;
            break;
        }
    }
    assertTrue(shipFound, "Placed ship not found in grid's ship list");

    ownGrid.placeShip(Ship{GridPosition{"D4"}, GridPosition{"G4"}});

    ownGrid.placeShip(Ship{GridPosition{"F6"}, GridPosition{"F9"}});

	ConsoleView console(&board);
	console.print();

}
void part2ShipPlaceTests()
{
	Board board(10,10);
	OwnGrid& ownGrid= board.getOwnGrid(); // Get a reference to the OwnGrid

	//our first test ship has length = 5

    ownGrid.placeShip(Ship{GridPosition{"B2"}, GridPosition{"B6"}});

    std::cout << "Test valid ship placement";

    bool placeTest1= ownGrid.placeShip(Ship{GridPosition{"B4"},
    									GridPosition{"B5"}});
    assertTrue(!placeTest1, "Ship can be placed next to each other");

    bool placeTest2= ownGrid.placeShip(Ship{GridPosition{"A6"},
    									GridPosition{"B7"}});
    assertTrue(!placeTest2, "Ship can be placed 45 degree");

    bool placeTest3=ownGrid.placeShip(Ship{GridPosition{"G15"},
    									GridPosition{"G6"}});
    assertTrue(!placeTest3, "Ship can be placed outside of the Grid");

    bool placeTest4=ownGrid.placeShip(Ship{GridPosition{"D2"},
    									GridPosition{"D6"}});
    assertTrue(!placeTest4, "Ship can still be placed after maximum value");

	ConsoleView console(&board);
	console.print();
}





