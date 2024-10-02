/**
 * @file WeeklyCourse.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include <Poco/DateTime.h>
#include <Poco/Data/Time.h>
#include "Course.h"

/**
 * @class WeeklyCourse
 * @brief Represents a WeeklyCourse inherits from Course
 */
class WeeklyCourse : public Course {
private:
	//! Day of the week for the course.
    Poco::DateTime::DaysOfWeek dayOfWeek;
    //! Start time of the course.
    Poco::Data::Time startTime;
    //! End time of the course.
    Poco::Data::Time endTime;

    /**
     * @brief convert to Poco::DateTime weekday from integer index
     * @param dayIndex Integer value of the day in a week
     * @return e.g Poco::DateTime::SUNDAY
     */
	Poco::DateTime::DaysOfWeek getDayOfWeekFromInt(int dayIndex) ;

public:
    /**
     * @brief Constructor for WeeklyCourse.
     */
    WeeklyCourse(unsigned int courseKey, std::string title, std::string major,
                 float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
                 Poco::Data::Time startTime, Poco::Data::Time endTime);

    /**
     * @brief Destructor for WeeklyCourse.
     */
    virtual ~WeeklyCourse();

    /**
     * @brief Get the day of the week for the course.
     * @return The day of the week.
     */
    Poco::DateTime::DaysOfWeek getDayOfWeek() const;

    /**
     * @brief Get the end time of the course.
     * @return The end time.
     */
    const Poco::Data::Time& getEndTime() const;

    /**
     * @brief Get the start time of the course.
     * @return The start time.
     */
    const Poco::Data::Time& getStartTime() const;

    /**
     * @brief Write the WeeklyCourse object to an output stream.
     * @param out The output stream.
     */
    void write(std::ostream& out) const override;

    /**
     * @brief Read the WeeklyCourse object from an input stream.
     * @param in The input stream.
     */
    void read(std::istream& in);

};

#endif /* WEEKLYCOURSE_H_ */
