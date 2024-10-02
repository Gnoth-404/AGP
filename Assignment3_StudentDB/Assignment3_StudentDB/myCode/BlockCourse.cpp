/*
 * BlockCourse.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include "BlockCourse.h"
#include <iostream>
#include <Poco/DateTimeParser.h>

BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime):
		Course{courseKey,title,major,creditPoints},
		startDate(startDate), endDate(endDate),
		startTime(startTime), endTime(endTime)
{
}

const Poco::Data::Date& BlockCourse::getEndDate() const
{
	return endDate;
}

const Poco::Data::Time& BlockCourse::getEndTime() const
{
	return endTime;
}

const Poco::Data::Date& BlockCourse::getStartDate() const
{
	return startDate;
}

const Poco::Data::Time& BlockCourse::getStartTime() const
{
	return startTime;
}

BlockCourse::~BlockCourse()
{
	// TODO Auto-generated destructor stub
}

void BlockCourse::write(std::ostream &out) const
{
	out << "B;";
	Course::write(out);

	out << this->startDate.day() << "." << this->startDate.month()<< "."
			<< this->startDate.year()<<";"
		<<	this->endDate.day() << "." << this->endDate.month()<< "."
		<< this->endDate.year()<<";"
		<< this->startTime.hour()<<":" << this->startTime.minute()
			<<";"<< this->endTime.hour()<<":" << this->endTime.minute()
			<< std::endl;
}

void BlockCourse::read(std::istream &in)
{
	Course::read(in);
	Poco::DateTimeParser parser;
	int timeZoneDif =0;
	std::string startDate, endDate, startTime, endTime;

	std::getline(in,startDate,';');
	this->startDate= parser.parse("%e.%n.%Y",startDate,timeZoneDif);

	std::getline(in,endDate,';');
	this->endDate = parser.parse("%e.%n.%Y",endDate,timeZoneDif);

	std::getline(in,startTime,';');
	this->startTime = parser.parse("%H:%M",startTime,timeZoneDif);

	std::getline(in,endTime);
	this->endTime = parser.parse("%H:%M",endTime,timeZoneDif);
}
