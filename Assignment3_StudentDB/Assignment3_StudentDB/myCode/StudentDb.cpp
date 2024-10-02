/*
 * StudentDb.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include "StudentDb.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "WeeklyCourse.h"
#include "BlockCourse.h"
StudentDb::StudentDb()
{

}


void StudentDb::addStudent(Student &student)
{
	this->students.insert(std::make_pair(student.getMatrikelNumber(),student));

}

void StudentDb::addCourse(std::unique_ptr<Course>& pCourse) {

	// Insert course when there is no existing course
    courses.insert(std::make_pair(pCourse->getCourseKey(), std::move(pCourse)));
}



bool StudentDb::addEnrollment(unsigned int matrikelNumber,
		unsigned int courseKey, const std::string &semester)
{
	Student& ourStudent = this->getStudentByID(matrikelNumber);


	const Course* enrollCourse = &(this->findCourseByCourseKey(courseKey));

	Enrollment enrollment(semester, enrollCourse);

	return ourStudent.enrollCourse(enrollment);

}



const std::map<int, std::unique_ptr<const Course> >& StudentDb::getCourses()
																	const
{
	return courses;
}



const std::map<int, Student>& StudentDb::getStudents() const
{
	return students;
}

void StudentDb::clearDatabase()
{
	this->courses.clear();
	this->students.clear();
}

StudentDb::~StudentDb()
{
	// TODO Auto-generated destructor stub
}

const std::vector<Student> StudentDb::findStudentByName(const std::string& name)
																	const
{
	std::vector<Student> result;
	for (const auto& student:this->students)
	{
		const auto& fullname = student.second.getFirstName() +
				student.second.getLastName();
		// find a search name in database , return all student has that name
		if (fullname.find(name) != std::string::npos) {
		    result.push_back(student.second);
		}
	}

	return result;
}

Student& StudentDb::getStudentByID(unsigned int matrikelNumber)
{
	return this->students.at(matrikelNumber);
}


const Course& StudentDb::findCourseByCourseKey(unsigned int courseKey) const
{

    auto it = this->courses.find(courseKey);

    const Course* enrollCourse = it->second.get();

    return *enrollCourse;


}

bool StudentDb::validStudent(unsigned int matrikelNumber)
{
    auto it = this->students.find(matrikelNumber);

    if (it == this->students.end())
    {
      return false;
    }
    return true;

}
bool StudentDb::validCourse(unsigned int courseKey)
{
    auto it = this->courses.find(courseKey);

    if (it == this->courses.end())
    {
      return false;
    }
    return true;
}

void StudentDb::write(std::ostream &out)
{
	// Print number of student
	out << this->students.size() << std::endl;
	for (auto& student:students)
	{
		student.second.write(out);

	}
	// Print number of courses
	out << this->courses.size() << std::endl;

	for (auto& course:courses)
	{
		course.second->write(out);
	}
	// Print Enrollment
	for (auto& student:students)
	{
		// Print out number of enrolled courses if !0
		if (student.second.getEnrollments().size()!=0)
		{
			out <<  student.second.getEnrollments().size()<< std::endl;
		}
		for(auto& enrollment:student.second.getEnrollments())
		{
			out << student.first<< ";";
			enrollment.write(out);
		}
	}

}

void StudentDb::read(std::istream &in)
{
	this->clearDatabase();
	int numStudents;
	in >> numStudents;
	in.ignore(); //Ignore new line character

	//Writing student
	for(int i=0; i< numStudents; ++i)
	{

		Student student{"","",Address{"",0,"",""},Poco::Data::Date{1,1,1}};
		// Create stringstream from each of line below number of students
		std::string studentLine;
		std::getline(in, studentLine, '\n');
		std::stringstream studentStream(studentLine);
		student.read(studentStream);
		this->addStudent(student);

	}
	int numCourses;
	in >> numCourses;
	in.ignore();

	// Writing course
	for(int i=0; i < numCourses;++i)
	{
		std::string courseLine;
		std::getline(in, courseLine, '\n');
		std::stringstream courseStream(courseLine);

		// Get course type
        std::string type;
        std::getline(courseStream, type, ';');

        // WeeklyCourse
        if (type == "W")
        {
        	std::unique_ptr<Course> pCourse(new WeeklyCourse(0,
    	    		"", "Automation", 0, Poco::DateTime::SUNDAY,
					Poco::Data::Time{0,0,0}, Poco::Data::Time{0,0,0}));
    		pCourse->read(courseStream);
    		this->addCourse(pCourse);


        }
        //BlockCourse
        else if (type == "B")
        {
        	std::unique_ptr<Course> pCourse(new BlockCourse(0,
    	    		"", "Automation", 0,
					Poco::Data::Date{1,1,1},Poco::Data::Date{1,1,1},
					Poco::Data::Time{0,0,0}, Poco::Data::Time{0,0,0}));
    		pCourse->read(courseStream);
    		this->addCourse(pCourse);
        }
	}

	// Writing enrollment

	int numEnrollments;
	in >> numEnrollments;
	in.ignore();
	for(int i=0; i < numEnrollments;++i)
	{
		// Create stringstream from each of line of enrollment
		std::string enrollmentLine;
		std::getline(in, enrollmentLine, '\n');
		std::stringstream enrollmentStream(enrollmentLine);

		// Get matrikulation number;
		unsigned int matrikelNumber;
		enrollmentStream >> matrikelNumber;
		enrollmentStream.ignore(1,';');

		//Get Course type
		unsigned int courseKey;
		enrollmentStream >> courseKey;
		enrollmentStream.ignore(1,';');

		const Course* enrollCourse = &(this->findCourseByCourseKey(courseKey));
		Enrollment enrollment{"",enrollCourse};
		enrollment.read(enrollmentStream);
		this->getStudentByID(matrikelNumber).enrollCourse(enrollment);

	}


}
