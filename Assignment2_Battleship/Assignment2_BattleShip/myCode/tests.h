/*
 * tests.h
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <iostream>

/**
 * @brief Function to assert a condition is true.
 * @param condition The condition to be checked.
 * @param failedMessage Message to be displayed if the condition is false.
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * @brief Test functions for basic classes.
 *
 * This function performs the following tests:
 * - Test GridPosition constructor
 * - Test getters and casts to string
 * - Test comparison
 * - Test Ship constructor
 * - Test length of the ship calculation
 * - Test Occupied Area
 */
void part1tests();

/**
 * @brief Test functions for displaying on ConsoleView
 *
 * Test 1:
 * - Create an instance of Board(10x10)
 * - Arrange three ships on the Board (B2/B4, D4/G5, F6/F9)
 * - Create console view with print
 *
*/
void part2Displaytests();

/**
 * @brief Test functions for checking ship validity
 * Test 2 (Valid Ship Placement):
 * - Not touch each other
 * - Grid fields occupied form a straight line
 * - May be positioned at the edges of the grid
 * - Must be positioned horizontally or vertically
 * - 10 ships only on the board, each ship has limited number;
 */
void part2ShipPlaceTests();

/**
 * @brief Test functions for the Shot class.
 *
 * - Test for shots (misses, hits, and final shots) on own Grid
 * - Test on detecting sunken ships on Opponent Grid
 */
void part3tests();

#endif /* TESTS_H_ */
