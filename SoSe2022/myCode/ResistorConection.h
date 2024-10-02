/*
 * ResistorConection.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef RESISTORCONNECTION_H_
#define RESISTORCONNECTION_H_

#include <list>
#include "Resistor.h"

class ResistorConnection: public Resistor
{
protected:
	std::list<ResistorPtr> resistors;
public:
	ResistorConnection(std::string name);
	virtual char separator() const;
	virtual const std::string getName() const;
	void write(std::ostream& out);
	ResistorConnection& operator+=(const ResistorPtr resistor);
};

#endif /* RESISTORCONNECTION_H_ */
