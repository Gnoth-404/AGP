/*
 * SerialResistorConnection.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef SERIALRESISTORCONNECTION_H_
#define SERIALRESISTORCONNECTION_H_

#include "ResistorConection.h"

class SerialResistorConnection: public ResistorConnection
{
public:
	SerialResistorConnection(std::string name);
	virtual char separator() const;
	 float nominalValue() const;
	 float minimumValue() const;
	 float maximumValue() const;

};

#endif /* SERIALRESISTORCONNECTION_H_ */
