/*
 * Temperature.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Measurement.h"
#include <memory>
class Temperature: public Measurement
{
private:
	float temperature;
public:
	Temperature(uint16_t timestamp, float temperature);
	virtual ~Temperature();
	std::string toString();
	float getTemperature();
	static std::shared_ptr<Temperature> fromString(uint16_t timestamp, std::string value);
	static Temperature* toType(Measurement* measurement);

};

#endif /* TEMPERATURE_H_ */
