/*
 * Item.cpp
 *
 *  Created on: Feb 16, 2024
 *      Author: tiena
 */

#include "Item.h"
#include <iostream>
Item::Item(std::string name, std::string shop, std::time_t until):name{name},shop{shop},until{until}
{
}

const std::string& Item::getName() const
{
	return name;
}

const std::string& Item::getShop() const
{
	return shop;
}

std::time_t Item::getUntil() const
{
	return until;
}

Item::~Item()
{
	// TODO Auto-generated destructor stub
}



std::string Item::toString() const
{
	// Rice (Super market)
	std::string result;
	result =   this->name +" (" + this->shop + ")";
	return result;
}

// this one is to save to file
void Item::save(std::ostream &to) const
{
	to << "Item;" <<this->name <<";" << this->shop <<";" << this->until << std::endl;
}


// this one is used for printing item on cout
std::ostream& operator <<(std::ostream &lhs, const Item &item)
{
	lhs << "Item;" << item.getName() <<";" << item.getShop() <<";" << item.getUntil() << std::endl;
	return lhs;
}

Item* Item::restore(std::string line)
{
	extern std::string splitAt(std::string& remainder, char separator);
	std::string type = splitAt(line, ';');
	if (type =="Item")
	{
		std::string name = splitAt(line,';');
		std::string shop = splitAt(line,';');
		std::string time = splitAt(line,';');
		std::time_t untilTime = std::stoi(time);
		auto *pItem = new Item(name, shop, untilTime);
		return pItem;
	}

	return nullptr;
}

std::set<std::string> Item::getNotes() const
{
	// return empty string here;
	return std::set<std::string>();
}
