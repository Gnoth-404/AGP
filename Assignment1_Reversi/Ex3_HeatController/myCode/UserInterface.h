/*
 * UserInterface.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include "Button.h"
#include "Display.h"

class UserInterface {
private:
    Button increaseTempButton;
    Button decreaseTempButton;
    Button confirmButton;
    Display display;

public:
    UserInterface();
    UserInterface(Button& incButton, Button& decButton, Button& confButton, Display& disp);
    void handleButtonPress(); // Handles the button press logic
    void updateDisplay(); // Update the display based on interactions
    ~UserInterface();
};

#endif /* USERINTERFACE_H_ */
