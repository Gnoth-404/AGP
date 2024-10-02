/*
 * Display.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */
#ifndef DISPLAY_H_
#define DISPLAY_H_
/**
 * @class Display
 * @brief Class for managing the display interface.
 *
 * This class provides functionalities for initializing the display,
 * displaying temperature, and clearing the display screen.
 */
class Display
{
public:
    /**
     * @brief Constructor for Display.
     *
     * Initializes a new Display object.
     */
    Display();

    /**
     * @brief  Destructor for Display.
     *
     */
    virtual ~Display();

    /**
     * @brief Initialize the display.
     *
     * Set up the display by configuring necessary hardware/ software settings.
     */
    void initDisplay();

    /**
     * @brief Display temperature on the display.
     *
     * @param temp The temperature value to be displayed.
     */
    void displayTemp(float temp);

    /**
     * @brief Clear the display.
     *
     * Erases any content currently shown on the display screen.
     */
    void clearDisplay();
};

#endif /* DISPLAY_H_ */
