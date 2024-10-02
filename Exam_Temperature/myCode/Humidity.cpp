/*
 * Humidity.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "Humidity.h"

Humidity::Humidity(uint16_t timestamp, float humidity):Measurement{timestamp},humidity{humidity}
{
}

Humidity::~Humidity()
{
}

float Humidity::getHumidity()
{
	return this->humidity;
}

std::string Humidity::toString()
{
	std::string result;

	result = "Humidity:"+std::to_string(this->humidity) +"%";
	return result;

}

std::shared_ptr<Humidity> Humidity::fromString(uint16_t timestamp,
		std::string value)
{
	value.pop_back();
	float humidity = std::stof(value);

	auto result = std::shared_ptr<Humidity>(new Humidity{timestamp,humidity});
	return result;
}

Humidity* Humidity::toType(Measurement *measurement)
{
	Humidity* pHumidity = dynamic_cast<Humidity*>(measurement);
	if(pHumidity!= nullptr)
	{
		return pHumidity;
	}
	else
	{
		return nullptr;
	}
}
