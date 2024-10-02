/*
 * ResistorPart.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef RESISTORPART_H_
#define RESISTORPART_H_

#include "Resistor.h"

class ResistorPart: public Resistor
{
private:
	float value;
	float tolerance;
public:
	ResistorPart(std::string name, float value, float tolerance);

	virtual float nominalValue() const;
	virtual float minimumValue() const;
	virtual float maximumValue() const;

	static ResistorPtr from(std::string line);

};

#endif /* RESISTORPART_H_ */
