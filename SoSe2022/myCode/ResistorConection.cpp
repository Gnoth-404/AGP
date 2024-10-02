/*
 * ResistorConection.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "ResistorConection.h"
#include <iostream>
ResistorConnection::ResistorConnection(std::string name):Resistor{name}
{
}


const std::string ResistorConnection::getName() const
{
	std::string result;
	result = Resistor::getName() + " [";
	for (auto& resistor:this->resistors)
	{
		result += resistor->Resistor::getName();

		result.push_back(this->separator());
	}
    result.pop_back(); // Remove the last separator character
	result +="]";
	return result;
}

void ResistorConnection::write(std::ostream &out)
{
	for (auto& resistor:this->resistors)
	{
		resistor->Resistor::write(out);
	}
	Resistor::write(out);
}

ResistorConnection& ResistorConnection::operator +=(const ResistorPtr resistor)
{
	this->resistors.push_back(resistor);
	return *this;
}



char ResistorConnection::separator() const
{
	return ',';

}
