/*
 * ModuloNCounter.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_
#include "ModuloNDigit.h"

/**
 * @class ModuloNCounter
 * @brief A class that represents a counter
 * with a configurable number of digits and base.
 *
 * The ModuloNCounter class allows creating a counter
 * that can increment within a specified range
 * determined by its number of digits and the counter's base type (2/8/10/16).
 */

class ModuloNCounter
{
private:
	/** The array of ModuloNDigit objects */
	ModuloNDigit* pDigitArray;
	/** The maximum number of digits in the counter */
	int numberOfDigits;
	/** The current index of the selected digit */
	int selectedDigit;
	/** The base type of the counter (2/8/10/16) */
	int counterType;
	/** The recursive function to +1 */
	void countRecursive(int index); 
public:
	/**
	 * Default constructor
	 * */
	ModuloNCounter();
	/**
	 * @brief Destructor for ModuloNCounter.
	 *
	 * Cleans up resources allocated by the ModuloNCounter,
	 * specifically the dynamically allocated array of ModuloNDigit objects.
	 */
	~ModuloNCounter();

	/**
	 * @brief Construct a new Modulo N Counter:: Modulo N Counter object
	 * 
	 * @param numberOfDigits [in] maximum number of digits of the counter
	 * @param counterType [in] the type of the counter [2/8/10/16]
	 */
	ModuloNCounter(int numberOfDigits, int counterType);


	/**
	 * @brief Copy constructor for ModuloNCounter.
	 *
	 * @param counter [in] The ModuloNCounter object to copy from.
	 */
	ModuloNCounter(const ModuloNCounter& counter);


	/**
	 * @brief Print the specified information of the counter.
	 */
	void print(PRINT_OPTIONS option);
	/**
	 * @brief Print the Name of the counter.
	 *
	 */
	void printCounterName();
	/**
	 * @brief Print the current value of the counter.
	 */
	void printCounterValue();
	/**
	 * @brief Increment the counter by one.
	 */
	void count();

	/**
	 * @brief Overloads the prefix increment operator.
	 *
	 * Increments the counter by one and returns the incremented counter.
	 * @return ModuloNCounter& Reference to the incremented counter.
	 */

	ModuloNCounter& operator++();

	/**
	 * @brief Overloads the postfix increment operator.
	 *
	 * Increments the counter by one and
	 * returns the counter's value before incrementing.
	 * @return ModuloNCounter The counter's value before incrementing.
	
	*/

	ModuloNCounter operator++(int);

	int getNumberOfDigits() const {
		return numberOfDigits;
	}

	int getSelectedDigit() const {
		return selectedDigit;
	}

	int getCounterType() const {
		return counterType;
	}



};

#endif /* MODULONCOUNTER_H_ */
