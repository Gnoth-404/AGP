/*
 * Schedule.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef ScheduleTask_H_
#define ScheduleTask_H_


/**
 * @class ScheduleTask
 * @brief Represents a temperature control schedule.
 *
 * This class manages a schedule that set the specific temperature at
 * specific time of the day
 */
class ScheduleTask {
private:
    int hour;          ///< Hour of the day for the schedule (0-23).
    int minute;        ///< Minute of the hour for the schedule (0-59).
    float temperature; ///< Desired temperature at this schedule time.

public:

    ScheduleTask();
    /**
     * Constructor for ScheduleTask.
     * @param h The hour of the day for the schedule (0-23).
     * @param m The minute of the hour for the schedule (0-59).
     * @param temp The target temperature for the scheduled time.
     */
    ScheduleTask(int h, int m, float temp) :
    	hour(h), minute(m), temperature(temp){}

    /**
     * Gets the scheduled temperature.
     * @return The scheduled temperature.
     */
    float getTemperature() const { return temperature; }

    /**
     * Checks if the schedule matches the given time.
     * @param h The hour of the day (0-23).
     * @param m The minute of the hour (0-59).
     * @return True if the schedule matches the given time, false otherwise.
     */
    bool isScheduledTime(int h, int m) const {
        return (hour == h && minute == m);
    }

    // Destructor
    ~ScheduleTask();
};

#endif /* ScheduleTask_H_ */
