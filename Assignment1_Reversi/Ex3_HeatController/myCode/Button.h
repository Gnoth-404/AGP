/*
 * Button.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/**
 * @class Button
 * @brief A class to represent and handle a button in Hardware API
 */
class Button
{
private:
    /**
     * @brief The GPIO input number
    */
	int pin;

public:

	/**
	 * @brief Default constructor.
	 */
	Button();
    /**
     * @brief Construct a new Button object
     * 
     * @param pin The GPIO pin number to which the button is connected. 
     */
    Button(int pin);

    /**
     * @brief Destroy the Button object
     * 
     */
    virtual ~Button();

    /**
     * @brief Checks if the button is currently pressed.
     * 
     * @return true If the button is pressed.
     * @return false Otherwise.
     */
    bool isPressed();

    /**
     * @brief Checks if the button is double-pressed
     * 
     * @return true If the button is double-pressed.
     * @return false Otherwise.
     */
    bool isDoublePressed();

    /**
     * @brief Checks if the button is being held for a longer duration.
     * 
     * @return true If the button is long-pressed.
     * @return false Otherwise.
     */
    bool isLongPressed();
};
#endif /* BUTTON_H_ */
