/*
 * Measurement.h
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_
#include <cinttypes>
#include <cstdio>
#include <string>
class Measurement
{
private:
	uint16_t timestamp;
public:
	Measurement(uint16_t timestamp);
	virtual ~Measurement();
	static uint16_t toTimestamp(int hour, int minute);
	static std::string toTimeOfDay(uint16_t timestamp);
	long getTimestamp();
	virtual std::string toString();
	static void parseLine(const std::string& line, uint16_t timestamp, std::string& type, std::string& remainder);
};
std::ostream& operator<< (std::ostream& lhs, Measurement& rhs);

#endif /* MEASUREMENT_H_ */
