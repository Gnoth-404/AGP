/*
 * Enrollment.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include "Enrollment.h"
#include <iostream>


Enrollment::Enrollment(const std::string& semester,const Course *course):
	semester{semester},course{course}
{
	this->grade = 0;

}



float Enrollment::getGrade() const
{
	return this->grade;
}

void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

const Course* Enrollment::getCourse() const
{
	return this->course;
}

const std::string& Enrollment::getSemester() const
{
	return this->semester;
}

Enrollment::~Enrollment()
{
	// TODO Auto-generated destructor stub
}

bool Enrollment::operator ==(const Enrollment &rop) const
{
  if((course == rop.getCourse()) && (semester == rop.getSemester()))
    return true;
  else
    return false;
}

void Enrollment::write(std::ostream &out) const
{
	out <<course->getCourseKey()<<";" <<semester <<";"<< grade << std::endl;
}

void Enrollment::read(std::istream &in)
{

	std::getline(in, this->semester, ';');
	in >> this->grade;
	in.ignore(1,';');

}
