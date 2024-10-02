/*
 * Address.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#include "Address.h"
#include <iostream>
#include <Poco/StringTokenizer.h>
#include <Poco/NumberParser.h>

Address::Address(const std::string& street, unsigned short postalCode,
		const std::string& cityName, const std::string& additionalInfo):
		street{street},postalCode{postalCode},cityName{cityName},
		additionalInfo{additionalInfo}
{
}

const std::string& Address::getAdditionalInfo() const
{
	return this->additionalInfo;
}

const std::string& Address::getCityName() const
{
	return this->cityName;
}

unsigned short Address::getPostalCode() const
{
	return this->postalCode;
}

const std::string& Address::getStreet() const
{
	return this->street;
}

Address Address::read(std::istream &in)
{
	Address result{"",0,"",""};

	std::getline(in,result.street,';');

	in >> result.postalCode;
	in.ignore(1,';');

	std::getline(in,result.cityName,';');

	std::getline(in,result.additionalInfo);

	return result;
}


void Address::write(std::ostream &out) {

	 out << this->street <<";"<< this->postalCode << ";" << this->cityName
				<<";" << this->additionalInfo;
}


Address::~Address()
{
	// TODO Auto-generated destructor stub
}


