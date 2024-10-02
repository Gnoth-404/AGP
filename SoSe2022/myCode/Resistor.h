/*
 * Resistor.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_

#include <string>
#include <memory>

class Resistor
{
private:
	std::string name;
public:
	Resistor(std::string name);
	virtual float nominalValue() const;
	virtual float minimumValue() const;
	virtual float maximumValue() const;

	virtual ~Resistor();
	virtual const std::string getName() const;
	virtual std::string toString() const;
	std::ostream& operator<<(std::ostream& in);
	void write(std::ostream& out);
};
typedef std::shared_ptr<Resistor> ResistorPtr;

#endif /* RESISTOR_H_ */
