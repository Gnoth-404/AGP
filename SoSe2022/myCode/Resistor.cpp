/*
 * Resistor.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "Resistor.h"
#include <iostream>
Resistor::Resistor(std::string name):name{name}
{
}


Resistor::~Resistor()
{
	// TODO Auto-generated destructor stub
}

float Resistor::nominalValue() const
{
	return 0;
}

float Resistor::minimumValue() const
{
	return 0;
}

float Resistor::maximumValue() const
{
	return 0;
}

const std::string Resistor::getName() const
{
	return name;
}


std::string Resistor::toString() const
{
	std::string result;
	result = this->getName() +"="+std::to_string(this->nominalValue()) +" Ohm";
	return result;
}

std::ostream& Resistor::operator <<(std::ostream &in)
{
	return in << this->toString();
}

void Resistor::write(std::ostream &out)
{
	float tolerance;
	tolerance = (this->maximumValue()-this->nominalValue())/this->nominalValue();


	out << this->getName()<<"; " << std::to_string(this->nominalValue()) << "; " << std::to_string(tolerance) << std::endl;
}
