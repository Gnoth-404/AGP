/*
 * Course.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include "Course.h"
#include <iostream>
std::map<unsigned char, std::string> Course::majorById=
{
		{'A',"Automation"},
		{'E',"Embedded"},
		{'T',"Telecommunication"},
		{'P',"Power"}
};

Course::Course(unsigned int courseKey, std::string title, std::string major,
		float creditPoints)
:courseKey{courseKey},creditPoints{creditPoints}
{
	this->title = title;
	for(auto entry:majorById)
	{
		if(entry.second == major)
		{
			this->major = entry.first;
			return;
		}
	}
	// if no current major found
	std::cout <<"!!Invalid course with non-existing major created!!"<<std::endl;
}

Course::~Course()
{
	// TODO Auto-generated destructor stub
}



unsigned int Course::getCourseKey() const
{
	return courseKey;
}

float Course::getCreditPoints() const
{
	return creditPoints;
}

const std::string& Course::getMajor() const
{
	return majorById[this->major];
}



const std::string& Course::getTitle() const
{
	return title;
}

void Course::write(std::ostream &out) const
{
	out << courseKey<<";" << title << ";" << getMajor() << ";" << creditPoints <<";";
}

void Course::read(std::istream &in)
{
    in >> this->courseKey;
    in.ignore(1,';');
    std::getline(in, this->title, ';');

    std::string majorStream;
    std::getline(in, majorStream, ';');

    for (auto major : this->majorById)
    {
        if (major.second == majorStream)
        {
            this->major = major.first;
        }
    }

    in >> this->creditPoints;
    in.ignore(1,';');

}

