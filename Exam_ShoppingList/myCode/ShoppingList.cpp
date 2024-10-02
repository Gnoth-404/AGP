/*
 * ShoppingList.cpp
 *
 *  Created on: Feb 16, 2024
 *      Author: tiena
 */

#include <iostream>
#include "ShoppingList.h"
#include "Food.h"
#include <set>
using namespace std;

ShoppingList& ShoppingList::operator +=(Item *item)
{
	//cast it to unique ptr here
	std::string name = item->getShop();
	auto pItem = std::unique_ptr<Item>(item);

	this->items[name].push_back(std::move(pItem));
	return *this;
}

void ShoppingList::print(std::time_t until) const
{
	std::cout << "Shopping List" << std::endl;
	std::set <std::string> uniqueNote;
 	for(auto& item:this->items)
	{
		cout << item.first <<":" << endl;
		for(const auto& itemData:item.second)
		{

			if(itemData->getUntil()<=until)
			{
				cout << itemData->toString() << endl;
                const auto& notes = itemData->getNotes(); // we need to create a note set here to invoke begin and end

				uniqueNote.insert(notes.begin(), notes.end());
			}

		}
	}
 	for (auto& note:uniqueNote)
 	{
 		cout << note << endl;
 	}
}

void ShoppingList::save(std::ostream &to) const
{
	for (auto& item:this->items)
	{
		for(auto& itemData:item.second)
		{
			itemData->save(to);
		}
	}
}

void ShoppingList::load(std::istream &from)
{
	std::string line;
	while(std::getline(from, line))
	{
		if(line.empty()) continue;
		if(line.find("Food")!=line.npos)
		{
			Food* food= Food::restore(line);
			// *this will be an reference to object, use this to add food
			*this += food;
		}
		else if (line.find("Item")!=line.npos)
		{
			Item* item= Item::restore(line);
			*this +=item;
		}
		else
		{
			cout << "Error";
		}
	}

}
