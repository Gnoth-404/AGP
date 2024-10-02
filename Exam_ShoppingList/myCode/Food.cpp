/*
 * Food.cpp
 *
 *  Created on: Feb 16, 2024
 *      Author: tiena
 */

#include "Food.h"




Food::Food(std::string name, std::string shop, std::time_t until,
		bool needsCooling):Item{name,shop,until},needsCooling{needsCooling}
{
}

bool Food::getNeedsCooling() const
{
	return this->needsCooling;
}

std::set<std::string> Food::getNotes() const
{
	if(!this->needsCooling)
	{
		return std::set<std::string>();
	}
	std::set<std::string> result;
	result.insert("One or more item require cooling!");
	return result;
}

std::string Food::toString() const
{
	std::string result= Item::toString();
	if(this->needsCooling)
	{
		result.append("[Keep cool!]");
	}
	return result;
}

void Food::save(std::ostream &to) const
{
	to << "Food;" << this->getName() <<";" <<this->getShop() <<";" <<this->getUntil() << ";" << this->getNeedsCooling() << std::endl;
}

Food* Food::restore(std::string line)
{
	extern std::string splitAt(std::string& remainder, char separator);
	std::string type = splitAt(line,';');
	if(type=="Food")
	{
		std::string name = splitAt(line,';');
		std::string shop = splitAt(line,';');
		std::string time = splitAt(line,';');
		std::time_t untilTime = std::stoi(time);
		bool needsCooling = std::stoi(splitAt(line,';'));
		auto *pFood = new Food(name, shop, untilTime, needsCooling);
		return pFood;
	}
	return nullptr;
}
