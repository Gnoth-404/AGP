/*
 * Measurement.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "Measurement.h"
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
Measurement::~Measurement()
{
	// TODO Auto-generated destructor stub
}

Measurement::Measurement(uint16_t timestamp):timestamp{timestamp}
{
}

uint16_t Measurement::toTimestamp(int hour, int minute)
{
	// convert given hour and minute to the number of minute since 0000
	return hour*60+minute;
}

std::string Measurement::toTimeOfDay(uint16_t timestamp)
{
	std::string result;
	int hour = timestamp % 60;
	int minute = timestamp /60;
	if (hour <10 && minute < 10)
	{
		result = "0" + std::to_string(hour) + ":" + "0" + std::to_string(minute);
	}
	else
	{
		result = std::to_string(hour) + ":" + std::to_string(minute);
	}
	return result;
}

long Measurement::getTimestamp()
{
	return this->timestamp;
}

std::string Measurement::toString()
{
	return "";
}

std::ostream& operator <<(std::ostream &lhs, Measurement &rhs)
{
	return lhs << rhs.toTimeOfDay(rhs.getTimestamp())<< " " << rhs.toString() << std::endl;
}

void Measurement::parseLine(const std::string &line, uint16_t timestamp,
		std::string &type, std::string &remainder)
{
	std::stringstream ss;
	ss.str(line);
	std::string timestampstr;
	std::getline(ss, timestampstr,';');
	timestamp = std::stol(timestampstr);
	std::getline(ss, type,':');
	std::getline(ss, remainder);
}
