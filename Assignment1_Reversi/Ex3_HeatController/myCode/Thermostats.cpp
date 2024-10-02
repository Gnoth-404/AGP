/*
 * Thermostats.cpp
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#include "Thermostats.h"

// Default constructor
Thermostats::Thermostats()
    : tempSensor(),       // Initialize the TemperatureSensor object
	  scheduleTask(),         // Initialize the ScheduleTask object
      bluetooth(),        // Initialize the Bluetooth object
      heatController(),   // Initialize the HeatController object
      userInterface()      // Initialize the UserInterface object
{
    // Any additional initialization code can go here
}

Thermostats::~Thermostats()
{
	// TODO Auto-generated destructor stub
}

void Thermostats::run()
{

}
