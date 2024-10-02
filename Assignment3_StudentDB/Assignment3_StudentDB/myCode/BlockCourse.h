/**
 * @file BlockCourse.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */
#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include "Course.h"
#include <Poco/DateTime.h>
#include <Poco/Data/Time.h>
#include <Poco/Data/Date.h>

/**
 * @class BlockCourse
 * @brief Represents a block course inherits from Course class
 */
class BlockCourse: public Course {
private:
	//! Start date of the block course.
    Poco::Data::Date startDate;
    //! End date of the block course.
    Poco::Data::Date endDate;
    //! Start time of the block course.
    Poco::Data::Time startTime;
    //! End time of the block course.
    Poco::Data::Time endTime;

public:
    /**
     * @brief Constructor for BlockCourse.

     */
    BlockCourse(unsigned int courseKey, std::string title, std::string major,
                float creditPoints,
				Poco::Data::Date startDate, Poco::Data::Date endDate,
                Poco::Data::Time startTime, Poco::Data::Time endTime);

    /**
     * @brief Destructor for BlockCourse.
     */
    virtual ~BlockCourse();

    /**
     * @brief Get the end date of the block course.
     * @return The end date.
     */
    const Poco::Data::Date& getEndDate() const;

    /**
     * @brief Get the end time of the block course.
     * @return The end time.
     */
    const Poco::Data::Time& getEndTime() const;

    /**
     * @brief Get the start date of the block course.
     * @return The start date.
     */
    const Poco::Data::Date& getStartDate() const;

    /**
     * @brief Get the start time of the block course.
     * @return The start time.
     */
    const Poco::Data::Time& getStartTime() const;

    /**
     * @brief Write the BlockCourse object to an output stream.
     * @param out The output stream.
     */
    void write(std::ostream& out) const override;

    /**
     * @brief Read the BlockCourse object from an input stream.
     * @param in The input stream.
     */
    void read(std::istream& in);
};

#endif /* BLOCKCOURSE_H_ */
