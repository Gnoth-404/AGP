/*
 * Item.h
 *
 *  Created on: Feb 16, 2024
 *      Author: tiena
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <ctime>
#include <string>
#include <set>
#include <ostream>
class Item
{
private:
	std::string name;
	std::string shop;
	std::time_t until;
public:
	Item(std::string name, std::string shop, std::time_t until);
	virtual ~Item();
	const std::string& getName() const;
	const std::string& getShop() const;
	std::time_t getUntil() const;

	virtual std::set<std::string> getNotes() const;
	virtual std::string toString() const;
	virtual void save(std::ostream& to) const;


	static Item* restore(std::string line);

};


std::ostream& operator << (std::ostream& lhs, const Item& item);
#endif /* ITEM_H_ */
