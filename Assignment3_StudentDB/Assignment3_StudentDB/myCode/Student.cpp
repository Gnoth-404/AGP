/*
 * Student.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include "Student.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <Poco/DateTimeParser.h>
unsigned int Student::nextMatrikelNumber =100000;

Student::Student(const std::string& firstName,
		const std::string& lastName,
		Address address, Poco::Data::Date dateOfBirth):
		firstName{firstName}, lastName{lastName},
		address{address}, dateOfBirth{dateOfBirth}

{

	this->matrikelNumber = this->nextMatrikelNumber;
	this->nextMatrikelNumber++;
}

const Address& Student::getAddress() const
{
	return address;
}

const Poco::Data::Date& Student::getDateOfBirth() const
{
	return dateOfBirth;
}

const std::string& Student::getFirstName() const
{
	return firstName;
}

const std::string& Student::getLastName() const
{
	return lastName;
}

unsigned int Student::getMatrikelNumber() const
{
	return matrikelNumber;
}



unsigned int Student::getNextMatrikelNumber() const
{
	return nextMatrikelNumber;
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

bool Student::enrollCourse(Enrollment &enrollment)
{
	if (this->duplicateEnrollment(enrollment))
	{
		return false;
	}
	else
	{
		this->enrollments.push_back(enrollment);
		return true;
	}
}

const std::vector<Enrollment>& Student::getEnrollments() const
{
	return enrollments;
}

bool Student::duplicateEnrollment(Enrollment& enrollment) const
{
	// Find if there is duplicate course from the vector

	if ( std::find(enrollments.begin(), enrollments.end(), enrollment)
													!= enrollments.end())
	   return true;
	else
	   return false;
}

void Student::setAddress(const Address &address)
{
	this->address = address;
}

void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}


bool Student::setNewGrade(unsigned int courseKey, float grade)
{
	for (auto& enrollment:this->enrollments)
	{
		if(enrollment.getCourse()->getCourseKey() == courseKey)
		{
			enrollment.setGrade(grade);
			return true;
		}
	}
	return false;
}


void Student::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}


void Student::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void Student::write(std::ostream &out)
{
	out << matrikelNumber<<";" <<firstName <<";" << lastName <<";"
			<< dateOfBirth.day() << "."
			<< dateOfBirth.month()<< "."
			<< dateOfBirth.year()<<";";

	address.write(out);
	out << std::endl;
}

void Student::read(std::istream &in)
{
	in >> this->matrikelNumber;

	if (this->matrikelNumber>this->nextMatrikelNumber)
	{
		this->nextMatrikelNumber = this->matrikelNumber +1;
	}
	in.ignore(256,';'); // Ignore ; after matrikulation number


	std::getline(in,this->firstName,';');
	std::getline(in,this->lastName,';');

	std::string birthDay;
	std::getline(in,birthDay,';');
	Poco::DateTimeParser parser;
	int timeZoneDiff = 0;
	/*
	Parse DateTime using Poco DateTimeFormatter package
		%e - day of month (1 .. 31)
		%n - month (1 .. 12)
		%Y - year with century (1970)
	*/
	this->dateOfBirth = parser.parse("%e.%n.%Y",birthDay,timeZoneDiff);


	this->address= address.read(in);
}
