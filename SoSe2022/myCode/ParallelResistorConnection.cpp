/*
 * ParallelResistorConnection.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "ParallelResistorConnection.h"
#include <algorithm>
ParallelResistorConnection::ParallelResistorConnection(std::string name):ResistorConnection{name}
{
}

char ParallelResistorConnection::separator() const
{
	return '|';
}

float ParallelResistorConnection::nominalValue() const
{
	float result =0;
	for (auto resistor:this->resistors)
	{
		result += 1/resistor->nominalValue();
	}
	return 1/result;
}

float ParallelResistorConnection::minimumValue() const
{
	float result =0;
	for (auto resistor:this->resistors)
	{
		result += 1/resistor->minimumValue();

	}
	return 1/result;
}

float ParallelResistorConnection::maximumValue() const
{
	float result =0;
	for (auto resistor:this->resistors)
	{
		result += 1/resistor->maximumValue();
	}
	return 1/result;
}
