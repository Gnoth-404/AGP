/*
 * ParallelResistorConnection.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef PARALLELRESISTORCONNECTION_H_
#define PARALLELRESISTORCONNECTION_H_

#include "ResistorConection.h"

class ParallelResistorConnection: public ResistorConnection
{
public:
	ParallelResistorConnection(std::string name);
	virtual char separator() const;
	 float nominalValue() const;
	 float minimumValue() const;
	 float maximumValue() const;
};

#endif /* PARALLELRESISTORCONNECTION_H_ */
