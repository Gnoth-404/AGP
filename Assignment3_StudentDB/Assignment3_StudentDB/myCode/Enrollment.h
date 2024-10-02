/**
 * @file Enrollment.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */
#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <string>
#include "Course.h"

/**
 * @class Enrollment
 * @brief Represents enrolled course details of given student object
 */
class Enrollment {
private:
	//! Grade obtained in the course.
    float grade;
    //! Semester of enrollment.
    std::string semester;
    //! Pointer to the enrolled course.
    const Course* course;

public:
    /**
     * @brief Constructor for Enrollment.

     */
    Enrollment(const std::string& semester, const Course* course);

    /**
     * @brief Destructor for Enrollment.
     */
    virtual ~Enrollment();

    /**
     * @brief Get the grade obtained in the course.
     * @return The grade.
     */
    float getGrade() const;

    /**
     * @brief Set the grade obtained in the course.
     * @param grade The grade to set.
     */
    void setGrade(float grade);

    /**
     * @brief Get the semester of enrollment.
     * @return The semester.
     */
    const std::string& getSemester() const;

    /**
     * @brief Get the enrolled course.
     * @return Pointer to the enrolled course.
     */
    const Course* getCourse() const;

    /**
     * @brief Compare if two enrolled courses are from the same semester.
     * @param rop The right-hand side Enrollment object for comparison.
     * @return True if equal, false otherwise.
     */
    bool operator==(const Enrollment& rop) const;

    /**
     * @brief Write the Enrollment object to an output stream.
     * @param out The output stream.
     */
    void write(std::ostream& out) const;

    /**
     * @brief Read an Enrollment object from an input stream.
     * @param in The input stream.
     */
    void read(std::istream& in);
};

#endif /* ENROLLMENT_H_ */
