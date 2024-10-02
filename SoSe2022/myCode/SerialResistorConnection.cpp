/*
 * SerialResistorConnection.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "SerialResistorConnection.h"

SerialResistorConnection::SerialResistorConnection(std::string name):ResistorConnection{name}
{
}

char SerialResistorConnection::separator() const
{
	return'-';
}

float SerialResistorConnection::nominalValue() const
{
	float result =0;
	for (auto resistor:this->resistors)
	{
		result += resistor->nominalValue();
	}
	return result;
}

float SerialResistorConnection::minimumValue() const
{
	float result =0;
	for (auto resistor:this->resistors)
	{
		result += resistor->minimumValue();
	}
	return result;
}

float SerialResistorConnection::maximumValue() const
{
	float result =0;
	for (auto resistor:this->resistors)
	{
		result += resistor->maximumValue();
	}
	return result;
}
