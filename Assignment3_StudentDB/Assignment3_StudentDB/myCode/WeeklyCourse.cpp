/*
 * WeeklyCourse.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include <iostream>
#include "WeeklyCourse.h"

WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints,
		Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime):
		Course(courseKey, title, major, creditPoints),
		dayOfWeek{dayOfWeek},startTime(startTime),endTime(endTime)
{
}

WeeklyCourse::~WeeklyCourse()
{
	// TODO Auto-generated destructor stub
}


Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeekFromInt(int dayIndex) {
    switch (dayIndex) {
        case 0:
            return Poco::DateTime::DaysOfWeek::SUNDAY;
        case 1:
            return Poco::DateTime::DaysOfWeek::MONDAY;
        case 2:
            return Poco::DateTime::DaysOfWeek::TUESDAY;
        case 3:
            return Poco::DateTime::DaysOfWeek::WEDNESDAY;
        case 4:
            return Poco::DateTime::DaysOfWeek::THURSDAY;
        case 5:
            return Poco::DateTime::DaysOfWeek::FRIDAY;
        case 6:
            return Poco::DateTime::DaysOfWeek::SATURDAY;
        default:
            return Poco::DateTime::DaysOfWeek::SUNDAY;
    }
}
Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return dayOfWeek;
}

const Poco::Data::Time& WeeklyCourse::getEndTime() const
{
	return endTime;
}

const Poco::Data::Time& WeeklyCourse::getStartTime() const
{
	return startTime;
}

void WeeklyCourse::write(std::ostream &out) const
{
	out << "W;";
	Course::write(out);
	out << this->dayOfWeek << ";"
			<< this->startTime.hour()<<":"
			<< this->startTime.minute()
			<<";"<< this->endTime.hour()
			<<":" << this->endTime.minute()<< std::endl;
}


void WeeklyCourse::read(std::istream &in)
{
	Course::read(in);
	Poco::DateTimeParser parser;
	int timeZoneDif =0;

	int dayIndex;
	in >> dayIndex;

	this->dayOfWeek = this->getDayOfWeekFromInt(dayIndex);
	in.ignore(1,';');
	std::string startTime, endTime;

	/*
	Parse DateTime using Poco DateTimeFormatter package
		%H - hour (00 .. 23)
		%M - minute (00 .. 59)
	*/
	std::getline(in,startTime,';');
	this->startTime = parser.parse("%H:%M",startTime,timeZoneDif);

	std::getline(in,endTime,';');
	this->endTime = parser.parse("%H:%M",endTime,timeZoneDif);


}
