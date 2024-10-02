/*
 * ModuloNDigit.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_


enum class PRINT_OPTIONS
{
	COUNTER_NAME,
	COUNTER_VALUE
};

/**
 * @class ModuloNDigit
 * @brief A class that represents a counter for 1 digit
 *
 * The ModuloNDigit class allows creating a counter
 * that can increment within a specified range
 * determined by the counter's base type (2/8/10/16).
 */

class ModuloNDigit
{
private:
	/** The maximum value of the counter */
	int maxValue; 
	/** The current value of the counter */
	int currentValue; 
	/** The flag to indicate the overflow of the counter */
	bool isOverFlow; 

public:
	/**
	 * @brief Construct a new Modulo N Digit object
	 * Default constructor
	 */
	ModuloNDigit();
	/**
	 * @brief Construct a new Modulo N Digit object
	 * 
	 * @param modulo[in] the modulo value
	 */
	ModuloNDigit(int modulo);
	~ModuloNDigit();

	/**
	 * @brief Construct a new Modulo N Digit object
	 * 
	 * @param counter[in] current counter
	 * @return new ModuloNDigit object
	 */
	ModuloNDigit(const ModuloNDigit& counter);
	

	/**
	 * @brief Print the counter based on the option
	 * 
	 * @param option[in] the option to print the counter
	 */
	void print(PRINT_OPTIONS option);
	

	bool count();
	
	void printCounterName();

	void printCounterValue();


	/**
	 * @brief Overloading the prefix operator ++i
	 * 
	 * @return ModuloNDigit 
	 */
	ModuloNDigit operator++(int);
	/**
	 * @brief Overloading the postfix operator i++
	 * 
	 * @return ModuloNDigit 
	 */
	ModuloNDigit& operator++();

	/**
	 * @brief Get the Max Value attribute
	 * 
	 * @return int 
	 */
	int getMaxValue() const
	{
		return maxValue;
	}
	/**
	 * @brief Get the Current Value attribute
	 * 
	 * @return int 
	 */
	int getCurrentValue() const
	{
		return currentValue;
	}
	/**
	 * @brief Get the Is Overflow Flag
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getIsOverflow() const
	{
		return isOverFlow;
	}
};

#endif /* MODULONDIGIT_H_ */
