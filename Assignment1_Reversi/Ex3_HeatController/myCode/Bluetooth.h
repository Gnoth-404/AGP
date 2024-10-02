/*
 * Bluetooth.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "ScheduleTask.h"
/**
 * @class Bluetooth
 * @brief Manages Bluetooth communication for the thermostat.
 *
 * This class handles Bluetooth connectivity,enabling remote control
 */
class Bluetooth{
private:
    bool isConnected; ///< Indicates the state of Bluetooth connection
    ScheduleTask* schedule;     ///< Pointer for Task manipulation

public:
    Bluetooth();
    /**
     * Constructor for Bluetooth.
     * @param schedule A pointer to a Schedule object for
     * setting schedules via Bluetooth.
     */
    Bluetooth(ScheduleTask* schedule);

	~Bluetooth();
    /**
     * Initializes the Bluetooth module.
     */
    void init();

    /**
     * Handles incoming Bluetooth communication and
     * updates the Timer schedules as needed.
     */
    void handleCommunication();

    /**
     * Gets the current state of the Bluetooth connection.
     * @return True if connected, false otherwise.
     */
    bool getBluetoothState() const;

};

#endif /* BLUETOOTH_H_ */
