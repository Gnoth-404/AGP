/*
 * ModuloNCounter.cpp
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#include "ModuloNCounter.h"
#include <iostream>

/**
 * @brief Destructor for ModuloNCounter.
 *
 * Cleans up resources allocated by the ModuloNCounter,
 * specifically the dynamically allocated array of ModuloNDigit objects.
 */
ModuloNCounter::~ModuloNCounter()
{
	delete[] pDigitArray;
}


ModuloNCounter::ModuloNCounter(int numberOfDigits, int counterType)
{
	this->numberOfDigits = numberOfDigits;
	this->counterType = counterType;
	pDigitArray = new ModuloNDigit[numberOfDigits];
	for (int i = 0; i < numberOfDigits; i++)
	{
		pDigitArray[i] = ModuloNDigit(counterType);
	}
	// array count from left to right,
	// so the selected digit is the rightmost digit
	this->selectedDigit = numberOfDigits -1;
}
/**
 * @brief Copy constructor for ModuloNCounter.
 *
 * @param counter [in] The ModuloNCounter object to copy from.
 */
ModuloNCounter::ModuloNCounter(const ModuloNCounter& counter)
{
	this->numberOfDigits = counter.numberOfDigits;
	this->counterType = counter.counterType;
	this->selectedDigit = counter.selectedDigit;
	this->pDigitArray = new ModuloNDigit[numberOfDigits];
	for (int i = 0; i < numberOfDigits; i++)
	{
		this->pDigitArray[i] = counter.pDigitArray[i];
	}
}
/**
 * @brief Increase the counter by 1
 * 
 */
void ModuloNCounter::count()
{
	countRecursive(this->selectedDigit);

}
/**
 * @brief Increase the counter by 1 recursively
 * 
 * @param index [in] the index of the digit to increase
 */
void ModuloNCounter::countRecursive(int index)
{
	if (index < 0)
	{
		return;
	}
	if (pDigitArray[index].count())
	{
		// If the current digit is overflowed,
		// then increase the digit on the left
		countRecursive(index-1);
	}
}

/**
 * @brief Print the specified information of the counter.
 *
 * @param option [in] The print option(COUNTER_NAME or COUNTER_VALUE)
 */
void ModuloNCounter::print(PRINT_OPTIONS option)
{
	switch(option)
	{
		case PRINT_OPTIONS::COUNTER_NAME:
			this->printCounterName();
			break;
		case PRINT_OPTIONS::COUNTER_VALUE:
			this->printCounterValue();
			break;

	}
}

void ModuloNCounter::printCounterName()
{
	switch (this->getCounterType())
	{
		case 2:
			std::cout << numberOfDigits << " digit binary counter\n";
			return;
		case 8:
			std::cout << numberOfDigits << " digit octal counter\n";
			return;
		case 10:
			std::cout << numberOfDigits << " digit decimal counter\n";
			return;
		case 16:
			std::cout << numberOfDigits << " digit hexadecimal counter\n";
			return;
	}
}

void ModuloNCounter::printCounterValue()
{
	for (int i = 0; i < numberOfDigits; i++)
	{
		pDigitArray[i].print(PRINT_OPTIONS::COUNTER_VALUE);
	}
	std::cout << " ";
}


/**
 * @brief Overloads the prefix increment operator.
 *
 * Increments the counter by one and returns the incremented counter.
 * @return ModuloNCounter& Reference to the incremented counter.
 */
ModuloNCounter &ModuloNCounter::operator++()
{
	this->count();
	return *this;
}
/**
 * @brief Overloads the postfix increment operator.
 *
 * Increments the counter by one and
 * returns the counter's value before incrementing.
 * @return ModuloNCounter The counter's value before incrementing.

*/
ModuloNCounter ModuloNCounter::operator++(int)
{
	ModuloNCounter temp (*this);
	++(*this);
	return temp;
}
