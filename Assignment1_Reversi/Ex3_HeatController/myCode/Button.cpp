/*
 * Button.cpp
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#include "Button.h"

Button::Button():pin(0)
{

}
Button::Button(int pin)
{
	this->pin =pin;
}
Button::~Button()
{
	// TODO Auto-generated destructor stub
}

