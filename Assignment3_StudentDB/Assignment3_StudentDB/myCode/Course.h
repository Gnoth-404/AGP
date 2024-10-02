/**
 * @file Course.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <string>
/**
 * @class Course
 * @brief Base course class
 */
class Course {
protected:
	//! Map of major IDs to major names for optimization.
    static std::map<unsigned char, std::string> majorById;
    //! Unique course key
    unsigned int courseKey;
    //! Title of the course.
    std::string title;
    //! Major of the course.
    unsigned char major;
    //! Credit points of the course.
    float creditPoints;

public:
    /**
     * @brief Constructor for Course.
     */
    Course(unsigned int courseKey, std::string title,
    		std::string major, float creditPoints);

    /**
     * @brief Virtual destructor for Course.
     */
    virtual ~Course() = 0;

    /**
     * @brief Get the course key.
     * @return The course key.
     */
    unsigned int getCourseKey() const;

    /**
     * @brief Get the credit points of the course.
     * @return The credit points.
     */
    float getCreditPoints() const;

    /**
     * @brief Get the major of the course.
     * @return The major.
     */
    const std::string& getMajor() const;

    /**
     * @brief Get the title of the course.
     * @return The title.
     */
    const std::string& getTitle() const;

    /**
     * @brief Write the Course object to an output stream.
     * @param out The output stream.
     */
    virtual void write(std::ostream& out) const;

    /**
     * @brief Read a Course object from an input stream.
     * @param in The input stream.
     */
    virtual void read(std::istream& in);
};

#endif /* COURSE_H_ */
