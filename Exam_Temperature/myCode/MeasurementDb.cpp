/*
 * MeasurementDb.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "MeasurementDb.h"
#include <iostream>
#include "Humidity.h"
#include "Temperature.h"
#include <algorithm>
void MeasurementDb::addMeasurement(const std::string &location,
		std::shared_ptr<Measurement> measurement)
{
	this->data[location].push_back(std::move(measurement));
}

void MeasurementDb::print()
{
	std::cout << "Content of database" << std::endl;
	for (auto& measurementData:this->data)
	{
		for (auto& type:measurementData.second)
		{
			std::cout << measurementData.first << ":" ;
			std::cout << type->toString() << std::endl;
		}
	}
}

void MeasurementDb::save(std::ostream &to)
{
	for (auto& measurementData:this->data)
	{
		to <<"[" <<measurementData.first << "]" << std::endl ;

		for (auto& type:measurementData.second)
		{
			to << type->getTimestamp()<<";" << type->toString() << std::endl;
		}
	}
}

void MeasurementDb::load(std::istream &from)
{
	this->data.clear();
	std::string line;
	std::string location;
	while(std::getline(from,line))
	{
		auto it = line.find("[");

		if(it!=line.npos)
		{
			// this is location
			//[location]
			location = line.substr(it+1);
			location.pop_back();
		}
		else
		{
			std::string remainder;
			uint16_t timestamp =0;
			std::string type;

			Measurement::parseLine(line, timestamp, type, remainder);
			if (type =="Humidity")
			{
				this->addMeasurement(location,Humidity::fromString(timestamp, remainder));

			}
			else if(type =="Temperature")
			{
				this->addMeasurement(location,Temperature::fromString(timestamp, remainder));

			}
		}

	}
}

bool MeasurementDb::maximumTemperature(std::string &location,
		std::shared_ptr<Measurement> &measurement)
{
	float maxtemp=0;
	for(auto& itemData:this->data)
	{
		for(auto& measurementData:itemData.second)
		{
			auto pTemp = Temperature::toType(measurementData.get());
			if (pTemp!=nullptr)
			{
				if( pTemp->getTemperature()> maxtemp)
				{
					maxtemp = pTemp->getTemperature();
					location = itemData.first;
					measurement = measurementData;
				}
			}
		}
	}
	if(maxtemp>0)
	{
		std::cout << maxtemp << std::endl;
		std::cout << location << std::endl;
		std::cout << measurement << std::endl;
		return true;
	}
	return false;
}
