/*
 * Thermostats.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef THERMOSTATS_H_
#define THERMOSTATS_H_

#include "TemperatureSensor.h"
#include "Display.h"
#include "HeatController.h"
#include "Button.h"
#include "UserInterface.h"
#include "Bluetooth.h"
#include "ScheduleTask.h"

/**
 * @brief The Thermostats class integrates various components like
 * temperature sensors, display, timer, Bluetooth, heat controller, buttons,
 * and user interface to create a complete Heat Controller system.
 * 
 * This class is responsible for controlling the interactions between
 * different components to control the temperature effectively.
 * It can control temperature adjustment,update display ,
 * and establish Bluetooth connectivity for remote control.
 */
class Thermostats
{
private:
    TemperatureSensor tempSensor;  ///< Temperature sensor
    ScheduleTask scheduleTask;	///< Schedule for scheduling thermostat temp.
    Bluetooth bluetooth;           ///< Bluetooth module(remote control)
    HeatController heatController; ///< Heating controller
    UserInterface userInterface;   ///< Interface for user input.

public:
    /**
     * @brief Construct a new Thermostats object
     * 
     * Initializes all components required for the thermostat's operation.
     */
    // Default constructor
    Thermostats();

    /**
     * @brief Destroy the Thermostats object
     * 
     * Responsible for clean-up and releasing resources.
     */
    virtual ~Thermostats();

    /**
     * @brief Main function to run the thermostat's operations.
     * 

     */
    void run();
};

#endif /* THERMOSTATS_H_ */
