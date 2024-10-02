/*
 * ResistorReader.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: tiena
 */

#include "ResistorReader.h"
#include <iostream>
#include <sstream>
#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"

ResistorReader::ResistorReader()
{
}

void ResistorReader::read(std::istream &in,
		std::map<std::string, ResistorPtr> &found)
{
	std::string line;
	while(std::getline(in, line))
	{
		if(line.find("[")!=line.npos)
		{
			// this is connection
			std::stringstream ss;
			ss.str(line);
			std::string name;
			std::getline(ss, name, '[');
			if (line.find('-'!=line.npos))
			{
				auto pSeries = new SerialResistorConnection(name);
				std::string connection;

				while(std::getline(ss, connection, '-'))
				{
					*pSeries += found.at(connection);
					found.erase(connection);

				}
				std::string lastResistor;
				std::getline(ss, lastResistor, ']');
				*pSeries += found.at(lastResistor);
				found.erase(lastResistor);
				found.emplace(name, pSeries);
			}
			else if (line.find('|'!=line.npos))
			{
				auto pParallel = new ParallelResistorConnection(name);
				std::string connection;
				while(std::getline(ss, connection, '|'))
				{
					*pParallel += found.at(connection);
					found.erase(connection);
				}
				std::string lastResistor;
				std::getline(ss, lastResistor, ']');
				*pParallel += found.at(lastResistor);
				found.erase(lastResistor);
				found.emplace(name, pParallel);
			}
		}
		else
		{
			auto resistor = ResistorPart::from(line);
			found.emplace(resistor->getName(),resistor);

			// this is resistor
		}
	}
}
