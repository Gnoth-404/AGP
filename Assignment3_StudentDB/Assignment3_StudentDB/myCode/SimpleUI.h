/**
 * @file SimpleUI.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */
#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

class StudentDb;
class Course;

/**
 * @class SimpleUI
 * @brief Represents a simple user interface for managing student database
 */
class SimpleUI {
private:
	//! Reference to the student database.

    StudentDb& db;
    /**
     * @brief List details of a course.
     * @param course Pointer to the Course object.
     */
    void listCourse(const Course* course) const;

    /**
     * @brief Print help information.
     */
    void printHelp() const;

    /**
     * @brief List all courses in the database.
     */
    void listCourses() const;


    /**
     * @brief Add a new course to the database.
     */
    void addNewCourse() const;

    /**
     * @brief Add a new student to the database.
     */
    void addNewStudent() const;

    /**
     * @brief Add an enrollment (linking a student to a course).
     */
    void addEnrollment() const;

    /**
     * @brief Print details of a student.
     */
    void printStudent() const;

    /**
     * @brief Search for a student in the database.
     */
    void searchStudent() const;

    /**
     * @brief Update student information.
     */
    void updateStudent() const;

    /**
     * @brief Write the database to a file.
     */
    void writeDatabase() const;

    /**
     * @brief Read the database from a file.
     */
    void readDatabase() const;

    /**
     * @brief Retrieve student information from a server.
     */
    void getStudentFromServer() const;

public:
    /**
     * @brief Constructor for SimpleUI.
     * @param db Reference to the student database.
     */
    SimpleUI(StudentDb &db);

    /**
     * @brief Run the user interface.
     */
    void run();

    /**
     * @brief Destructor for SimpleUI.
     */
    virtual ~SimpleUI();
};

#endif /* SIMPLEUI_H_ */
