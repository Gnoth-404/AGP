/**
 * @file StudentDB.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include <memory>
#include <map>
#include "Student.h"
class Course;

/**
 * @class StudentDb
 * @brief Represents a database of students and courses.
 */
class StudentDb {
private:
	//! Map of students, keyed by matriculation number.
    std::map<int, Student> students;
    //! Map of courses, keyed by course key.
    std::map<int, std::unique_ptr<const Course>> courses;

    /**
     * @brief Clear the database by removing all students and courses.
     */
    void clearDatabase();

public:
    /**
     * @brief Constructor for StudentDb.
     */
    StudentDb();

    /**
     * @brief Add a course to the database.
     * @param pCourse Pointer to the course to add.
     */
    void addCourse(std::unique_ptr<Course>& pCourse);

    /**
     * @brief Add a student to the database.
     * @param student The student to add.
     */
    void addStudent(Student& student);

    /**
     * @brief Enroll student to a course in give semester.
     * @param matrikelNumber The matriculation number of the student.
     * @param courseKey The course key.
     * @param semester The semester.
     * @return True if enrollment is successful, false otherwise.
     */
    bool addEnrollment(unsigned int matrikelNumber,
    		unsigned int courseKey, const std::string& semester);

    /**
     * @brief Get a student from the database by matriculation number.
     * @param matrikelNumber The matriculation number of the student.
     * @return Reference to the student object.
     */
    Student& getStudentByID(unsigned int matrikelNumber);

    /**
     * @brief Check validation of given matriculation number.
     * @param matrikelNumber The matriculation number of the student.
     * @return True if the student exists, false otherwise.
     */
    bool validStudent(unsigned int matrikelNumber);

    /**
     * @brief Check validation of given coursekey.
     * @param courseKey The course key.
     * @return True if the course exists, false otherwise.
     */
    bool validCourse(unsigned int courseKey);

    /**
     * @brief Write the StudentDb object to an output stream.
     * @param out The output stream.
     */
    void write(std::ostream& out);

    /**
     * @brief Read a StudentDb object from an input stream.
     * @param in The input stream.
     */
    void read(std::istream& in);

    /**
     * @brief Get the map of courses in the database.
     * @return Reference to the map of courses.
     */
    const std::map<int, std::unique_ptr<const Course>>& getCourses() const;

    /**
     * @brief Get the map of students in the database.
     * @return Reference to the map of students.
     */
    const std::map<int, Student>& getStudents() const;

    /**
     * @brief Find students by name in the database.
     * @param name The name to search for.
     * @return Vector of matching students.
     */
    const std::vector<Student> findStudentByName(const std::string& name) const;

    /**
     * @brief Find a course by course key in the database.
     * @param courseKey The course key.
     * @return Reference to the found course.
     */
    const Course& findCourseByCourseKey(unsigned int courseKey) const;

    /**
     * @brief Destructor for StudentDb.
     */
    virtual ~StudentDb();
};

#endif /* STUDENTDB_H_ */
