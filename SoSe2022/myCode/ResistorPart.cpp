/*
 * ResistorPart.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "ResistorPart.h"
#include <iostream>
#include <sstream>
ResistorPart::ResistorPart(std::string name, float value, float tolerance):Resistor{name},value{value},tolerance{tolerance}
{
}

float ResistorPart::nominalValue() const
{
	return value;
}

float ResistorPart::minimumValue() const
{
	return value-tolerance*value;
}

float ResistorPart::maximumValue() const
{
	return value+tolerance*value;
}

ResistorPtr ResistorPart::from(std::string line)
{
	std::stringstream ss;
	ss.str(line);

	std::string name;
	std::getline(ss, name, ';');

	std::string value;
	std::getline(ss, value, ';');

	std::string tolerance;
	std::getline(ss, tolerance, ';');

	auto pResistorPart = ResistorPtr(new ResistorPart(name, std::stof(value), std::stof(tolerance)));
	return pResistorPart;
}
