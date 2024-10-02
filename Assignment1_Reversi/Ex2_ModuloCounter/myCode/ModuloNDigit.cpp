/*
 * ModuloNDigit.cpp
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#include "ModuloNDigit.h"
#include <iostream>

ModuloNDigit::ModuloNDigit()
{
	maxValue = 0;
	currentValue = 0;
	isOverFlow = false;
}
ModuloNDigit::~ModuloNDigit()
{
}
/**
 * @brief Construct a new Modulo N Digit object
 * 
 */

ModuloNDigit::ModuloNDigit(int modulo)
{
	if (modulo !=2 && modulo != 10 && modulo != 16 && modulo != 8)
	{
		std::cout << "Invalid modulo value" << std::endl;
		return;
	}
	maxValue = modulo;
	currentValue = 0;
	isOverFlow = false;
}

/**
 * @brief Print the counter based on the option
 * 
 * @param option[in] the option to print the counter
 */
void ModuloNDigit::print(PRINT_OPTIONS option)
{
	switch(option)
	{
	case PRINT_OPTIONS::COUNTER_NAME:
		this->printCounterName();
		break;
	case PRINT_OPTIONS::COUNTER_VALUE:
		this->printCounterValue();
		break;

	default:
		std::cout << "Invalid option" << std::endl;
		break;
	}
}
/**
 * @brief Print the counter name
 * 
 */
void ModuloNDigit::printCounterName() 
{
			switch(this->maxValue)
		{
		case 2:
			std::cout << "Binary" ;
			break;
		case 8:
			std::cout << "Octal" ;
			break;
		case 10:
			std::cout << "Decimal" ;
			break;
		case 16:
			std::cout << "Hexadecimal";
			break;
		}
		std::cout << " counter: " << std::endl;
}
/**
 * @brief Construct a new Modulo N Digit object
 * 
 * @param counter[in] current counter
 * @return new ModuloNDigit object
 */
ModuloNDigit::ModuloNDigit(const ModuloNDigit& counter)
{
	this->maxValue = counter.maxValue;
	this->currentValue = counter.currentValue;
	this->isOverFlow = counter.isOverFlow;
}
/**
 * @brief Increase the counter value by 1 until it reaches the maximum value
 * @return 1 if the counter is overflowed, 0 otherwise
 */

bool ModuloNDigit::count()
{


	++this->currentValue;
	this->currentValue%=this->maxValue;
	if (this->currentValue == 0)
	{
		this->isOverFlow = true;
	}
	else
	{
		this->isOverFlow = false;
	}
	return this->isOverFlow;
}
/**
 * @brief Print the current counter value
 * 
 */
void ModuloNDigit::printCounterValue()
{
	switch(this->maxValue)
	{
	case 8:
		std::cout << std::oct << this->currentValue << std::dec ;
		return;
	case 16:
		std::cout << std::hex << std::uppercase << this->currentValue ;
		std::cout << std::nouppercase << std::dec;
		return;
	default:
		std::cout << this->currentValue ;
		return;
	}

}
/**
 * @brief Overloading the prefix operator ++i
 * 
 * @return ModuloNDigit 
 */
ModuloNDigit& ModuloNDigit::operator++()
{
	count();
	return *this;
}
/**
 * @brief Overloading the postfix operator i++
 * 
 * @return ModuloNDigit 
 */
ModuloNDigit ModuloNDigit::operator++(int)
{
	ModuloNDigit temp(*this);
	++*this;

	return temp;
}
