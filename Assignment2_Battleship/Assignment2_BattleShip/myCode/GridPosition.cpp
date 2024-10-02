/*
 * GridPosition.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: tiena
 */

#include "GridPosition.h"
#include "iostream"



GridPosition::GridPosition(char row, int column):row(row),column(column)
{
}

GridPosition::GridPosition(std::string position)
{
	if (position.empty())
		std::cout << "Please input non-empty string" << std::endl;
	// Row character is first string member
	this->row = position[0];
	// Column integer is the rest of the string, convert it to substring-> int
	this->column = std::stoi(position.substr(1));
}

bool GridPosition::isValid() const
{
	return ((this->row >= 'A' && this->row <= 'Z') && this->column >0);
}

char GridPosition::getRow() const
{
	return this->row;
}

int GridPosition::getColumn() const
{
	return this->column;
}

GridPosition::operator std::string() const
{
	std::string result;
	// Cast int column to string by using std::to_string
	// Convert char row to string by using std::string
	result = std::string(1, this->row) + std::to_string(this->column);
	return result;
}

bool GridPosition::operator ==(const GridPosition& rop) const
{
	if ((rop.getColumn() == this->column) && (rop.getRow() == this ->row))
		return 1;
	return 0;
}

bool GridPosition::operator <(const GridPosition& rop) const
{
	if (rop.getRow() == this->row)
		return this->column < rop.getColumn();
	else
		return this->row < rop.getRow();
}

GridPosition::~GridPosition()
{
	// TODO Auto-generated destructor stub
}

