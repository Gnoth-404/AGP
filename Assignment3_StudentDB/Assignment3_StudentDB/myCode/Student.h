/**
 * @file Student.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <vector>
#include <string>
#include <Poco/Data/Date.h>
#include "Address.h"
#include "Enrollment.h"

/**
 * @class Student
 * @brief Represents a student with personal information and enrolled courses.
 */
class Student {
private:
	//! Static member for generating next matriculation number.
    static unsigned int nextMatrikelNumber;
    //! Unique matriculation number.
    unsigned int matrikelNumber;
    //! First name of the student.
    std::string firstName;
    //! Last name of the student.
    std::string lastName;
    //! Address of the student.
    Address address;
    //! Student birthday
    Poco::Data::Date dateOfBirth;
    //! Vector of enrollments courses.
    std::vector<Enrollment> enrollments;

public:
    /**
     * @brief Constructor for Student.

     */
    Student(const std::string& firstName, const std::string& lastName,
    		Address address, Poco::Data::Date dateOfBirth);

    /**
     * @brief Destructor for Student.
     */
    virtual ~Student();

    // Get methods
    bool duplicateEnrollment(Enrollment& enrollment) const;
    const Address& getAddress() const;
    const Poco::Data::Date& getDateOfBirth() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    unsigned int getMatrikelNumber() const;
    unsigned int getNextMatrikelNumber() const;
    const std::vector<Enrollment>& getEnrollments() const;

    // Set methods
    void setAddress(const Address& address);
    void setDateOfBirth(const Poco::Data::Date& dateOfBirth);
    bool setNewGrade(unsigned int courseKey, float grade);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);

    /**
     * @brief Enroll the student in a course.
     * @param enrollment Enrollment object
     * @return True if enrollment is successful, false otherwise.
     */
    bool enrollCourse(Enrollment& enrollment);

    /**
     * @brief Write the Student object to an output stream.
     * @param out The output stream.
     */
    void write(std::ostream& out);

    /**
     * @brief Read a Student object from an input stream.
     * @param in The input stream.
     */
    void read(std::istream& in);
};

#endif /* STUDENT_H_ */
