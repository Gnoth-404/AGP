/*
 * Humidity.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include "Measurement.h"
#include <memory>
class Humidity: public Measurement
{
private:
	float humidity;

public:
	Humidity(uint16_t timestamp, float humidity);
	virtual ~Humidity();
	float getHumidity();
	std::string toString();
	static std::shared_ptr<Humidity> fromString(uint16_t timestamp, std::string value);
	static Humidity* toType(Measurement* measurement);

};

#endif /* HUMIDITY_H_ */
