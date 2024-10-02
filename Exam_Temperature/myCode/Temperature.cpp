   /*
 *                   Temperature.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "Temperature.h"



Temperature::Temperature(uint16_t timestamp, float temperature):Measurement{timestamp},temperature{temperature}
{
}

Temperature::~Temperature()
{
	// TODO Auto-generated destructor stub
}

std::string Temperature::toString()
{
	std::string result;

	result = "Temperature:"+std::to_string(this->temperature) +"°C";
	return result;


}

float Temperature::getTemperature()
{
	return this->temperature;
}

std::shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp,
		std::string value)
{
	// Erase 2 last character
	value.pop_back();
	value.pop_back();
	float temperature = std::stof(value);

	auto result = std::shared_ptr<Temperature>(new Temperature{timestamp,temperature});
	return result;
}

Temperature* Temperature::toType(Measurement *measurement)
{
	Temperature* pTemp = dynamic_cast<Temperature*>(measurement);
	if(pTemp!= nullptr)
	{
		return pTemp;
	}
	else
	{
		return nullptr;
	}
}
